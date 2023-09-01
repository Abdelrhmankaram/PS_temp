#include<bits/stdc++.h>
#define ll long long
using namespace std;

void insertion_sort(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        int j=i;
        while(true){
            if(j==0)break;
            if(arr[j]>=arr[j-1])break;
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

void merge(int arr[], int l, int mid, int r){
    int left_size = mid - l + 1;
    int right_size = r - mid;
    int left[left_size], right[right_size];
    for(int i=0; i < left_size; i++) left[i] = arr[i + l];
    for(int i=0; i < right_size; i++) right[i] = arr[mid + 1 + i];
    int i=0, j=0, k=l;
    while(i < left_size && j < right_size){
        if(left[i] >= right[j]){
            arr[k]=left[i];
            i++;
        }
        else {
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i < left_size){
        arr[k]=left[i];
        i++; k++;
    }
    while(j < right_size){
        arr[k]=right[j];
        j++; k++;
    }
}
void merge_sort(int arr[],int l,int r){
    if(l<r){
        int mid = l + (r - l) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}


void heapify(int arr[],int n,int i){
    int largest = i;
    int left=(2*i)+1,
        right=(2*i)+2;
    if(left<n){
        if(arr[left]>arr[largest])
            largest=left;
    }
    if(right<n){
        if(arr[right]>arr[largest])
            largest=right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void build_heap(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--)heapify(arr,n,i);
}

void heapsort(int arr[],int n){
    build_heap(arr,n);
    for(int i=n-1;i>=0;i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void quickSort(int arr[] ,int start ,int end){
    int r=end,l=start,p=l;
    while(l!=r){
        if(p==l){
            if(arr[p] <= arr[r])r--;
            else{
                swap(arr[p],arr[r]);p=r;
            }
        }
        else if(p==r){
            if(arr[p]>=arr[l])l++;
            else{
                swap(arr[p],arr[l]);p=l;
            }
        }
    }
    if(start<p)quickSort(arr,start,p-1);
    if(end>p)quickSort(arr,p+1,end);
}