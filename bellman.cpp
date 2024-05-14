#include "bellman.h"

//INT_MAX

void BF(int arr[][1000], int n, char start, int label[], int pre[]){
    int first = start - 'A';

    for (int i=0;i<n;i++){
        pre[i]  = -1;
        if (i!=first) label[i] = INT_MAX;
        else label[i] = 0;
    }

    for (int i=0;i<n;i++){
        if (arr[first][i]!=0) {
            label[i] = arr[first][i];
        }
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if ((arr[i][j] + label[i] < label[j])&&(arr[i][j]!=0)) {
                label[j] = arr[i][j] + label[i];
                pre[j] = i;
            }
        }
    }

    for (int i=0;i<n;i++){
        if ((i!=first)&&(arr[first][i]!=0)){
        if (label[first] + arr[first][i] < label[i]) {
            cout<<"Contains circuit of negative weight"<<endl;
            return;
        }
        }
    }

    for (int i=0;i<n;i++){
        cout<<label[i]<<" ";
    }
    cout<<endl;
    for (int i=0;i<n;i++){
        cout<<pre[i]<<" ";
    }
    cout<<endl;
    return;

}

string BF_path(int arr[][1000], int n, char start, char goal){
    int label[100];
    int pre[100];
    BF(arr, n, start, label, pre);
    string ans = "";
    ans.push_back(goal);
    ans+= " ";
    int end = (int)goal - 'A'; 
    while (pre[end]!=-1){
        char temp = (char)'A' + pre[end];
        ans.push_back(temp);
        ans+=" ";
        end = pre[end];
    }
    ans.push_back(start);


    int t = ans.size();
    for (int i=0;i<t/2;i++){
        swap(ans[i],ans[t-i-1]);
    }

    return ans;

}
    


