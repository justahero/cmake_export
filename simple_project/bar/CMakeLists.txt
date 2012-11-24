file (GLOB_RECURSE src_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ./*.cpp)
file (GLOB_RECURSE header_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ./*.h)

add_executable (bar ${src_files} ${header_files})
target_link_libraries (bar ${SAMPLE_LIBRARIES})
