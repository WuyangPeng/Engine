///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/01 22:39)

#include "WideCharConversionUTF8Testing.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/CFileManagerHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WideCharConversionUTF8Testing::WideCharConversionUTF8Testing(const OStreamShared& stream)
    : ParentType{ stream, 31, CoreTools::CFileManagerHelper::LoadFromFile("Resource/StringConversionTesting/WideCharConversionUTF8.txt") },  // Ӣ�İ�1�������㣬���İ�3�������㣬������ֹ����
      wideCharInitial{ L"WideChar�ַ���ת��ΪUTF8" },
      wideCharInitialLength{ boost::numeric_cast<int>(wideCharInitial.size() + 1) }
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
    const auto multiByteLength = WideCharConversionUTF8(wideCharInitial.c_str(), wideCharInitialLength, nullptr, 0);
    LengthChecking(multiByteLength);

    MultiByteType multiByte{};
    const auto multiByteActualLength = WideCharConversionUTF8(wideCharInitial.c_str(), wideCharInitialLength, multiByte.data(), multiByteLength);

    ASSERT_NOT_THROW_EXCEPTION_3(ResultChecking, multiByte, multiByteActualLength, multiByteLength);
}
