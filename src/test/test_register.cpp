#include "catch/catch.hpp"

#include <miotal/generic/register.hpp>

TEST_CASE("Bitfield masks are correct", "[bitfield]") {
    using namespace platform::generic;
    REQUIRE(Bitfield<Generic_Register<std::uint32_t>, 0>::offset == 0);
    REQUIRE(Bitfield<Generic_Register<std::uint32_t>, 0>::width == 1);
    REQUIRE(Bitfield<Generic_Register<std::uint32_t>, 0>::mask == 1u);
}
