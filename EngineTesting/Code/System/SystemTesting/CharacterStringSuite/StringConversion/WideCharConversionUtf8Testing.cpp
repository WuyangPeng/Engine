/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:38)

#include "WideCharConversionUtf8Testing.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/CFileManagerHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WideCharConversionUtf8Testing::WideCharConversionUtf8Testing(const OStreamShared& stream)
    : ParentType{ stream, 31, CoreTools::CFileManagerHelper::LoadFromFile("Resource/StringConversionTesting/WideCharConversionUtf8.txt") },  /// 英文按1个长度算，中文按3个长度算，包括终止符。
      wideCharInitial{ L"WideChar字符串转换为Utf8" },
      wideCharInitialLength{ boost::numeric_cast<int>(wideCharInitial.size() + 1) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WideCharConversionUtf8Testing)

void System::WideCharConversionUtf8Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WideCharConversionUtf8Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WideCharConversionUtf8Test);
}

void System::WideCharConversionUtf8Testing::WideCharConversionUtf8Test()
{
    const auto multiByteLength = WideCharConversionUtf8(wideCharInitial.c_str(), wideCharInitialLength, nullptr, 0);
    LengthChecking(multiByteLength);

    MultiByteType multiByte{};
    const auto multiByteActualLength = WideCharConversionUtf8(wideCharInitial.c_str(), wideCharInitialLength, multiByte.data(), multiByteLength);

    ASSERT_NOT_THROW_EXCEPTION_3(ResultChecking, multiByte, multiByteActualLength, multiByteLength);
}
