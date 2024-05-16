#include "bellman.h"

//INT_MAX

int num=0;
void BF(int arr[][20], int n, char start, int label[], int pre[]){
    int first = start -'A';
        if (num==0){
        for (int i=0;i<n;i++){
        if (i!=first) {label[i] = arr[first][i]; pre[i] = first;}
        else {label[i] = 0; pre[i] = -1;}
        }
        num++;
        return;
        }
    int test1[20];
    int test2[20];
    for (int i=0;i<n;i++){
        test1[i] = label[i];
        test2[i] = pre[i];
    }
        
    
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if ((arr[j][i] + label[j] < test1[i])) {
                test1[i] = arr[j][i] + label[j];
                test2[i] = j;
            }
        }
    }   
    for (int i=0;i<n;i++){
        label[i] = test1[i];
        pre[i] = test2[i] ;
    }
    
    
    num++;
    num = num%n;
    return;

}

string BF_Path(int arr[][20], int n, char start, char goal){
    int label[20];
    int pre[20];
    if (start==goal){
        string t="";
        t.push_back(start);
        return t;
    }
    int first = start - 'A';
    for (int i=0;i<n-1;i++){
        BF(arr,n,start,label,pre);
    }
    string ans = "";
    ans.push_back(goal);
    ans+= " ";
    int end = (int)goal - 'A'; 
    while (pre[end]!=first){
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
    
void BF2(int arr[][20], int n, char start, int label[], int pre[]){
    int first = start - 'A';
    for (int i=0;i<n;i++){
        //label[i] = -1;
        pre[i] = -1;
    }

    for (int i=0;i<n;i++){
        if (i!=first) {label[i] = 99999; }
        else label[i] = 0;
    }

    for (int i=0;i<n;i++){
        if (arr[first][i]!=0) {
            label[i] = arr[first][i];
            pre[i] = first;
        }
    }

    int t = n-1;
    while (t--){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if ((arr[i][j] + label[i] < label[j])&&(arr[i][j]!=0)&&(j!=first)) {
                label[j] = arr[i][j] + label[i];
                pre[j] = i;
            }
        }
    }
    }
    /*for (int i=0;i<n;i++){
        if ((label[i]=-1)&&(i!=first)&&(arr[i][first]!=0)){
            pre[i] = first;
        }
    }*/

    for (int i=0;i<n;i++){
        if ((i!=first)&&(arr[first][i]!=0)){
        if (label[first] + arr[first][i] < label[i]) {
            cout<<"Contains circuit of negative weight"<<endl;
            return;
        }
        }
    }

    return;
}







