#include <queue>

class MyStack {
  public:
  private:
    std::queue<int> q;

  public:
    MyStack() {}

    // the only tricky part of this problem is that we have to use the queue
    // and pop wont work as expected, because it removes an element from the top of the queue, but we need back element
    void push(int x) {
        // so on each push we just simple reverse the queue, its not optimal tho
        // but the problem is about implementing a stack using a queue, and not to find an optimal solution, so its ok

        // [1, 2]
        // push(3)
        // [1, 2, 3]
        // push all the front elements until the last one, which is 3 in this case
        // push(1)
        // pop()
        // push(2)
        // pop()
        // [3, 2, 1]
        //
        // so now the pop will work as expected, because 3 is a top of the stack
        this->q.push(x);
        for (int i = 0; i < this->q.size() - 1; i++) {
            this->q.push(this->q.front());
            this->q.pop();
        }
    }

    int pop() {
        const int back = this->q.front();
        this->q.pop();
        return back;
    }

    int top() { return this->q.front(); }
    bool empty() { return this->q.empty(); }
};
