// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 16:06)

#include "RealAddressTesting.h"
#include "Detail/RealAddressTest.h"
#include "Detail/RealAddressTestAddress.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/RealAddressDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, RealAddressTesting)

void CoreTools::RealAddressTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(AddressTest);
}

void CoreTools::RealAddressTesting
	::AddressTest()
{
	RealAddressTest volatile firstRealAddressTest;
	RealAddressTest const secondRealAddressTest;
	RealAddressTest thirdRealAddressTest;
	RealAddressTestAddress const realAddressTestAddress;

	ASSERT_TRUE(&firstRealAddressTest == nullptr);
	ASSERT_TRUE(&secondRealAddressTest == nullptr);
	ASSERT_TRUE(&thirdRealAddressTest == nullptr);
	ASSERT_UNEQUAL_NULL_PTR(&realAddressTestAddress);

	ASSERT_FALSE(GetAddress(firstRealAddressTest) == nullptr);
	ASSERT_FALSE(GetAddress(secondRealAddressTest) == nullptr);
	ASSERT_FALSE(GetAddress(thirdRealAddressTest) == nullptr);
	ASSERT_UNEQUAL_NULL_PTR(GetAddress(realAddressTestAddress));
}

