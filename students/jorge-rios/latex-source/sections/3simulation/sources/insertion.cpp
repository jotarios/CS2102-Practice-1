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
