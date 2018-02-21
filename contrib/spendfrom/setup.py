from distutils.core import setup
setup(name='RLYspendfrom',
      version='1.0',
      description='Command-line utility for relay "coin control"',
      author='Gavin Andresen',
      author_email='gavin@relayfoundation.org',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
