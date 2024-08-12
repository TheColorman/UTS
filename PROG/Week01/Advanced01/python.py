"""
what the fuck is wrong with y'all test script, I had to
jump through to many hoops just to stop getting
"is_prime is not defined" errors, why not just open a
subprocess to test the script instead of the whole exec
bullshit. Like I had to define is_prime once at the top-
level, cause the test script has hardcoded imports for
it (?????), then I had to define it AGAIN in the __main__
part because it wasn't defined when I used it. And don't
even get me started on the import of math.sqrt.

anyway, rant over, sorry for the harsh language, kisses <3.
"""

from math import sqrt

def is_prime(n):
    if n <= 1: return False
    for i in range(2, int(sqrt(n))+1):
        if n % i == 0: return False
    return True

if __name__ == '__main__':
    from math import sqrt
    def is_prime(n):
        if (n <= 1):
            return False
        from math import sqrt
        for i in range(2, int(sqrt(n))+1):
            if (n % i == 0):
                return False

        return True

    ints = []
    while True:
        i = int(input("Enter an integer (-1 to exit): "))
        if i == -1: break
        ints.append(i)
    
    nonprimes = [i for i in ints if not is_prime(i)]
    if len(nonprimes) < 2:
        print("No average to display.")
    else:
        print(f"Average of non-prime numbers: {sum(nonprimes)/len(nonprimes)}")