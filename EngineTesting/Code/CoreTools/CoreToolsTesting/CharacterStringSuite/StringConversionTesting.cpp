///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	°æ±¾£º0.9.1.5 (2023/10/24 17:27)

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
    ASSERT_NOT_THROW_EXCEPTION_0(WideCharConversionMultiByteTest);

    ASSERT_NOT_THROW_EXCEPTION_0(StandardConversionWideCharTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StandardConversionMultiByteTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultiByteConversionStandardTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WideCharConversionStandardTest);

    ASSERT_NOT_THROW_EXCEPTION_0(StandardConversionDynamicLinkStringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicLinkStringConversionMultiByteTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicLinkStringConversionStandardTest);

    ASSERT_NOT_THROW_EXCEPTION_0(StandardConversionCFileStringTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Utf8ConversionWideCharTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Utf8ConversionStandardTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Utf8ConversionMultiByteTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WideCharUtf8ConversionStandardTest);
}

void CoreTools::StringConversionTesting::MultiByteConversionWideCharTest()
{
    const auto wideChar0 = StringConversion::MultiByteConversionWideChar("Converted MultiByte to WideChar"s);

    ASSERT_EQUAL(wideChar0, L"Converted MultiByte to WideChar"s);

    const auto wideChar1 = StringConversion::MultiByteConversionWideChar("MultiByte×Ö·û´®×ª»»ÎªWideChar×Ö·û´®"s);

    ASSERT_EQUAL(wideChar1, L"MultiByte×Ö·û´®×ª»»ÎªWideChar×Ö·û´®"s);
}

void CoreTools::StringConversionTesting::WideCharConversionMultiByteTest()
{
    const auto multiByte0 = StringConversion::WideCharConversionMultiByte(L"Converted WideChar to MultiByte"s);

    ASSERT_EQUAL(multiByte0, "Converted WideChar to MultiByte"s);

    const auto multiByte1 = StringConversion::WideCharConversionMultiByte(L"WideChar×Ö·û´®×ª»»ÎªMultiByte×Ö·û´®"s);

    ASSERT_EQUAL(multiByte1, "WideChar×Ö·û´®×ª»»ÎªMultiByte×Ö·û´®"s);
}

void CoreTools::StringConversionTesting::StandardConversionWideCharTest()
{
    const auto wideChar0 = StringConversion::StandardConversionWideChar(SYSTEM_TEXT("Converted Standard to WideChar"s));

    ASSERT_EQUAL(wideChar0, L"Converted Standard to WideChar"s);

    const auto wideChar1 = StringConversion::StandardConversionWideChar(SYSTEM_TEXT("±ê×¼×Ö·û´®×ª»»ÎªWideChar×Ö·û´®"s));

    ASSERT_EQUAL(wideChar1, L"±ê×¼×Ö·û´®×ª»»ÎªWideChar×Ö·û´®"s);
}

void CoreTools::StringConversionTesting::StandardConversionMultiByteTest()
{
    const auto multiByte0 = StringConversion::StandardConversionMultiByte(SYSTEM_TEXT("Converted Standard to MultiByte"s));

    ASSERT_EQUAL(multiByte0, "Converted Standard to MultiByte"s);

    const auto multiByte1 = StringConversion::StandardConversionMultiByte(SYSTEM_TEXT("±ê×¼×Ö·û´®×ª»»ÎªMultiByte×Ö·û´®"s));

    ASSERT_EQUAL(multiByte1, "±ê×¼×Ö·û´®×ª»»ÎªMultiByte×Ö·û´®"s);
}

void CoreTools::StringConversionTesting::MultiByteConversionStandardTest()
{
    const auto standard0 = StringConversion::MultiByteConversionStandard("Converted MultiByte to Standard"s);

    ASSERT_EQUAL(standard0, SYSTEM_TEXT("Converted MultiByte to Standard"s));

    const auto standard1 = StringConversion::MultiByteConversionStandard("MultiByte×Ö·û´®×ª»»Îª±ê×¼×Ö·û´®"s);

    ASSERT_EQUAL(standard1, SYSTEM_TEXT("MultiByte×Ö·û´®×ª»»Îª±ê×¼×Ö·û´®"s));
}

void CoreTools::StringConversionTesting::WideCharConversionStandardTest()
{
    const auto standard0 = StringConversion::WideCharConversionStandard(L"Converted WideChar to Standard"s);

    ASSERT_EQUAL(standard0, SYSTEM_TEXT("Converted WideChar to Standard"s));

    const auto standard1 = StringConversion::WideCharConversionStandard(L"WideChar×Ö·û´®×ª»»Îª±ê×¼×Ö·û´®"s);

    ASSERT_EQUAL(standard1, SYSTEM_TEXT("WideChar×Ö·û´®×ª»»Îª±ê×¼×Ö·û´®"s));
}

void CoreTools::StringConversionTesting::StandardConversionDynamicLinkStringTest()
{
    const auto dynamicLinkString0 = StringConversion::StandardConversionDynamicLinkString(SYSTEM_TEXT("Converted Standard to DynamicLink"s));

    ASSERT_EQUAL(dynamicLinkString0, DYNAMIC_LINK_TEXT("Converted Standard to DynamicLink"s));

    const auto dynamicLinkString1 = StringConversion::StandardConversionDynamicLinkString(SYSTEM_TEXT("±ê×¼×Ö·û´®×ª»»ÎªDynamicLink×Ö·û´®"s));

    ASSERT_EQUAL(dynamicLinkString1, DYNAMIC_LINK_TEXT("±ê×¼×Ö·û´®×ª»»ÎªDynamicLink×Ö·û´®"s));
}

