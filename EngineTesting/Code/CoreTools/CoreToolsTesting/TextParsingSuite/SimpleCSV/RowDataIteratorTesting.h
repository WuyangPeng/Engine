///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 16:17)

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
        void DoRunUnitTest() final;
        void MainTest();

        void RowDataIteratorTest();
        void SuffixIteratorTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_ROW_DATA_ITERATOR_TESTING_H