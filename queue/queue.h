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
        Queue(int size = 4);
        ~Queue();
        int getQueueSize() const;
        int getArrSize() const;
        bool push(int value);
        bool pop(int &value);
    private:
        bool resize();
    private:
        int *arr;
        int queueSize;
        int arrSize;
        int popPos;
        int pushPos;
};

#endif
