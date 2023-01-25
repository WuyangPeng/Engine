///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/03 20:55)

#include "FillAttributeTesting.h"
#include "System/Console/ConsoleColours.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FillAttributeTesting::FillAttributeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FillAttributeTesting)

void System::FillAttributeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FillAttributeTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::FillAttributeTesting::RandomShuffleFlags()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffleConsoleFlags);

    ASSERT_NOT_THROW_EXCEPTION_0(FillAttributeTest);

    return true;
}

void System::FillAttributeTesting::FillAttributeTest()
{
    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoFillAttributeTest, index);
    }
}

void System::FillAttributeTesting::PrintTipsMessage()
{
    GetStream() << "������Իᵼ�¿���̨��ǰ512�ֽڱ����Ϊĳ����ɫ��\n";

    SystemPause();
}

void System::FillAttributeTesting::DoFillAttributeTest(size_t index)
{
    const auto standardHandle = GetConsoleStandardHandle(index);
    const auto consoleHandle = GetStandardHandle(standardHandle);
    const auto textColour = GetTextColour(index);
    const auto backgroundColour = GetBackgroundColour(index);
    const auto consoleCommon = GetConsoleCommon(index);
    const auto writeAttribute = boost::numeric_cast<WindowsWord>(EnumCastUnderlying(textColour) |
                                                                 EnumCastUnderlying(backgroundColour) |
                                                                 EnumCastUnderlying(consoleCommon));

    constexpr ConsoleCoord coord{ 0, 0 };
    AttributeType readAttribute{};

    WindowsDWord numberOfAttributesWrite{ 0 };
    ASSERT_TRUE(FillSystemConsoleOutputAttribute(consoleHandle, writeAttribute, bufferSize, coord, &numberOfAttributesWrite));

    ASSERT_EQUAL(numberOfAttributesWrite, bufferSize);

    WindowsDWord numberOfAttributesRead{ 0 };
    ASSERT_TRUE(ReadSystemConsoleOutputAttribute(consoleHandle, readAttribute.data(), bufferSize, coord, &numberOfAttributesRead));

    ASSERT_NOT_THROW_EXCEPTION_2(FillAttributeResultTest, readAttribute, writeAttribute);
}

void System::FillAttributeTesting::FillAttributeResultTest(const AttributeType& readAttributes, WindowsWord writeAttribute)
{
    for (auto readAttribute : readAttributes)
    {
        ASSERT_NOT_THROW_EXCEPTION_3(ColourEqualTest, readAttribute, writeAttribute, textColourMask);
        ASSERT_NOT_THROW_EXCEPTION_3(ColourEqualTest, readAttribute, writeAttribute, backgroundColourMask);
    }
}
