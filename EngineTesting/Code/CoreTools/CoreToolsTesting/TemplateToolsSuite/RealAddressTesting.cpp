///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:35)

#include "RealAddressTesting.h"
#include "Detail/RealAddressTest.h"
#include "Detail/RealAddressTestAddress.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
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
    RealAddressTest volatile realAddressTest0{};
    RealAddressTest const realAddressTest1{};
    RealAddressTest realAddressTest2;
    RealAddressTestAddress const realAddressTest3;

    ASSERT_TRUE(&realAddressTest0 == nullptr);
    ASSERT_TRUE(&realAddressTest1 == nullptr);
    ASSERT_TRUE(&realAddressTest2 == nullptr);
    ASSERT_UNEQUAL_NULL_PTR(&realAddressTest3);

    ASSERT_FALSE(GetAddress(realAddressTest0) == nullptr);
    ASSERT_FALSE(GetAddress(realAddressTest1) == nullptr);
    ASSERT_FALSE(GetAddress(realAddressTest2) == nullptr);
    ASSERT_UNEQUAL_NULL_PTR(GetAddress(realAddressTest3));
}
