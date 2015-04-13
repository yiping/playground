__author__ = 'Yiping'

import time

N = 35


def benchmark(func):
    def wrapper():
        tic = time.clock()
        func()
        toc = time.clock()
        print "elapsed time:", tic - toc

    return wrapper



def fibonacci(n):
    if n == 1:
        return 1
    if n == 2:
        return 1
    return fibonacci(n-1)+fibonacci(n-2)

def fibonacci_cached(n):
    if n == 1:
        return 1
    if n == 2:
        return 1
    if fibonacci_cached.sequence[n] != 0:
        return fibonacci_cached.sequence[n]
    fibonacci_cached.sequence[n] = fibonacci_cached(n-1)+fibonacci_cached(n-2)
    return fibonacci_cached.sequence[n]


@benchmark
def test_fibo1():
    print fibonacci(N)

@benchmark
def test_fibo2():
    fibonacci_cached.sequence = [0]*(N+1)
    print fibonacci_cached(N)

if __name__ == "__main__":
    test_fibo2();
    test_fibo1();
