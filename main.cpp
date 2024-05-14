#include "bellman.cpp"
#include "tsm.cpp"

int main(){
    //test bellman 
    int a[4][1000] = {  {0, 17, 11, 15}, 
                        {17, 0, 2, 4},
                        {11, 2, 0, 3},
                        {15, 4, 3, 0}   };
    int label[100];
    int pre[100];
    char start = 'A';
    char end = 'D';
    //BF(a,4,'A',label,pre);
    cout<<BF_path(a,4,start,end);
    cout<<endl;
    travelling(a,'A',4);
    //cout<<endl;
    //nearestneighbor(a,'A',4);
}