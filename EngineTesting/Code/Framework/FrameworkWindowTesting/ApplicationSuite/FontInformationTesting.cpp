///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 15:54)

#include "FontInformationTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/Application/FontInformation.h"

using namespace std::literals;

Framework::FontInformationTesting::FontInformationTesting(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream }, hWnd{ hWnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, FontInformationTesting)

void Framework::FontInformationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::FontInformationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WindowFontInformationTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GlutFontInformationTest);
}

void Framework::FontInformationTesting::WindowFontInformationTest()
{
    const FontInformation fontInformation0{ hWnd };

    const auto testText = SYSTEM_TEXT("TestText"s);
    const auto size = boost::numeric_cast<int>(testText.size());

    ASSERT_TRUE(size < fontInformation0.GetStringWidth(testText));
    ASSERT_TRUE(0 < fontInformation0.GetCharacterWidth(SYSTEM_TEXT('A')));
    ASSERT_TRUE(fontInformation0.GetCharacterWidth(SYSTEM_TEXT('T')) < fontInformation0.GetStringWidth(testText));
    ASSERT_TRUE(0 < fontInformation0.GetFontHeight());

    const FontInformation fontInformation1{ PlatformTypes::Window };

    ASSERT_TRUE(size < fontInformation1.GetStringWidth(testText));
    ASSERT_TRUE(0 < fontInformation1.GetCharacterWidth(SYSTEM_TEXT('B')));
    ASSERT_TRUE(fontInformation1.GetCharacterWidth(SYSTEM_TEXT('T')) < fontInformation1.GetStringWidth(testText));
    ASSERT_TRUE(0 < fontInformation1.GetFontHeight());

    ASSERT_EQUAL(fontInformation0.GetStringWidth(testText), fontInformation1.GetStringWidth(testText));
    ASSERT_EQUAL(fontInformation0.GetCharacterWidth('C'), fontInformation1.GetCharacterWidth('C'));
    ASSERT_EQUAL(fontInformation0.GetFontHeight(), fontInformation1.GetFontHeight());
}

void Framework::FontInformationTesting::GlutFontInformationTest()
{
    const FontInformation fontInformation{ PlatformTypes::Glut };

    const auto testText = SYSTEM_TEXT("TestText"s);
    const auto size = boost::numeric_cast<int>(testText.size());

    ASSERT_TRUE(size < fontInformation.GetStringWidth(testText));
    ASSERT_TRUE(0 < fontInformation.GetCharacterWidth(SYSTEM_TEXT('A')));
    ASSERT_TRUE(0 < fontInformation.GetFontHeight());
    ASSERT_EQUAL(fontInformation.GetCharacterWidth(SYSTEM_TEXT('T')) * size, fontInformation.GetStringWidth(testText));
}
