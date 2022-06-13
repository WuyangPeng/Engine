///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 1:12)

#include "UnicodeUsingTesting.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std::literals;

System::UnicodeUsingTesting::UnicodeUsingTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, UnicodeUsingTesting)

void System::UnicodeUsingTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::UnicodeUsingTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StringStreamMacroTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileStreamMacroTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ToStringTest);
}

void System::UnicodeUsingTesting::StringStreamMacroTest()
{
    OStringStream testOStringStream{};
    testOStringStream << SYSTEM_TEXT("������һ�в������ݣ�");

    OStream& testOStream{ COUT };
    testOStream << testOStringStream.str();

    IStream& testIStream{ CIN };
    String testString{};
    testIStream >> testString;

    const StringView stringView{ testString };

    StringStream testStringStream{};
    Stream& testStream{ testStringStream };
    testStringStream << SYSTEM_TEXT("������ʾ�ղ���������ݣ�");
    testStream << stringView << TChar{ '\n' };

    CERR << testStringStream.str();

    IStringStream testIStringStream{ testStringStream.str() };

    testIStringStream >> testString;

    CLOG << testString << TChar{ '\n' };
}

void System::UnicodeUsingTesting::FileStreamMacroTest()
{
    FileStream testFStream{ "Resource/UnicodeMacroTesting/UnicodeMacroFStreamTest.txt" };
    OFileStream testOFStream{ "Resource/UnicodeMacroTesting/UnicodeMacroOFStreamTest.txt" };
    IFileStream testIFStream{ "Resource/UnicodeMacroTesting/UnicodeMacroIFStreamTest.txt" };

    ASSERT_TRUE(testFStream && testOFStream && testIFStream);
}

void System::UnicodeUsingTesting::ToStringTest()
{
    const auto value = ToString(2);

    ASSERT_EQUAL(value, SYSTEM_TEXT("2"s));
}
