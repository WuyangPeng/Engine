/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 21:33)

#include "StringConversionTesting.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::StringConversionTesting::StringConversionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StringConversionTesting)

void CoreTools::StringConversionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::StringConversionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MultiByteConversionWideCharTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChineseMultiByteConversionWideCharTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WideCharConversionMultiByteTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChineseWideCharConversionMultiByteTest);

    ASSERT_NOT_THROW_EXCEPTION_0(StandardConversionWideCharTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChineseStandardConversionWideCharTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StandardConversionMultiByteTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChineseStandardConversionMultiByteTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultiByteConversionStandardTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChineseMultiByteConversionStandardTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WideCharConversionStandardTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChineseWideCharConversionStandardTest);

    ASSERT_NOT_THROW_EXCEPTION_0(StandardConversionDynamicLinkStringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChineseStandardConversionDynamicLinkStringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicLinkStringConversionMultiByteTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChineseDynamicLinkStringConversionMultiByteTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicLinkStringConversionStandardTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChineseDynamicLinkStringConversionStandardTest);

    ASSERT_NOT_THROW_EXCEPTION_0(StandardConversionCFileStringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChineseStandardConversionCFileStringTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Utf8ConversionWideCharTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChineseUtf8ConversionWideCharTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Utf8ConversionStandardTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChineseUtf8ConversionStandardTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Utf8ConversionMultiByteTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChineseUtf8ConversionMultiByteTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WideCharUtf8ConversionStandardTest);
}

void CoreTools::StringConversionTesting::MultiByteConversionWideCharTest()
{
    const auto wideChar = StringConversion::MultiByteConversionWideChar("Converted MultiByte to WideChar"s);
    ASSERT_EQUAL(wideChar, L"Converted MultiByte to WideChar"s);
}

void CoreTools::StringConversionTesting::ChineseMultiByteConversionWideCharTest()
{
    const auto wideChar = StringConversion::MultiByteConversionWideChar("MultiByte字符串转换为WideChar字符串"s);
    ASSERT_EQUAL(wideChar, L"MultiByte字符串转换为WideChar字符串"s);
}

void CoreTools::StringConversionTesting::WideCharConversionMultiByteTest()
{
    const auto multiByte = StringConversion::WideCharConversionMultiByte(L"Converted WideChar to MultiByte"s);
    ASSERT_EQUAL(multiByte, "Converted WideChar to MultiByte"s);
}

void CoreTools::StringConversionTesting::ChineseWideCharConversionMultiByteTest()
{
    const auto multiByte = StringConversion::WideCharConversionMultiByte(L"WideChar字符串转换为MultiByte字符串"s);
    ASSERT_EQUAL(multiByte, "WideChar字符串转换为MultiByte字符串"s);
}

void CoreTools::StringConversionTesting::StandardConversionWideCharTest()
{
    const auto wideChar = StringConversion::StandardConversionWideChar(SYSTEM_TEXT("Converted Standard to WideChar"s));
    ASSERT_EQUAL(wideChar, L"Converted Standard to WideChar"s);
}

void CoreTools::StringConversionTesting::ChineseStandardConversionWideCharTest()
{
    const auto wideChar = StringConversion::StandardConversionWideChar(SYSTEM_TEXT("标准字符串转换为WideChar字符串"s));
    ASSERT_EQUAL(wideChar, L"标准字符串转换为WideChar字符串"s);
}

void CoreTools::StringConversionTesting::StandardConversionMultiByteTest()
{
    const auto multiByte = StringConversion::StandardConversionMultiByte(SYSTEM_TEXT("Converted Standard to MultiByte"s));
    ASSERT_EQUAL(multiByte, "Converted Standard to MultiByte"s);
}

void CoreTools::StringConversionTesting::ChineseStandardConversionMultiByteTest()
{
    const auto multiByte = StringConversion::StandardConversionMultiByte(SYSTEM_TEXT("标准字符串转换为MultiByte字符串"s));
    ASSERT_EQUAL(multiByte, "标准字符串转换为MultiByte字符串"s);
}

