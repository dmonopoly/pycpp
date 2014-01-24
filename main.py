from ctypes import *
from foo_wrapper import Foo

print '#2'
f = Foo()
f.bar()

print
print '- Taking Py -> C++ -'
f.take_py_into_cpp(-4.5)

print
print '- Get returned values from C++ -'
print 'Integer:'
i = f.get_int()
print i

print 'Double:'
d = f.get_double()
print d

print 'String:'
s = f.get_string()
print s

print
