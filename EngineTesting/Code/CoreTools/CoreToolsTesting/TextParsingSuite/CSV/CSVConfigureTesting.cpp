/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/05/31 11:05)

#include "CSVConfigureTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/BatchConversionCSV.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/CSVConfigureContainer.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/Chapter.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/ChapterContainerDetail.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/Equip.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/EquipContainerDetail.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/Hero.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/HeroContainerDetail.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/Scene.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/SceneContainerDetail.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/Skill.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/SkillContainerDetail.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/SystemConstant.h"
#include "Toolset/CoreTools/CSVConfigure/CSVConfigure/SystemConstantContainer.h"

#include <ranges>

CoreTools::CSVConfigureTesting::CSVConfigureTesting(const OStreamShared& stream)
    : ParentType{ stream },
      directory{ SYSTEM_TEXT("Resource/CSVConfigure") }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVConfigureTesting)

void CoreTools::CSVConfigureTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CSVConfigureTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateCSV);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVConfigureContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChapterContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EquipContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(HeroContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SceneContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SkillContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SystemConstantContainerTest);
}

void CoreTools::CSVConfigureTesting::CreateCSV()
{
    const BatchConversionCSV batchConversionCSV{ directory, directory };
}

void CoreTools::CSVConfigureTesting::CSVConfigureContainerTest()
{
    const CSVConfigure::CSVConfigureContainer csvConfigureContainer{ directory };

    ASSERT_UNEQUAL_NULL_PTR(csvConfigureContainer.GetChapterContainer());
    ASSERT_UNEQUAL_NULL_PTR(csvConfigureContainer.GetEquipContainer());
    ASSERT_UNEQUAL_NULL_PTR(csvConfigureContainer.GetHeroContainer());
    ASSERT_UNEQUAL_NULL_PTR(csvConfigureContainer.GetSceneContainer());
    ASSERT_UNEQUAL_NULL_PTR(csvConfigureContainer.GetSkillContainer());
    ASSERT_UNEQUAL_NULL_PTR(csvConfigureContainer.GetSystemConstantContainer());
}

