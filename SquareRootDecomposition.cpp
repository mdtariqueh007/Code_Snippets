#include<bits/stdc++.h>

using namespace std;

void sqrtDecomp(){
    int n;
    cin>>n;

    int a[n];

   
    int block_size = sqrt(n);

    int blocks = block_size + 1;

    int block[blocks] = {0};

     for(int i = 0;i<n;i++){
        cin>>a[i];

        block[i-block_size] += a[i];
    }

    int q;
    cin>>q;

    while(q--){
        int type;
        cin>>type;

        if(type==1){
            int ind,val;
            cin>>ind>>val;
            a[ind] += val;
            block[ind/block_size] += val;
        }else{
            int l,r;
            cin>>l>>r;

            int i = l;
            int sum = 0;
            while(i<=r){
                if(i%block_size==0 && (i+block_size-1)<=r){
                    sum += block[i/block_size];
                    i += block_size;
                }else{
                    sum += a[i];
                    i++;
                }
            }
        }
    }




}

int main(){


    return 0;
}
