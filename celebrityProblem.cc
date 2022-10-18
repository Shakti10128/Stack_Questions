#include<bits/stdc++.h>
#include"StackClass.cc"
using namespace std;



bool knows(vector<vector<int>>& M,int n,int a,int b){
    if(M[a][b]==1){
        return true;
    }
    else{
        return false;
    }
}

int celebrityProblem(vector<vector<int>>& M,int n){
    // step-1 create a stack and push all the element or(person in party) with celebrity
    Stack<int> s;
    for(int i = 0;i<n;i++){
        s.push(i);
    }

    // step-2 to checking each person wether he/she know more than one person in the party or not
    while(s.size()>1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(knows(M,n,a,b)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }

    // step-3 pop last element from the stack and verify that he/she celebrity or not
    int celebrity = s.top();

    // step-4 to check all the elements in row of celebrity should be 0
    bool rowcheck = false;
    int zerocount = 0;
    for(int i = 0;i<n;i++){
        if(M[celebrity][i]==0){
            zerocount++;
        }
    }
    if(zerocount == n){
        rowcheck = true;
    }
    // step-5 to check all the elements in celebrity coloumn should be 1 to neglect celebrity
    bool colcheck = false;
    int onecount = 0;
    for(int i = 0;i<n;i++){
        if(M[i][celebrity]==1){
            onecount++;
        }
    }
    if(onecount == n-1){
        colcheck = true;
    }

    if(rowcheck == true && colcheck == true){
        return celebrity;
    }
    else{
        return -1;
    }
}

int main(){
    vector<vector<int>> M = {{0,0,0,1},{0,0,0,1},{0,0,0,1},{0,0,0,0}};
    int n = M.size();
    int ans = celebrityProblem(M,n);
    cout<<ans<<endl;
}