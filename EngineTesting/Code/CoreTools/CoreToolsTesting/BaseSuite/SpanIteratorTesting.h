///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/10 19:17)

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
        void DoRunUnitTest() override;
        void MainTest();

        void BaseTest();
        void DereferenceTest();
        void StepTest();
        void IncreaseTest();
        void SubtractionTest();
        void IterSwapTest();
        void ConstTest();
    };
}

#endif  // CORE_TOOLS_BASE_SUITE_SPAN_ITERATOR_TESTING_H