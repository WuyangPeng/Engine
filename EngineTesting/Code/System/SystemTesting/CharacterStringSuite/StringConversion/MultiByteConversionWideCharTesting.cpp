///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 13:33)

#include "MultiByteConversionWideCharTesting.h"
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

System::MultiByteConversionWideCharTesting::MultiByteConversionWideCharTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MultiByteConversionWideCharTesting)

void System::MultiByteConversionWideCharTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MultiByteConversionWideCharTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MultiByteToWideCharTest);
    ASSERT_NOT_THROW_EXCEPTION_1(MultiByteToWideCharUseFlagTest, MultiByte::NoFlags);
    ASSERT_NOT_THROW_EXCEPTION_1(MultiByteToWideCharUseFlagTest, MultiByte::ErrInvalidChars);
}

void System::MultiByteConversionWideCharTesting::MultiByteToWideCharTest()
{
    constexpr auto bufferSize = 256;
    const string multiByteInitial{ "MultiByte�ַ���ת��ΪWideChar" };
    const wstring wideCharHelpResult{ L"MultiByte�ַ���ת��ΪWideChar" };
    constexpr auto minLength = 24;  // ����Ӣ�Ļ����Ķ���1�������㣬������ֹ����

    const auto wideCharLength = MultiByteConversionWideChar(multiByteInitial.c_str(), boost::numeric_cast<int>(multiByteInitial.size() + 1), nullptr, 0);

    ASSERT_TRUE_FAILURE_THROW(minLength <= wideCharLength && wideCharLength < bufferSize, "ת���ַ���ʧ�ܡ�");

    array<wchar_t, bufferSize> wideChar{};

    const auto wideCharResultLength = MultiByteConversionWideChar(multiByteInitial.c_str(), boost::numeric_cast<int>(multiByteInitial.size() + 1), wideChar.data(), wideCharLength);

    wstring wideCharResult{ wideChar.data() };
    ASSERT_EQUAL(wideCharResultLength, boost::numeric_cast<int>(wideCharResult.size() + 1));

    ASSERT_EQUAL(wideCharResult, wideCharHelpResult);
    ASSERT_EQUAL(wideCharResultLength, wideCharLength);
}

void System::MultiByteConversionWideCharTesting::MultiByteToWideCharUseFlagTest(MultiByte multiByte)
{
    constexpr auto bufferSize = 256;
    const string multiByteInitial{ "MultiByte�ַ���ת��ΪWideChar" };
    const wstring wideCharHelpResult{ L"MultiByte�ַ���ת��ΪWideChar" };
    constexpr auto minLength = 24;  // ����Ӣ�Ļ����Ķ���1�������㣬������ֹ����
    const auto codePage = GetANSICodePage();

    const auto wideCharLength = MultiByteConversionWideChar(codePage, multiByte, multiByteInitial.c_str(), boost::numeric_cast<int>(multiByteInitial.size() + 1), nullptr, 0);

    ASSERT_TRUE_FAILURE_THROW(minLength <= wideCharLength && wideCharLength < bufferSize, "ת���ַ���ʧ�ܡ�");

    array<wchar_t, bufferSize> wideChar{};

    const auto wideCharResultLength = MultiByteConversionWideChar(codePage, multiByte, multiByteInitial.c_str(), boost::numeric_cast<int>(multiByteInitial.size() + 1), wideChar.data(), wideCharLength);

    wstring wideCharResult{ wideChar.data() };
    ASSERT_EQUAL(wideCharResultLength, boost::numeric_cast<int>(wideCharResult.size() + 1));

    ASSERT_EQUAL(wideCharResult, wideCharHelpResult);
    ASSERT_EQUAL(wideCharResultLength, wideCharLength);
}
