# CMake generated Testfile for 
# Source directory: C:/Development/c++/lab4
# Build directory: C:/Development/c++/lab4/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(run_tests "C:/Development/c++/lab4/build/Debug/tests.exe")
  set_tests_properties(run_tests PROPERTIES  _BACKTRACE_TRIPLES "C:/Development/c++/lab4/CMakeLists.txt;34;add_test;C:/Development/c++/lab4/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(run_tests "C:/Development/c++/lab4/build/Release/tests.exe")
  set_tests_properties(run_tests PROPERTIES  _BACKTRACE_TRIPLES "C:/Development/c++/lab4/CMakeLists.txt;34;add_test;C:/Development/c++/lab4/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(run_tests "C:/Development/c++/lab4/build/MinSizeRel/tests.exe")
  set_tests_properties(run_tests PROPERTIES  _BACKTRACE_TRIPLES "C:/Development/c++/lab4/CMakeLists.txt;34;add_test;C:/Development/c++/lab4/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(run_tests "C:/Development/c++/lab4/build/RelWithDebInfo/tests.exe")
  set_tests_properties(run_tests PROPERTIES  _BACKTRACE_TRIPLES "C:/Development/c++/lab4/CMakeLists.txt;34;add_test;C:/Development/c++/lab4/CMakeLists.txt;0;")
else()
  add_test(run_tests NOT_AVAILABLE)
endif()
subdirs("_deps/gtest-build")
