///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/24 15:53)

#ifndef SYSTEM_FILE_MANAGE_SUITE_ENVIRONMENT_VARIABLE_TESTING_H
#define SYSTEM_FILE_MANAGE_SUITE_ENVIRONMENT_VARIABLE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class EnvironmentVariableTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnvironmentVariableTesting;
        using ParentType = UnitTest;

    public:
        explicit EnvironmentVariableTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void EnvironmentTest();
    };
}

#endif  // SYSTEM_FILE_MANAGE_SUITE_ENVIRONMENT_VARIABLE_TESTING_H