/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 17:34)

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
    SYSTEM_SELF_CLASS_IS_VALID_1;
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
    ASSERT_NOT_THROW_EXCEPTION_0(NodiscardTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FallthroughTest);
    ASSERT_THROW_EXCEPTION_0(NoReturnTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArchitectureTypeTest);

    /// 这里开启OPEN_DEPRECATED_MACRO会产生一个编译警告
#ifdef OPEN_DEPRECATED_MACRO

    ASSERT_NOT_THROW_EXCEPTION_0(Deprecate);

#endif  // OPEN_DEPRECATED_MACRO
}

void System::ConfigMarkTesting::UnusedTest() const noexcept
{
    MAYBE_UNUSED constexpr auto unused = 0;
}

void System::ConfigMarkTesting::MaybeNullptrTest()
{
    const auto nullPtr = GetNullptr();

    ASSERT_EQUAL_NULL_PTR(nullPtr);
}

void System::ConfigMarkTesting::NodiscardTest()
{
    const auto result = FallthroughTest();

    ASSERT_EQUAL(result, 4);
}

int System::ConfigMarkTesting::FallthroughTest() const noexcept
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

int System::ConfigMarkTesting::NoReturnTest() const
{
    NoReturn();
}

void System::ConfigMarkTesting::Deprecate() const noexcept
{
}

const int* System::ConfigMarkTesting::GetNullptr() const noexcept
{
    return nullptr;
}

void System::ConfigMarkTesting::NoReturn()
{
    THROW_WINDOWS_EXCEPTION
}

void System::ConfigMarkTesting::ArchitectureTypeTest() const noexcept
{
#ifdef TCRE_ARCHITECTURE_TYPE_64

    static_assert(sizeof(size_t) == sizeof(uint64_t));

#else  // !TCRE_ARCHITECTURE_TYPE_64

    static_assert(sizeof(size_t) == sizeof(uint32_t));

#endif  // TCRE_ARCHITECTURE_TYPE_64
}
