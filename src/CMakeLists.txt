option(BUILD_SHARED_LIBS "Build as shared" OFF)
add_library(polygons)
target_include_directories(polygons PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(HEADERS
  Point.hpp
  Segment.hpp
  Polygon.hpp
)

set(SOURCES
  Point.cpp
  Segment.cpp
  Polygon.cpp
)

target_sources(polygons PRIVATE
  ${HEADERS}
  ${SOURCES}
)

set_property(TARGET polygons PROPERTY PUBLIC_HEADER ${HEADERS})

install(TARGETS polygons DESTINATION polygons/lib PUBLIC_HEADER DESTINATION polygons/include)