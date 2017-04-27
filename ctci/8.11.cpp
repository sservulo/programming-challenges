#include<iostream>
#include<vector>
using namespace std;

int countC = 0;
vector<vector<int> > v(501, vector<int>(4,0));

int count(vector<int>& coin, int index, int n){
    if(n<0 || index<0){return 0;}
    if(n==0){return 1;}
    countC++;
    if(v[n][index] == 0){
      v[n][index] = count(coin, index-1, n) + count(coin, index, n-coin[index]);
    }
    return v[n][index];
}

// Driver program to test above function
int main()
{
    int change = 500;
    vector<int> coin = {1, 5, 10, 25};
    cout << count(coin, coin.size()-1, change) << endl;
    cout << countC <<endl;
    return 0;
}
