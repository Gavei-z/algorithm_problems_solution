class BoundedBlockingQueue {
    int _max_size;
    queue<int> q;
    mutex _mtx;
    condition_variable cv;
public:
    BoundedBlockingQueue(int capacity) {
        _max_size = capacity;
    }
    
    void enqueue(int element) {
        unique_lock lock(_mtx);
        cv.wait(lock, [&](){return q.size() < _max_size;});
        q.push(element);
        lock.unlock();
        cv.notify_one();
    }
    
    int dequeue() {
        unique_lock lock(_mtx);
        cv.wait(lock, [&](){return q.size() > 0;});
        int res = q.front();
        q.pop();
        lock.unlock();
        cv.notify_one();
        return res;
    }
    
    int size() {
        unique_lock lock(_mtx);
        int res = q.size();
        lock.unlock();
        return res;
    }
};
