// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/12 21:20)

#include "FontInformationTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/FontInformation.h"

using namespace std::literals;

namespace Framework
{
	using TestingType = FontInformation;
}

Framework::FontInformationTesting
	::FontInformationTesting(const OStreamShared& stream, HWnd hwnd)
	:ParentType{ stream }, m_Hwnd{ hwnd }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
} 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, FontInformationTesting)

void Framework::FontInformationTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::FontInformationTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(WindowFontInformationTest);
	ASSERT_NOT_THROW_EXCEPTION_0(GlutFontInformationTest);
}

void Framework::FontInformationTesting
	::WindowFontInformationTest()
{
	TestingType fontInformation1{ m_Hwnd };

	auto testText = SYSTEM_TEXT("TestText"s);
	const auto size = boost::numeric_cast<int>(testText.size());

	ASSERT_TRUE(size < fontInformation1.GetStringWidth(testText));
	ASSERT_TRUE(0 < fontInformation1.GetCharacterWidth(SYSTEM_TEXT('A')));
	ASSERT_TRUE(fontInformation1.GetCharacterWidth(SYSTEM_TEXT('T')) < fontInformation1.GetStringWidth(testText));
	ASSERT_TRUE(0 < fontInformation1.GetFontHeight());

	TestingType fontInformation2{ PlatformTypes::Window };

	ASSERT_TRUE(size < fontInformation2.GetStringWidth(testText));
	ASSERT_TRUE(0 < fontInformation2.GetCharacterWidth(SYSTEM_TEXT('B')));
	ASSERT_TRUE(fontInformation2.GetCharacterWidth(SYSTEM_TEXT('T')) < fontInformation2.GetStringWidth(testText));
	ASSERT_TRUE(0 < fontInformation2.GetFontHeight());

	ASSERT_EQUAL(fontInformation1.GetStringWidth(testText), fontInformation2.GetStringWidth(testText));
	ASSERT_EQUAL(fontInformation1.GetCharacterWidth('C'), fontInformation2.GetCharacterWidth('C'));
	ASSERT_EQUAL(fontInformation1.GetFontHeight(), fontInformation2.GetFontHeight());
}

void Framework::FontInformationTesting
	::GlutFontInformationTest()
{
	TestingType fontInformation{ PlatformTypes::Glut };

	auto testText = SYSTEM_TEXT("TestText"s);
	const auto size = boost::numeric_cast<int>(testText.size());

	ASSERT_TRUE(size < fontInformation.GetStringWidth(testText));
	ASSERT_TRUE(0 < fontInformation.GetCharacterWidth(SYSTEM_TEXT('A')));
	ASSERT_TRUE(0 < fontInformation.GetFontHeight());	
	ASSERT_EQUAL(fontInformation.GetCharacterWidth(SYSTEM_TEXT('T')) * size, fontInformation.GetStringWidth(testText));
}


