/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 16:06)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_LEXICO_ARRAY2_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_LEXICO_ARRAY2_TESTING_H

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
        using DoubleContainer = std::vector<double>;
        using DoubleContainerIter = DoubleContainer::iterator;
        using DoubleContainerConstIter = DoubleContainer::const_iterator;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void RowMajorLexicoArray2Test();
        void ColumnMajorLexicoArray2Test();
        void RowMajorConstantLexicoArray2Test();
        void ColumnMajorConstantLexicoArray2Test();
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_LEXICO_ARRAY2_TESTING_H