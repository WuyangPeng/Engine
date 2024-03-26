/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:20)

#include "EngineeringOffsetTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::EngineeringOffsetTesting::EngineeringOffsetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EngineeringOffsetTesting)

void System::EngineeringOffsetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EngineeringOffsetTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OffsetTest);
}

void System::EngineeringOffsetTesting::OffsetTest() const noexcept
{
    std::ignore = GetEngineeringOffsetValue();
}
