///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.5 (2021/10/21 15:26)

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
