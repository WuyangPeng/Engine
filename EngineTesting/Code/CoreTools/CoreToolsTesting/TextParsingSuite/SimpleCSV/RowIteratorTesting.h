///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.4 (2021/10/11 11:24)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_ROW_ITERATOR_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_ROW_ITERATOR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class RowIteratorTesting final : public UnitTest
    {
    public:
        using ClassType = RowIteratorTesting;
        using ParentType = UnitTest;

    public:
        explicit RowIteratorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void RowIteratorTest();
        void SuffixIteratorTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_ROW_ITERATOR_TESTING_H