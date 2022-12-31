///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/03 21:55)

#include "ReadAttributeTesting.h"
#include "System/Console/ConsoleColours.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/Using/ConsoleColoursUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ReadAttributeTesting::ReadAttributeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ReadAttributeTesting)

void System::ReadAttributeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ReadAttributeTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::ReadAttributeTesting::RandomShuffleFlags()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffleConsoleFlags);

    ASSERT_NOT_THROW_EXCEPTION_0(ReadAttributeTest);

    return true;
}

void System::ReadAttributeTesting::ReadAttributeTest()
{
    for (auto standardHandle : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoReadAttributeTest, standardHandle);
    }
}

void System::ReadAttributeTesting::DoReadAttributeTest(StandardHandle standardHandle)
{
    AttributeType attribute{};
    constexpr ConsoleCoord readCoord{ 0, 0 };

    const auto consoleHandle = GetStandardHandle(standardHandle);

    WindowsDWord numberOfAttributesRead{ 0 };
    ASSERT_TRUE(ReadSystemConsoleOutputAttribute(consoleHandle, attribute.data(), bufferSize, readCoord, &numberOfAttributesRead));

    ASSERT_EQUAL(numberOfAttributesRead, bufferSize);

    ASSERT_NOT_THROW_EXCEPTION_1(AttributeResultTest, attribute);
}

void System::ReadAttributeTesting::AttributeResultTest(AttributeType attribute)
{
    for (auto word : attribute)
    {
        // ����TextColour��BackgroundColour��ConsoleCommonö�ٵ�ʵ��ֵ��ռ��λ�ó�0x000F��0x00F0��0xFF00��ֵ��
        ASSERT_TRUE(HasTextColour(UnderlyingCastEnum<TextColour>(word & textColourMask)));
        ASSERT_TRUE(HasBackgroundColour(UnderlyingCastEnum<BackgroundColour>(word & backgroundColourMask)));
        ASSERT_TRUE(HasConsoleCommon(UnderlyingCastEnum<ConsoleCommon>(word & consoleCommonMask)));
    }
}
