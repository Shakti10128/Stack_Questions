#include<iostream>
#include"StackClass.cc"
using namespace std;

int findMinimumCost(string str) {
  // Write your code here
    if(str.length()%2==1){
        return -1;
    }
   Stack<char> s;
    for(int i = 0;i<str.length();i++){
        char ch = str[i];
        if(ch == '{'){
            s.push(ch);
        }
        else{
            if(!s.isEmpty() && s.top()=='{'){
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
    }
    int a =0;
    int b = 0;
    while(!s.isEmpty()){
        if(s.top()=='{'){
            a++;
        }
        else{
            b++;
        }
        s.pop();
    }
    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}

int main(){
    string str = "{{{}";
    cout<<findMinimumCost(str);

}