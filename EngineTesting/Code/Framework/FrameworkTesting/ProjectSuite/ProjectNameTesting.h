///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/14 14:11)

#ifndef FRAMEWORK_PROJECT_SUITE_PROJECT_NAME_TESTING_H
#define FRAMEWORK_PROJECT_SUITE_PROJECT_NAME_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class ProjectNameTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ProjectNameTesting;
        using ParentType = UnitTest;

    public:
        explicit ProjectNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ProjectNameTest();
    };
}

#endif  // FRAMEWORK_PROJECT_SUITE_PROJECT_NAME_TESTING_H