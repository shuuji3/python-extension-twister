from distutils.core import setup, Extension

twistermodule = Extension('twister',
                          sources=['src/twistermodule.c', 'src/SFMT-src-1.5.1/SFMT.c'])

setup(name='twister',
      version='1.2.0',
      author='TAKAHASHI Shuuji',
      author_email='shuuji3@gmail.com',
      url='https://github.com/shuuji3/python-extension-twister/',
      description='Generate random numbers by using Mersenne twister.',
      ext_modules=[twistermodule])
