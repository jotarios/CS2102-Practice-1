#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <random>
#include <fstream>

#define FILE_PATHNAME "plotter/input/data.txt"
#define STEP 10
#define MAX 800
#define MAX_RANDOM 20000

template<class AnyObject>
class Sort {
 private:
  std::vector<AnyObject> collection;
 public:
  Sort(std::vector<AnyObject> collection) {
    this->collection = collection;
  }

  std::vector<AnyObject> &getCollection() {
    return collection;
  }

  void setCollection(const std::vector<AnyObject> &collection) {
    Sort::collection = collection;
  }

  void insertion() {
    for (int i = 1; i < this->collection.size(); i++) {
      int j = i;
      AnyObject key = this->collection[i];

      while (j > 0 && this->collection[j - 1] > key) {
        this->collection[j] = this->collection[j - 1];
        j--;
      }

      this->collection[j] = key;
    }
  }

  void mergeCollection(std::vector<AnyObject> &collection, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    std::vector<AnyObject> L(n1 + 1);
    std::vector<AnyObject> R(n2 + 1);

    for (int i = 0; i < n1; ++i) {
      L[i] = collection[p + i];
    }

    for (int j = 0; j < n2; ++j) {
      R[j] = collection[q + j + 1];
    }

    L[n1] = std::numeric_limits<AnyObject>::max();
    R[n2] = std::numeric_limits<AnyObject>::max();

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++) {
      if (L[i] <= R[j]) {
        collection[k] = L[i];
        i++;
      } else {
        collection[k] = R[j];
        j++;
      }
    }
  }

  void merge(std::vector<AnyObject> &collection, int p, int r) {
    if (p < r) {
      int q = std::floor((p + r) / 2.0);

      merge(collection, p, q);
      merge(collection, q + 1, r);

      mergeCollection(collection, p, q, r);
    }
  }

  void describe() {
    for (auto &element : collection) {
      std::cout << element << " ";
    }

    std::cout << std::endl;
  }
};

void writeFile(std::vector<std::pair<float, float>> measures) {
  std::fstream file(FILE_PATHNAME, std::ios::out);

  if (!file.is_open()) {
    std::cout << "Error al leer el archivo" << std::endl;
  }

  for (auto &x : measures) {
    file << std::fixed << x.first << " " << x.second << std::endl;
  }

  file.close();
}

int main() {
  std::vector<std::pair<float, float>> measures;
  std::pair<float, float> measure;

  for (int i = 1; i < (MAX / STEP) + 1; i++) {
    std::vector<int> collection(i * STEP);

    std::generate(collection.begin() + i - 1, collection.end(), []() {
      return rand() % MAX_RANDOM;
    });

    auto sort = new Sort<int>(collection);

    // Insertion Sort
    auto t0 = clock();
    sort->insertion();
    auto t1 = clock();
    auto insertionTime = (float) (t1 - t0) / CLOCKS_PER_SEC;

    // Merge sort
    sort->setCollection(collection);
    t0 = clock();
    sort->merge(sort->getCollection(), 0, collection.size() - 1);
    t1 = clock();
    auto mergeTime = (float) (t1 - t0) / CLOCKS_PER_SEC;

    measure.first = insertionTime;
    measure.second = mergeTime;
    measures.push_back(measure);
  }

  writeFile(measures);

  return 0;
}
