add_executable(task task.cpp)
target_include_directories(task PUBLIC ../LibraryCPPTemplate)

add_test(NAME Test1 COMMAND task ${CMAKE_CURRENT_SOURCE_DIR}/tests/script1.txt ${CMAKE_CURRENT_SOURCE_DIR}/tests/input1.txt)
set_property(TEST Test1 PROPERTY PASS_REGULAR_EXPRESSION "A\nB\nC")

add_test(NAME Test2 COMMAND task ${CMAKE_CURRENT_SOURCE_DIR}/tests/script2.txt ${CMAKE_CURRENT_SOURCE_DIR}/tests/input2.txt)
set_property(TEST Test2 PROPERTY PASS_REGULAR_EXPRESSION "A")

add_test(NAME Test3 COMMAND task ${CMAKE_CURRENT_SOURCE_DIR}/tests/script3.txt ${CMAKE_CURRENT_SOURCE_DIR}/tests/input3.txt)
set_property(TEST Test3 PROPERTY PASS_REGULAR_EXPRESSION "3\nt")

add_test(NAME Test4 COMMAND task ${CMAKE_CURRENT_SOURCE_DIR}/tests/script4.txt ${CMAKE_CURRENT_SOURCE_DIR}/tests/input4.txt)
set_property(TEST Test4 PROPERTY PASS_REGULAR_EXPRESSION "AA")

add_test(NAME Test5 COMMAND task ${CMAKE_CURRENT_SOURCE_DIR}/tests/script5.txt ${CMAKE_CURRENT_SOURCE_DIR}/tests/input5.txt)
set_property(TEST Test5 PROPERTY PASS_REGULAR_EXPRESSION "A")

add_test(NAME Test6 COMMAND task ${CMAKE_CURRENT_SOURCE_DIR}/tests/script6.txt ${CMAKE_CURRENT_SOURCE_DIR}/tests/input6.txt)
set_property(TEST Test6 PROPERTY WILL_FAIL TRUE)