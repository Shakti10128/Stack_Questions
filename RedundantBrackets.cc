#include<iostream>
#include"StackClass.cc"
using namespace std;


bool findRedundantBrackets(string &s)
{
    Stack<char> st;
    for(int i = 0;i<s.length();i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*'){
            st.push(ch);
        }
        else{
            if(ch == ')'){
                bool isRedundant = true;
                while(st.top()!='('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '/' || top == '*'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true)
                    return true;
                st.pop();
            }
        }
    }
    return false;
}


int main(){
    string str = "(a*b+(c/d))";
    if(findRedundantBrackets(str))
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;
}