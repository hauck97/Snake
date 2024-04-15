if (ENABLE_TESTING)
    set(TEST_MAIN "unit_tests")
    set(TESTS_SOURCES
        "main.cc")
    set(TEST_INCLUDES
        "./")

    add_executable(${TEST_MAIN} ${TESTS_SOURCES})
    target_include_directories(${TEST_MAIN} PUBLIC
        ${TEST_INCLUDES})
    target_link_libraries(${TEST_MAIN} PUBLIC
        ${LIBRARY_NAME}
        ${CURSES_LIBRARIES}
        Catch2::Catch2)
endif()
