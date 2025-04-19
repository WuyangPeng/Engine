﻿/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:38)

#include "Utf8ConversionWideCharTesting.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/CFileManagerHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::Utf8ConversionWideCharTesting::Utf8ConversionWideCharTesting(const OStreamShared& stream)
    : ParentType{ stream, 19, L"Utf8字符串转换为WideChar" },  /// 不论英文或中文都按1个长度算，包括终止符。
      multiByteInitial{ CoreTools::CFileManagerHelper::LoadFromFile("Resource/StringConversionTesting/Utf8ConversionWideChar.txt") },
      multiByteInitialLength{ boost::numeric_cast<int>(multiByteInitial.size() + 1) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, Utf8ConversionWideCharTesting)

void System::Utf8ConversionWideCharTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::Utf8ConversionWideCharTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Utf8ConversionWideCharTest);
}

void System::Utf8ConversionWideCharTesting::Utf8ConversionWideCharTest()
{
    const auto wideCharLength = Utf8ConversionWideChar(multiByteInitial.c_str(), multiByteInitialLength, nullptr, 0);
    LengthChecking(wideCharLength);

    WideCharType wideChar{};
    const auto wideCharActualLength = Utf8ConversionWideChar(multiByteInitial.c_str(), multiByteInitialLength, wideChar.data(), wideCharLength);

    ASSERT_NOT_THROW_EXCEPTION_3(ResultChecking, wideChar, wideCharActualLength, wideCharLength);
}
