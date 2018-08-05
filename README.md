# python-extension-twister
Experimental Python C extension to generate random numbers by using SFMT.

## How to Install
```bash
$ pip install git+http://github.com/shuuji3/python-extension-twister
```

## Usage
```python
# Import twister
In [1]: import twister

# Print 10 random numbers in [0, 1)
In [2]: twister.print_rand(10)
# print 10 random numbers
0.74267051 0.10469427 0.51529110 0.45155755 0.21537663
0.70587656 0.72606148 0.23982524 0.12357313 0.02734480

# Print 10 random integers
In [3]: twister.print_rand_int(10)
# print 10 random int
417027613315812928 7755367230055191373 1402612387991082057 10286183145994199879 5429956317790515455
924206946219013396 1240004913946181787 2465701365545514233 9106585261156457095 6024743191489145339

# Generate 10 random numbers in [0, 1)
In [4]: for i in range(10):
   ...:     n = twister.random()
   ...:     print(n)
   ...:
0.3211053404957056
0.41760002658702433
0.21292581199668348
0.3803016252350062
0.8739533922635019
0.11525170947425067
0.16432665497995913
0.41316993441432714
0.3746205491479486
0.7015205009374768

# Generate 10 random integers in [0, 100)
In [5]: for i in range(10):
   ...:     n = twister.randint(0, 100)
   ...:     print(n)
   ...:
   ...:
59
57
34
81
78
92
21
83
30
72
```

## Used Library
- [SIMD-oriented Fast Mersenne Twister (SFMT)](http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/SFMT/) v1.5.1
