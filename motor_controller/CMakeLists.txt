add_library(motor_controller STATIC
    motor_controller.c
)

target_include_directories(motor_controller PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)
