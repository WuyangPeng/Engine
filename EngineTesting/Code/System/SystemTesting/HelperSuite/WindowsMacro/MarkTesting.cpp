/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 10:00)

#include "MarkTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MarkTesting::MarkTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MarkTesting)

void System::MarkTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MarkTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CallBackTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WinApiTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ParameterMarkTest);
}

void System::MarkTesting::CallBackTest() const noexcept
{
}

void System::MarkTesting::WinApiTest() const noexcept
{
}

void System::MarkTesting::ParameterMarkTest() const noexcept
{
    constexpr auto in = 0;
    auto inOpt = 0;
    auto out = 0;
    auto outOpt = 0;
    auto inOut = 0;
    auto inOutOpt = 0;

    DoParameterMarkTest(in, &inOpt, out, &outOpt, inOut, &inOutOpt);
}

void System::MarkTesting::DoParameterMarkTest(SYSTEM_IN int in, SYSTEM_IN_OPT int* inOpt, SYSTEM_OUT int& out, SYSTEM_OUT_OPT int* outOpt, SYSTEM_IN_OUT int& inOut, SYSTEM_IN_OUT_OPT int* inOutOpt) const noexcept
{
    if (inOpt != nullptr)
    {
        *inOpt = in;
    }

    out = in;

    if (outOpt != nullptr)
    {
        *outOpt = in;
    }

    if (inOutOpt != nullptr)
    {
        *inOutOpt = inOut;
    }
}
