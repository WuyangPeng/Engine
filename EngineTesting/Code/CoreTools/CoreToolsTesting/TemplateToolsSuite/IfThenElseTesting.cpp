﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:34)

#include "IfThenElseTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/TemplateTools/IfThenElse.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::IfThenElseTesting::IfThenElseTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, IfThenElseTesting)

void CoreTools::IfThenElseTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::IfThenElseTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IfThenElseTest);
}

void CoreTools::IfThenElseTesting::IfThenElseTest() noexcept
{
    static_assert(std::is_same_v<IfThenElse<true, bool, int>::ResultType, bool>);
    static_assert(std::is_same_v<IfThenElse<false, bool, int>::ResultType, int>);
}
