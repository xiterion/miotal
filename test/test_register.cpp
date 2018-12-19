#include "catch/catch.hpp"

#include <miotal/platforms/generic/register.hpp>

TEST_CASE("Bitfield masks are correct", "[bitfield]") {
    using namespace platform::generic;
    REQUIRE(Bitfield<Generic_Register<std::uint32_t>, 0>::offset == 0);
}
