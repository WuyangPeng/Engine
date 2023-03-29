///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.4 (2023/03/10 10:14)

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
        void DoRunUnitTest() override;
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
