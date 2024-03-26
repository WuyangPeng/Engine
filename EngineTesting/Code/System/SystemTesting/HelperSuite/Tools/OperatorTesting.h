/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/08 16:26)

#ifndef SYSTEM_TESTING_HELPER_SUITE_OPERATOR_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_OPERATOR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OperatorTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OperatorTesting;
        using ParentType = UnitTest;

    public:
        explicit OperatorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void PlusTest();
        void MinusTest();
        void ProductTest();
        void DivideTest();
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_OPERATOR_TESTING_H
