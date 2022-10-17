#include<bits/stdc++.h>
#include"StackClass.cc"
using namespace std;

void print(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
/*---------------------Next smaller element------------*/
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    Stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i = n-1;i>=0;i--){
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main(){
    vector<int> arr;
    arr.push_back(6);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(8);
    arr.push_back(0);
    vector<int> ans = nextSmallerElement(arr,arr.size());
    print(ans);

}