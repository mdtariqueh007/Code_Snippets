#include <iostream>

using namespace std;

int seg[4*100004], lazy[4*100004];

int sum(int ind,int low,int high,int l,int r){
    // whenever you reach a segment tree node
    // first check if there is a previous update pending or not
    // if a previous update is pending, do that update and then 
    // decide for the current node

    if(lazy[ind]!=0){
        seg[ind] += (high - low + 1) * lazy[ind]; // for range min query just do +lazy[ind]

        //propagate downwards if there are children as
        // I have done the pending updates for the current node
        //if not a leaf node it will always have a children

        if(low!=high){
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }

        lazy[ind] = 0;
    }

    //no overlap
    if(high>low || high<l){
        return 0;
    }

    //complete overlap

    if(low>=l && high<=r){
        return seg[ind];
    }

    //partial overlap

    int mid = low + (high - low)/2;
    int left = sum(2*ind+1,low,mid,l,r);
    int right = sum(2*ind+2,mid+1,high,l,r);

    return left + right;

}

void update(int ind,int low,int high,int l,int r,int val){

    // whenever you reach a segment tree node
    // first check if there is a previous update pending or not
    // if a previous update is pending, do that update and then 
    // decide for the current node

    if(lazy[ind]!=0){
        seg[ind] += (high - low + 1) * lazy[ind]; // for range min query just do +lazy[ind]

        //propagate downwards if there are children as
        // I have done the pending updates for the current node
        //if not a leaf node it will always have a children

        if(low!=high){
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }

        lazy[ind] = 0;
    }

    //no overlap
    //l r low high or low high l r
    if(high>low || high<l){
        return;
    }

    //complete overlap
    // l low   high r
    //do the update and then propagate downwards
    if(low>=l && high<=r){
        //upadating the current node
        seg[ind] += val*(high - low + 1); // for range min query do +val

        //propagating
        if(low!=high){
            lazy[2*ind+1] += val;
            lazy[2*ind+2] += val;
        }
        return;
    }

    //partial overlap
    int mid = low + (high - low)/2;
    update(2*ind+1,low,mid,l,r,val);
    update(2*ind+2,mid+1,high,l,r,val);

    seg[ind] = seg[2*ind+1] + seg[2*ind+2];

}

int main(){

    return 0;
}
