/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:38)

#include "WideCharConversionMultiByteTesting.h"
#include "System/CharacterString/CodePage.h"
#include "System/CharacterString/Flags/StringConversionFlags.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::WideCharConversionMultiByteTesting::WideCharConversionMultiByteTesting(const OStreamShared& stream)
    : ParentType{ stream, 30, "WideChar字符串转换为MultiByte" },  /// 英文按1个长度算，中文按2个长度算，包括终止符。
      wideCharInitial{ L"WideChar字符串转换为MultiByte" },
      wideCharInitialLength{ boost::numeric_cast<int>(wideCharInitial.size() + 1) },
      codePage{ GetAnsiCodePage() }
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
    ASSERT_NOT_THROW_EXCEPTION_1(WideCharToMultiByteUseFlagAndUsedDefaultChar, WideChar::NoFlags);
    ASSERT_NOT_THROW_EXCEPTION_1(WideCharToMultiByteUseFlagAndUsedDefaultChar, WideChar::NoBestFitChars);
}

void System::WideCharConversionMultiByteTesting::WideCharToMultiByteTest()
{
    const auto multiByteLength = WideCharConversionMultiByte(wideCharInitial.c_str(),
                                                             wideCharInitialLength,
                                                             nullptr,
                                                             0);
    LengthChecking(multiByteLength);

    MultiByteType multiByte{};
    const auto multiByteActualLength = WideCharConversionMultiByte(wideCharInitial.c_str(),
                                                                   wideCharInitialLength,
                                                                   multiByte.data(),
                                                                   multiByteLength);

    ASSERT_NOT_THROW_EXCEPTION_3(ResultChecking, multiByte, multiByteActualLength, multiByteLength);
}

void System::WideCharConversionMultiByteTesting::WideCharToMultiByteUseFlagTest(WideChar wideChar)
{
    const auto multiByteLength = WideCharConversionMultiByte(codePage,
                                                             wideChar,
                                                             wideCharInitial.c_str(),
                                                             wideCharInitialLength,
                                                             nullptr,
                                                             0,
                                                             nullptr,
                                                             nullptr);
    LengthChecking(multiByteLength);

    MultiByteType multiByte{};
    const auto multiByteActualLength = WideCharConversionMultiByte(codePage,
                                                                   wideChar,
                                                                   wideCharInitial.c_str(),
                                                                   wideCharInitialLength,
                                                                   multiByte.data(),
                                                                   multiByteLength,
                                                                   nullptr,
                                                                   nullptr);

    ASSERT_NOT_THROW_EXCEPTION_3(ResultChecking, multiByte, multiByteActualLength, multiByteLength);
}

void System::WideCharConversionMultiByteTesting::WideCharToMultiByteUseFlagAndUsedDefaultChar(WideChar wideChar)
{
    const auto defaultChar = "a"s;
    auto usedDefaultChar = true;

    const auto multiByteLength = WideCharConversionMultiByte(codePage,
                                                             wideChar,
                                                             wideCharInitial.c_str(),
                                                             wideCharInitialLength,
                                                             nullptr,
                                                             0,
                                                             defaultChar.c_str(),
                                                             &usedDefaultChar);
    ASSERT_EQUAL(usedDefaultChar, false);
    LengthChecking(multiByteLength);

    MultiByteType multiByte{};
    const auto multiByteActualLength = WideCharConversionMultiByte(codePage,
                                                                   wideChar,
                                                                   wideCharInitial.c_str(),
                                                                   wideCharInitialLength,
                                                                   multiByte.data(),
                                                                   multiByteLength,
                                                                   defaultChar.c_str(),
                                                                   &usedDefaultChar);

    ASSERT_EQUAL(usedDefaultChar, false);
    ASSERT_NOT_THROW_EXCEPTION_3(ResultChecking, multiByte, multiByteActualLength, multiByteLength);
}
