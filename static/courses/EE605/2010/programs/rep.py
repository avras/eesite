#! /usr/bin/env python

apriori = {'0000' : 0.5, '1111' : 0.5} # Apriori probabilities of the messages
p = 0.1 # BSC crossover probability

###############################################################################
############## Helper functions ###############################################
###############################################################################
def hamming_distance(s1, s2):
    assert len(s1) == len(s2)
    return sum(ch1 != ch2 for ch1, ch2 in zip(s1, s2))

def aposteriori_probability(r, s, p):
    return pow((1-p), 4)*pow(p/(1-p), hamming_distance(r,s))* apriori[s]/unconditional_probability(r, p)

def unconditional_probability(r, p):
    return pow((1-p),4)*pow(p/(1-p), hamming_distance(r,'0000'))* apriori['0000'] + pow((1-p), 4)*pow(p/(1-p), hamming_distance(r,'1111'))* apriori['1111'] 

def conditional_probability(r, s, p):
    return pow((1-p),4)*pow(p/(1-p), hamming_distance(r,s))

###############################################################################
############## Main Program starts here #######################################
###############################################################################

Omega = set(['0000', '0001', '0010', '0100', '1000', '0011', '0101', '0110',    '1001', '1010', '1100', '0111', '1011', '1101', '1110', '1111'])

print 'Omega = ', Omega

Omega0, Omega1 = set([]), set([]) 

for r in Omega:
    if hamming_distance(r,'0000') <= 2:
        Omega0.add(r)
    else:
        Omega1.add(r)


print '\n'
print 'Partition obtained using Hamming distance'
print 'Omega0 = ', Omega0
print 'Omega1 = ', Omega1

Omega0, Omega1 = set([]), set([]) 

for r in Omega:
    if aposteriori_probability(r, '0000', p) >= aposteriori_probability(r, '1111', p):
        Omega0.add(r)
    else:
        Omega1.add(r)


print '\n'
print 'Partition obtained using aposteriori probability'
print 'Omega0 = ', Omega0
print 'Omega1 = ', Omega1


print '\n'
print 'Calculating the conditional probability of error'
P_0 = 0
P_1 = 0

for r in Omega0:
    P_0 += conditional_probability(r, '0000', p)

P_0 = 1- P_0

for r in Omega1:
    P_1 += conditional_probability(r, '1111', p)

P_1 = 1- P_1

print 'P_0 = ', P_0
print 'P_1 = ', P_1
print 'Average prob of error = ', P_0*apriori['0000'] + P_1*apriori['1111']

