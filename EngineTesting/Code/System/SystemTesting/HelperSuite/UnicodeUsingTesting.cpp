///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 1:12)

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
    testOStringStream << SYSTEM_TEXT("请输入一行测试数据：");

    OStream& testOStream{ COUT };
    testOStream << testOStringStream.str();

    IStream& testIStream{ CIN };
    String testString{};
    testIStream >> testString;

    const StringView stringView{ testString };

    StringStream testStringStream{};
    Stream& testStream{ testStringStream };
    testStringStream << SYSTEM_TEXT("这里显示刚才输入的数据：");
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
