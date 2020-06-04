/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int num0, num1;
    int flag = 0;
    int i, j;
    for(i = 0; i < numsSize - 1; i++){
        for(j =  i + 1; j < numsSize; j++){
            if(nums[i] + nums[j] == target){
                num0 = i;
                num1 = j;
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            break;
        }
    }
    int *re = (int *)malloc(sizeof(int) * 2);
    re[0] = num0;
    re[1] = num1;
    * returnSize = 2;
    return re;
}
