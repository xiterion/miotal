#include "catch/catch.hpp"

#include <miotal/generic/register.hpp>

using namespace platform::generic;

TEST_CASE("Bitfield offset", "[Bitfield]") {
    REQUIRE(Bitfield<Generic_Register<std::uint32_t>, 0>::offset == 0);
    REQUIRE(Bitfield<Generic_Register<std::uint32_t>, 31>::offset == 31);
    REQUIRE(Bitfield<Generic_Register<std::uint32_t>, 3, 2>::offset == 2);
    REQUIRE(Bitfield<Generic_Register<std::uint32_t>, 31, 28>::offset == 28);
}

TEST_CASE("Bitfield width", "[Bitfield]") {
    REQUIRE(Bitfield<Generic_Register<std::uint32_t>, 0>::width == 1);
    REQUIRE(Bitfield<Generic_Register<std::uint32_t>, 31>::width == 1);
    REQUIRE(Bitfield<Generic_Register<std::uint32_t>, 12>::width == 1);
    REQUIRE(Bitfield<Generic_Register<std::uint32_t>, 16, 12>::width == 5);
}

TEST_CASE("Bitfield masks are correct", "[Bitfield]") {
    REQUIRE(Bitfield<Generic_Register<std::uint32_t>, 0>::mask == 1u);
    REQUIRE(Bitfield<Generic_Register<std::uint32_t>, 31>::mask == 0x8000'0000u);
    REQUIRE(Bitfield<Generic_Register<std::uint32_t>, 16>::mask == 0x0001'0000u);
    REQUIRE(Bitfield<Generic_Register<std::uint32_t>, 15, 12>::mask == 0x0000'F000u);
}

TEST_CASE("Bitfield decodes register value", "[Bitfield]") {
    SUCCEED("not implemented");
}
