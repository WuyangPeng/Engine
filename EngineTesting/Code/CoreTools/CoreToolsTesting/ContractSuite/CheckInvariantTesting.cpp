///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 14:31)

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
    ASSERT_NOT_THROW_EXCEPTION_0(OnlyPreconditionsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OnlyPostconditionsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FullyTest);
}

void CoreTools::CheckInvariantTesting::OnlyPreconditionsTest() noexcept
{
    TestingType checkInvariant{ *this, CORE_TOOLS_FUNCTION_DESCRIBED, CheckInvariantConditions::OnlyPreconditions };
}

void CoreTools::CheckInvariantTesting::OnlyPostconditionsTest() noexcept
{
    TestingType checkInvariant{ *this, CORE_TOOLS_FUNCTION_DESCRIBED, CheckInvariantConditions::OnlyPostconditions };
}

void CoreTools::CheckInvariantTesting::FullyTest() noexcept
{
    TestingType checkInvariant{ *this, CORE_TOOLS_FUNCTION_DESCRIBED, CheckInvariantConditions::Fully };
}
