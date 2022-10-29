///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/03 12:35)

#ifndef SYSTEM_TESTING_HELPER_SUITE_DEBUG_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_DEBUG_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class DebugTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DebugTesting;
        using ParentType = UnitTest;

    public:
        explicit DebugTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void DebugTest() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_DEBUG_TESTING_H
