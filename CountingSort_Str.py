RANGE = 255
def CountingSort(string):
    # Create a count array to store count of inidividul characters and
    # initialize count array as 0
    count = [0 for i in range(RANGE+1)] #as number of characters is 255
    
    # Store count of each character
    for i in string:
        count[ord(i)]+=1

    # Change count[i] so that count[i] now contains actual position of
    # this character in output array
    for i in range(1,RANGE+1):
        count[i]+=count[i-1]

    # Build the output character array
    output = range(len(string))
    for i in range(len(string)):
        output[count[ord(string[i])]-1] = string[i]
        count[ord(string[i])] -= 1

    return output