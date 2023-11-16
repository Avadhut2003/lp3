#include <iostream>
#include <algorithm>
using namespace std;

struct Object {
    int profit;
    int weight;
    double p_w; // profit-to-weight ratio
};

bool compare(Object a, Object b) {
    return a.p_w > b.p_w;
}

int main() {
    int object, m;
    cout << "Enter the Total Objects: ";
    cin >> object;

    Object objects[object];
    for (int i = 0; i < object; i++) {
        cout << "Enter the Profit and weight for object " << (i + 1) << ": ";
        cin >> objects[i].profit >> objects[i].weight;
        objects[i].p_w = static_cast<double>(objects[i].profit) / objects[i].weight;
    }

    cout << "\nEnter the Knapsack capacity: ";
    cin >> m;

    sort(objects, objects + object, compare);

    cout << "\n-----Data-Set------" << endl;
    cout << "Objects\t";
    for (int i = 1; i <= object; i++) {
        cout << i << "\t";
    }
    cout << endl;
    cout << "Profit\t";
    for (int i = 0; i < object; i++) {
        cout << objects[i].profit << "\t";
    }
    cout << endl;
    cout << "Weight\t";
    for (int i = 0; i < object; i++) {
        cout << objects[i].weight << "\t";
    }
    cout << endl;
    cout << "P/W\t";
    for (int i = 0; i < object; i++) {
        cout << objects[i].p_w << "\t";
    }

    double sum = 0;
    cout << endl;
    for (int i = 0; i < object; i++) {
        if (objects[i].weight <= m) {
            sum += objects[i].profit;
            m -= objects[i].weight;
        } else {
            double x4 = m * objects[i].profit;
            double x5 = objects[i].weight;
            double x6 = x4 / x5;
            sum += x6;
            break;
        }
    }

    cout << "\nFinal Profit is: " << sum << endl;

    return 0;
}
