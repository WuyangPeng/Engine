/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/15 14:43)

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
        void IncreaseArrayTest();
        void SubtractionTest();
        void IterSwapTest();
        void ConstTest();
        void GetSetValueTest();
    };
}

#endif  // CORE_TOOLS_BASE_SUITE_SPAN_ITERATOR_TESTING_H