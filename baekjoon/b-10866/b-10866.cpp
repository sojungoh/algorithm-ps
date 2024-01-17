#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Deque {
    int head;
    int tail;
    int count;
    vector<int> container;
    
    public:
        Deque(int x) : head(x), tail(x), count(0) {}
        void alloc();
        void push_front(int x);
        void push_back(int x);
        int pop_front();
        int pop_back();
        int size() const;
        int empty() const;
        int front() const;
        int back() const;
};

void Deque::alloc() { 
    this->container.resize(2*head + 1);
    fill(this->container.begin(), this->container.end(), 0);
}
void Deque::push_front(int x) {
    if(count == 0) tail++;
    else head--;
    this->container[head] = x;
    count += 1;
}
void Deque::push_back(int x) {
    this->container[tail++] = x;
    count += 1;
}
int Deque::pop_front() {
    if(count == 0)
        return -1;
    count -= 1;
    return this->container[head++];
}
int Deque::pop_back() {
    if(count == 0)
        return -1;
    count -= 1; 
    return this->container[--tail];
}
int Deque::size() const { return this->count; }
int Deque::empty() const {
    if(count == 0)
        return 1;
    return 0;
}
int Deque::front() const {
    if(count == 0)
        return -1;
    return this->container[head];
}
int Deque::back() const {
    if(count == 0)
        return -1;
    return this->container[tail - 1];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    Deque deck(n - 1);
    deck.alloc();

    string cmd;

    while(n--) {
        cin >> cmd;
        
        if(cmd == "push_front") {
            int x; cin >> x;
            deck.push_front(x);
        }
        else if(cmd == "push_back") {
            int x; cin >> x;
            deck.push_back(x);
        }
        else if(cmd == "pop_front") { cout << deck.pop_front() << '\n'; }
        else if(cmd == "pop_back") { cout << deck.pop_back() << '\n'; }
        else if(cmd == "size") { cout << deck.size() << '\n'; }
        else if(cmd == "empty") { cout << deck.empty() << '\n'; }
        else if(cmd == "front") { cout << deck.front() << '\n'; }
        else if(cmd == "back") { cout << deck.back() << '\n'; }
    }

    return 0;
}