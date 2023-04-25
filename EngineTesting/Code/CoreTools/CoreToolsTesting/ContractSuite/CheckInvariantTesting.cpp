///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 15:35)

#include "CheckInvariantTesting.h"
#include "CoreTools/Contract/CheckInvariantDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::CheckInvariantTesting::CheckInvariantTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

bool CoreTools::CheckInvariantTesting::IsValid() const noexcept
{
#ifdef OPEN_CLASS_INVARIANT

    return ParentType::IsValid();

#else  // !OPEN_CLASS_INVARIANT

    return true;

#endif  // OPEN_CLASS_INVARIANT
}

void CoreTools::CheckInvariantTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CheckInvariantTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OnlyPreConditionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OnlyPostConditionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FullyTest);
}

void CoreTools::CheckInvariantTesting::OnlyPreConditionTest() noexcept
{
    TestingType checkInvariant{ *this, CORE_TOOLS_FUNCTION_DESCRIBED, CheckInvariantConditions::OnlyPreCondition };
}

void CoreTools::CheckInvariantTesting::OnlyPostConditionTest() noexcept
{
    TestingType checkInvariant{ *this, CORE_TOOLS_FUNCTION_DESCRIBED, CheckInvariantConditions::OnlyPostCondition };
}

void CoreTools::CheckInvariantTesting::FullyTest() noexcept
{
    TestingType checkInvariant{ *this, CORE_TOOLS_FUNCTION_DESCRIBED, CheckInvariantConditions::Fully };
}
