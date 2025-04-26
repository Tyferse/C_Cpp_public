#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
// #include <random>
#include <time.h>
#include <chrono>
#include <mpi.h>


std::string clean_word(std::string word) {
    std::string cleaned;
    for (char ch : word) {
        if (std::isalnum(ch)) {
            // std::cout << "\"" << (char)std::tolower(ch) << "\" ";
            cleaned += (char)std::tolower(ch);
        }
    }

    // std::cout << "\"" << cleaned << "\" ";
    return cleaned;
}

std::string trim(const std::string& str) {
    std::string trimmed = str;
    
    trimmed.erase(trimmed.begin(), std::find_if(trimmed.begin(), trimmed.end(), 
                  [](unsigned char c) { return !std::isspace(c); }));
    trimmed.erase(std::find_if(trimmed.rbegin(), trimmed.rend(), 
                  [](unsigned char c) { return !std::isspace(c); }).base(), trimmed.end());
    return trimmed;
}

std::vector<std::string> find_unique_words(const char* text) {
    std::istringstream iss(text);
    std::string line;
    std::string word;
    std::vector<std::string> unique_words;
    bool unique;        
    while (iss >> word) {
        // std::cout << word << std::endl;  
        word = clean_word(word);
        // std::cout << word << std::endl;        
        unique = true;
        for (auto w : unique_words) {
            if (w == word) {
                unique = false;
                break;
            }
        }

        if (unique)
            unique_words.push_back(word);
        }

    return unique_words;
}

// void send_string(const std::string& str, int dest, int tag, MPI_Comm comm) {
//     int length = str.size();
//     MPI_Send(&length, 1, MPI_INT, dest, tag, comm);
//     MPI_Send(str.c_str(), length, MPI_CHAR, dest, tag, comm);
// }

