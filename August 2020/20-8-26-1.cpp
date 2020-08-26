#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <windows.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
	sort(nums.begin(), nums.end());
	int size = nums.size();
	int i;
	vector<vector<int>> arr_return={};
	int last = 999999;
	for(i = 0;i< size-2;i++){
		int temp = nums[i];
		if(temp!=last){
            last=temp;
			int arr_begin = i+1, arr_end = size-1;
            int count=0;
			while(arr_begin!=arr_end){
				if(temp+nums[arr_begin]+nums[arr_end] == 0){
					vector<int> add = {temp, nums[arr_begin], nums[arr_end]};
                    if(nums[arr_begin]!=nums[arr_begin-1]||count==0)
					arr_return.push_back(add);
                    count++;
					arr_begin++;
				}
				else if(temp+nums[arr_begin]+nums[arr_end] < 0){
					arr_begin++;
				}
				else{
					arr_end--;
				}
				
			}
		}

	} 
	return arr_return;
}

int main(){
	vector<int> nums = {0,0,0,0} ;
	vector<vector<int>> vec = threeSum(nums); 
	
	return 0;
} 
