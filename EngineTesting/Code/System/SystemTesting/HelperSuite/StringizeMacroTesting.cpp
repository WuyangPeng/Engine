///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 09:54)

#include "StringizeMacroTesting.h"
#include "System/Helper/StringizeMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>

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
    const std::string testValue{ SYSTEM_STRINGIZE(100TestValue) };

    ASSERT_EQUAL(testValue, "100TestValue");
}

void System::StringizeMacroTesting::ConcatenatorTest()
{
    const std::string SYSTEM_CONCATENATOR(test, Value){ "TestValue" };

    ASSERT_EQUAL(testValue, "TestValue");
}

void System::StringizeMacroTesting::MultipleConcatenatorTest()
{
    const std::string SYSTEM_MULTIPLE_CONCATENATOR(test, Value, 1){ "TestValue" };

    ASSERT_EQUAL(testValue1, "TestValue");
}