void CoreTools::StringConversionTesting::MultiByteConversionStandardTest()
{
    const auto standard = StringConversion::MultiByteConversionStandard("Converted MultiByte to Standard"s);
    ASSERT_EQUAL(standard, SYSTEM_TEXT("Converted MultiByte to Standard"s));
}

void CoreTools::StringConversionTesting::ChineseMultiByteConversionStandardTest()
{
    const auto standard = StringConversion::MultiByteConversionStandard("MultiByte字符串转换为标准字符串"s);
    ASSERT_EQUAL(standard, SYSTEM_TEXT("MultiByte字符串转换为标准字符串"s));
}

void CoreTools::StringConversionTesting::WideCharConversionStandardTest()
{
    const auto standard = StringConversion::WideCharConversionStandard(L"Converted WideChar to Standard"s);
    ASSERT_EQUAL(standard, SYSTEM_TEXT("Converted WideChar to Standard"s));
}

void CoreTools::StringConversionTesting::ChineseWideCharConversionStandardTest()
{
    const auto standard = StringConversion::WideCharConversionStandard(L"WideChar字符串转换为标准字符串"s);
    ASSERT_EQUAL(standard, SYSTEM_TEXT("WideChar字符串转换为标准字符串"s));
}

void CoreTools::StringConversionTesting::StandardConversionDynamicLinkStringTest()
{
    const auto dynamicLinkString = StringConversion::StandardConversionDynamicLinkString(SYSTEM_TEXT("Converted Standard to DynamicLink"s));
    ASSERT_EQUAL(dynamicLinkString, DYNAMIC_LINK_TEXT("Converted Standard to DynamicLink"s));
}

void CoreTools::StringConversionTesting::ChineseStandardConversionDynamicLinkStringTest()
{
    const auto dynamicLinkString = StringConversion::StandardConversionDynamicLinkString(SYSTEM_TEXT("标准字符串转换为DynamicLink字符串"s));
    ASSERT_EQUAL(dynamicLinkString, DYNAMIC_LINK_TEXT("标准字符串转换为DynamicLink字符串"s));
}

void CoreTools::StringConversionTesting::DynamicLinkStringConversionMultiByteTest()
{
    const auto multiByte = StringConversion::DynamicLinkStringConversionMultiByte(DYNAMIC_LINK_TEXT("Converted DynamicLink to MultiByte"s));
    ASSERT_EQUAL(multiByte, "Converted DynamicLink to MultiByte"s);
}

void CoreTools::StringConversionTesting::ChineseDynamicLinkStringConversionMultiByteTest()
{
    const auto multiByte = StringConversion::DynamicLinkStringConversionMultiByte(SYSTEM_TEXT("DynamicLink转换为MultiByte字符串"s));
    ASSERT_EQUAL(multiByte, "DynamicLink转换为MultiByte字符串"s);
}

void CoreTools::StringConversionTesting::DynamicLinkStringConversionStandardTest()
{
    const auto standard = StringConversion::DynamicLinkStringConversionStandard(DYNAMIC_LINK_TEXT("Converted DynamicLink to Standard"s));
    ASSERT_EQUAL(standard, SYSTEM_TEXT("Converted DynamicLink to Standard"s));
}

void CoreTools::StringConversionTesting::ChineseDynamicLinkStringConversionStandardTest()
{
    const auto standard = StringConversion::DynamicLinkStringConversionStandard(SYSTEM_TEXT("DynamicLink字符串转换为标准字符串"s));
    ASSERT_EQUAL(standard, SYSTEM_TEXT("DynamicLink字符串转换为标准字符串"s));
}

void CoreTools::StringConversionTesting::StandardConversionCFileStringTest()
{
    const auto cFile = StringConversion::StandardConversionCFileString(SYSTEM_TEXT("Converted Standard to CFile"s));
    ASSERT_EQUAL(cFile, SYSTEM_FILE_TEXT("Converted Standard to CFile"s));
}

