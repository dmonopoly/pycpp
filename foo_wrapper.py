from ctypes import *
lib = cdll.LoadLibrary('libfoo.so')

class Foo(object):
  def __init__(self):
    self.obj = lib.Foo_new()

  def bar(self):
    lib.Foo_bar(self.obj)

  def take_py_into_cpp(self, d):
    lib.CppTakePythonIntoCpp(c_double(d))

  def get_int(self):
    return lib.CppGetInt()

  def get_double(self):
    lib.CppGetDouble.restype = c_double
    return lib.CppGetDouble()

  def get_string(self):
    lib.CppGetString.restype = c_char_p
    return lib.CppGetString()

f = Foo()
print '#1'
f.bar()
