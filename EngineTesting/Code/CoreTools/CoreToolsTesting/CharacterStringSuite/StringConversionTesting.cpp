///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.2 (2021/08/30 14:04)

#include "StringConversionTesting.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::string;
using std::wstring;
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

    ASSERT_NOT_THROW_EXCEPTION_0(UTF8ConversionWideCharTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UTF8ConversionStandardTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UTF8ConversionMultiByteTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WideCharUTF8ConversionStandardTest);

    ASSERT_NOT_THROW_EXCEPTION_0(ToFirstLetterUpperTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ToFirstLetterLowerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ToUpperMacroTest);
}

void CoreTools::StringConversionTesting::MultiByteConversionWideCharTest()
{
    const auto wideChar0 = StringConversion::MultiByteConversionWideChar("Converted MultiByte to WideChar"s);

    ASSERT_EQUAL(wideChar0, L"Converted MultiByte to WideChar"s);

    const auto wideChar1 = StringConversion::MultiByteConversionWideChar("MultiByte�ַ���ת��ΪWideChar�ַ���"s);

    ASSERT_EQUAL(wideChar1, L"MultiByte�ַ���ת��ΪWideChar�ַ���"s);
}

void CoreTools::StringConversionTesting::WideCharConversionMultiByteTest()
{
    const auto multiByte0 = StringConversion::WideCharConversionMultiByte(L"Converted WideChar to MultiByte"s);

    ASSERT_EQUAL(multiByte0, "Converted WideChar to MultiByte"s);

    const auto multiByte1 = StringConversion::WideCharConversionMultiByte(L"WideChar�ַ���ת��ΪMultiByte�ַ���"s);

    ASSERT_EQUAL(multiByte1, "WideChar�ַ���ת��ΪMultiByte�ַ���"s);
}

void CoreTools::StringConversionTesting::StandardConversionWideCharTest()
{
    const auto wideChar0 = StringConversion::StandardConversionWideChar(SYSTEM_TEXT("Converted Standard to WideChar"s));

    ASSERT_EQUAL(wideChar0, L"Converted Standard to WideChar"s);

    const auto wideChar1 = StringConversion::StandardConversionWideChar(SYSTEM_TEXT("��׼�ַ���ת��ΪWideChar�ַ���"s));

    ASSERT_EQUAL(wideChar1, L"��׼�ַ���ת��ΪWideChar�ַ���"s);
}

void CoreTools::StringConversionTesting::StandardConversionMultiByteTest()
{
    const auto multiByte0 = StringConversion::StandardConversionMultiByte(SYSTEM_TEXT("Converted Standard to MultiByte"s));

    ASSERT_EQUAL(multiByte0, "Converted Standard to MultiByte"s);

    const auto multiByte1 = StringConversion::StandardConversionMultiByte(SYSTEM_TEXT("��׼�ַ���ת��ΪMultiByte�ַ���"s));

    ASSERT_EQUAL(multiByte1, "��׼�ַ���ת��ΪMultiByte�ַ���"s);
}

void CoreTools::StringConversionTesting::MultiByteConversionStandardTest()
{
    const auto standard0 = StringConversion::MultiByteConversionStandard("Converted MultiByte to Standard"s);

    ASSERT_EQUAL(standard0, SYSTEM_TEXT("Converted MultiByte to Standard"s));

    const auto standard1 = StringConversion::MultiByteConversionStandard("MultiByte�ַ���ת��Ϊ��׼�ַ���"s);

    ASSERT_EQUAL(standard1, SYSTEM_TEXT("MultiByte�ַ���ת��Ϊ��׼�ַ���"s));
}

void CoreTools::StringConversionTesting::WideCharConversionStandardTest()
{
    const auto standard0 = StringConversion::WideCharConversionStandard(L"Converted WideChar to Standard"s);

    ASSERT_EQUAL(standard0, SYSTEM_TEXT("Converted WideChar to Standard"s));

    const auto standard1 = StringConversion::WideCharConversionStandard(L"WideChar�ַ���ת��Ϊ��׼�ַ���"s);

    ASSERT_EQUAL(standard1, SYSTEM_TEXT("WideChar�ַ���ת��Ϊ��׼�ַ���"s));
}

