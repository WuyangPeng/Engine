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
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/CSVConfigureContainer.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/ChapterBase.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/ChapterContainer.h"

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
        static constexpr auto beginKey = 10001;
        static constexpr auto endKey = 10007;
        using String = System::String;
        using ChapterContainer = CSVConfigure::ChapterContainer;
        using EquipContainer = CSVConfigure::EquipContainer;
        using HeroContainer = CSVConfigure::HeroContainer;
        using SceneContainer = CSVConfigure::SceneContainer;
        using SkillContainer = CSVConfigure::SkillContainer;

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

        void FirstChapterTest(const ChapterContainer& chapterContainer);
        void ChapterKeyTest(const ChapterContainer& chapterContainer);
        void ChapterSizeTest(const ChapterContainer& chapterContainer);
        void FirstChapterSearchTest(const ChapterContainer& chapterContainer);
        void ChapterSizeSearchTest(const ChapterContainer& chapterContainer);

        void EquipKeyTest(const EquipContainer& equipContainer);
        void EquipSizeTest(const EquipContainer& equipContainer);
        void FirstEquipSearchTest(const EquipContainer& equipContainer);
        void EquipSizeSearchTest(const EquipContainer& equipContainer);

        void FirstHeroTest(const HeroContainer& heroContainer);
        void HeroKeyTest(const HeroContainer& heroContainer);
        void HeroSizeTest(const HeroContainer& heroContainer);
        void FirstHeroSearchTest(const HeroContainer& heroContainer);
        void HeroSizeSearchTest(const HeroContainer& heroContainer);

        void FirstSceneTest(const SceneContainer& sceneContainer);
        void SceneKeyTest(const SceneContainer& sceneContainer);
        void SceneSizeTest(const SceneContainer& sceneContainer);
        void FirstSceneSearchTest(const SceneContainer& sceneContainer);
        void SceneSizeSearchTest(const SceneContainer& sceneContainer);

        void FirstSkillTest(const SkillContainer& skillContainer);
        void SkillKeyTest(const SkillContainer& skillContainer);
        void SkillSizeTest(const SkillContainer& skillContainer);
        void FirstSkillSearchTest(const SkillContainer& skillContainer);
        void SkillSizeSearchTest(const SkillContainer& skillContainer);

    private:
        String directory;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CSV_CONFIGURE_TESTING_H
