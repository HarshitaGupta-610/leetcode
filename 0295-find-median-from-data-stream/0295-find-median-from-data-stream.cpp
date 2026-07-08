class MedianFinder {
public:

    // Left half -> Max Heap
    // Isme hamesha chhota half store hoga.
    // Top pe left half ka sabse bada element hoga.
    priority_queue<int> left;

    // Right half -> Min Heap
    // Isme hamesha bada half store hoga.
    // Top pe right half ka sabse chhota element hoga.
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {

    }

    void addNum(int num) {

        // Agar left heap empty hai ya num left ke top se chhota/equal hai
        // to num left half me jayega.
        if (left.empty() || num <= left.top()) {
            left.push(num);
        }
        else {
            // warna right half me jayega.
            right.push(num);
        }

        // ---------------- BALANCING ----------------

        // Agar left heap me 2 se zyada extra elements ho gaye
        // to uska top right heap me bhej do.
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }

        // Agar right heap me zyada elements ho gaye
        // to uska smallest element left heap me bhej do.
        else if (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {

        // Dono heaps ka size equal hai
        // Median = dono tops ka average
        if (left.size() == right.size()) {

            // 2.0 likhna zaruri hai warna integer division ho jayegi.
            return (left.top() + right.top()) / 2.0;
        }

        // Agar left heap bada hai
        if (left.size() > right.size()) {
            return left.top();
        }

        // Agar right heap bada hai
        return right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */