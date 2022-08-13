# Cpp Standard Library
This folder contains discussion about standard library.

Standard library can be classified into:
- Containers: container of different variables
- Algorithms: different common operations on stuff from containers
- Iterators: provides access point for containers which is used by algorithms, it states as a bridge between Containers & Algorithms

## List of Contents
- **1 Namespace**

## 1 Namespace
When we want to include some standard libraries (or header files), we should:
```c++
#include <header_file_name>
```

### Basics of Namespace
Refer to [basics of namespace](001_Namespace/001_Cpp_namespace_basics.pdf) (https://www.geeksforgeeks.org/namespace-in-c/)

We can refer to a namespace by:
```c++
...
namespace namespace_name {
    ... variable definition ...
    ... function definition ...
    ... clss     definition ...
}

namespace_name::variable/function/clss to access objects within functions
```
We can have more than one namespace
```c++
namespace name1 {
    ...
}

namespace name2 {
    ...
}
```

Moreover, since we have to access the variable within those namespaces by: `namespace_name::variable_name`, we can simplify the access by:
- `using`
```c++
using namespace namespace_name; // all variable within this namespace can be called directly
```
- single `using`
```c++
using namespace_name::variable_name; // can call variable_name directly
```
- namespace alias
```c++
alias_name = namespace_name::variable_name;
```

Here is a complete [coding example]()

**A very important note is that if we import something/using something in a cpp file and import it in main, then 
namespace within the file being imported is also visible in main. That is why we should use namespace directly to avoid 
namespace pollution and collision.** 

- same namespace --> same variable (defined in different file) --> error
- different namespace --> same variable --> error if we call the function
