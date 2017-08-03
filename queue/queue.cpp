#include "queue.h"
#define ARR_LEN 4
#define RE_SIZE_MULTIPLE 2

Queue::Queue(): queueSize(0), arrSize(ARR_LEN), popPos(0), pushPos(0)
{
    arr = new int[arrSize];
}

Queue::~Queue()
{
    if(arr)
    {
        delete []arr;
        arr = NULL;
    }
}

int Queue::getQueueSize() const
{
    cout << "QueueSize:" << queueSize << endl;
    return queueSize;
}

int Queue:: getArrSize() const
{
    cout << "ArrSize:" << arrSize << endl;
    return arrSize;
}

bool Queue::push(int value)
{
    // no space in array
    if(popPos == pushPos){
        if(queueSize == arrSize){
            resize();
            cout << "resize" << endl;
        }
    }
    arr[pushPos] = value;
    queueSize++;
    // at the end of array
    if(pushPos == arrSize-1){
        pushPos = 0;
    }
    else{
        pushPos++;
    }
    cout << "push value:" << value << " pushPos:" << pushPos <<endl;
    return true;
}

int  Queue::pop()
{
    // queue empty
    if(queueSize == 0){
        cout << "popPos == pushPos" << endl;
        return -1;
    }
    // at the end of array
    if(popPos == arrSize-1){
        popPos = 0;
        return arr[arrSize-1];
    }
    
    popPos++;
    queueSize--;
    cout << "popPos:" << popPos << endl;
    return arr[popPos-1];
}

// resize array if no space when pushing the element
void Queue::resize()
{
    int *arr_resize = new int[arrSize*RE_SIZE_MULTIPLE];
    if(popPos == 0){
        memcpy(arr_resize, arr, arrSize*sizeof(int));
    }
    // queue loops to front positions of the array
    else{
        memcpy(arr_resize, &arr[popPos], (arrSize-popPos)*sizeof(int));
        memcpy(&arr_resize[arrSize-popPos], arr, popPos*sizeof(int));
    }
    popPos = 0;
    pushPos = arrSize;
    
    if(arr){
        delete []arr;
        arr = NULL;
    }
    arr = arr_resize;
    arrSize *=RE_SIZE_MULTIPLE;
}
