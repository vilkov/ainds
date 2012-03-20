# CMake tools
include ("collect_sources")


collect_sources (src_HEADERS src_SOURCES ${CMAKE_SOURCE_DIR})


# Regex
if (UNIX)
    set (EXCLUDE_FILES_MASK ".*/win32/.*")
elseif (WIN32)
    set (EXCLUDE_FILES_MASK ".*/unix/.*")
endif ()


# Headers
set (tmp_src_HEADERS "")
foreach (src_HEADER ${src_HEADERS})
    if (NOT ${src_HEADER} MATCHES ${EXCLUDE_FILES_MASK})
        set (tmp_src_HEADERS ${tmp_src_HEADERS} ${src_HEADER})
    endif ()
endforeach ()
set (src_HEADERS ${tmp_src_HEADERS})
set (ainds_HEADERS ${ainds_HEADERS} ${src_HEADERS} PARENT_SCOPE)


# Sources
set (tmp_src_SOURCES "")
foreach (src_SOURCE ${src_SOURCES})
    if (NOT ${src_SOURCE} MATCHES ${EXCLUDE_FILES_MASK})
        set (tmp_src_SOURCES ${tmp_src_SOURCES} ${src_SOURCE})
    endif ()
endforeach ()
set (src_SOURCES ${tmp_src_SOURCES})
set (ainds_SOURCES ${ainds_SOURCES} ${src_SOURCES} PARENT_SCOPE)


# UIs
file (GLOB_RECURSE src_UIS RELATIVE ${ainds_SOURCE_DIR} FOLLOW_SYMLINKS "*.ui")
set (ainds_UIS ${ainds_UIS} ${src_UIS} PARENT_SCOPE)
