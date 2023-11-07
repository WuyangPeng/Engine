///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 15:31)

#include "ClassInvariantMacroTesting.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/ClassInvariantStubMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ClassInvariantMacroTesting::ClassInvariantMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ClassInvariantMacroTesting)

void CoreTools::ClassInvariantMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ClassInvariantMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StubMacroTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LevelTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ValidTest);
}

void CoreTools::ClassInvariantMacroTesting::StubMacroTest() noexcept
{
    const ClassInvariantStubMacroTesting classInvariantStubMacroTesting{};
}

void CoreTools::ClassInvariantMacroTesting::LevelTest()
{
    ASSERT_RANGE(CLASS_INVARIANT_LEVEL, 0, 9);
    ASSERT_RANGE(CLASS_INVARIANT_CONST_LEVEL, 0, 9);
}

void CoreTools::ClassInvariantMacroTesting::ValidTest() noexcept
{
    CLASS_IS_VALID;
    CLASS_IS_VALID_CONST;
    SELF_CLASS_IS_VALID;

    CLASS_IS_VALID_0;
    CLASS_IS_VALID_CONST_0;
    SELF_CLASS_IS_VALID_0;

    CLASS_IS_VALID_1;
    CLASS_IS_VALID_CONST_1;
    SELF_CLASS_IS_VALID_1;

    CLASS_IS_VALID_2;
    CLASS_IS_VALID_CONST_2;
    SELF_CLASS_IS_VALID_2;

    CLASS_IS_VALID_3;
    CLASS_IS_VALID_CONST_3;
    SELF_CLASS_IS_VALID_3;

    CLASS_IS_VALID_4;
    CLASS_IS_VALID_CONST_4;
    SELF_CLASS_IS_VALID_4;

    CLASS_IS_VALID_5;
    CLASS_IS_VALID_CONST_5;
    SELF_CLASS_IS_VALID_5;

    CLASS_IS_VALID_6;
    CLASS_IS_VALID_CONST_6;
    SELF_CLASS_IS_VALID_6;

    CLASS_IS_VALID_7;
    CLASS_IS_VALID_CONST_7;
    SELF_CLASS_IS_VALID_7;

    CLASS_IS_VALID_8;
    CLASS_IS_VALID_CONST_8;
    SELF_CLASS_IS_VALID_8;

    CLASS_IS_VALID_9;
    CLASS_IS_VALID_CONST_9;
    SELF_CLASS_IS_VALID_9;
}
