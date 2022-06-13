///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 14:43)

#ifndef CORE_TOOLS_BASE_SUITE_SPAN_ITERATOR_TESTING_H
#define CORE_TOOLS_BASE_SUITE_SPAN_ITERATOR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SpanIteratorTesting final : public UnitTest
    {
    public:
        using ClassType = SpanIteratorTesting;
        using ParentType = UnitTest;

    public:
        explicit SpanIteratorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void BaseTest();
        void DereferenceTest();
        void StepTest();
        void IncreaseTest();
        void SubtractionTest();
        void IterSwapTest();
    };
}

#endif  // CORE_TOOLS_BASE_SUITE_SPAN_ITERATOR_TESTING_H