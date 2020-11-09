

import ctypes

libfoo = ctypes.cdll.LoadLibrary('./temparray.so')
foo = libfoo.foo
foo.argtypes = ()
foo.restype = ctypes.POINTER(ctypes.c_double)
result = foo()
print(result[0], result[1])
