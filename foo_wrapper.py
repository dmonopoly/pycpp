from ctypes import cdll
lib = cdll.LoadLibrary('./libfoo.so')

class Foo(object):
  def __init__(self):
    self.obj = lib.Foo_new()

  def bar(self):
    lib.Foo_bar(self.obj)

f = Foo()
print '#1'
f.bar()
