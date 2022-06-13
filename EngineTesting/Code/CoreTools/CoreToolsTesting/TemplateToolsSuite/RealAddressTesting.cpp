///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 19:05)

#include "RealAddressTesting.h"
#include "Detail/RealAddressTest.h"
#include "Detail/RealAddressTestAddress.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/RealAddressDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, RealAddressTesting)

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
