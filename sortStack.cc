#include<bits/stdc++.h>
#include"StackClass.cc"
using namespace std;

// printing stack
void print(Stack<int> s){
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

/*---------------------sortStack-----------------------*/

void helper(Stack<int> & s,int num){
    if(s.isEmpty()){
        s.push(num);
        return;
    }
    if(s.top()<num){
        s.push(num);
        return;
    }
    int val = s.top();
    s.pop();
    helper(s,num);
    s.push(val);
}

void sortStack(Stack<int> & s){
    if(s.isEmpty()){
        return;
    }
    int num = s.top();
    s.pop();
    // recursive calls
    sortStack(s);

    helper(s,num);
}

int main(){
    Stack<int> s(10);
    s.push(1);
    s.push(7);
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(5);
    s.push(3);

    sortStack(s);
    print(s);
}