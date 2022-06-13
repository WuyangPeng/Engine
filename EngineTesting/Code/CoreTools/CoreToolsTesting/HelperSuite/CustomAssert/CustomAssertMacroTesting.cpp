///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
///	¡™œµ◊˜’ﬂ£∫94458936@qq.com
///
///	±Í◊º£∫std:c++20
///	“˝«Ê≤‚ ‘∞Ê±æ£∫0.8.0.8 (2022/05/19 11:22)

#include "CustomAssertMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/CustomAssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::CustomAssertMacroTesting::CustomAssertMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CustomAssertMacroTesting)

void CoreTools::CustomAssertMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CustomAssertMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Assert1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(LevelTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConstexprTest);
}

void CoreTools::CustomAssertMacroTesting::Assert1Test()
{
    ASSERTION(true, "∂œ—‘≤‚ ‘£°");
    ASSERTION_USE_FUNCTION_DESCRIBED(true, CORE_TOOLS_FUNCTION_DESCRIBED, "∂œ—‘≤‚ ‘£°");

    ASSERTION_0(true, "∂œ—‘≤‚ ‘£°");
    ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "∂œ—‘≤‚ ‘£°");

    ASSERTION_1(true, "∂œ—‘≤‚ ‘£°");
    ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "∂œ—‘≤‚ ‘£°");

    ASSERTION_2(true, "∂œ—‘≤‚ ‘£°");
    ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "∂œ—‘≤‚ ‘£°");

    ASSERTION_3(true, "∂œ—‘≤‚ ‘£°");
    ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "∂œ—‘≤‚ ‘£°");

    ASSERTION_4(true, "∂œ—‘≤‚ ‘£°");
    ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "∂œ—‘≤‚ ‘£°");
}

void CoreTools::CustomAssertMacroTesting::LevelTest()
{
    ASSERT_RANGE(ASSERT_LEVEL, 0, 5);
}

void CoreTools::CustomAssertMacroTesting::ConstexprTest() noexcept
{
#ifdef CORE_TOOLS_USE_ASSERT

    static_assert(g_Assert == ASSERT_LEVEL);

#else  // !CORE_TOOLS_USE_ASSERT

    static_assert(g_Assert == -1);

#endif  // CORE_TOOLS_USE_ASSERT

#if defined(_DEBUG) && defined(CORE_TOOLS_USE_ASSERT) && 0 <= ASSERT_LEVEL

    static_assert(g_AssertDebug);

#else  // !defined(_DEBUG) || defined(CORE_TOOLS_USE_ASSERT) || ASSERT_LEVEL < 0

    static_assert(!g_AssertDebug);

#endif  // defined(_DEBUG) && defined(CORE_TOOLS_USE_ASSERT) && 0 <= ASSERT_LEVEL
}
