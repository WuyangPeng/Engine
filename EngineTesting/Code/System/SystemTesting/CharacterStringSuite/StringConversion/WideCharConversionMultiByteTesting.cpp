///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/14 21:25)

#include "WideCharConversionMultiByteTesting.h"
#include "System/CharacterString/CodePage.h"
#include "System/CharacterString/Flags/StringConversionFlags.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;
using std::string;
using std::wstring;

System::WideCharConversionMultiByteTesting::WideCharConversionMultiByteTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WideCharConversionMultiByteTesting)

void System::WideCharConversionMultiByteTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WideCharConversionMultiByteTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WideCharToMultiByteTest);
    ASSERT_NOT_THROW_EXCEPTION_1(WideCharToMultiByteUseFlagTest, WideChar::NoFlags);
    ASSERT_NOT_THROW_EXCEPTION_1(WideCharToMultiByteUseFlagTest, WideChar::NoBestFitChars);
}

void System::WideCharConversionMultiByteTesting::WideCharToMultiByteTest()
{
    constexpr auto bufferSize = 256;
    const wstring wideCharInitial{ L"WideChar�ַ���ת��ΪMultiByte" };
    const string multiByteHelpResult{ "WideChar�ַ���ת��ΪMultiByte" };
    constexpr auto minLength = 30;  // Ӣ�İ�1�������㣬���İ�2�������㣬������ֹ����

    const auto multiByteLength = WideCharConversionMultiByte(wideCharInitial.c_str(), boost::numeric_cast<int>(wideCharInitial.size() + 1), nullptr, 0);

    ASSERT_TRUE_FAILURE_THROW(minLength <= multiByteLength && multiByteLength < bufferSize, "ת���ַ���ʧ�ܡ�");

    array<char, bufferSize> multiByte{};

    const auto multiByteResultLength = WideCharConversionMultiByte(wideCharInitial.c_str(), boost::numeric_cast<int>(wideCharInitial.size() + 1), multiByte.data(), multiByteLength);

    string multiByteResult{ multiByte.data() };
    ASSERT_EQUAL(multiByteResultLength, boost::numeric_cast<int>(multiByteResult.size() + 1));

    ASSERT_EQUAL(multiByteResult, multiByteHelpResult);
    ASSERT_EQUAL(multiByteResultLength, multiByteLength);
}

void System::WideCharConversionMultiByteTesting::WideCharToMultiByteUseFlagTest(WideChar wideChar)
{
    constexpr auto bufferSize = 256;
    const wstring wideCharInitial{ L"WideChar�ַ���ת��ΪMultiByte" };
    const string multiByteHelpResult{ "WideChar�ַ���ת��ΪMultiByte" };
    constexpr auto minLength = 30;  // Ӣ�İ�1�������㣬���İ�2�������㣬������ֹ����
    const auto codePage = GetANSICodePage();

    const string defaultChar{ "a" };
    auto usedDefaultChar = true;

    const auto multiByteLength = WideCharConversionMultiByte(codePage, wideChar, wideCharInitial.c_str(), boost::numeric_cast<int>(wideCharInitial.size() + 1), nullptr, 0, defaultChar.c_str(), &usedDefaultChar);

    ASSERT_EQUAL(usedDefaultChar, false);
    ASSERT_TRUE_FAILURE_THROW(minLength <= multiByteLength && multiByteLength < bufferSize, "ת���ַ���ʧ�ܡ�");

    array<char, bufferSize> multiByte{};

    const auto multiByteResultLength = WideCharConversionMultiByte(codePage,
                                                                   wideChar,
                                                                   wideCharInitial.c_str(),
                                                                   boost::numeric_cast<int>(wideCharInitial.size() + 1),
                                                                   multiByte.data(),
                                                                   multiByteLength,
                                                                   defaultChar.c_str(),
                                                                   &usedDefaultChar);

    ASSERT_EQUAL(usedDefaultChar, false);
    string multiByteResult{ multiByte.data() };
    ASSERT_EQUAL(multiByteResultLength, boost::numeric_cast<int>(multiByteResult.size() + 1));

    ASSERT_EQUAL(multiByteResult, multiByteHelpResult);
    ASSERT_EQUAL(multiByteResultLength, multiByteLength);
}
