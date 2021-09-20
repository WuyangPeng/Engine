///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/19 14:47)

#include "ConfigMarkTesting.h"
#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define OPEN_DEPRECATED_MACRO
#undef OPEN_DEPRECATED_MACRO

System::ConfigMarkTesting::ConfigMarkTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConfigMarkTesting)

void System::ConfigMarkTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ConfigMarkTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(UnusedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MaybeNullptrTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NnodiscardTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FallthroughTest);
    ASSERT_THROW_EXCEPTION_0(NoReturnTest);

#ifdef OPEN_DEPRECATED_MACRO  // 这里开启OPEN_DEPRECATED_MACRO会产生一个编译警告
    ASSERT_NOT_THROW_EXCEPTION_0(Deprecate);
#endif  // OPEN_DEPRECATED_MACRO
}

void System::ConfigMarkTesting::UnusedTest() noexcept
{
    MAYBE_UNUSED constexpr auto unused = 0;
}

void System::ConfigMarkTesting::MaybeNullptrTest()
{
    auto nullPtr = GetNullptr();

    ASSERT_EQUAL_NULL_PTR(nullPtr);
}

void System::ConfigMarkTesting::NnodiscardTest()
{
    const auto result = FallthroughTest();

    ASSERT_EQUAL(result, 4);
}

int System::ConfigMarkTesting::FallthroughTest() noexcept
{
    auto testValue = 1;
    switch (testValue)
    {
        case 1:
            ++testValue;
            FALLTHROUGH;
        case 2:
            ++testValue;
            FALLTHROUGH;
        default:
            ++testValue;
            break;
    }

    return testValue;
}

int System::ConfigMarkTesting::NoReturnTest()
{
    NoReturn();
}

void System::ConfigMarkTesting::Deprecate() noexcept
{
}

const int* System::ConfigMarkTesting::GetNullptr() noexcept
{
    return nullptr;
}

void System::ConfigMarkTesting::NoReturn()
{
    THROW_WINDOWS_EXCEPTION;
}
