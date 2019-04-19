#####################################################################
# KIT103/KMA155 Programming Assignment 3: Number Theory part 1
# Submission script
#
# Name: Connor
# ID: 	xxxxxx
#
# Enter your answers to each question below by completing each
# function. After answering a question run this script and test
# your implementation in the IPython console.


# Question 1: Divisibility of really, really big integers (2 marks)

def divisible_by_4(s):
    numstr = str(s)
    abc = len(numstr)
    last2 = numstr[abc-2:]
    x = int(last2)
    
    if x % 4 == 0:
        return True
    else:
        return False

def divisible_by_5(s):
    numstr = str(s)
    abc = len(numstr)
    last2 = numstr[abc-1:]
    x = int(last2)
    
    if x % 5 == 0:
        return True
    else:
        return False
    

def divisible_by_9(s):
    total = 0
    numstr = str(s)
    abc = len(numstr)
    for a in range (0, abc):
        number = numstr[a:1+a]
        x = int(number)
        total = total + x

    total2 = 0
    numstr = str(total)
    abc2 = len(numstr)
    for b in range (0, abc2):
        number = numstr[b:1+b]
        x = int(number)
        total2 = total2 + x
        
    if total2 % 9 == 0:
        return True
    else:
        return False

def divisible_by_11(s):
    total = 0
    numstr = str(s)
    abc = len(numstr)
    
    for a in range (0, abc):
        number = numstr[a + (a*1): a + 1 + (a*1)]
        number.strip()
        x = int((number) or '0')
        total = total + x
        
        
        number2 = numstr[a+1+(a*1): a + 2 + (a*1)]
        x2 = int((number2) or '0')
        total = total - x2
        
    if total % 11 == 0:
        return True
    else:
        return False
        


# Question 2: LCM from a prime factorisations (2 marks)

from collections import Counter

def q2_factor_lcm(a, b):
    fA = factor_list(a)
    fB = factor_list(b)
    bagA = Counter()
    for prime in (fA):
        bagA[prime] += 1;
    bagB = Counter()
    for prime in (fB):
        bagB[prime] += 1
    exps = bagA | bagB
    lcm = 1
    for p in exps:
        lcm = lcm * p**exps[p]
    return lcm


# Question 3: Are a and b coprime (i.e., relatively prime)? (1 mark)

def q3_coprime(a, b):
    fA = factor_list(a)
    fB = factor_list(b)
    bagA = Counter()
    for prime in (fA):
        bagA[prime] += 1;
    bagB = Counter()
    for prime in (fB):
        bagB[prime] += 1
    exps = bagA & bagB
    gcd = 1
    for p in exps:
        gcd = gcd * p**exps[p]
        
    if gcd == 1:
        return True
    else:
        return False

# End of answers


# Provided functions

from math import floor, sqrt

def primes(n):
    primes = set(range(2, n+1))
    for k in range(2, floor(sqrt(n))+1):
        if k in primes:
            primes.difference_update( range(k**2, n+1, k) )
    return primes

def primes_list(n):
    return sorted(primes(n))

def factor_list(n):
    factors = []
    iprimes = iter( primes_list(n) )
    while n > 1:
        p = next(iprimes)
        while n % p == 0:
            n = n // p
            factors.append(p)
    return factors

'''reference : Stack Overflow, Tutorials Point, wikipedia, mathsisfun
python.org.

https://docs.python.org/2/library/collections.html#collections.Counter
'''
# End of provided functions
