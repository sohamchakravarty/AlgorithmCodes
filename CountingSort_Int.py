MAX = 10001
def CountingSort(arr,N):
    # Create a count array to store count of inidividul characters and
    # initialize count array as 0
    count = [0 for i in range(MAX)]
        
    # Store count of each character
    for i in arr:
        count[i] += 1
    
    # Change count[i] so that count[i] now contains actual position of
    # this number in output array
    for i in range(1,MAX):
        count[i]+=count[i-1]
    
    # Build the output character array
    output = [0 for i in range(N)]
    for i in arr:
        output[count[i]-1] = i
        count[i] -= 1
    
    return output