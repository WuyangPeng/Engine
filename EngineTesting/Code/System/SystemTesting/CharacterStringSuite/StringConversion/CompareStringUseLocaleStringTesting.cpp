/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:38)

#include "CompareStringUseLocaleStringTesting.h"
#include "System/CharacterString/Flags/StringConversionFlags.h"
#include "System/CharacterString/StringConversion.h"
#include "System/CharacterString/Using/StringConversionUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CompareStringUseLocaleStringTesting::CompareStringUseLocaleStringTesting(const OStreamShared& stream)
    : ParentType{ stream },
      languageLocaleStrings{ gLocaleUserDefault,
                             gLocaleNameInvariant,
                             gLocaleSystemDefault },
      comparesWStrings{

#ifdef SYSTEM_PLATFORM_WIN32

          L"啊",
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
          L"0"

#endif  // SYSTEM_PLATFORM_WIN32

      },
      maxSize{ CoreTools::MaxElement({ languageLocaleStrings.size(), GetComparesSize(), comparesWStrings.size() }) },
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
    ASSERT_NOT_THROW_EXCEPTION_1(RandomShuffleCompares, randomEngine);
    std::ranges::shuffle(languageLocaleStrings, randomEngine);
    std::ranges::shuffle(comparesWStrings, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(CompareStringUseLocaleStringTest);

    return true;
}

void System::CompareStringUseLocaleStringTesting::CompareStringUseLocaleStringTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CompareStringTest, index);
    }
}

void System::CompareStringUseLocaleStringTesting::CompareStringTest(size_t index)
{
    const auto compare = GetCompares(index);
    auto languageLocaleString = languageLocaleStrings.at(index % languageLocaleStrings.size());
    auto lhsComparesWString = comparesWStrings.at(index % comparesWStrings.size());

    ASSERT_NOT_THROW_EXCEPTION_3(CompareStringEqualTest, languageLocaleString, compare, lhsComparesWString);

    const auto nextIndex = index + 1;
    const auto rhsComparesWString = comparesWStrings.at(nextIndex % comparesWStrings.size());

    CompareStringOppositeTest(languageLocaleString, compare, lhsComparesWString, rhsComparesWString);
}

void System::CompareStringUseLocaleStringTesting::CompareStringEqualTest(const wchar_t* languageLocaleString, Compares compare, const std::wstring& comparesWString)
{
    const auto result = CompareStringUseLocale(languageLocaleString, compare, comparesWString, comparesWString);
    ASSERT_EQUAL(result, ComparesStringReturn::Equal);
}

void System::CompareStringUseLocaleStringTesting::CompareStringOppositeTest(const wchar_t* languageLocaleString, Compares compare, const std::wstring& lhsComparesWString, const std::wstring& rhsComparesWString)
{
    const auto lhsCompareRhs = CompareStringUseLocale(languageLocaleString, compare, lhsComparesWString, rhsComparesWString);
    const auto rhsCompareLhs = CompareStringUseLocale(languageLocaleString, compare, rhsComparesWString, lhsComparesWString);

    CompareTest(lhsCompareRhs, rhsCompareLhs);
}
