///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 16:06)

#include "LocaleTesting.h"
#include "System/CharacterString/Data/Locale.h"
#include "System/CharacterString/Flags/CodePageFlags.h"
#include "System/CharacterString/FormatString.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <locale>

using namespace std::literals;

System::LocaleTesting::LocaleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LocaleTesting)

void System::LocaleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LocaleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LocaleTest);
}

void System::LocaleTesting::LocaleTest()
{
    const auto defaultLocale = Locale::GetLocaleType(setlocale(LC_ALL, nullptr));

    {
        Locale locale{ CodePage::Utf7 };

        const auto currentLocale = Locale::GetLocaleType(setlocale(LC_ALL, nullptr));
        std::string result{ currentLocale.data() };

        ASSERT_UNEQUAL(result.find("936"), std::string::npos);
    }

    const auto currentLocale = Locale::GetLocaleType(setlocale(LC_ALL, nullptr));
    ASSERT_EQUAL(defaultLocale, currentLocale);
}
