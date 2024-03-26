/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 23:01)

#include "CompilerConfigTesting.h"
#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CompilerConfigTesting::CompilerConfigTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CompilerConfigTesting)

void System::CompilerConfigTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CompilerConfigTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CompilerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VisualCTest);
}

void System::CompilerConfigTesting::CompilerTest()
{
    auto& stream = GetStream();

    stream << "编译器使用的C++标准是C++" << SYSTEM_CPP_STANDARD << '\n';

    stream << "编译器是：" << TCRE_SYSTEM_COMPILER << '\n';

    stream << "编译器使用的版本是：" << TCRE_COMPILER_VERSION << '\n';
}

void System::CompilerConfigTesting::VisualCTest() const noexcept
{
#ifdef TCRE_USE_MSVC

    static_assert(MSVC_VERSION == TCRE_USE_MSVC);

    static_assert(193530324 <= MSVC_FULL_VERSION);
    static_assert(14.3 <= MSVC_COMPILER_VERSION);

#endif  // TCRE_USE_MSVC
}
