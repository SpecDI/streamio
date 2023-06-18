#include <streamio_greeter.hpp>

#include <chrono>
#include <iostream>

#include <fmt/format.h>

#include <boost/asio.hpp>

using namespace std::chrono_literals;

namespace streamio {

void async_greet()
{
  boost::asio::io_context io_ctx;
  boost::asio::co_spawn(
    io_ctx,
    [&io_ctx]() -> boost::asio::awaitable<void> {
      boost::asio::steady_timer timer(io_ctx, 2s);
      co_await timer.async_wait(boost::asio::use_awaitable);

      fmt::print("{}\n", get_message());
    },
    boost::asio::detached);

  io_ctx.run();
}

}// namespace streamio