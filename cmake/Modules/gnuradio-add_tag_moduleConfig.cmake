find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_ADD_TAG_MODULE gnuradio-add_tag_module)

FIND_PATH(
    GR_ADD_TAG_MODULE_INCLUDE_DIRS
    NAMES gnuradio/add_tag_module/api.h
    HINTS $ENV{ADD_TAG_MODULE_DIR}/include
        ${PC_ADD_TAG_MODULE_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_ADD_TAG_MODULE_LIBRARIES
    NAMES gnuradio-add_tag_module
    HINTS $ENV{ADD_TAG_MODULE_DIR}/lib
        ${PC_ADD_TAG_MODULE_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-add_tag_moduleTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_ADD_TAG_MODULE DEFAULT_MSG GR_ADD_TAG_MODULE_LIBRARIES GR_ADD_TAG_MODULE_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_ADD_TAG_MODULE_LIBRARIES GR_ADD_TAG_MODULE_INCLUDE_DIRS)
