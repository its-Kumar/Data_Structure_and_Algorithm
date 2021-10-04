''' BINARY SEARCH ALGORITHM '''

# this method returns the index of target element, if found. Otherwise it returns -1
# this algorithm only works on arrays sorted in NON DECREASING order
def binary_search(a:list, target:int): 
    start = 0
    end = len(a)-1
    while start <= end:
        mid = start + (end - start) // 2
        if a[mid] < target:
            start = mid + 1
        elif a[mid] > target:
            end = mid - 1
        else:
            return mid
    
    return -1

if __name__ == '__main__':
    a = [3,5,8,14,57,90]
    target = 140
    ans = binary_search(a,target)
    print(ans)
