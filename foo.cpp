#include <iostream>
#include <vector>

using namespace std;

class Foo {
 public:
  void bar() {
    cout << "Hello from C++" << endl;
    vector<double> some_vals;
    for (int i = 0; i < 4; ++i) {
      some_vals.push_back(i);
    }
    cout << "A value from a vector: " << some_vals.back() << endl;
  }
};

// Functions here are available outside the C/C++ code - i.e., in the Python.
// Since Python ctypes interface with C, not C++, we use extern, which prevents
// C++ name-mangling. Also, the C code in here can call C++ functions elsewhere.
extern "C" {
  Foo* Foo_new() { return new Foo(); }
  void Foo_bar(Foo* foo) { foo->bar(); }
  int CppGetInt() {
    return 4;
  }
  double CppGetDouble() {
    return -2.5;
  }
  const char* CppGetString() {
    string tmp = "This string was set in C.";
    return tmp.c_str();
  }
  void CppTakePythonIntoCpp(double d) {
    cout << "double value from python: " << d << endl;
    d *= 1.1;
    cout << "changed value from C code: " << d << endl;
  }
}
