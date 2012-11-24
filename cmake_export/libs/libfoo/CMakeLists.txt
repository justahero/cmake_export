configure_file (config.h.in "${CMAKE_CURRENT_BINARY_DIR}/config.h" @ONLY)

file (GLOB_RECURSE src_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} foo/*.cpp)
file (GLOB_RECURSE header_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} foo/*.h)

add_library (foo SHARED ${src_files} ${header_files} config.h.in)

set_target_properties(
    foo PROPERTIES
    PUBLIC_HEADER "${header_files};${CMAKE_CURRENT_BINARY_DIR}/config.h"
)

install (
    TARGETS foo
    EXPORT SampleLibraryDepends
    RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
    LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
    PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/foo" COMPONENT dev
    ARCHIVE DESTINATION "${INSTALL_LIB_DIR}"
)

