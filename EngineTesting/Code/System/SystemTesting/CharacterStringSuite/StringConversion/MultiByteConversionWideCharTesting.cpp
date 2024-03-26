/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 14:38)

#include "MultiByteConversionWideCharTesting.h"
#include "System/CharacterString/CodePage.h"
#include "System/CharacterString/Flags/StringConversionFlags.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::MultiByteConversionWideCharTesting::MultiByteConversionWideCharTesting(const OStreamShared& stream)
    : ParentType{ stream, 24, L"MultiByte�ַ���ת��ΪWideChar" },  /// ����Ӣ�Ļ����Ķ���1�������㣬������ֹ����
      multiByteInitial{ "MultiByte�ַ���ת��ΪWideChar" },
      multiByteInitialLength{ boost::numeric_cast<int>(multiByteInitial.size() + 1) },
      codePage{ GetAnsiCodePage() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MultiByteConversionWideCharTesting)

void System::MultiByteConversionWideCharTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MultiByteConversionWideCharTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MultiByteToWideCharTest);
    ASSERT_NOT_THROW_EXCEPTION_1(MultiByteToWideCharUseFlagTest, MultiByte::NoFlags);
    ASSERT_NOT_THROW_EXCEPTION_1(MultiByteToWideCharUseFlagTest, MultiByte::ErrInvalidChars);
}

void System::MultiByteConversionWideCharTesting::MultiByteToWideCharTest()
{
    const auto wideCharLength = MultiByteConversionWideChar(multiByteInitial.c_str(), multiByteInitialLength, nullptr, 0);
    LengthChecking(wideCharLength);

    WideCharType wideChar{};
    const auto wideCharActualLength = MultiByteConversionWideChar(multiByteInitial.c_str(), multiByteInitialLength, wideChar.data(), wideCharLength);

    ASSERT_NOT_THROW_EXCEPTION_3(ResultChecking, wideChar, wideCharActualLength, wideCharLength);
}

void System::MultiByteConversionWideCharTesting::MultiByteToWideCharUseFlagTest(MultiByte multiByte)
{
    const auto wideCharLength = MultiByteConversionWideChar(codePage, multiByte, multiByteInitial.c_str(), multiByteInitialLength, nullptr, 0);
    LengthChecking(wideCharLength);

    WideCharType wideChar{};
    const auto wideCharActualLength = MultiByteConversionWideChar(codePage, multiByte, multiByteInitial.c_str(), multiByteInitialLength, wideChar.data(), wideCharLength);

    ASSERT_NOT_THROW_EXCEPTION_3(ResultChecking, wideChar, wideCharActualLength, wideCharLength);
}
