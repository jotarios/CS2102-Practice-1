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
