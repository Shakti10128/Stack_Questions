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

/*---------------------reversing stack using recursion-----------------------*/
 void insertAtButtom(Stack<int>&stack,int x){
   if(stack.isEmpty()){
       stack.push(x);
       return;
   }
   int y=stack.top();
   stack.pop();
   insertAtButtom(stack,x);
   stack.push(y);
} 
void reverseStack(Stack<int> &stack) {
    if(stack.isEmpty()){
        return;
    }
//     rucursive calls
    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    
    insertAtButtom(stack,num);
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
    cout<<"Before reversing the stack"<<endl;
    print(s);
    cout<<"After reversing the stack"<<endl;
    reverseStack(s);
    print(s);
}