void CoreTools::StringConversionTesting::StandardConversionDynamicLinkStringTest()
{
    const auto dynamicLinkString0 = StringConversion::StandardConversionDynamicLinkString(SYSTEM_TEXT("Converted Standard to DynamicLink"s));

    ASSERT_EQUAL(dynamicLinkString0, DYNAMIC_LINK_TEXT("Converted Standard to DynamicLink"s));

    const auto dynamicLinkString1 = StringConversion::StandardConversionDynamicLinkString(SYSTEM_TEXT("��׼�ַ���ת��ΪDynamicLink�ַ���"s));

    ASSERT_EQUAL(dynamicLinkString1, DYNAMIC_LINK_TEXT("��׼�ַ���ת��ΪDynamicLink�ַ���"s));
}

void CoreTools::StringConversionTesting::DynamicLinkStringConversionMultiByteTest()
{
    const auto multiByte0 = StringConversion::DynamicLinkStringConversionMultiByte(DYNAMIC_LINK_TEXT("Converted DynamicLink to MultiByte"s));

    ASSERT_EQUAL(multiByte0, "Converted DynamicLink to MultiByte"s);

    const auto multiByte1 = StringConversion::DynamicLinkStringConversionMultiByte(SYSTEM_TEXT("DynamicLinkת��ΪMultiByte�ַ���"s));

    ASSERT_EQUAL(multiByte1, "DynamicLinkת��ΪMultiByte�ַ���"s);
}

void CoreTools::StringConversionTesting::DynamicLinkStringConversionStandardTest()
{
    const auto standard0 = StringConversion::DynamicLinkStringConversionStandard(DYNAMIC_LINK_TEXT("Converted DynamicLink to Standard"s));

    ASSERT_EQUAL(standard0, SYSTEM_TEXT("Converted DynamicLink to Standard"s));

    const auto standard1 = StringConversion::DynamicLinkStringConversionStandard(SYSTEM_TEXT("DynamicLink�ַ���ת��Ϊ��׼�ַ���"s));

    ASSERT_EQUAL(standard1, SYSTEM_TEXT("DynamicLink�ַ���ת��Ϊ��׼�ַ���"s));
}

void CoreTools::StringConversionTesting::StandardConversionCFileStringTest()
{
    const auto cFile0 = StringConversion::StandardConversionCFileString(SYSTEM_TEXT("Converted Standard to CFile"s));

    ASSERT_EQUAL(cFile0, SYSTEM_FILE_TEXT("Converted Standard to CFile"s));

    const auto cFile1 = StringConversion::StandardConversionCFileString(SYSTEM_TEXT("��׼�ַ���ת��ΪCFile�ַ���"s));

    ASSERT_EQUAL(cFile1, SYSTEM_FILE_TEXT("��׼�ַ���ת��ΪCFile�ַ���"s));
}

void CoreTools::StringConversionTesting::UTF8ConversionWideCharTest()
{
    const auto original0 = L"Converted WideChar to UTF8"s;
    const auto multiByte0 = StringConversion::WideCharConversionUTF8(original0);
    const auto wideChar0 = StringConversion::UTF8ConversionWideChar(multiByte0);
    ASSERT_EQUAL(wideChar0, original0);

    const auto original1 = L"WideChar�ַ���ת��ΪUTF8�ַ���"s;
    const auto multiByte1 = StringConversion::WideCharConversionUTF8(original1);
    const auto wideChar1 = StringConversion::UTF8ConversionWideChar(multiByte1);
    ASSERT_EQUAL(wideChar1, original1);
}

void CoreTools::StringConversionTesting::UTF8ConversionStandardTest()
{
    const auto original0 = SYSTEM_TEXT("Converted Standard to UTF8"s);
    const auto multiByte0 = StringConversion::StandardConversionUTF8(original0);
    const auto standard0 = StringConversion::UTF8ConversionStandard(multiByte0);
    ASSERT_EQUAL(standard0, original0);

    const auto original1 = SYSTEM_TEXT("��׼�ַ���ת��ΪUTF8�ַ���"s);
    const auto multiByte1 = StringConversion::StandardConversionUTF8(original1);
    const auto standard1 = StringConversion::UTF8ConversionStandard(multiByte1);
    ASSERT_EQUAL(standard1, original1);
}

