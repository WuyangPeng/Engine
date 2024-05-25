/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/16 22:37)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_LEXICO_ARRAY2_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_LEXICO_ARRAY2_TESTING_H

#include "CoreTools/MemoryTools/MemoryToolsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LexicoArray2Testing final : public UnitTest
    {
    public:
        using ClassType = LexicoArray2Testing;
        using ParentType = UnitTest;

    public:
        explicit LexicoArray2Testing(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto numRows = 5;
        static constexpr auto numColumns = 4;
        static constexpr auto containerSize = numRows * numColumns;

        using DoubleContainer = std::vector<double>;
        using DoubleContainerIter = DoubleContainer::iterator;
        using DoubleContainerConstIter = DoubleContainer::const_iterator;
        using LexicoArray2Type0 = LexicoArray2<true, DoubleContainerIter, numRows, numColumns>;
        using LexicoArray2Type1 = LexicoArray2<true, DoubleContainerConstIter, numRows, numColumns>;
        using LexicoArray2Type2 = LexicoArray2<false, DoubleContainerIter, numRows, numColumns>;
        using LexicoArray2Type3 = LexicoArray2<false, DoubleContainerConstIter, numRows, numColumns>;
        using LexicoArray2Type4 = LexicoArray2<true, DoubleContainerIter>;
        using LexicoArray2Type5 = LexicoArray2<true, DoubleContainerConstIter>;
        using LexicoArray2Type6 = LexicoArray2<false, DoubleContainerIter>;
        using LexicoArray2Type7 = LexicoArray2<false, DoubleContainerConstIter>;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void RowMajorLexicoArray2Test();
        void ColumnMajorLexicoArray2Test();
        void RowMajorConstantLexicoArray2Test();
        void ColumnMajorConstantLexicoArray2Test();

        void RowMajorLexicoArray2Result0Test(LexicoArray2Type0& lexicoArray);
        void RowMajorLexicoArray2Result1Test(LexicoArray2Type0& lhsLexicoArray, LexicoArray2Type1& rhsLexicoArray);
        void ColumnMajorLexicoArray2Result0Test(LexicoArray2Type2& lexicoArray);
        void ColumnMajorLexicoArray2Result1Test(LexicoArray2Type2& lhsLexicoArray, LexicoArray2Type3& rhsLexicoArray);
        void RowMajorConstantLexicoArray2Result0Test(LexicoArray2Type4& lexicoArray);
        void RowMajorConstantLexicoArray2Result1Test(LexicoArray2Type4& lhsLexicoArray, LexicoArray2Type5& rhsLexicoArray);
        void ColumnMajorConstantLexicoArray2Result0Test(LexicoArray2Type6& lexicoArray);
        void ColumnMajorConstantLexicoArray2Result1Test(LexicoArray2Type6& lhsLexicoArray, LexicoArray2Type7& rhsLexicoArray);
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_LEXICO_ARRAY2_TESTING_H