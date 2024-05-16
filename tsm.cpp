#include "tsm.h"


void travelling(int arr[][20], char start, int n){
    if (n<=10){
    vector <int> a;
    int first = start - 'A';
    for (int i=0;i<n;i++){
        if (i!=first) a.push_back(i);
    }
    int min_length = INT_MAX;
    int temp = 0;

    do {
        int distance = 0;
        for (int i=0;i<n-1;i++){
            if ((i==0)&&(arr[first][a[0]]==0)) break;
            if ((i==0)&&(arr[first][a[0]]!=0)) {distance+= arr[first][a[0]]; continue;}
            if (arr[a[i-1]][a[i]]==0) {distance=0; break;}
            if (arr[a[i-1]][a[i]]!=0) distance+= arr[a[i-1]][a[i]];
        }
        if (distance==0) continue;
        if (arr[a[n-2]][first]==0) continue;
        distance+= arr[a[n-2]][first];
        if (distance<min_length) min_length = distance;
        temp++;
    }
    while (next_permutation(a.begin(),a.end()));
    cout<<"Min distance: "<<min_length<<endl;

    vector <int> b;
    for (int i=0;i<n;i++){
        if (i!=first) b.push_back(i);
    }
    string ans = "";
    do {
        int distance = 0;
        for (int i=0;i<n-1;i++){
            if ((i==0)&&(arr[first][b[0]]==0)) break;
            if ((i==0)&&(arr[first][b[0]]!=0)) {distance+= arr[first][b[0]]; continue;}
            if (arr[b[i-1]][b[i]]==0) {distance=0; break;}
            if (arr[b[i-1]][b[i]]!=0) distance+= arr[b[i-1]][b[i]];
        }
        if (distance==0) continue;
        if (arr[b[n-2]][first]==0) continue;
        distance+= arr[b[n-2]][first];
        if (distance==min_length){
            ans.push_back(start);
            ans = ans + " ";
            for (int i=0;i<n-1;i++){
                char t = 'A' + b[i];
                ans.push_back(t);
                ans = ans + " ";
            }
            ans.push_back(start);
            cout<<ans<<endl;
            ans = "";
        }
    }
    while (next_permutation(b.begin(),b.end()));
    }
    else {nearestneighbor(arr,start,n);}
    
    return;

}

bool check(vector<int>arr,int t){
    int s = sizeof(arr)/sizeof(int);
    for (int i=0;i<s;i++){
        if (arr[i]==t) return false;
    }
    return true;
}

void nearestneighbor(int arr[][20], char start, int n){
    int nearest = INT_MAX;
    vector <int> ans;
    int road;

    //Find nearest path in each vertex
    for (int i=0;i<n;i++){
        road = 0;
        vector <int> a;
        a.push_back(i);
        int iterator = i;
        while (a.size()<n){
            int min = INT_MAX;
            for (int j=0;j<n;j++){
                if (check(a,j)) {
                    int t = arr[iterator][j];
                    if (t<min) {min = t;}
                }
            }
            road+=min;
            for (int j=0;j<n;j++){
                if (check(a,j)) {
                    if (arr[iterator][j] == min) {
                        a.push_back(j);
                        iterator = j;
                    }
                }
            }
        }
        road+=arr[iterator][i];
        if (road<nearest) {ans = a;}
    }
    cout<<"Min distance find by nearest neighbor: "<<road<<endl;
    
    //Print path
    string path="";
    int first = start - 'A';
    int index = 0;
    for (int i=0;i<n;i++){
        if (ans[i]==first) {index = i;break;}
    }
    for (int i=0;i<n;i++){
        char t = ans[(index+i)%n] + 'A';
        path.push_back(t);
        path+= " ";
    } 
    path.push_back(start);
    cout<<path;

    return;

}