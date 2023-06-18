#pragma once

#include <string>

namespace streamio {
void async_greet();
[[nodiscard]] constexpr std::string get_message() { return "Hello from ASIO coro!"; }
}// namespace streamio
