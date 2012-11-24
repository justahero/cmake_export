file (GLOB_RECURSE src_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ./*.cpp)
file (GLOB_RECURSE header_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ./*.h)

add_executable (project_a ${src_files} ${header_files})
target_link_libraries (project_a foo)

install (
    TARGETS project_a
    EXPORT SampleLibraryDepends
    RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
)
