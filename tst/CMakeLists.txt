add_executable(polygon_tests
    main.cpp
    point_test.cpp
    segment_test.cpp
)
target_link_libraries(polygon_tests PRIVATE Catch2::Catch2)
target_link_libraries(polygon_tests PRIVATE polygons)

include(CTest)
include(Catch)
catch_discover_tests(polygon_tests)

if (RUN_TESTS)
  add_custom_command(
       TARGET polygon_tests
       POST_BUILD 
       COMMAND ctest polygon_tests
       COMMENT "Run tests"
  )
endif (RUN_TESTS)