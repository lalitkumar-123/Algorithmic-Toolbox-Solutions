#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    vector<int> k;
    int sum = 0;

    if (n <= 2){
        summands.push_back(n);
        return summands;
    }

    for (int i = 1; i < n; ++i)
    {
        k.push_back(n - sum);
        sum += i;
        if (sum > n)
        {
            summands[i - 2] = k[i - 2];
            return summands;
        }
        else
            summands.push_back(i);
    }
    return summands;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
    return 0;
}
