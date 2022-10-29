///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/14 21:24)

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
    const wstring wideCharHelpResult{ L"UTF8字符串转换为WideChar" };
    constexpr auto minLength = 19;  // 不论英文或中文都按1个长度算，包括终止符。

    const auto wideCharLength = UTF8ConversionWideChar(multiByteInitial.c_str(), boost::numeric_cast<int>(multiByteInitial.size() + 1), nullptr, 0);

    ASSERT_TRUE_FAILURE_THROW(minLength <= wideCharLength && wideCharLength < bufferSize, "转换字符串失败。");

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
        THROW_EXCEPTION(SYSTEM_TEXT("测试文件不存在。"s));
    }
}
