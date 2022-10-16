#include<iostream>
#include"StackClass.cc"
using namespace std;
bool isValidParenthesis(string expression)
{
    // Write your code here.
    
    Stack<char> s;
    for(int i = 0;i<expression.length();i++){
        char ch = expression[i];
        if(ch == '(' || ch == '[' || ch == '{'){
            s.push(ch);
        }
        else{
          if(!s.isEmpty()){
            char top = s.top();
            if((ch == ')' && top =='(') || (ch == ']' && top == '[') || (ch == '}' && top == '{')){
                s.pop();
             }
              else{
                  return false;
              }
          }
            else{
                  return false;
              }
    }
    }
        if(s.isEmpty())
        return true;
    else
        return false;
}

int main(){
    string str = "{([])}{}";
    if(isValidParenthesis(str))
    cout<<"Balanced"<<endl;
    else
    cout<<"Not Balanced"<<endl;
}