///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/16 10:21)

#include "ReplaceTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/Replace.h"

AssistTools::ReplaceTesting::ReplaceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, ReplaceTesting)

void AssistTools::ReplaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AssistTools::ReplaceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReplaceTest);
}

void AssistTools::ReplaceTesting::ReplaceTest()
{
    const Replace replace{ SYSTEM_TEXT("keyCode"), SYSTEM_TEXT("parameter") };

    ASSERT_EQUAL(replace.GetKeyCode(), SYSTEM_TEXT("keyCode"));
    ASSERT_EQUAL(replace.GetParameter(), SYSTEM_TEXT("parameter"));
}
