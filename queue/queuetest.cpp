#include <iostream>
#include <thread>
#include "queue.h"
using namespace std;

int main()
{
    Queue q = Queue();
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(4);
    q.push(4);
    q.push(4);
    q.push(4);
    q.pop();
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.getQueueSize();
    q.getArrSize();
    return 0;
}
