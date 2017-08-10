#include "queue.h"
#define RE_SIZE_MULTIPLE 2

Queue::Queue(int size, int value): queueSize(0), arrSize(size), popPos(0), pushPos(0)
{
    arr = new int[arrSize];
    // TODO: handle exception
    memset(arr, value, arrSize);
}

Queue::Queue(const int array[], int size): queueSize(0), arrSize(size), popPos(0), pushPos(0)
{
    arr = new int[arrSize];
    // TODO: handle exception
    memcpy(arr, array, arrSize);
}

Queue::Queue(const Queue& queue)
{
    queueSize = queue.queueSize;
    arrSize = queue.arrSize;
    arr = new int[arrSize];
    //memcpy(arr, queue.arr, arrSize);
    for (int i=0; i<arrSize; i++) {
        arr[i] = queue.arr[i];
    }
    popPos = queue.popPos;
    pushPos = queue.pushPos;
}

Queue::~Queue()
{
    if (arr) {
        delete []arr;
        arr = NULL;
    }
}

int Queue::getQueueSize() const
{
    cout << "queueSize:" << queueSize << endl;
    return queueSize;
}

int Queue:: getArrSize() const
{
    cout << "arrSize:" << arrSize << endl;
    return arrSize;
}

bool Queue::push(int value)
{
    // TODO: thread safety
    // no more space in array, need to resize
    if ( popPos == pushPos && queueSize == arrSize ) {
        if ( resize() == false) {
            cout << "resize fail" << endl;
            return false;
        }
    }

    arr[pushPos] = value;
    cout << "push value:" << "a[" << pushPos << "] = " << arr[pushPos];
    // at end of array, need to loop to the head
    if ( pushPos == arrSize-1 ) {
        pushPos = 0;
    }
    else {
        pushPos++;
    }
    queueSize++;
    cout << " pushPos: " << pushPos << " queueSize: " << queueSize << endl;
    return true;
}

bool Queue::pop(int &value)
{
    // TODO: thread safety
    if ( queueSize == 0 ) {
        cout << "queue empty, pop fail" << endl;
        return false;
    }
    // at end of array, need to loop to the head
    value = arr[popPos];
    cout << "pop value: " << "a[" << popPos << "] = " << value;
    if ( popPos == arrSize-1 ) {
        popPos = 0;
    }
    else {
        popPos++;
    } 
    queueSize--;
    cout << " popPos: " << popPos << " queueSize: " << queueSize << endl;
    return true;
}

// resize array if no space when pushing the element
bool Queue::resize()
{
    cout << "begin to " << RE_SIZE_MULTIPLE << " multiple size the array" << endl;
    int *arr_resize = new int[arrSize*RE_SIZE_MULTIPLE];
    if ( arr == NULL ) {
        cout << "resize fail"<< endl;
        return false;
    }
    if ( popPos == 0 ) {
        memcpy(arr_resize, arr+popPos, arrSize*sizeof(int));
    }
    // for case that pushPos loops ahead of popPos
    else {
        memcpy(arr_resize, arr+popPos, (arrSize-popPos)*sizeof(int));
        memcpy(arr_resize+(arrSize-popPos), arr, popPos*sizeof(int));
    }

    popPos = 0;
    pushPos = queueSize;
    
    if (arr) {
        delete []arr;
        arr = NULL;
    }
    arr = arr_resize;
    arrSize *=RE_SIZE_MULTIPLE;
    return true;
}
