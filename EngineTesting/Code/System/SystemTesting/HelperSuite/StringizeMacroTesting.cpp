///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/09/15 19:01)

#include "StringizeMacroTesting.h"
#include "System/Helper/StringizeMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>

using std::string;

System::StringizeMacroTesting::StringizeMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, StringizeMacroTesting)

void System::StringizeMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::StringizeMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StringizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConcatenatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultipleConcatenatorTest);
}

void System::StringizeMacroTesting::StringizeTest()
{
    string testValue{ SYSTEM_STRINGIZE(100TestValue) };

    ASSERT_EQUAL(testValue, "100TestValue");
}

void System::StringizeMacroTesting::ConcatenatorTest()
{
    string SYSTEM_CONCATENATOR(test, Value){ "TestValue" };

    ASSERT_EQUAL(testValue, "TestValue");
}

void System::StringizeMacroTesting::MultipleConcatenatorTest()
{
    string SYSTEM_MULTIPLE_CONCATENATOR(test, Value, 1){ "TestValue" };

    ASSERT_EQUAL(testValue1, "TestValue");
}
