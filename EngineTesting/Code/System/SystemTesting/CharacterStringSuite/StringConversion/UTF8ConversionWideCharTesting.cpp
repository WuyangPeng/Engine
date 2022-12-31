///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/01 13:15)

#include "UTF8ConversionWideCharTesting.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/CFileManagerHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::UTF8ConversionWideCharTesting::UTF8ConversionWideCharTesting(const OStreamShared& stream)
    : ParentType{ stream, 19, L"UTF8�ַ���ת��ΪWideChar" },  // ����Ӣ�Ļ����Ķ���1�������㣬������ֹ����
      multiByteInitial{ CoreTools::CFileManagerHelper::LoadFromFile("Resource/StringConversionTesting/UTF8ConversionWideChar.txt") },
      multiByteInitialLength{ boost::numeric_cast<int>(multiByteInitial.size() + 1) } 
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
    const auto wideCharLength = UTF8ConversionWideChar(multiByteInitial.c_str(), multiByteInitialLength, nullptr, 0);
    LengthChecking(wideCharLength);

    WideCharType wideChar{};
    const auto wideCharActualLength = UTF8ConversionWideChar(multiByteInitial.c_str(), multiByteInitialLength, wideChar.data(), wideCharLength);

    ASSERT_NOT_THROW_EXCEPTION_3(ResultChecking, wideChar, wideCharActualLength, wideCharLength);
}
