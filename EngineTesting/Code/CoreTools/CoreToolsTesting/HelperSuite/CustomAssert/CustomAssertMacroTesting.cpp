/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 00:13)

#include "CustomAssertMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/CustomAssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::CustomAssertMacroTesting::CustomAssertMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CustomAssertMacroTesting)

void CoreTools::CustomAssertMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CustomAssertMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AssertMacroTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LevelTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConstexprTest);
}

void CoreTools::CustomAssertMacroTesting::AssertMacroTest()
{
    ASSERTION(true, "断言测试！");
    ASSERTION_USE_FUNCTION_DESCRIBED(true, CORE_TOOLS_FUNCTION_DESCRIBED, "断言测试！");

    ASSERTION_0(true, "断言测试！");
    ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "断言测试！");

    ASSERTION_1(true, "断言测试！");
    ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "断言测试！");

    ASSERTION_2(true, "断言测试！");
    ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "断言测试！");

    ASSERTION_3(true, "断言测试！");
    ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "断言测试！");

    ASSERTION_4(true, "断言测试！");
    ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "断言测试！");

    ASSERTION_DEBUG(true, "断言测试！");
    ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(true, CORE_TOOLS_FUNCTION_DESCRIBED, "断言测试！");
}

void CoreTools::CustomAssertMacroTesting::LevelTest()
{
    ASSERT_RANGE(ASSERT_LEVEL, 0, 5);
}

void CoreTools::CustomAssertMacroTesting::ConstexprTest() noexcept
{
#ifdef CORE_TOOLS_USE_ASSERT

    static_assert(gAssert == ASSERT_LEVEL);

#else  // !CORE_TOOLS_USE_ASSERT

    static_assert(gAssert == -1);

#endif  // CORE_TOOLS_USE_ASSERT

#if defined(_DEBUG) && defined(CORE_TOOLS_USE_ASSERT) && 0 <= ASSERT_LEVEL

    static_assert(gAssertDebug);

#else  // !defined(_DEBUG) || defined(CORE_TOOLS_USE_ASSERT) || ASSERT_LEVEL < 0

    static_assert(!gAssertDebug);

#endif  // defined(_DEBUG) && defined(CORE_TOOLS_USE_ASSERT) && 0 <= ASSERT_LEVEL
}
