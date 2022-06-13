///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 13:33)

#include "WideCharConversionUTF8Testing.h"
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

System::WideCharConversionUTF8Testing::WideCharConversionUTF8Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WideCharConversionUTF8Testing)

void System::WideCharConversionUTF8Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WideCharConversionUTF8Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WideCharConversionUTF8Test);
}

void System::WideCharConversionUTF8Testing::WideCharConversionUTF8Test()
{
    constexpr auto bufferSize = 256;

    const wstring wideCharInitial{ L"WideChar字符串转换为UTF8" };
    const auto multiByteHelpResult = GetUTF8();
    constexpr auto minLength = 31;  // 英文按1个长度算，中文按3个长度算，包括终止符。

    const auto multiByteLength = WideCharConversionUTF8(wideCharInitial.c_str(), boost::numeric_cast<int>(wideCharInitial.size() + 1), nullptr, 0);

    ASSERT_TRUE_FAILURE_THROW(minLength <= multiByteLength && multiByteLength < bufferSize, "转换字符串失败。");

    array<char, bufferSize> multiByte{};

    const auto multiByteResultLength = WideCharConversionUTF8(wideCharInitial.c_str(), boost::numeric_cast<int>(wideCharInitial.size() + 1), multiByte.data(), multiByteLength);

    string multiByteResult{ multiByte.data() };
    ASSERT_EQUAL(multiByteResultLength, boost::numeric_cast<int>(multiByteResult.size() + 1));

    ASSERT_EQUAL(multiByteResult, multiByteHelpResult);
    ASSERT_EQUAL(multiByteResultLength, multiByteLength);
}

string System::WideCharConversionUTF8Testing::GetUTF8()
{
    ifstream file{ "Resource/StringConversionTesting/WideCharConversionUTF8.txt"s };

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
