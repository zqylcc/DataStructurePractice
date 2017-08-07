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
        Queue(int size = 4, int value = 0);
        Queue(int array[], int size);
        Queue(const Queue& queue);
        ~Queue();
        int getQueueSize() const;
        int getArrSize() const;
        /*
         * push element at end of queue
         *
         * @param:
         *          value(int) the element need to push
         * @return:
         *          true: successful
         *          false: failed
         * 
         */
        bool push(int value);
        /*
         *pop and remove the head element of queue
         *
         * @param: 
         *          value(&int) get the element need to pop
         *@return:
         *          true: successful
         *          false: failed
         *
         */
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
