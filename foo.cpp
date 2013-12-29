#include <iostream>

using namespace std;

class Foo {
 public:
  void bar() {
    cout << "Hello" << endl;
  }
};

// Functions here are available outside the C++ - i.e., in the Python.
extern "C" {
  Foo* Foo_new() { return new Foo(); }
  void Foo_bar(Foo* foo) { foo->bar(); }
}
