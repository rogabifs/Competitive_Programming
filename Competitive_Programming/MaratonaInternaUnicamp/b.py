from collections import Counter
import sys
input = sys.stdin.read

def solve():
    data = input().split()
    index = 0
    t = int(data[index])
    index += 1
    results = []
    
    for _ in range(t):
        n = int(data[index])
        m = int(data[index + 1])
        index += 2
        
        # Read first matrix
        matrix1 = []
        for _ in range(n):
            matrix1.extend(data[index:index + m])
            index += m
        
        # Read second matrix
        matrix2 = []
        for _ in range(n):
            matrix2.extend(data[index:index + m])
            index += m
        
        # Count frequencies
        count1 = Counter(matrix1)
        count2 = Counter(matrix2)
        
        # Compare counts
        if count1 == count2:
            results.append("YES")
        else:
            results.append("NO")
    
    # Print all results
    sys.stdout.write("\n".join(results) + "\n")






