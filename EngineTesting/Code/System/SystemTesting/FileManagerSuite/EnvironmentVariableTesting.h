/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 11:23)

#ifndef SYSTEM_FILE_MANAGER_SUITE_ENVIRONMENT_VARIABLE_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_ENVIRONMENT_VARIABLE_TESTING_H

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
        void DoRunUnitTest() override;
        void MainTest();

        void EnvironmentExistTest();
        void EnvironmentNonExistentTest();
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_ENVIRONMENT_VARIABLE_TESTING_H