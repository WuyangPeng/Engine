///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 13:38)

#ifndef CORE_TOOLS_EXCEPTION_SUITE_LAST_ERROR_TESTING_H
#define CORE_TOOLS_EXCEPTION_SUITE_LAST_ERROR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LastErrorTesting final : public UnitTest
    {
    public:
        using ClassType = LastErrorTesting;
        using ParentType = UnitTest;

    public:
        explicit LastErrorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void LastErrorTest();
    };
}

#endif  // CORE_TOOLS_EXCEPTION_SUITE_LAST_ERROR_TESTING_H
