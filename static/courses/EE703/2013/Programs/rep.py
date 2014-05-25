# Name: Put your name here
# Roll No: Put your roll number here
# Hint: pow(x,y) calculates x^y

p = 0.1 # BSC crossover probability
probZero = 0.5 # Probability of the message bit being zero
probOne = 1 - probZero # Probability of the message bit being one
N = 3   # The number of times the bit will be repeated


# Function to calculate the Hamming distance between two strings
def hamming(x,y):
    return sum(map(lambda a,b:  int(a != b), x, y))
  
  
# Creating a list of all binary N-tuples 
ObservationSpace = [bin(i)[2:].zfill(N) for i in range(pow(2,N))]
print "Gamma =", ObservationSpace

# The all zeros and all ones N-tuples
allZeros = '0'*N
allOnes = '1'*N

# Initializing the partitions of the decision rule to empty lists
ZeroPartition = []
OnePartition = []

# Populating the partitions of the decision rule
for y in ObservationSpace:
    if hamming(y, allZeros) <= hamming(y, allOnes):  ## Change this line to change decision rule ##
        ZeroPartition.append(y)
    else:
        OnePartition.append(y)

print "ZeroPartition = ", ZeroPartition
print "OnePartition = ", OnePartition
