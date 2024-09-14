#include <vector>
#include <random>
#include <ctime>

using namespace std;

class BubbleSort {
public:
    BubbleSort(int tam) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 50);

        for (int i = 0; i < tam; ++i) {
            num.push_back(dis(gen));
        }
    }

    vector<int> Sort() {
        int tam = num.size();
        for (int i = 0; i < tam - 1; i++) {
            for (int j = 0; j < tam - i - 1; j++) {
                if (num[j] > num[j + 1]) {
                    swap(num[j], num[j + 1]);
                }
            }
        }
        return num;
    }

    vector<int> GetUnsortedArray() {
        return num;
    }

private:
    vector<int> num;
};
