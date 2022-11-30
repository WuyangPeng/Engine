///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/26 18:24)

#include "LocaleTesting.h"
#include "System/CharacterString/Data/Locale.h"
#include "System/CharacterString/Flags/CodePageFlags.h"
#include "System/CharacterString/FormatString.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <locale>

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
        Locale locale{ CodePage::UTF8 };

        const auto currentLocale = Locale::GetLocaleType(setlocale(LC_ALL, nullptr));
        ASSERT_EQUAL(std::string{ currentLocale.data() }, "zh_CN.utf8");
    }

    const auto currentLocale = Locale::GetLocaleType(setlocale(LC_ALL, nullptr));
    ASSERT_EQUAL(defaultLocale, currentLocale);
}
