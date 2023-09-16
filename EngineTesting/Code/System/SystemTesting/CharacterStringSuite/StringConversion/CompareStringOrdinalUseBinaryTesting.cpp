///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 16:15)

#include "CompareStringOrdinalUseBinaryTesting.h"
#include "System/CharacterString/Flags/StringConversionFlags.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CompareStringOrdinalUseBinaryTesting::CompareStringOrdinalUseBinaryTesting(const OStreamShared& stream)
    : ParentType{ stream },
      comparesWStrings{ L"��",
                        L"��",
                        L"��",
                        L"��",
                        L"��",
                        L"��",
                        L"��",
                        L"��",
                        L"��",
                        L"��",
                        L"��",
                        L"��",
                        L"��",
                        L"Ŷ",
                        L"ƽ",
                        L"��",
                        L"��",
                        L"��",
                        L"��",
                        L"��",
                        L"��",
                        L"Ҫ",
                        L"��",
                        L"a",
                        L"A",
                        L"0" },
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
    ASSERT_ENUM_EQUAL(returnFlag, ComparesStringReturn::Equal);
}

void System::CompareStringOrdinalUseBinaryTesting::CompareStringOppositeTest(const std::wstring& lhsComparesWString, const std::wstring& rhsComparesWString)
{
    const auto lhsCompareRhs = CompareStringOrdinalUseBinary(lhsComparesWString, rhsComparesWString, false);
    const auto rhsCompareLhs = CompareStringOrdinalUseBinary(rhsComparesWString, lhsComparesWString, false);

    CompareTest(lhsCompareRhs, rhsCompareLhs);
}
