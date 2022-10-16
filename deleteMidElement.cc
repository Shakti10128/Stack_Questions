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
/*---------------------delete mid element from the stack by iteration------------*/
void solve(Stack<int> &temp, int count, int n){
    int mid = n/2;
    Stack<int> t(0);
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

void deleteMiddle(Stack<int> &s, int N){
   // Write your code here
    int count = 0;
    solve(s,count,N);
}

/*---------------------deleting mid element by recursion-------------------------*/

void solve1(Stack<int> &s,int count,int size){
    if(count == size/2){
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    solve1(s,count+1,size);

    s.push(num);
}

void deleteMid(Stack<int> &s){
    int size = s.size();
    int count = 0;
    solve(s,count,size);
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

    // delete mid element by iteration
    cout<<"deleting mid element by iteration "<<endl;
    deleteMiddle(s,s.size());
    print(s);

    // delete mid element by recursion
    cout<<"deleting mid element by recursion "<<endl;
    deleteMid(s);
    print(s);

}