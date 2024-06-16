#include <fstream>
#include <vector>


struct Edge {
    int train_begin;
    int train_end;
    int distantion;
};


int main() {
    int amount_station, end, amount_trains;
    std::ifstream in("a.in");
    std::ofstream out("a.out");

    in >> amount_station >> end >> amount_trains;
    std::vector<std::vector<Edge>> escape(1 + amount_station);
    for (int i = 0; i < amount_trains; i++) {
        int len;
        in >> len;
        int previos_station, previos_train;
        in >> previos_station >> previos_train;

        for (int j = 1; j < len; j++) {
            int current_station, current_train;

            in >> current_station >> current_train;
            escape[previos_station].push_back(Edge{previos_train, current_train, current_station});

            previos_station = current_station;
            previos_train = current_train;
        }
    }

    const int MAX = 1000 * 1000 * 1000 + 1;

    std::vector<int> minimal_time(1 + amount_station, MAX);

    minimal_time[1] = 0;

    std::vector<bool> isFinal(1 + amount_station, false);

    while (true) {
        int minimal_station = -1, minimal_train = MAX;
        for (int i = 1; i <= amount_station; i++) {
            if (!isFinal[i] && minimal_time[i] < minimal_train) {
                minimal_train = minimal_time[i];
                minimal_station = i;
            }
        }

        if (minimal_train == MAX) {
            break;
        }

        isFinal[minimal_station] = true;

        for (const Edge edge : escape[minimal_station]) {
            if (edge.train_begin >= minimal_time[minimal_station]) {
                if (edge.train_end < minimal_time[edge.distantion]) {
                    minimal_time[edge.distantion] = edge.train_end;
                }
            }
        }
    }

    if (minimal_time[end] == MAX) {
        out << -1;
    }
    else 
        out << minimal_time[end];

    return 0;
}
