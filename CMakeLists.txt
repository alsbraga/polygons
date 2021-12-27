project (polygons)
cmake_minimum_required(VERSION 3.18)

option(BUILD_TESTS "Build Test Cases" OFF)
option(RUN_TESTS "Build and run Test Cases" OFF)
if (RUN_TESTS)
  set(BUILD_TESTS "Forced building Test Cases" ON CACHE PATH "" FORCE)
endif (RUN_TESTS)

add_subdirectory(src)

if(BUILD_TESTS)
  message(CHECK_START "Finding Catch2 v2")
  find_package(Catch2 2 QUIET)
  if (Catch2_FOUND)
    message(CHECK_PASS "found, configuring tests")
    add_subdirectory(tst)
  else()
    message(CHECK_FAIL "not found, tests not configured")
  endif (Catch2_FOUND)
endif(BUILD_TESTS)



