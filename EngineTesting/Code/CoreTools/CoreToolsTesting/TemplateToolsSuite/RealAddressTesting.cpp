///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 19:05)

#include "RealAddressTesting.h"
#include "Detail/RealAddressTest.h"
#include "Detail/RealAddressTestAddress.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/RealAddressDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
CoreTools::RealAddressTesting::RealAddressTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, RealAddressTesting)

void CoreTools::RealAddressTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::RealAddressTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AddressTest);
}

void CoreTools::RealAddressTesting::AddressTest()
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
