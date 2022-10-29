///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/14 21:23)

#include "CompareStringUseLocaleFlagsTesting.h"
#include "System/CharacterString/Flags/StringConversionFlags.h"
#include "System/CharacterString/StringConversion.h"
#include "System/CharacterString/Using/StringConversionUsing.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::to_string;

System::CompareStringUseLocaleFlagsTesting::CompareStringUseLocaleFlagsTesting(const OStreamShared& stream)
    : ParentType{ stream },
      // 这里不测试CustomUIDefault和CustomUnspecified。
      languageLocaleFlags{ LanguageLocale::SystemDefault,
                           LanguageLocale::UserDefault,
                           LanguageLocale::CustomDefault,
                           LanguageLocale::Neutral,
                           LanguageLocale::Invariant },
      comparesFlags{ Compares::NormIgnoreCase,
                     Compares::NormIgnoreNonSpace,
                     Compares::NormIgnoreSymbols,
                     Compares::LinguisticIgnoreCase,
                     Compares::LinguisticIgnoreDiacritic,
                     Compares::NormIgnoreKanaType,
                     Compares::IgnoreWidth,
                     Compares::LinguisticCasing,
                     Compares::SortStringSort,
                     Compares::SortDigitsAsNumbers },
      comparesString{ SYSTEM_TEXT("啊"),
                      SYSTEM_TEXT("吧"),
                      SYSTEM_TEXT("抽"),
                      SYSTEM_TEXT("的"),
                      SYSTEM_TEXT("额"),
                      SYSTEM_TEXT("发"),
                      SYSTEM_TEXT("给"),
                      SYSTEM_TEXT("胡"),
                      SYSTEM_TEXT("奖"),
                      SYSTEM_TEXT("看"),
                      SYSTEM_TEXT("了"),
                      SYSTEM_TEXT("吗"),
                      SYSTEM_TEXT("你"),
                      SYSTEM_TEXT("哦"),
                      SYSTEM_TEXT("平"),
                      SYSTEM_TEXT("气"),
                      SYSTEM_TEXT("人"),
                      SYSTEM_TEXT("是"),
                      SYSTEM_TEXT("他"),
                      SYSTEM_TEXT("我"),
                      SYSTEM_TEXT("想"),
                      SYSTEM_TEXT("要"),
                      SYSTEM_TEXT("做"),
                      SYSTEM_TEXT("a"),
                      SYSTEM_TEXT("A"),
                      SYSTEM_TEXT("0") },
      maxSize{ CoreTools::MaxElement<size_t>({ languageLocaleFlags.size(), comparesFlags.size(), comparesString.size() }) },
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
    shuffle(languageLocaleFlags.begin(), languageLocaleFlags.end(), randomEngine);
    shuffle(comparesFlags.begin(), comparesFlags.end(), randomEngine);
    shuffle(comparesString.begin(), comparesString.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(CompareStringUseLocaleFlagsTest);

    return true;
}

void System::CompareStringUseLocaleFlagsTesting::CompareStringUseLocaleFlagsTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        auto languageLocale = languageLocaleFlags.at(index % languageLocaleFlags.size());
        auto compares = comparesFlags.at(index % comparesFlags.size());
        auto lhsComparesString = comparesString.at(index % comparesString.size());

        const auto returnFlag = CompareStringUseLocale(languageLocale,
                                                       compares,
                                                       lhsComparesString.c_str(),
                                                       boost::numeric_cast<int>(lhsComparesString.size()),
                                                       lhsComparesString.c_str(),
                                                       boost::numeric_cast<int>(lhsComparesString.size()));
        ASSERT_ENUM_EQUAL(returnFlag, ComparesStringReturn::Equal);

        const auto nextIndex = (index + 1);

        auto rhsComparesString = comparesString.at(nextIndex % comparesString.size());

        const auto lhsCompareRhs = CompareStringUseLocale(languageLocale,
                                                          compares,
                                                          lhsComparesString.c_str(),
                                                          boost::numeric_cast<int>(lhsComparesString.size()),
                                                          rhsComparesString.c_str(),
                                                          boost::numeric_cast<int>(rhsComparesString.size()));

        const auto rhsCompareLhs = CompareStringUseLocale(languageLocale,
                                                          compares,
                                                          rhsComparesString.c_str(),
                                                          boost::numeric_cast<int>(rhsComparesString.size()),
                                                          lhsComparesString.c_str(),
                                                          boost::numeric_cast<int>(lhsComparesString.size()));

        CompareTest(lhsCompareRhs, rhsCompareLhs);
    }
}
