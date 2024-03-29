#include <bits/stdc++.h> 
#include<vector>
int partitionArray(std::vector<int>& arr, int start, int end) {
	// Write your code here
	int pivot = start ;
	int i = start;
	int j =end;

	while(i < j){
		while( arr[i] > arr[pivot] && i < end ){
			i++;
		}
		while(arr[j] <= arr[pivot] && j > start){
			j--;
		}
		if(i < j){
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[j], arr[pivot]);
	return j;

}
void qSort(std::vector<int>& arr, int start, int end) {
	
     if(start < end )  // this is to prevent single element being forced go under quick sort 
	 {
		 int partitionIndex  =  partitionArray(arr, start,  end);
		 qSort(arr,  start, partitionIndex-1);
		 qSort(arr, partitionIndex+1, end);
	 }
}
std::vector<int> quickSort(std::vector<int>& arr)
{
    // Write your code here.
    qSort(arr, 0, arr.size()-1);
    // for(auto it: arr){
    //     std::cout << it << " ";
    // }
    return arr;
}
int main (){
    std::vector<int> arr = { 13, 46, 24, 52, 20, 9};
    quickSort(arr);

    for(auto it: arr){
        std::cout << it << " ";
    }
}
