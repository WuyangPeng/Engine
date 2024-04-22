/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 14:23)

#include "CompareStringUseLocaleFlagsTesting.h"
#include "System/CharacterString/Flags/StringConversionFlags.h"
#include "System/CharacterString/StringConversion.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CompareStringUseLocaleFlagsTesting::CompareStringUseLocaleFlagsTesting(const OStreamShared& stream)
    : ParentType{ stream },
      /// TODO: LanguageLocale::CustomUiDefault����ʧ�ܡ�
      languageLocales{ LanguageLocale::SystemDefault,
                       LanguageLocale::UserDefault,
                       LanguageLocale::CustomDefault,
                       LanguageLocale::Neutral,
                       LanguageLocale::Invariant,
                       LanguageLocale::CustomUnspecified },
      comparesStrings{ SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("Ŷ"),
                       SYSTEM_TEXT("ƽ"),
                       SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("Ҫ"),
                       SYSTEM_TEXT("��"),
                       SYSTEM_TEXT("a"),
                       SYSTEM_TEXT("A"),
                       SYSTEM_TEXT("0") },
      maxSize{ CoreTools::MaxElement({ languageLocales.size(), GetComparesSize(), comparesStrings.size() }) },
      randomEngine{ GetEngineRandomSeed() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CompareStringUseLocaleFlagsTesting)

void System::CompareStringUseLocaleFlagsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CompareStringUseLocaleFlagsTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::CompareStringUseLocaleFlagsTesting::RandomShuffleFlags()
{
    std::ranges::shuffle(languageLocales, randomEngine);
    ASSERT_NOT_THROW_EXCEPTION_1(RandomShuffleCompares, randomEngine);
    std::ranges::shuffle(comparesStrings, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(CompareStringUseLocaleFlagsTest);

    return true;
}

void System::CompareStringUseLocaleFlagsTesting::CompareStringUseLocaleFlagsTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CompareStringTest, index);
    }
}

void System::CompareStringUseLocaleFlagsTesting::CompareStringTest(size_t index)
{
    const auto compare = GetCompares(index);
    const auto languageLocale = languageLocales.at(index % languageLocales.size());
    const auto lhsComparesString = comparesStrings.at(index % comparesStrings.size());

    ASSERT_NOT_THROW_EXCEPTION_3(CompareStringEqualTest, languageLocale, compare, lhsComparesString);

    const auto nextIndex = index + 1;
    const auto rhsComparesString = comparesStrings.at(nextIndex % comparesStrings.size());

    CompareStringOppositeTest(languageLocale, compare, lhsComparesString, rhsComparesString);
}

void System::CompareStringUseLocaleFlagsTesting::CompareStringEqualTest(LanguageLocale languageLocale, Compares compare, const String& comparesString)
{
    const auto result = CompareStringUseLocale(languageLocale, compare, comparesString, comparesString);
    ASSERT_EQUAL(result, ComparesStringReturn::Equal);
}

void System::CompareStringUseLocaleFlagsTesting::CompareStringOppositeTest(LanguageLocale languageLocale, Compares compare, const String& lhsComparesString, const String& rhsComparesString)
{
    const auto lhsCompareRhs = CompareStringUseLocale(languageLocale, compare, lhsComparesString, rhsComparesString);
    const auto rhsCompareLhs = CompareStringUseLocale(languageLocale, compare, rhsComparesString, lhsComparesString);

    CompareTest(lhsCompareRhs, rhsCompareLhs);
}
