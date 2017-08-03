#ifndef QUEUE_H
#define QUEUE_H

#include <cstring>
#include <iostream>
using namespace std;

/*
 * Implement circular queue by array
 *
 *@author Qiuyue Zhang
 *@date 2017/8/3
 */
class Queue
{
    public:
        Queue();
        ~Queue();
        int getQueueSize() const;
        int getArrSize() const;
        bool push(int value);
        int pop();
    private:
        void resize();
    private:
        int *arr;
        int queueSize;
        int arrSize;
        int popPos;
        int pushPos;
};

#endif
