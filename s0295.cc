class MedianFinder {
  priority_queue<int, vector<int>> max_heap;
  priority_queue<int, vector<int>, decltype([](int l, int r){ return l > r; })> min_heap;
public:
  MedianFinder() {
  }

  void addNum(int num) {
    if (max_heap.empty()) {
      max_heap.push(num);
      return;
    }

    if (num < max_heap.top()) {
      max_heap.push(num);
      if (max_heap.size() - 1 > min_heap.size()) {
        min_heap.push(max_heap.top());
        max_heap.pop();
      }
    } else {
      min_heap.push(num);
      if (min_heap.size() - 1 > max_heap.size()) {
        max_heap.push(min_heap.top());
        min_heap.pop();
      }
    }
  }

  double findMedian() {
    if (max_heap.size() == min_heap.size()) {
      return (double)(max_heap.top() + min_heap.top()) / 2.f;
    } else if (max_heap.size() > min_heap.size()) {
      return (float)(max_heap.top());
    } else {
      return (float)(min_heap.top());
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
