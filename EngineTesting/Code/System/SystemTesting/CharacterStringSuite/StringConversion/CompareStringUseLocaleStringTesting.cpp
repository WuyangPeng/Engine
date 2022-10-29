///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/14 21:23)

#include "CompareStringUseLocaleStringTesting.h"
#include "System/CharacterString/Flags/StringConversionFlags.h"
#include "System/CharacterString/StringConversion.h"
#include "System/CharacterString/Using/StringConversionUsing.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CompareStringUseLocaleStringTesting::CompareStringUseLocaleStringTesting(const OStreamShared& stream)
    : ParentType{ stream },
      languageLocaleString{ gLocaleUserDefault, gLocaleNameInvariant, gLocaleSystemDefault },
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
      wComparesString{ L"啊",
                       L"吧",
                       L"抽",
                       L"的",
                       L"额",
                       L"发",
                       L"给",
                       L"胡",
                       L"奖",
                       L"看",
                       L"了",
                       L"吗",
                       L"你",
                       L"哦",
                       L"平",
                       L"气",
                       L"人",
                       L"是",
                       L"他",
                       L"我",
                       L"想",
                       L"要",
                       L"做",
                       L"a",
                       L"A",
                       L"0" },
      maxSize{ CoreTools::MaxElement<size_t>({ languageLocaleString.size(), comparesFlags.size(), wComparesString.size() }) },
      randomEngine{ GetEngineRandomSeed() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CompareStringUseLocaleStringTesting)

void System::CompareStringUseLocaleStringTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CompareStringUseLocaleStringTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::CompareStringUseLocaleStringTesting::RandomShuffleFlags()
{
    shuffle(languageLocaleString.begin(), languageLocaleString.end(), randomEngine);
    shuffle(comparesFlags.begin(), comparesFlags.end(), randomEngine);
    shuffle(wComparesString.begin(), wComparesString.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(CompareStringUseLocaleStringTest);

    return true;
}

void System::CompareStringUseLocaleStringTesting::CompareStringUseLocaleStringTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        auto languageLocale = languageLocaleString.at(index % languageLocaleString.size());
        auto compares = comparesFlags.at(index % comparesFlags.size());
        auto lhsComparesString = wComparesString.at(index % wComparesString.size());

        const auto returnFlag = CompareStringUseLocale(languageLocale,
                                                       compares,
                                                       lhsComparesString.c_str(),
                                                       boost::numeric_cast<int>(lhsComparesString.size()),
                                                       lhsComparesString.c_str(),
                                                       boost::numeric_cast<int>(lhsComparesString.size()));
        ASSERT_ENUM_EQUAL(returnFlag, ComparesStringReturn::Equal);

        const auto nextIndex = (index + 1);

        const auto rhsComparesString = wComparesString.at(nextIndex % wComparesString.size());

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
