/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/13 00:13)

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
    ASSERTION(true, "���Բ��ԣ�");
    ASSERTION_USE_FUNCTION_DESCRIBED(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    ASSERTION_0(true, "���Բ��ԣ�");
    ASSERTION_USE_FUNCTION_DESCRIBED_0(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    ASSERTION_1(true, "���Բ��ԣ�");
    ASSERTION_USE_FUNCTION_DESCRIBED_1(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    ASSERTION_2(true, "���Բ��ԣ�");
    ASSERTION_USE_FUNCTION_DESCRIBED_2(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    ASSERTION_3(true, "���Բ��ԣ�");
    ASSERTION_USE_FUNCTION_DESCRIBED_3(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    ASSERTION_4(true, "���Բ��ԣ�");
    ASSERTION_USE_FUNCTION_DESCRIBED_4(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");

    ASSERTION_DEBUG(true, "���Բ��ԣ�");
    ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(true, CORE_TOOLS_FUNCTION_DESCRIBED, "���Բ��ԣ�");
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
