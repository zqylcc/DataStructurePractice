#include <iostream>
#include <thread>
#include "queue.h"
using namespace std;

void resize_1(Queue& q)
{
    int value;
    q.pop(value);
    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    
}

void resize_2(Queue& q)
{
    int value;
    q.push(0);
    q.pop(value);
    q.push(1);
    q.push(2);
    q.pop(value);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    cout << "queue: ";
    int size = q.getQueueSize();
    for (int i=0; i<size; i++) {
        q.pop(value);
    }
}

int main()
{
    Queue queue1(4, 0);
    cout << "resize_1" << endl;
    resize_1(queue1);
    cout << "resize_2" << endl;
    Queue queue2(queue1);
    resize_2(queue2);
    return 0;
}
