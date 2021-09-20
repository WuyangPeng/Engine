///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/08 17:55)

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
