#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
using namespace std;

void firstUniqChar() {
    string s;
    cout << "Enter line: ";
    cin >> s;
    int count[26] = { 0 }; 
    int n = s.length();
    int index = -1;
        for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }
    for (int i = 0; i < n; i++) {
        if (count[s[i] - 'a'] == 1) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        cout << "First unique char '" << s[index] << "' index: " << index << endl;
    }
    else {
        cout << "No uniques chars" << endl;
    }
}

class MyStack {
public:
    queue<int> q1, q2;

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        if (q1.empty()) {
            return -1; 
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int top = q1.front();
        q1.pop();

        swap(q1, q2);

        return top;
    }

    int top() {
        if (q1.empty()) {
            return -1;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int top = q1.front();

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }

        return top;
    }

    bool empty() {
        return q1.empty();
    }
};

void handleQueueStack() {
    MyStack stack;
    int choice, val, counter = 0;
    do {
        cout << "Stack Operations:\n1. Push\n2. Pop\n3. Top\n4. Exit\nChoose an option: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> val;
            stack.push(val);
            counter++;
            break;
        case 2:
            if (counter != 0)
            {
                stack.pop();
                cout << "Top element popped.\n";
                counter--;
            }
            else cout << "Stack is empty.\n";
            break;
        case 3:
            if (counter != 0)
            {
                cout << "Top element: " << stack.top() << endl;
            }
            else cout << "Stack is empty.\n";
            break;   
        case 4:
            cout << "Exiting QueueStack operations.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}

class RecentCounter {
public:
    queue<int> pings;

    RecentCounter() {}

    int ping(int t) {
        pings.push(t);

        while (!pings.empty() && t - pings.front() > 3000) {
            pings.pop();
        }

        return pings.size();
    }
};

void handleRecentCounter()
{
    RecentCounter counter;
    int choice;
    
    do {
        cout << "RecentCounter Operations:\n1. ping(1)\n2. ping(100)\n3. ping(1000)\n4. Exit\nChoose an option: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << counter.ping(1) << endl;
            break;
        case 2:
            cout << counter.ping(100) << endl;
            break;
        case 3:
            cout << counter.ping(1000) << endl;
            break;
        case 4:
            cout << "Exiting operations.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}

class MyCircularQueue {
public:
    int* data;
    int front, rear, size, capacity;

    MyCircularQueue(int k) {
        data = new int[k];
        front = -1;
        rear = -1;
        size = 0;
        capacity = k;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return data[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return data[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

void handleCircularQueue()
{
    {
        MyCircularQueue Myqueue(1);
        int choice, val, counter = 0;
        do {
            cout << "Myqueue Operations:\n1. enQueue\n2. deQueue\n3. Front\n4. Rear \n5.isEmpty \n6.isFull \n7.Exit\nChoose an option: ";
            cin >> choice;
            switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                Myqueue.enQueue(val);
                counter++;
                break;
            case 2:
                if (counter != 0)
                {
                    Myqueue.deQueue();
                    cout << "Top element popped.\n";
                    counter--;
                }
                else cout << "Queue is empty.\n";
                break;
            case 3:
                if (counter != 0)
                {
                    cout << "Front element: " << Myqueue.Front() << endl;
                }
                else cout << "Queue is empty.\n";
                break;
            case 4:
                if (counter != 0)
                {
                    cout << "Last element: " << Myqueue.Rear() << endl;
                }
                else cout << "Stack is empty.\n";
                break;
            case 5:
                if (Myqueue.isEmpty())
                {
                    cout << "Queue is empty " <<endl;
                }
                else cout << "Queue is full.\n";
                break;
            case 6:
                if (Myqueue.isFull())
                {
                    cout << "Queue is full";
                }
                else cout << "Queue is empty.\n";
                break;

            case 7:
                cout << "Exiting Queue operations.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 7);
    }
}


bool canPlace(const string& s, const string& stamp, int pos) {
    for (int i = 0; i < stamp.size(); ++i) {
        if (s[pos + i] != '?' && s[pos + i] != stamp[i]) {
            return false;
        }
    }
    return true;
}

void stampString(string& s, const string& stamp, int pos) {
    for (int i = 0; i < stamp.size(); ++i) {
        s[pos + i] = '?';
    }
}

vector<int> movesToStamp(string stamp, string target) {
    string s(target.size(), '?'); 
    vector<int> result;
    int maxTurns = 10 * target.size();
    bool changed;

    while (s != target && maxTurns--) {
        changed = false;

        for (int i = 0; i <= target.size() - stamp.size(); ++i) {
            if (canPlace(target, stamp, i)) {
                stampString(target, stamp, i);
                result.push_back(i);
                changed = true;
            }
        }

        if (!changed) return {}; 
    }

    if (target != s) return {}; 
    reverse(result.begin(), result.end());
    return result;
}

void handleStampSequence() {
    string stamp, target;
    cout << "Enter the stamp: ";
    cin >> stamp;
    cout << "Enter the target: ";
    cin >> target;

    vector<int> result = movesToStamp(stamp, target);

    if (result.empty()) {
        cout << "Cannot stamp the target string.\n";
    }
    else {
        cout << "Stamping positions: ";
        for (int pos : result) {
            cout << pos << " ";
        }
        cout << endl;
    }
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq; 

    for (int i = 0; i < nums.size(); ++i) {
      
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

       dq.push_back(i);

        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

void handleSlidingWindowMax() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the size of the sliding window: ";
    cin >> k;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Maximum values in each sliding window: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

int constrainedSubsetSum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n, 0);
    deque<int> dq;

    int maxSum = nums[0];
    for (int i = 0; i < n; ++i) {
        
        dp[i] = nums[i] + (dq.empty() ? 0 : dp[dq.front()]);
        maxSum = max(maxSum, dp[i]);

       
        if (!dq.empty() && dq.front() < i - k) {
            dq.pop_front();
        }

        while (!dq.empty() && dp[dq.back()] <= dp[i]) {
            dq.pop_back();
        }

        if (dp[i] > 0) {
            dq.push_back(i);
        }
    }

    return maxSum;
}

void handleConstrainedSubsetSum() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int result = constrainedSubsetSum(nums, k);
    cout << "Maximum constrained subsequence sum: " << result << endl;
}


int main() {
    int choice;
    vector<int> result;
    while (1)
    {
        cout << "Choose a task to execute (1-8):\n";
        cout << "1. Unique char\n";
        cout << "2. Queue stack\n";
        cout << "3. Recent counter\n";
        cout << "4. Circular queue\n";
        cout << "5. Stamp\n";
        cout << "6. Sliding window\n";
        cout << "7. Constrained subset sum\n";
        cout << "8. Exit\n";
        cin >> choice;
        switch (choice) {
        case 1:
            firstUniqChar();
            break;
        case 2:
            handleQueueStack();
            break;
        case 3:
            handleRecentCounter();
            break;
        case 4:
            handleCircularQueue();
            break;
        case 5:
            handleStampSequence();     
            break;
        case 6:
            handleSlidingWindowMax();
            break;
        case 7:
            handleConstrainedSubsetSum();
            break;
        case 8:
            return 0;
        default:
            cout << "Invalid choice. Please select a valid task." << endl;
        }
    }

    return 0;
}