///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 13:24)

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

        const auto returnFlag = CompareStringOrdinalUseBinary(lhsComparesString.c_str(),
                                                              boost::numeric_cast<int>(lhsComparesString.size()),
                                                              lhsComparesString.c_str(),
                                                              boost::numeric_cast<int>(lhsComparesString.size()),
                                                              gFalse);
        ASSERT_ENUM_EQUAL(returnFlag, ComparesStringReturn::Equal);

        const auto nextIndex = (index + 1);

        auto rhsComparesString = wComparesString.at(nextIndex % wComparesString.size());

        const auto lhsCompareRhs = CompareStringOrdinalUseBinary(lhsComparesString.c_str(),
                                                                 boost::numeric_cast<int>(lhsComparesString.size()),
                                                                 rhsComparesString.c_str(),
                                                                 boost::numeric_cast<int>(rhsComparesString.size()),
                                                                 gFalse);

        const auto rhsCompareLhs = CompareStringOrdinalUseBinary(rhsComparesString.c_str(),
                                                                 boost::numeric_cast<int>(rhsComparesString.size()),
                                                                 lhsComparesString.c_str(),
                                                                 boost::numeric_cast<int>(lhsComparesString.size()),
                                                                 gFalse);

        CompareTest(lhsCompareRhs, rhsCompareLhs);
    }
}
