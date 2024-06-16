#include <iostream>
#include <vector>
using namespace std;


typedef long long q;  // переименовывание типа


typedef struct {
    float due;
    int over_due;
    char name[40];
} client;  // имя типа

struct ObjectName {
    int var1;
    int var2;
    float average;
};


class ObjectClass {
    private:
        int var1;
        int var2;
    public:
        float average;
    
};


struct coord {
    double x, y, another_value;
};

bool operator<(const coord &a, const coord &b) {
    return a.x < b.x;
}


// typedef struct coord {
//     double x, y, another_value;
// } new_name;


enum LivingCreatureState {
    NOT_BORN,
    IS_ALIVE,
    DEAD
};

struct LivingCreature {
    LivingCreatureState state = LivingCreatureState::NOT_BORN;  // 0 - not born, is_alive - 1, dead - 2;
    float age;
    LivingCreature() {
        age = 0;
    }

    LivingCreature(float age) {
        (*this).age = age;
        this->state = LivingCreatureState::IS_ALIVE;
    }

    void burn() {
        if (state == LivingCreatureState::NOT_BORN)
            cout << "tree not found" << endl;
        else {
            state = LivingCreatureState::DEAD;
            cout << "Sorry? it has burnt" << endl;
        }
    }
};


int main() {
    q n = 10000;
    cout << n << endl;
    // ObjectName o = {var1: 1, var2: 45, average: 0};

    vector<coord> coords;
    coords.emplace_back((coord) {x: 0, y: 0, another_value: 5});

    // LivingCreature tree = {state: LivingCreatureState::NOT_BORN};
    LivingCreature tree = LivingCreature();
    LivingCreature tree2 = LivingCreature(45);
    tree.state = LivingCreatureState::IS_ALIVE;
    tree2.state = (LivingCreatureState) 1;

    cout << tree.state << " " << tree2.state << endl;
    tree.burn();
    cout << tree2.age << endl;

    cout << coords[0].another_value;
}
