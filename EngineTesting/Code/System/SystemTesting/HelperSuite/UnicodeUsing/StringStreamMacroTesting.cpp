///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/17 0:22)

#include "StringStreamMacroTesting.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <iostream>
#include <sstream>
#include <string>

System::StringStreamMacroTesting::StringStreamMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, StringStreamMacroTesting)

void System::StringStreamMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::StringStreamMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PrintTipsMessage);

    ASSERT_NOT_THROW_EXCEPTION_0(StringStreamMacroTest);
}

void System::StringStreamMacroTesting::StringStreamMacroTest()
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

void System::StringStreamMacroTesting::PrintTipsMessage()
{
    GetStream() << "���������Ҫ����̨���롣\n";

    SystemPause();
}
