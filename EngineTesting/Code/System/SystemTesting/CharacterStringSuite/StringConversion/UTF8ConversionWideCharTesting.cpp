///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/14 21:24)

#include "UTF8ConversionWideCharTesting.h"
#include "System/CharacterString/CodePage.h"
#include "System/CharacterString/Flags/StringConversionFlags.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>
#include <fstream>

using std::array;
using std::ifstream;
using std::string;
using std::stringstream;
using std::wstring;
using namespace std::literals;

System::UTF8ConversionWideCharTesting::UTF8ConversionWideCharTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, UTF8ConversionWideCharTesting)

void System::UTF8ConversionWideCharTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::UTF8ConversionWideCharTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(UTF8ConversionWideCharTest);
}

void System::UTF8ConversionWideCharTesting::UTF8ConversionWideCharTest()
{
    constexpr auto bufferSize = 256;

    const auto multiByteInitial = GetUTF8();
    const wstring wideCharHelpResult{ L"UTF8�ַ���ת��ΪWideChar" };
    constexpr auto minLength = 19;  // ����Ӣ�Ļ����Ķ���1�������㣬������ֹ����

    const auto wideCharLength = UTF8ConversionWideChar(multiByteInitial.c_str(), boost::numeric_cast<int>(multiByteInitial.size() + 1), nullptr, 0);

    ASSERT_TRUE_FAILURE_THROW(minLength <= wideCharLength && wideCharLength < bufferSize, "ת���ַ���ʧ�ܡ�");

    array<wchar_t, bufferSize> wideChar{};

    const auto wideCharResultLength = UTF8ConversionWideChar(multiByteInitial.c_str(), boost::numeric_cast<int>(multiByteInitial.size() + 1), wideChar.data(), wideCharLength);

    wstring wideCharResult{ wideChar.data() };
    ASSERT_EQUAL(wideCharResultLength, boost::numeric_cast<int>(wideCharResult.size() + 1));

    ASSERT_EQUAL(wideCharResult, wideCharHelpResult);
    ASSERT_EQUAL(wideCharResultLength, wideCharLength);
}

string System::UTF8ConversionWideCharTesting::GetUTF8()
{
    ifstream file{ "Resource/StringConversionTesting/UTF8ConversionWideChar.txt"s };

    if (file)
    {
        stringstream ss{};

        ss << file.rdbuf();

        return ss.str();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�����ļ������ڡ�"s));
    }
}
