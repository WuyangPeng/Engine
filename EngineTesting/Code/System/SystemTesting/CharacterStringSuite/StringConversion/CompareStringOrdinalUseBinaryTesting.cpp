/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:23)

#include "CompareStringOrdinalUseBinaryTesting.h"
#include "System/CharacterString/Flags/StringConversionFlags.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::CompareStringOrdinalUseBinaryTesting::CompareStringOrdinalUseBinaryTesting(const OStreamShared& stream)
    : ParentType{ stream },
      comparesWStrings{ L"啊"s,
                        L"吧"s,
                        L"抽"s,
                        L"的"s,
                        L"额"s,
                        L"发"s,
                        L"给"s,
                        L"胡"s,
                        L"奖"s,
                        L"看"s,
                        L"了"s,
                        L"吗"s,
                        L"你"s,
                        L"哦"s,
                        L"平"s,
                        L"气"s,
                        L"人"s,
                        L"是"s,
                        L"他"s,
                        L"我"s,
                        L"想"s,
                        L"要"s,
                        L"做"s,
                        L"a"s,
                        L"A"s,
                        L"0"s },
      randomEngine{ GetEngineRandomSeed() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CompareStringOrdinalUseBinaryTesting)

void System::CompareStringOrdinalUseBinaryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CompareStringOrdinalUseBinaryTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::CompareStringOrdinalUseBinaryTesting::RandomShuffleFlags()
{
    std::ranges::shuffle(comparesWStrings, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(CompareStringOrdinalUseBinaryTest);

    return true;
}

void System::CompareStringOrdinalUseBinaryTesting::CompareStringOrdinalUseBinaryTest()
{
    for (auto index = 0u; index < comparesWStrings.size(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CompareStringTest, index);
    }
}

void System::CompareStringOrdinalUseBinaryTesting::CompareStringTest(size_t index)
{
    auto lhsComparesWString = comparesWStrings.at(index % comparesWStrings.size());

    ASSERT_NOT_THROW_EXCEPTION_1(CompareStringEqualTest, lhsComparesWString);

    const auto nextIndex = (index + 1);
    auto rhsComparesWString = comparesWStrings.at(nextIndex % comparesWStrings.size());

    ASSERT_NOT_THROW_EXCEPTION_2(CompareStringOppositeTest, lhsComparesWString, rhsComparesWString);
}

void System::CompareStringOrdinalUseBinaryTesting::CompareStringEqualTest(const std::wstring& comparesWString)
{
    const auto returnFlag = CompareStringOrdinalUseBinary(comparesWString, comparesWString, false);
    ASSERT_EQUAL(returnFlag, ComparesStringReturn::Equal);
}

void System::CompareStringOrdinalUseBinaryTesting::CompareStringOppositeTest(const std::wstring& lhsComparesWString, const std::wstring& rhsComparesWString)
{
    const auto lhsCompareRhs = CompareStringOrdinalUseBinary(lhsComparesWString, rhsComparesWString, false);
    const auto rhsCompareLhs = CompareStringOrdinalUseBinary(rhsComparesWString, lhsComparesWString, false);

    CompareTest(lhsCompareRhs, rhsCompareLhs);
}