void CoreTools::StringConversionTesting::DynamicLinkStringConversionMultiByteTest()
{
    const auto multiByte0 = StringConversion::DynamicLinkStringConversionMultiByte(DYNAMIC_LINK_TEXT("Converted DynamicLink to MultiByte"s));

    ASSERT_EQUAL(multiByte0, "Converted DynamicLink to MultiByte"s);

    const auto multiByte1 = StringConversion::DynamicLinkStringConversionMultiByte(SYSTEM_TEXT("DynamicLink×ª»»ÎªMultiByte×Ö·û´®"s));

    ASSERT_EQUAL(multiByte1, "DynamicLink×ª»»ÎªMultiByte×Ö·û´®"s);
}

void CoreTools::StringConversionTesting::DynamicLinkStringConversionStandardTest()
{
    const auto standard0 = StringConversion::DynamicLinkStringConversionStandard(DYNAMIC_LINK_TEXT("Converted DynamicLink to Standard"s));

    ASSERT_EQUAL(standard0, SYSTEM_TEXT("Converted DynamicLink to Standard"s));

    const auto standard1 = StringConversion::DynamicLinkStringConversionStandard(SYSTEM_TEXT("DynamicLink×Ö·û´®×ª»»Îª±ê×¼×Ö·û´®"s));

    ASSERT_EQUAL(standard1, SYSTEM_TEXT("DynamicLink×Ö·û´®×ª»»Îª±ê×¼×Ö·û´®"s));
}

void CoreTools::StringConversionTesting::StandardConversionCFileStringTest()
{
    const auto cFile0 = StringConversion::StandardConversionCFileString(SYSTEM_TEXT("Converted Standard to CFile"s));

    ASSERT_EQUAL(cFile0, SYSTEM_FILE_TEXT("Converted Standard to CFile"s));

    const auto cFile1 = StringConversion::StandardConversionCFileString(SYSTEM_TEXT("±ê×¼×Ö·û´®×ª»»ÎªCFile×Ö·û´®"s));

    ASSERT_EQUAL(cFile1, SYSTEM_FILE_TEXT("±ê×¼×Ö·û´®×ª»»ÎªCFile×Ö·û´®"s));
}

void CoreTools::StringConversionTesting::Utf8ConversionWideCharTest()
{
    const auto original0 = L"Converted WideChar to UTF8"s;
    const auto multiByte0 = StringConversion::WideCharConversionUtf8(original0);
    const auto wideChar0 = StringConversion::Utf8ConversionWideChar(multiByte0);
    ASSERT_EQUAL(wideChar0, original0);

    const auto original1 = L"WideChar×Ö·û´®×ª»»ÎªUTF8×Ö·û´®"s;
    const auto multiByte1 = StringConversion::WideCharConversionUtf8(original1);
    const auto wideChar1 = StringConversion::Utf8ConversionWideChar(multiByte1);
    ASSERT_EQUAL(wideChar1, original1);
}

void CoreTools::StringConversionTesting::Utf8ConversionStandardTest()
{
    const auto original0 = SYSTEM_TEXT("Converted Standard to UTF8"s);
    const auto multiByte0 = StringConversion::StandardConversionUtf8(original0);
    const auto standard0 = StringConversion::Utf8ConversionStandard(multiByte0);
    ASSERT_EQUAL(standard0, original0);

    const auto original1 = SYSTEM_TEXT("±ê×¼×Ö·û´®×ª»»ÎªUTF8×Ö·û´®"s);
    const auto multiByte1 = StringConversion::StandardConversionUtf8(original1);
    const auto standard1 = StringConversion::Utf8ConversionStandard(multiByte1);
    ASSERT_EQUAL(standard1, original1);
}

void CoreTools::StringConversionTesting::Utf8ConversionMultiByteTest()
{
    const auto original0 = "Converted MultiByte to UTF8"s;
    const auto uft0 = StringConversion::MultiByteConversionUtf8(original0);
    const auto multiByte0 = StringConversion::Utf8ConversionMultiByte(uft0);
    ASSERT_EQUAL(multiByte0, original0);

    const auto original1 = "MultiByte×Ö·û´®×ª»»ÎªUTF8×Ö·û´®"s;
    const auto uft1 = StringConversion::MultiByteConversionUtf8(original1);
    const auto multiByte1 = StringConversion::Utf8ConversionMultiByte(uft1);
    ASSERT_EQUAL(multiByte1, original1);
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
    const auto original = "WideCharUTF8×Ö·û´®×ª»»Îª±ê×¼×Ö·û´®"s;
    const auto uft8 = StringConversion::MultiByteConversionUtf8(original);
    const auto wideCharUft8 = StringUtility::ConvertNarrowToWide(uft8);

    const auto standard = StringConversion::Utf8ConversionStandard(wideCharUft8);
    ASSERT_EQUAL(standard, SYSTEM_TEXT("WideCharUTF8×Ö·û´®×ª»»Îª±ê×¼×Ö·û´®"s));
}