#include <iostream>
#include <vector>
using namespace std;

int compute_min_refills(int destination, int tank, vector<int> & stops) {
    int min_refills = 0;
    int cand = 0;
    int curr = 0;

    for (size_t i = 1; i < stops.size(); ++i) {
        if ((stops.at(i) - stops.at(i - 1) > tank)
            || (stops.at(0) > tank)
            || (destination - stops.at(stops.size() - 1) > tank))
            return -1;
    }

    for (size_t j = 0; j < stops.size(); ++j) {
        if (j == stops.size() - 1) {
            if ((destination - curr) <= tank)
                return min_refills;
            else if ((stops.at(j) - curr) <= tank)
                return min_refills + 1;
            else {
                min_refills += 1;
                curr = stops.at(j - 1);
                j--;
                continue;
            }
        } else if ((stops.at(j) - curr) <= tank) {
            cand = stops.at(j);
        } else {
            min_refills += 1;
            curr = cand;
            j--;
        }
    }
    return min_refills;
}

int main() {
    int destination, tank, n;
    cin >> destination >> tank >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(destination, tank, stops) << "\n";
    return 0;
}
