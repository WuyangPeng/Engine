///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 1:03)

#ifndef SYSTEM_THREADING_SUITE_INTERLOCKED_BINARY_TESTING_H
#define SYSTEM_THREADING_SUITE_INTERLOCKED_BINARY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class InterlockedBinaryTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = InterlockedBinaryTesting;
        using ParentType = UnitTest;

    public:
        explicit InterlockedBinaryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        template <typename T>
        void InterlockedBinaryTest();
    };
}

#endif  // SYSTEM_THREADING_SUITE_INTERLOCKED_BINARY_TESTING_H