#include <iostream>
//----------------------------------- 02_OOP
#include "01_Basics/03_inplace_experiment.cpp"
#include "01_Basics/06_pass_by_reference.cpp"
#include "02_OOP/05_constructors.cpp"
#include "02_OOP/08_delete_to_ban_functions.cpp"
#include "02_OOP/11_header.h"
#include "02_OOP/12_inheritance.cpp"
#include "02_OOP/12_1_diamond_problem.cpp"
#include "02_OOP/12_7_virtual_functions.cpp"
#include "02_OOP/13_operator_overload.cpp"
#include "02_OOP/14_functor_callable.cpp"

// ----------------------------------- 03_STL
#include "03_Standard_Library/001_Namespace/namespace.cpp"
#include "03_Standard_Library/001_Namespace/namespace_included.h"
#include "03_Standard_Library/001_Namespace/common_namespace_1.h"
#include "03_Standard_Library/001_Namespace/common_namespace_2.h"
#include "03_Standard_Library/001_Namespace/different_namespace_same_function.cpp"
#include "03_Standard_Library/002_Common_Functions/min_max.cpp"
#include "03_Standard_Library/002_Common_Functions/move.cpp"
#include "03_Standard_Library/002_Common_Functions/forward.cpp"

//using namespace std;

int main() {
    //----------------------------------- 02_OOP
    // this is the playground for all cpp file
    //test_inplace();
    //test_pass_by_reference_value_difference();
    //test_constructors();
    //test_move_constructor_vector();
    //test_heap_stack_delete();
    //Header().toString();
    //Header h;
    //test_override();
    //test_diamond();
    //test_with_virtual_function_copy_constructor();
    //test_without_virtual_function_copy_constructor();
    //test_with_virtual_pointer();
    //test_without_virtual_pointer();
    //test_operator_override();
    //test_type_conversion();
    //test_callable();

    // ----------------------------------- 03_STL
    //namespace_1::print_name();
    //namespace_2::print_name();
    //namespace_3::namespace_3_1::print_name();
    //name_space_included::print_name();
    //common_namespace::func1();
    //common_namespace::func2();
    //using namespace common_namespace;
    //func1();
    //func2();
    //If we uncomment the common function defined within common_namespace (both 1 and 2), it will cause an error
    //using namespace name1;
    //using namespace name2; // No error here if we do not call the function
    //func_same(); // error if we call the function
    //test_min_max();
    //test_access_object_after_move();
    //test_access_primitives_after_move();
    test_forward();
    return 0;
}
