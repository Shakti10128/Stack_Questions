#include<bits/stdc++.h>
#include"StackClass.cc"
using namespace std;

void print(Stack<int> s){
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

/*------------------inserting an element at bottom of stack------------------------*/

void solve(Stack<int> & s,int x){
    if(s.isEmpty()){
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();
    solve(s,x);
    s.push(num);
}

Stack<int> pushAtBottom(Stack<int>& myStack, int x) 
{
    // Write your code here.
    if(myStack.isEmpty()){
        myStack.push(x);
        return myStack;
    }
    solve(myStack, x);
    return myStack;
}

int main(){
    Stack<int> s(10);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);

    int n;
    cout<<"Enter the number which you want to insert at bottom"<<endl;
    cin>>n;
    pushAtBottom(s,n);
    print(s);
}