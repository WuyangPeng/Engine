///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 16:19)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CSV_CONFIGURE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CSV_CONFIGURE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CSVConfigureTesting final : public UnitTest
    {
    public:
        using ClassType = CSVConfigureTesting;
        using ParentType = UnitTest;

    public:
        explicit CSVConfigureTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateCSV();
        void CSVConfigureContainerTest();
        void ChapterContainerTest();
        void EquipContainerTest();
        void HeroContainerTest();
        void SceneContainerTest();
        void SkillContainerTest();
        void SystemConstantContainerTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CSV_CONFIGURE_TESTING_H
