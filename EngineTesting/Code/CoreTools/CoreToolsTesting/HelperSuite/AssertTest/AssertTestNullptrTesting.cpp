///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
///	¡™œµ◊˜’ﬂ£∫94458936@qq.com
///
///	±Í◊º£∫std:c++17
///	“˝«Ê≤‚ ‘∞Ê±æ£∫0.7.2.1 (2021/08/02 19:33)

#include "AssertTestNullptrTesting.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/MacroTestEnum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::AssertTestNullptrTesting::AssertTestNullptrTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AssertTestNullptrTesting)

void CoreTools::AssertTestNullptrTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::AssertTestNullptrTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AssertNullptrTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertNullptrMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertNullptrFailureThrowTest);
}

void CoreTools::AssertTestNullptrTesting::AssertNullptrTest()
{
    int* ptr{ nullptr };

    ASSERT_EQUAL_NULL_PTR(ptr);

    auto value = 0;
    ptr = &value;

    ASSERT_UNEQUAL_NULL_PTR(ptr);
}

void CoreTools::AssertTestNullptrTesting::AssertNullptrMessageTest()
{
    int* ptr{ nullptr };

    ASSERT_EQUAL_NULL_PTR_USE_MESSAGE(ptr, "≤‚ ‘");

    auto value = 0;
    ptr = &value;

    ASSERT_UNEQUAL_NULL_PTR_USE_MESSAGE(ptr, "≤‚ ‘");
}

void CoreTools::AssertTestNullptrTesting::AssertNullptrFailureThrowTest()
{
    int* ptr{ nullptr };

    ASSERT_EQUAL_NULL_PTR_FAILURE_THROW(ptr, "≤‚ ‘");

    auto value = 0;
    ptr = &value;

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(ptr, "≤‚ ‘");
}