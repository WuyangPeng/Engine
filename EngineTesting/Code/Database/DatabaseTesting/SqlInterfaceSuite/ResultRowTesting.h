///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 16:15)

#ifndef DATABASE_TESTING_DATABASE_INTERFACE_SUITE_RESULT_ROW_TESTING_H
#define DATABASE_TESTING_DATABASE_INTERFACE_SUITE_RESULT_ROW_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Database
{
    class ResultRowTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ResultRowTesting;
        using ParentType = UnitTest;

    public:
        explicit ResultRowTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // DATABASE_TESTING_DATABASE_INTERFACE_SUITE_RESULT_ROW_TESTING_H