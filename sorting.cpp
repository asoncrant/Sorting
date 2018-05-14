//////////////////////////////////////////////////////////////
// below is the skeleton of [your_uniqname]_hw1a.cpp file
//////////////////////////////////////////////////////////////
#include <Rcpp.h>
#include <iostream>
#include <algorithm>
using namespace Rcpp;
using namespace std;
// [[Rcpp::export]]

NumericVector insertion_sort(NumericVector x) {
	/*
	Using insertion sort algorithm,
	make x sorted and return it.
	*/
	int n = x.size();
	float tmp;
	for(int i = 1; i < n; i++){
		for(int j = i; j > 0; j--){
			if(x[j-1] > x[j]){
			    tmp = x[j];
			    x[j] = x[j-1];
			    x[j-1] = tmp;
			  } 	 
			else{
		   		break;
			}
		}
	}
	return x; /* x contains the sorted vector*/
}
// [[Rcpp::export]]

NumericVector bubble_sort(NumericVector x) {
	/*
	Using bubble sort algorithm,
	make x sorted and return it.
	*/
	int n = x.size();
	for(int i = 0; i < n; i++){
		bool swapped = false;
		float tmp;
		for(int j = 0; j < n-1; j++){
			if(x[j] > x[j+1]){
				tmp = x[j+1];
				x[j+1] = x[j];
				x[j] = tmp;
				swapped = true;
			}
		}
		if(swapped == false){
			break;
		}
	}
	return x;
}

void merge_sort(NumericVector x, int l, int r) {
	/*
	Using merge sort algorithm, make x sorted between indicies l ... (r-1)
	Do not attempt to return it (as oppsed to other functions)
	*/

	if(r-l <= 1){
		return;
	}
	else{
		int mid = floor((l + r) / 2);
		merge_sort(x, l, mid);
		merge_sort(x, mid, r);
		NumericVector tmp(x.begin()+l,x.begin()+mid);
		int i = 0;
		int j = mid;
		int k = l;
		while((i < mid-l) || (j < r)){
			if(i == mid - l){
				x[k] = x[j];
				j+=1;
			}
			else if(( j == r) || (tmp[i] < x[j])){
				x[k] = tmp[i];
				i+=1;
			}
			else{
				x[k] = x[j];
				j+=1;
			}
			k+=1;
		}
	}
}


// [[Rcpp::export]]
NumericVector merge_sort(NumericVector x) {
// Do not modify this function.
// This function simply calls the merge_sort function above
// that uses divide-and-conquer algorithm
merge_sort(x, 0, (int)x.size());
return x;
}
// [[Rcpp::export]]
NumericVector std_sort(NumericVector x) {
// Do not modify this function.
// This function uses std::sort() function to perform sorting
sort(x.begin(), x.end());
return x;
}
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////