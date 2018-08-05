from distutils.core import setup, Extension

twistermodule = Extension('twister',
                          sources=['src/twistermodule.c', 'src/mt19937ar/mt19937ar.c'])

setup(name='twister',
      version='1.1.0',
      author='TAKAHASHI Shuuji',
      author_email='shuuji3@gmail.com',
      url='https://github.com/shuuji3/python-extension-twister/',
      description='Generate random numbers by using Mersenne twister.',
      ext_modules=[twistermodule])
