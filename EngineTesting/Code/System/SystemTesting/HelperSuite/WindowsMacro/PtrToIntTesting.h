/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/08 09:57)

#ifndef SYSTEM_TESTING_HELPER_SUITE_PTR_TO_INT_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_PTR_TO_INT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @brief ����PtrConversionInt����
    class PtrToIntTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = PtrToIntTesting;
        using ParentType = UnitTest;

    public:
        explicit PtrToIntTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void PtrToIntTest();
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_PTR_TO_INT_TESTING_H
