///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��1.0.0.0 (2023/11/08 15:28)

#ifndef ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_GAME_MODULE_TESTING_H
#define ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_GAME_MODULE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace AssistTools
{
    class GameModuleTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GameModuleTesting;
        using ParentType = UnitTest;

    public:
        explicit GameModuleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GameModuleReadTest();
    };
}

#endif  // ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_GAME_MODULE_TESTING_H