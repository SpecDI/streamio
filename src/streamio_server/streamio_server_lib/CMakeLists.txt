include(GenerateExportHeader)


add_library(streamio_server_lib streamio_greeter.cpp)

add_library(streamio::streamio_server_lib ALIAS streamio_server_lib)

target_link_libraries(
  streamio_server_lib
  PRIVATE myproject::myproject_options
          myproject::myproject_warnings)

target_link_system_libraries(
  streamio_server_lib
  PRIVATE
          fmt::fmt
          spdlog::spdlog
          lefticus::tools)

target_include_directories(streamio_server_lib ${WARNING_GUARD} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                                                                  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include> PRIVATE "${PROJECT_SOURCE_DIR}/src/streamio_server/streamio_server_lib")

target_compile_features(streamio_server_lib PUBLIC cxx_std_20)
target_compile_definitions(streamio_server_lib PUBLIC BOOST_ASIO_HAS_CO_AWAIT)

set_target_properties(
  streamio_server_lib
  PROPERTIES VERSION ${PROJECT_VERSION}
             CXX_VISIBILITY_PRESET hidden
             VISIBILITY_INLINES_HIDDEN YES)

# generate_export_header(streamio_server_lib EXPORT_FILE_NAME ${PROJECT_BINARY_DIR}/include/streamio/streamio_server_lib_export.hpp)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(streamio_server_lib PUBLIC streamio_server_lib_STATIC_DEFINE)
endif()
