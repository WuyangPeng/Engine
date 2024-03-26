/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 18:28)

#include "WriteAttributeTesting.h"
#include "System/Console/ConsoleColour.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/Using/ConsoleColourUsing.h"
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
    GetStream() << "������Իᵼ�¿���̨��ǰ512�ֽڱ����Ϊ������ɫ��\n";

    SystemPause();
}

void System::WriteAttributeTesting::WriteAttributeTest()
{
    for (const auto standardHandle : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoWriteAttributeTest, standardHandle);
    }
}

void System::WriteAttributeTesting::DoWriteAttributeTest(StandardHandle standardHandle)
{
    const auto consoleHandle = GetStandardHandle(standardHandle);

    constexpr ConsoleCoord coord{ 0, 0 };
    const auto writeAttribute = GetWriteAttribute();

    WindowsDWord numberOfAttributesWrite{ 0 };
    ASSERT_TRUE(WriteSystemConsoleOutputAttribute(consoleHandle, writeAttribute.data(), defaultBufferSize, coord, &numberOfAttributesWrite));

    ASSERT_EQUAL(numberOfAttributesWrite, writeAttribute.size());

    AttributeType readAttribute{};
    WindowsDWord numberOfAttributesRead{ 0 };
    ASSERT_TRUE(ReadSystemConsoleOutputAttribute(consoleHandle, readAttribute.data(), defaultBufferSize, coord, &numberOfAttributesRead));

    ReadAttributeTest(readAttribute, writeAttribute);
}

System::WriteAttributeTesting::AttributeType System::WriteAttributeTesting::GetWriteAttribute() const
{
    AttributeType writeAttribute{};

    for (auto index = 0; index < defaultBufferSize; ++index)
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
    for (auto index = 0; index < defaultBufferSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoReadAttributeTest, readAttribute.at(index), writeAttribute.at(index));
    }
}

void System::WriteAttributeTesting::DoReadAttributeTest(WindowsWord readAttribute, WindowsWord writeAttribute)
{
    ASSERT_NOT_THROW_EXCEPTION_3(ColourEqualTest, readAttribute, writeAttribute, textColourMask);
    ASSERT_NOT_THROW_EXCEPTION_3(ColourEqualTest, readAttribute, writeAttribute, backgroundColourMask);
}
