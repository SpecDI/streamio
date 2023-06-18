add_executable(streamio_server main.cpp)

target_link_libraries(
  streamio_server
  PRIVATE myproject::myproject_options
          myproject::myproject_warnings
          streamio_server_lib)

target_compile_definitions(streamio_server PUBLIC BOOST_ASIO_HAS_CO_AWAIT)

target_link_system_libraries(
  streamio_server
  PRIVATE
          fmt::fmt
          spdlog::spdlog
          lefticus::tools)

target_include_directories(streamio_server PRIVATE "${CMAKE_BINARY_DIR}/configured_files/include" "${PROJECT_SOURCE_DIR}/src/streamio_server/streamio_server_lib")
