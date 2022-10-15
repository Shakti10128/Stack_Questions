#include<bits/stdc++.h>
#include"StackClass.cc"
using namespace std;

// delete mid element from the stack
void solve(Stack &temp, int count, int n){
    int mid = n/2;
    Stack t(0);
    while(count<=mid){
        t.push(temp.top());
        temp.pop();
        count++;
    }
    t.pop();
    while(!t.isEmpty()){
        temp.push(t.top());
        t.pop();
    }
}

void deleteMiddle(Stack &s, int N){
   // Write your code here
    int count = 0;
    solve(s,count,N);
}
void print(Stack s){
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main(){
    Stack s(10);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    deleteMiddle(s,s.size());
    cout<<s.size()<<endl;
    print(s);

}