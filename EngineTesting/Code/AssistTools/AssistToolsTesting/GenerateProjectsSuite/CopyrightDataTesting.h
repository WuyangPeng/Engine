///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 10:50)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_COPYRIGHT_DATA_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_COPYRIGHT_DATA_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace AssistTools
{
    class CopyrightDataTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = CopyrightDataTesting;
        using ParentType = UnitTest;

    public:
        explicit CopyrightDataTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void AccessTest();

        void DoRunUnitTest() override;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_COPYRIGHT_DATA_TESTING_H