void CoreTools::StringConversionTesting::ChineseStandardConversionCFileStringTest()
{
    const auto cFile = StringConversion::StandardConversionCFileString(SYSTEM_TEXT("标准字符串转换为CFile字符串"s));
    ASSERT_EQUAL(cFile, SYSTEM_FILE_TEXT("标准字符串转换为CFile字符串"s));
}

void CoreTools::StringConversionTesting::Utf8ConversionWideCharTest()
{
    const auto original = L"Converted WideChar to UTF8"s;
    const auto uft8 = StringConversion::WideCharConversionUtf8(original);
    const auto wideChar = StringConversion::Utf8ConversionWideChar(uft8);
    ASSERT_EQUAL(wideChar, original);
}

void CoreTools::StringConversionTesting::ChineseUtf8ConversionWideCharTest()
{
    const auto original = L"WideChar字符串转换为UTF8字符串"s;
    const auto uft8 = StringConversion::WideCharConversionUtf8(original);
    const auto wideChar = StringConversion::Utf8ConversionWideChar(uft8);
    ASSERT_EQUAL(wideChar, original);
}

void CoreTools::StringConversionTesting::Utf8ConversionStandardTest()
{
    const auto original = SYSTEM_TEXT("Converted Standard to UTF8"s);
    const auto uft8 = StringConversion::StandardConversionUtf8(original);
    const auto standard = StringConversion::Utf8ConversionStandard(uft8);
    ASSERT_EQUAL(standard, original);
}

void CoreTools::StringConversionTesting::ChineseUtf8ConversionStandardTest()
{
    const auto original = SYSTEM_TEXT("标准字符串转换为UTF8字符串"s);
    const auto uft8 = StringConversion::StandardConversionUtf8(original);
    const auto standard = StringConversion::Utf8ConversionStandard(uft8);
    ASSERT_EQUAL(standard, original);
}

void CoreTools::StringConversionTesting::Utf8ConversionMultiByteTest()
{
    const auto original = "Converted MultiByte to UTF8"s;
    const auto uft8 = StringConversion::MultiByteConversionUtf8(original);
    const auto multiByte = StringConversion::Utf8ConversionMultiByte(uft8);
    ASSERT_EQUAL(multiByte, original);
}

void CoreTools::StringConversionTesting::ChineseUtf8ConversionMultiByteTest()
{
    const auto original = "MultiByte字符串转换为UTF8字符串"s;
    const auto uft8 = StringConversion::MultiByteConversionUtf8(original);
    const auto multiByte = StringConversion::Utf8ConversionMultiByte(uft8);
    ASSERT_EQUAL(multiByte, original);
}

void CoreTools::StringConversionTesting::WideCharUtf8ConversionStandardTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WideCharUtf8ConversionStandardEnglishTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WideCharUtf8ConversionStandardChineseTest);
}

void CoreTools::StringConversionTesting::WideCharUtf8ConversionStandardEnglishTest()
{
    const auto original = "Converted WideCharUTF8 to Standard"s;
    const auto uft8 = StringConversion::MultiByteConversionUtf8(original);
    const auto wideCharUft8 = StringUtility::ConvertNarrowToWide(uft8);
    const auto standard = StringConversion::Utf8ConversionStandard(wideCharUft8);

    ASSERT_EQUAL(standard, SYSTEM_TEXT("Converted WideCharUTF8 to Standard"s));
}

void CoreTools::StringConversionTesting::WideCharUtf8ConversionStandardChineseTest()
{
    const auto original = "WideCharUTF8字符串转换为标准字符串"s;
    const auto uft8 = StringConversion::MultiByteConversionUtf8(original);
    const auto wideCharUft8 = StringUtility::ConvertNarrowToWide(uft8);
    const auto standard = StringConversion::Utf8ConversionStandard(wideCharUft8);

    ASSERT_EQUAL(standard, SYSTEM_TEXT("WideCharUTF8字符串转换为标准字符串"s));
}