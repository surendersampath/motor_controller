add_executable(suite_1_app
    suite_1.c
)

target_link_libraries(suite_1_app
    motor_controller
    Unity
)

add_test(suite_1_test suite_1_app)
