///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��1.0.0.0 (2023/11/13 19:16)

#ifndef ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_GENERATE_ENGINE_TESTING_H
#define ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_GENERATE_ENGINE_TESTING_H

#include "GenerateTesting.h"

namespace AssistTools
{
    class GenerateEngineTesting final : public GenerateTesting
    {
    public:
        using ClassType = GenerateEngineTesting;
        using ParentType = GenerateTesting;

    public:
        explicit GenerateEngineTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GenerateEngineTest();
    };
}

#endif  // ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_GENERATE_ENGINE_TESTING_H