void CoreTools::CSVConfigureTesting::ChapterContainerTest()
{
    const CSVConfigure::CSVConfigureContainer csvConfigureContainer{ directory };

    const auto chapterContainer = csvConfigureContainer.GetChapterContainer();

    ASSERT_NOT_THROW_EXCEPTION_1(FirstChapterTest, *chapterContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(ChapterKeyTest, *chapterContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(ChapterSizeTest, *chapterContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(FirstChapterSearchTest, *chapterContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(ChapterSizeSearchTest, *chapterContainer);
}

void CoreTools::CSVConfigureTesting::FirstChapterTest(const ChapterContainer& chapterContainer)
{
    const auto firstChapter = chapterContainer.GetFirstChapter();
    ASSERT_UNEQUAL_NULL_PTR(firstChapter);

    ASSERT_EQUAL(firstChapter->GetKey(), beginKey);
}

void CoreTools::CSVConfigureTesting::ChapterKeyTest(const ChapterContainer& chapterContainer)
{
    for (auto i = beginKey; i < endKey; ++i)
    {
        const auto chapter = chapterContainer.GetChapter(i);
        ASSERT_UNEQUAL_NULL_PTR(chapter);

        ASSERT_EQUAL(chapter->GetKey(), i);
    }
}

void CoreTools::CSVConfigureTesting::ChapterSizeTest(const ChapterContainer& chapterContainer)
{
    const auto container = chapterContainer.GetContainer();
    ASSERT_GREATER_EQUAL(boost::numeric_cast<int>(container.size()), endKey - beginKey);

    for (const auto& chapter : container)
    {
        ASSERT_UNEQUAL_NULL_PTR(chapter);
    }
}

void CoreTools::CSVConfigureTesting::FirstChapterSearchTest(const ChapterContainer& chapterContainer)
{
    const auto firstChapter = chapterContainer.GetFirstChapter([](const auto& element) noexcept {
        if (beginKey < element->GetKey() && element->GetKey() < beginKey + 3)
            return true;
        else
            return false;
    });

    ASSERT_UNEQUAL_NULL_PTR(firstChapter);
    ASSERT_EQUAL(firstChapter->GetKey(), beginKey + 1);
}

void CoreTools::CSVConfigureTesting::ChapterSizeSearchTest(const ChapterContainer& chapterContainer)
{
    const auto chapter = chapterContainer.GetChapter([](const auto& element) noexcept {
        if (beginKey < element->GetKey() && element->GetKey() < beginKey + 3)
            return true;
        else
            return false;
    });
    ASSERT_EQUAL(chapter.size(), 2u);
}

void CoreTools::CSVConfigureTesting::EquipContainerTest()
{
    const CSVConfigure::CSVConfigureContainer csvConfigureContainer{ directory };

    const auto equipContainer = csvConfigureContainer.GetEquipContainer();

    ASSERT_NOT_THROW_EXCEPTION_1(EquipKeyTest, *equipContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(EquipSizeTest, *equipContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(FirstEquipSearchTest, *equipContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(EquipSizeSearchTest, *equipContainer);
}

void CoreTools::CSVConfigureTesting::EquipKeyTest(const EquipContainer& equipContainer)
{
    for (auto index = beginKey; index < endKey; ++index)
    {
        const auto equip = equipContainer.GetEquip(index);

        ASSERT_EQUAL(equip.size(), 1u);
        ASSERT_EQUAL(equip.at(0)->GetKey(), index);

        const auto firstEquip = equipContainer.GetFirstEquip(index);
        ASSERT_EQUAL(firstEquip->GetKey(), index);
    }
}

void CoreTools::CSVConfigureTesting::EquipSizeTest(const EquipContainer& equipContainer)
{
    const auto container = equipContainer.GetContainer();
    ASSERT_EQUAL(boost::numeric_cast<int>(container.size()), endKey - beginKey);

    for (const auto& equip : container)
    {
        ASSERT_UNEQUAL_NULL_PTR(equip);
    }
}

void CoreTools::CSVConfigureTesting::FirstEquipSearchTest(const EquipContainer& equipContainer)
{
    const auto firstEquip = equipContainer.GetFirstEquip([](const auto& element) noexcept {
        if (beginKey < element->GetKey() && element->GetKey() < beginKey + 3)
            return true;
        else
            return false;
    });

    ASSERT_UNEQUAL_NULL_PTR(firstEquip);
    ASSERT_EQUAL(firstEquip->GetKey(), beginKey + 1);
}

void CoreTools::CSVConfigureTesting::EquipSizeSearchTest(const EquipContainer& equipContainer)
{
    const auto equip = equipContainer.GetEquip([](const auto& element) noexcept {
        if (beginKey < element->GetKey() && element->GetKey() < beginKey + 3)
            return true;
        else
            return false;
    });
    ASSERT_EQUAL(equip.size(), 2u);
}

void CoreTools::CSVConfigureTesting::HeroContainerTest()
{
    const CSVConfigure::CSVConfigureContainer csvConfigureContainer{ directory };

    const auto heroContainer = csvConfigureContainer.GetHeroContainer();

    ASSERT_NOT_THROW_EXCEPTION_1(FirstHeroTest, *heroContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(HeroKeyTest, *heroContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(HeroSizeTest, *heroContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(FirstHeroSearchTest, *heroContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(HeroSizeSearchTest, *heroContainer);
}

void CoreTools::CSVConfigureTesting::FirstHeroTest(const HeroContainer& heroContainer)
{
    const auto firstHero = heroContainer.GetFirstHero();
    ASSERT_UNEQUAL_NULL_PTR(firstHero);

    ASSERT_EQUAL(firstHero->GetKey(), beginKey);
}

void CoreTools::CSVConfigureTesting::HeroKeyTest(const HeroContainer& heroContainer)
{
    for (auto i = beginKey; i < endKey; ++i)
    {
        auto hero = heroContainer.GetHero(i);
        ASSERT_UNEQUAL_NULL_PTR(hero);

        ASSERT_EQUAL(hero->GetKey(), i);
    }
}

void CoreTools::CSVConfigureTesting::HeroSizeTest(const HeroContainer& heroContainer)
{
    const auto container = heroContainer.GetContainer();
    ASSERT_EQUAL(boost::numeric_cast<int>(container.size()), endKey - beginKey);

    for (const auto& hero : container | std::views::values)
    {
        ASSERT_UNEQUAL_NULL_PTR(hero);
    }
}

void CoreTools::CSVConfigureTesting::FirstHeroSearchTest(const HeroContainer& heroContainer)
{
    const auto firstHero = heroContainer.GetFirstHero([](const auto& element) noexcept {
        if (beginKey < element->GetKey() && element->GetKey() < beginKey + 3)
            return true;
        else
            return false;
    });

    ASSERT_UNEQUAL_NULL_PTR(firstHero);
    ASSERT_EQUAL(firstHero->GetKey(), beginKey + 1);
}

void CoreTools::CSVConfigureTesting::HeroSizeSearchTest(const HeroContainer& heroContainer)
{
    const auto hero = heroContainer.GetHero([](const auto& element) noexcept {
        if (beginKey < element->GetKey() && element->GetKey() < beginKey + 3)
            return true;
        else
            return false;
    });
    ASSERT_EQUAL(hero.size(), 2u);
}

void CoreTools::CSVConfigureTesting::SceneContainerTest()
{
    const CSVConfigure::CSVConfigureContainer csvConfigureContainer{ directory };

    const auto sceneContainer = csvConfigureContainer.GetSceneContainer();

    ASSERT_NOT_THROW_EXCEPTION_1(FirstSceneTest, *sceneContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(SceneKeyTest, *sceneContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(SceneSizeTest, *sceneContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(FirstSceneSearchTest, *sceneContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(SceneSizeSearchTest, *sceneContainer);
}

void CoreTools::CSVConfigureTesting::FirstSceneTest(const SceneContainer& sceneContainer)
{
    const auto firstScene = sceneContainer.GetFirstScene();
    ASSERT_UNEQUAL_NULL_PTR(firstScene);

    ASSERT_EQUAL(firstScene->GetKey(), beginKey);
}

void CoreTools::CSVConfigureTesting::SceneKeyTest(const SceneContainer& sceneContainer)
{
    for (auto i = beginKey; i < endKey; ++i)
    {
        auto scene = sceneContainer.GetScene(i);
        ASSERT_UNEQUAL_NULL_PTR(scene);

        ASSERT_EQUAL(scene->GetKey(), i);
    }
}

void CoreTools::CSVConfigureTesting::SceneSizeTest(const SceneContainer& sceneContainer)
{
    const auto container = sceneContainer.GetContainer();
    ASSERT_EQUAL(boost::numeric_cast<int>(container.size()), endKey - beginKey);

    for (const auto& scene : container | std::views::values)
    {
        ASSERT_UNEQUAL_NULL_PTR(scene);
    }
}

void CoreTools::CSVConfigureTesting::FirstSceneSearchTest(const SceneContainer& sceneContainer)
{
    const auto firstScene = sceneContainer.GetFirstScene([](const auto& element) noexcept {
        if (beginKey < element->GetKey() && element->GetKey() < beginKey + 3)
            return true;
        else
            return false;
    });

    ASSERT_UNEQUAL_NULL_PTR(firstScene);
    ASSERT_EQUAL(firstScene->GetKey(), beginKey + 1);
}

void CoreTools::CSVConfigureTesting::SceneSizeSearchTest(const SceneContainer& sceneContainer)
{
    const auto scene = sceneContainer.GetScene([](const auto& element) noexcept {
        if (beginKey < element->GetKey() && element->GetKey() < beginKey + 3)
            return true;
        else
            return false;
    });
    ASSERT_EQUAL(scene.size(), 2u);
}

void CoreTools::CSVConfigureTesting::SkillContainerTest()
{
    const CSVConfigure::CSVConfigureContainer csvConfigureContainer{ directory };

    const auto skillContainer = csvConfigureContainer.GetSkillContainer();

    ASSERT_NOT_THROW_EXCEPTION_1(FirstSkillTest, *skillContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(SkillKeyTest, *skillContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(SkillSizeTest, *skillContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(FirstSkillSearchTest, *skillContainer);
    ASSERT_NOT_THROW_EXCEPTION_1(SkillSizeSearchTest, *skillContainer);
}

void CoreTools::CSVConfigureTesting::FirstSkillTest(const SkillContainer& skillContainer)
{
    const auto firstSkill = skillContainer.GetFirstSkill();
    ASSERT_UNEQUAL_NULL_PTR(firstSkill);

    ASSERT_EQUAL(firstSkill->GetKey(), CSVConfigure::Skill::GenerateKey(beginKey, 1));
}

void CoreTools::CSVConfigureTesting::SkillKeyTest(const SkillContainer& skillContainer)
{
    auto reward = 1;
    for (auto i = beginKey; i < endKey; ++i)
    {
        auto skill = skillContainer.GetSkill(CSVConfigure::Skill::GenerateKey(i, reward));
        ASSERT_UNEQUAL_NULL_PTR(skill);

        ASSERT_EQUAL(skill->GetKey(), CSVConfigure::Skill::GenerateKey(i, reward));

        ++reward;
    }
}

void CoreTools::CSVConfigureTesting::SkillSizeTest(const SkillContainer& skillContainer)
{
    const auto container = skillContainer.GetContainer();
    ASSERT_EQUAL(boost::numeric_cast<int>(container.size()), endKey - beginKey);

    for (const auto& skill : container)
    {
        ASSERT_UNEQUAL_NULL_PTR(skill);
    }
}

void CoreTools::CSVConfigureTesting::FirstSkillSearchTest(const SkillContainer& skillContainer)
{
    const auto firstSkill = skillContainer.GetFirstSkill([](const auto& element) noexcept {
        if (beginKey < element->GetId() && element->GetId() < beginKey + 3)
            return true;
        else
            return false;
    });

    ASSERT_UNEQUAL_NULL_PTR(firstSkill);
    ASSERT_EQUAL(firstSkill->GetId(), beginKey + 1);
}

void CoreTools::CSVConfigureTesting::SkillSizeSearchTest(const SkillContainer& skillContainer)
{
    const auto skill = skillContainer.GetSkill([](const auto& element) noexcept {
        if (beginKey < element->GetId() && element->GetId() < beginKey + 3)
            return true;
        else
            return false;
    });
    ASSERT_EQUAL(skill.size(), 2u);
}

void CoreTools::CSVConfigureTesting::SystemConstantContainerTest()
{
    const CSVConfigure::CSVConfigureContainer csvConfigureContainer{ directory };

    const auto systemConstantContainer = csvConfigureContainer.GetSystemConstantContainer();

    const auto systemConstant = systemConstantContainer->GetSystemConstant();
    ASSERT_UNEQUAL_NULL_PTR(systemConstant);

    ASSERT_EQUAL(systemConstant->GetKey(), beginKey);
}
