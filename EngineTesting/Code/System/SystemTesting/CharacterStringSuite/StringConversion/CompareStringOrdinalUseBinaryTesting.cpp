///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/14 21:23)

#include "CompareStringOrdinalUseBinaryTesting.h"
#include "System/CharacterString/Flags/StringConversionFlags.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CompareStringOrdinalUseBinaryTesting::CompareStringOrdinalUseBinaryTesting(const OStreamShared& stream)
    : ParentType{ stream },
      wComparesString{ L"��",
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
    shuffle(wComparesString.begin(), wComparesString.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(CompareStringOrdinalUseBinaryTest);

    return true;
}

void System::CompareStringOrdinalUseBinaryTesting::CompareStringOrdinalUseBinaryTest()
{
    for (auto index = 0u; index < wComparesString.size(); ++index)
    {
        auto lhsComparesString = wComparesString.at(index % wComparesString.size());

        const auto returnFlag = CompareStringOrdinalUseBinary(lhsComparesString,
                                                              lhsComparesString,
                                                              gFalse);
        ASSERT_ENUM_EQUAL(returnFlag, ComparesStringReturn::Equal);

        const auto nextIndex = (index + 1);

        auto rhsComparesString = wComparesString.at(nextIndex % wComparesString.size());

        const auto lhsCompareRhs = CompareStringOrdinalUseBinary(lhsComparesString,
                                                                 rhsComparesString,
                                                                 gFalse);

        const auto rhsCompareLhs = CompareStringOrdinalUseBinary(rhsComparesString,
                                                                 lhsComparesString,
                                                                 gFalse);

        CompareTest(lhsCompareRhs, rhsCompareLhs);
    }
}
