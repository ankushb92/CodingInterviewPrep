#include<iostream>

using namespace std;


int* merge(int* arr1, int* arr2, int len1, int len2) {
    int *return_arr = new int[len1+len2];
    int ind1 = 0;
    int ind2 = 0;
    int ret_ind = 0;
    while(ind1<len1 && ind2<len2) {
        if (arr1[ind1]<arr2[ind2]) {
            return_arr[ret_ind] = arr1[ind1];
            ind1 += 1;
            ret_ind += 1;
        }
        else {
            return_arr[ret_ind] = arr2[ind2];
            ind2 += 1;
            ret_ind += 1;
        }
    }
    while(ind1<len1) {
        return_arr[ret_ind] = arr1[ind1];
        ind1 += 1;
        ret_ind += 1;
    }
    while(ind2<len2) {
        return_arr[ret_ind] = arr2[ind2];
        ind2 += 1;
        ret_ind += 1;
    }
    return return_arr;
}

int* merge_sort(int* arr, int start, int end) {
    if (start==end) {
        int *return_arr = new int[1];
        return_arr[0] = arr[start];
        return return_arr;
    }
    int mid = (start+end)/2;
    return merge(merge_sort(arr, start, mid), merge_sort(arr, mid+1, end), mid-start+1, end-mid);
}


int main() {
    int arr[10] = {5,1,6,2,3,7,9,8,4,0};
    int *sorted_arr;
    sorted_arr = merge_sort(arr, 0, 9);
    for (int i=0; i<10; i++) {
        cout<<sorted_arr[i]<<' ';
    }
    cout<<endl;
    return 0;
}