// void receive_string(std::string& str, int source, int tag, MPI_Comm comm) {
//     MPI_Status status;
//     int length;
//     MPI_Recv(&length, 1, MPI_INT, source, tag, comm, MPI_STATUS_IGNORE);
//     std::vector<char> buffer(length);
//     MPI_Recv(buffer.data(), length, MPI_CHAR, source, tag, comm, MPI_STATUS_IGNORE);
//     str.assign(buffer.begin(), buffer.end());
// }

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int trank, tsize;
    MPI_Comm_rank(MPI_COMM_WORLD, &trank);
    MPI_Comm_size(MPI_COMM_WORLD, &tsize);

    std::string text = "", new_text = "";
    int max_word_len = 0, total_words = 0;
    std::chrono::_V2::system_clock::time_point start, end;
    if (trank == 0) {
        std::ifstream inputFile("input2.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Unable to open file!" << std::endl;
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        std::string line, word;
        std::cout << "String from input.txt: ";
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            // std::string word;
  
            // std::cout << "String from input.txt: ";
            while (iss >> word) {
                // std::cout << word << " ";
                text += word + " ";
                total_words += 1;
                // std::cout << words.back() << " ";

                if (max_word_len < word.length())
                    max_word_len = word.length();
            }

            // std::cout << std::endl;
        }

        inputFile.close();

        start = std::chrono::high_resolution_clock::now();
        std::vector<std::string> unique_words = find_unique_words(text.c_str());
        end = std::chrono::high_resolution_clock::now();

        std::cout << "\nTotal unique words: " << unique_words.size() << std::endl << std::endl;

        for (auto w : unique_words) {
            // if (max_word_len < w.length())
            //     max_word_len = w.length();

            std::cout << w << ", ";
        }
        std::cout << std::endl << std::endl;

        std::cout << "Sequence time: " << (std::chrono::duration<double>(end - start)).count();
        std::cout << std::endl << std::endl;

        // Добавляем пробельные символы, чтобы можно было разделить строку на равные части
        std::istringstream iss(text);
        while (iss >> word) {
            new_text += word;
            for (int i = 0; i < max_word_len - word.length() + 1; i++)
                new_text += " ";
        }

        // std::cout << new_text << std::endl;
    }

    MPI_Bcast(&max_word_len, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&total_words, 1, MPI_INT, 0, MPI_COMM_WORLD);
    
    int BLOCK_SIZE = total_words / tsize, SUBBLOCK_SIZE = total_words % tsize;
    int END_BLOCK = BLOCK_SIZE;
    if (SUBBLOCK_SIZE != 0) {
        // BLOCK_SIZE = total_words / (tsize - 1);
        // SUBBLOCK_SIZE = total_words % (tsize - 1);
        BLOCK_SIZE += 1;
        END_BLOCK = BLOCK_SIZE;
        
        // if (trank == tsize - 1) 
        //     END_BLOCK = SUBBLOCK_SIZE;
        // else
        //     END_BLOCK = BLOCK_SIZE;
    }

    // std::cout << total_words << " " << BLOCK_SIZE << " " << SUBBLOCK_SIZE << " ";

    // if (trank == 0) 
    //     start = std::chrono::high_resolution_clock::now();

    std::vector<char> local_words(BLOCK_SIZE * (max_word_len + 1)), global_words(tsize * BLOCK_SIZE * (max_word_len + 1));
    if (trank == 0) 
        start = std::chrono::high_resolution_clock::now();

    MPI_Scatter(new_text.c_str(), BLOCK_SIZE * (max_word_len + 1), MPI_CHAR, 
                local_words.data(), BLOCK_SIZE * (max_word_len + 1), MPI_CHAR, 
                0, MPI_COMM_WORLD);

    // std::string buff;
    // if (trank == tsize - 1)
    std::string buff(local_words.begin(), local_words.end());
    // std::cout << buff << std::endl;
    // else 
    //     buff = buff(local_words.begin(), local_words.end());

    std::vector<std::string> uwu = find_unique_words(buff.c_str());
    buff = "";
    for (auto w : uwu) {
        buff += w;
        for (int i = 0; i < max_word_len - w.length() + 1; i++)
            buff += " ";
    }

    for (int i = 0; i < (END_BLOCK - uwu.size()) * (max_word_len + 1); i++)
        buff += " ";

    // std::cout << trank << " " << buff << std::endl;
    MPI_Gather(buff.c_str(), BLOCK_SIZE * (max_word_len + 1), MPI_CHAR, 
               global_words.data(), BLOCK_SIZE * (max_word_len + 1), MPI_CHAR, 
               0, MPI_COMM_WORLD);

    // if (trank == 0) {
    //     std::string all_unique_words;
    //     for (int i = 1; i < tsize; i++) {
    //         receive_string(uw, i, 0, MPI_COMM_WORLD);
    //     }
    // }
    // else {
    //     MPI_Send(uw.c_str(), uw.size(), MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    // }

    if (trank == 0) {
        std::string buff2(global_words.begin(), global_words.end());
        // std::cout << buff2 << std::endl;
        uwu = find_unique_words(buff2.c_str());
        end = std::chrono::high_resolution_clock::now();
        
        std::cout << "\nTotal unique words: " << uwu.size() << std::endl << std::endl;

        for (auto w : uwu) {
            // if (max_word_len < w.length())
            //     max_word_len = w.length();

            std::cout << w << ", ";
        }
        std::cout << std::endl << std::endl;
        
        std::cout << "Parallel time: " << (std::chrono::duration<double>(end - start)).count();

        // for (auto w : uwu) {
        //     std::cout << w << " ";
        // }
    }

    // std::cout << "Process " << trank << " recieve words: ";
    // for (int i = 0; i < uwu.size(); i++) { 
        // std::string word(local_words.begin() + i * (max_word_len + 1), local_words.begin() + i + (i + 1)*max_word_len);
        // std::cout << trim(word.c_str()) << " "; 
        // std::cout << uwu.at(i) << " ";
    // }

    // std::cout << std::endl;

    MPI_Finalize();
    return 0;
}
