/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 14:38)

#include "WideCharConversionUtf8Testing.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/CFileManagerHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WideCharConversionUtf8Testing::WideCharConversionUtf8Testing(const OStreamShared& stream)
    : ParentType{ stream, 31, CoreTools::CFileManagerHelper::LoadFromFile("Resource/StringConversionTesting/WideCharConversionUtf8.txt") },  /// Ӣ�İ�1�������㣬���İ�3�������㣬������ֹ����
      wideCharInitial{ L"WideChar�ַ���ת��ΪUtf8" },
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
