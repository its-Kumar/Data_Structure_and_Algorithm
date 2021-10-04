''' REVERSE BINARY SEARCH ALGORITHM '''

# this method returns the index of target element, if found. Otherwise it returns -1
# this algorithm only works on arrays sorted in NON INCREASING order
def binary_search_reverse(a:list, target:int): 
    start = 0
    end = len(a)-1
    while start <= end:
        mid = start + (end - start) // 2
        if a[mid] > target:
            start = mid + 1
        elif a[mid] < target:
            end = mid - 1
        else:
            return mid
    
    return -1

if __name__ == '__main__':
    a = [108,87,67,59,32,19,5]
    target = 19
    ans = binary_search_reverse(a,target)
    print(ans)
