"""
Author :    krishna
Problem description:  Given an array (of size > 0) of numbers , find the contiguous sub array with maximum sum
Problem category:  Dynamic Programming
"""


# Brute force approach of max_Sum_Subarray_bruteforce
def max_Sum_Subarray_bruteforce(arr):
    """
    :param arr: array of numbers
    :return: an integer denoting the maximum contiguous sub array sum
    """

    """
        In this approach, we will use two nested for loops. In the outer for loop we traverse from index i = 0 to len(arr)-2 and
        in the inner for loop we traverse from index j = i+1 to len(arr) -1 so that we will get the sub array from index i to j.
        Now we will keep track of the maximum sum of all the sub arrays using the variable max_sum.
        
    """
    if len(arr) == 1:
        return arr[0]

    max_sum = -float("inf")
    for i in range(len(arr)-1):  # array will be traversed from index 0 to index len(arr)-2
        for j in range(i+1, len(arr)): # array will be traversed from index i + 1 to index len(arr)-1
            sub_array = arr[i:j]
            max_sum = max(max_sum,sum(sub_array))

    return(max_sum)

    """
        Time complexity :- O(n^3) because 2 for loops take O(n^2) time and we are calculating sum(sub_array) in each iteration)
        Space complexity :- O(n) because we are using extra space to store sub array
    """

# Dynamic programming approach
def max_Sum_Subarray_dp(nums) :
    """
    :param arr: array of numbers
    :return: an integer denoting the maximum contiguous sub array sum
    """

    """
        The idea of this approach is to traverse the array linearly and update the array such that arr[i] holds the 
        maximum sum of all the sub arrays ending at index i.
        
        While traversing when we are at index k (k>0), arr[k-1] contains the maximum sum of all the sub arrays ending at index k-1.
        So if arr[k-1] is positive we will update arr[k] as arr[k] = arr[k] + arr[k-1].
        otherwise , we will not do anything because the array [arr[k]] is the sub array which gives maximum sum of all 
        the sub arrays ending at index k.  
                
    """
    for i in range(1,len(nums)):
        if nums[i-1]>0:
            nums[i] = nums[i] + nums[i-1]

    return max(nums)

    """
        Time complexity :- O(n) because we are linearly traversing the array once.
        Space complexity :- O(1) because we are not using any extra space. 
    """


# main function
if __name__ == "__main__":
    arr = [-2,1,-3,4,-1,2,1,-5,4]
    #arr = [-13, -3, -25, -20, -3, -16, -23, -12, -5, -22, -15, -4, -7]
    #arr = [-2, -3, 4, -1, -2, 1, 5, -3]
    #arr = [1]
    print("The maximum continuous sub array sum using brute force method is : " + str(max_Sum_Subarray_bruteforce(arr)))
    print("The maximum continuous sub array sum using Dynamic programming method is : " + str(max_Sum_Subarray_dp(arr)))
