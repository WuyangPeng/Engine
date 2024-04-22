/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:27)

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
