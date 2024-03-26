/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 14:38)

#include "Utf8ConversionWideCharTesting.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/CFileManagerHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::Utf8ConversionWideCharTesting::Utf8ConversionWideCharTesting(const OStreamShared& stream)
    : ParentType{ stream, 19, L"Utf8�ַ���ת��ΪWideChar" },  /// ����Ӣ�Ļ����Ķ���1�������㣬������ֹ����
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
