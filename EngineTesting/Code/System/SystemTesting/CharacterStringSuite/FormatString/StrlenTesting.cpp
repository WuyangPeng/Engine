///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/06 16:36)

#include "StrlenTesting.h"
#include "System/CharacterString/FormatStringDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::string;

System::StrlenTesting::StrlenTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, StrlenTesting)

void System::StrlenTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::StrlenTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StrlenTest);
}

void System::StrlenTesting::StrlenTest()
{
    const char* testString{ "strlen" };

    ASSERT_EQUAL(Strlen(testString), string{ testString }.size());
}