void CoreTools::StringConversionTesting::UTF8ConversionMultiByteTest()
{
    const auto original0 = "Converted MultiByte to UTF8"s;
    const auto uft0 = StringConversion::MultiByteConversionUTF8(original0);
    const auto multiByte0 = StringConversion::UTF8ConversionMultiByte(uft0);
    ASSERT_EQUAL(multiByte0, original0);

    const auto original1 = "MultiByte�ַ���ת��ΪUTF8�ַ���"s;
    const auto uft1 = StringConversion::MultiByteConversionUTF8(original1);
    const auto multiByte1 = StringConversion::UTF8ConversionMultiByte(uft1);
    ASSERT_EQUAL(multiByte1, original1);
}

void CoreTools::StringConversionTesting::WideCharUTF8ConversionStandardTest()
{
    const auto original0 = "Converted WideCharUTF8 to Standard"s;
    const auto uft0 = StringConversion::MultiByteConversionUTF8(original0);
    wstring wideCharuft0{};
    for (auto c : uft0)
    {
        wideCharuft0 += c;
    }
    const auto standard0 = StringConversion::UTF8ConversionStandard(wideCharuft0);
    ASSERT_EQUAL(standard0, SYSTEM_TEXT("Converted WideCharUTF8 to Standard"s));

    const auto original1 = "WideCharUTF8�ַ���ת��Ϊ��׼�ַ���"s;
    const auto uft1 = StringConversion::MultiByteConversionUTF8(original1);
    wstring wideCharuft1{};
    for (auto c : uft1)
    {
        wideCharuft1 += c;
    }
    const auto standard1 = StringConversion::UTF8ConversionStandard(wideCharuft1);
    ASSERT_EQUAL(standard1, SYSTEM_TEXT("WideCharUTF8�ַ���ת��Ϊ��׼�ַ���"s));
}

void CoreTools::StringConversionTesting::ToFirstLetterUpperTest()
{
    ASSERT_EQUAL(StringConversion::ToFirstLetterUpper(SYSTEM_TEXT("AuAu"s)), SYSTEM_TEXT("AuAu"s));
    ASSERT_EQUAL(StringConversion::ToFirstLetterUpper(SYSTEM_TEXT("auAu"s)), SYSTEM_TEXT("AuAu"s));
    ASSERT_EQUAL(StringConversion::ToFirstLetterUpper(SYSTEM_TEXT(" auAu"s)), SYSTEM_TEXT(" auAu"s));
}

void CoreTools::StringConversionTesting::ToFirstLetterLowerTest()
{
    ASSERT_EQUAL(StringConversion::ToFirstLetterLower(SYSTEM_TEXT("AuAu"s)), SYSTEM_TEXT("auAu"s));
    ASSERT_EQUAL(StringConversion::ToFirstLetterLower(SYSTEM_TEXT("auAu"s)), SYSTEM_TEXT("auAu"s));
    ASSERT_EQUAL(StringConversion::ToFirstLetterLower(SYSTEM_TEXT(" AuAu"s)), SYSTEM_TEXT(" AuAu"s));
}

void CoreTools::StringConversionTesting::ToUpperMacroTest()
{
    ASSERT_EQUAL(StringConversion::ToUpperMacro(SYSTEM_TEXT("AuAu"s)), SYSTEM_TEXT("AU_AU"s));
    ASSERT_EQUAL(StringConversion::ToUpperMacro(SYSTEM_TEXT("auAu"s)), SYSTEM_TEXT("AU_AU"s));
    ASSERT_EQUAL(StringConversion::ToUpperMacro(SYSTEM_TEXT(" AuAu"s)), SYSTEM_TEXT("AU_AU"s));
    ASSERT_EQUAL(StringConversion::ToUpperMacro(SYSTEM_TEXT(" Au_Au"s)), SYSTEM_TEXT("AU__AU"s));
    ASSERT_EQUAL(StringConversion::ToUpperMacro(SYSTEM_TEXT("Au_uu"s)), SYSTEM_TEXT("AU_UU"s));
}
