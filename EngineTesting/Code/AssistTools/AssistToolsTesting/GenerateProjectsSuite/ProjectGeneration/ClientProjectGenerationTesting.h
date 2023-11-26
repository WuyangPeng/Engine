///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��1.0.0.0 (2023/11/13 11:01)

#ifndef ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_CLIENT_PROJECT_GENERATION_TESTING_H
#define ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_CLIENT_PROJECT_GENERATION_TESTING_H

#include "ProjectGenerationTesting.h"

namespace AssistTools
{
    class ClientProjectGenerationTesting final : public ProjectGenerationTesting
    {
    public:
        using ClassType = ClientProjectGenerationTesting;
        using ParentType = ProjectGenerationTesting;

    public:
        explicit ClientProjectGenerationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CallRunBatTest();
    };
}

#endif  // ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_CLIENT_PROJECT_GENERATION_TESTING_H