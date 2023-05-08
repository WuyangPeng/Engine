///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.7 (2023/04/26 15:12)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_ROW_DATA_ITERATOR_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_ROW_DATA_ITERATOR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class RowDataIteratorTesting final : public UnitTest
    {
    public:
        using ClassType = RowDataIteratorTesting;
        using ParentType = UnitTest;

    public:
        explicit RowDataIteratorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void RowDataIteratorTest();
        void SuffixIteratorTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_ROW_DATA_ITERATOR_TESTING_H