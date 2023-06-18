#include <streamio_greeter.hpp>

#include <chrono>
#include <iostream>

#include <fmt/format.h>

#include <boost/asio.hpp>

using namespace std::chrono_literals;

int main()
{
  try {
    streamio::async_greet();
    return EXIT_SUCCESS;
  } catch (...) {
    return EXIT_FAILURE;
  }
}