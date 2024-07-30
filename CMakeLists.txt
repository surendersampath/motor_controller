project("Thorlabs test" C)
cmake_minimum_required(VERSION 3.0)

set(TARGET_GROUP production CACHE STRING "Group to build")

add_subdirectory(motor_controller)

if(TARGET_GROUP STREQUAL production)
    add_subdirectory(main)
    message("Building application")
elseif(TARGET_GROUP STREQUAL test)
    include(CTest)

    add_subdirectory(external)
    add_subdirectory(test)
    message("Building test suite")
else()
    message(FATAL_ERROR "Given TARGET_GROUP unknown")
endif()
