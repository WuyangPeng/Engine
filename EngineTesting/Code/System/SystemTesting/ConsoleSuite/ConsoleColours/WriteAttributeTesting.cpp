///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/03 23:27)

#include "WriteAttributeTesting.h"
#include "System/Console/ConsoleColours.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/Using/ConsoleColoursUsing.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WriteAttributeTesting::WriteAttributeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WriteAttributeTesting)

void System::WriteAttributeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WriteAttributeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PrintTipsMessage);

    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::WriteAttributeTesting::RandomShuffleFlags()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffleConsoleFlags);

    ASSERT_NOT_THROW_EXCEPTION_0(WriteAttributeTest);

    return true;
}

void System::WriteAttributeTesting::PrintTipsMessage()
{
    GetStream() << "这个测试会导致控制台的前512字节被填充为各种颜色。\n";

    SystemPause();
}

void System::WriteAttributeTesting::WriteAttributeTest()
{
    for (auto standardHandle : *this)
    {
        const auto consoleHandle = GetStandardHandle(standardHandle);

        ASSERT_NOT_THROW_EXCEPTION_1(DoWriteAttributeTest, consoleHandle);
    }
}

void System::WriteAttributeTesting::DoWriteAttributeTest(WindowsHandle consoleHandle)
{
    constexpr ConsoleCoord coord{ 0, 0 };
    const auto writeAttribute = GetWriteAttribute();

    WindowsDWord numberOfAttributesWrite{ 0 };
    ASSERT_TRUE(WriteSystemConsoleOutputAttribute(consoleHandle, writeAttribute.data(), bufferSize, coord, &numberOfAttributesWrite));

    ASSERT_EQUAL(numberOfAttributesWrite, writeAttribute.size());

    AttributeType readAttribute{};
    WindowsDWord numberOfAttributesRead{ 0 };
    ASSERT_TRUE(ReadSystemConsoleOutputAttribute(consoleHandle, readAttribute.data(), bufferSize, coord, &numberOfAttributesRead));

    ReadAttributeTest(readAttribute, writeAttribute);
}

System::WriteAttributeTesting::AttributeType System::WriteAttributeTesting::GetWriteAttribute()
{
    AttributeType writeAttribute{};

    for (auto index = 0u; index < bufferSize; ++index)
    {
        const auto textColour = GetTextColour(index);
        const auto backgroundColour = GetBackgroundColour(index);
        const auto consoleCommon = GetConsoleCommon(index);
        writeAttribute.at(index) = boost::numeric_cast<WindowsWord>(EnumCastUnderlying(textColour) |
                                                                    EnumCastUnderlying(backgroundColour) |
                                                                    EnumCastUnderlying(consoleCommon));
    }

    return writeAttribute;
}

void System::WriteAttributeTesting::ReadAttributeTest(const AttributeType& readAttribute, const AttributeType& writeAttribute)
{
    for (auto index = 0u; index < bufferSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_3(ColourEqualTest, readAttribute.at(index), writeAttribute.at(index), textColourMask);
        ASSERT_NOT_THROW_EXCEPTION_3(ColourEqualTest, readAttribute.at(index), writeAttribute.at(index), backgroundColourMask);
    }
}
