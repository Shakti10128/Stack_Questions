#include<iostream>
using namespace std;
template<typename T>
class Stack {
public:
    public:
    T data;
    int asize;
    T *arr;
    int s;
    int index;

    public:
    Stack(){
        arr = new T[0];
        index = -1;
        s = 0;
    }

    void push(int num) {
        // Write your code here.
        if(s == asize){
            T * a = new T[asize*2];
            for(int i = 0;i<asize;i++){
                a[i] = arr[i];
            }
            delete []arr;
            arr = a;
            asize = asize*2;
        }
        index++;
        arr[index] = num;
        s++;
    }

    int pop() {
        // Write your code here.
        if(index == -1){
            return -1;
        }
        int del = arr[index];
        index--;
        s--;
        return del;
    }
    
    int top() {
        // Write your code here.
        if(index == -1){
            return -1;
        }
        return arr[index];
    }
    
    bool isEmpty(){
        return s == 0;
    }
    bool isFull(){
        return s == asize;
    }
    int size(){
        return s;
    }
    
};