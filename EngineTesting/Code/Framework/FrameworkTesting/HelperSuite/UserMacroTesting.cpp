///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 20:23)

#include "UserMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/Helper/UserMacro.h"

Framework::UserMacroTesting::UserMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, UserMacroTesting)

void Framework::UserMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::UserMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MacroExistTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidTestMacroValidTest);
}

void Framework::UserMacroTesting::MacroExistTest()
{
    ASSERT_LESS(0, CLOSE_FRAMEWORK_MAX);

    ASSERT_LESS_EQUAL(0, COMPILE_FRAMEWORK_CLOSE);

#if defined(BUILDING_STATIC) ^ defined(BUILDING_FRAMEWORK_STATIC)

    ASSERT_TRUE_USE_MESSAGE(false, "BUILDING_STATIC 和 BUILDING_FRAMEWORK_STATIC必须同时定义或同时不定义。");

#else  // !(defined(BUILDING_STATIC) ^ defined(BUILDING_FRAMEWORK_STATIC))

    ASSERT_TRUE_USE_MESSAGE(true, "BUILDING_STATIC 和 BUILDING_FRAMEWORK_STATIC必须同时定义或同时不定义。");

#endif  // defined(BUILDING_STATIC) ^ defined(BUILDING_FRAMEWORK_STATIC)
}

void Framework::UserMacroTesting::AndroidTestMacroValidTest()
{
    auto useAndroidTestCount = 0;
    for (auto i = 1; i <= CLOSE_FRAMEWORK_MAX; i <<= 1)
    {
        if ((CLOSE_USE_ANDROID_TEST & i) != 0)
        {
            ++useAndroidTestCount;
        }
    }

    ASSERT_EQUAL(useAndroidTestCount, 1);
}
