#include <catch2/catch_test_macros.hpp>
#include <streamio_greeter.hpp>

TEST_CASE("Correct greet message", "[greet]") { REQUIRE(streamio::get_message() == "Hello from ASIO coro!"); }