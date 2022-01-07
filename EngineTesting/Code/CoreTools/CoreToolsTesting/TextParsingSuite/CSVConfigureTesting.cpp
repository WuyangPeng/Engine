///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.5 (2021/10/17 12:49)

#include "CSVConfigureTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/BatchConversionCSV.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVGenerate.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
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

using namespace std::literals;

CoreTools::CSVConfigureTesting::CSVConfigureTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
    const BatchConversionCSV batchConversionCSV{ SYSTEM_TEXT("Resource/CSVConfigure"s), SYSTEM_TEXT("Resource/CSVConfigure") };
}

void CoreTools::CSVConfigureTesting::CSVConfigureContainerTest()
{
    CSVConfigure::CSVConfigureContainer csvConfigureContainer{ SYSTEM_TEXT("Resource/CSVConfigure"s) };

    ASSERT_UNEQUAL_NULL_PTR(csvConfigureContainer.GetChapterContainer());
    ASSERT_UNEQUAL_NULL_PTR(csvConfigureContainer.GetEquipContainer());
    ASSERT_UNEQUAL_NULL_PTR(csvConfigureContainer.GetHeroContainer());
    ASSERT_UNEQUAL_NULL_PTR(csvConfigureContainer.GetSceneContainer());
    ASSERT_UNEQUAL_NULL_PTR(csvConfigureContainer.GetSkillContainer());
    ASSERT_UNEQUAL_NULL_PTR(csvConfigureContainer.GetSystemConstantContainer());
}

void CoreTools::CSVConfigureTesting::ChapterContainerTest()
{
    CSVConfigure::CSVConfigureContainer csvConfigureContainer{ SYSTEM_TEXT("Resource/CSVConfigure"s) };

    auto chapterContainer = csvConfigureContainer.GetChapterContainer();

    auto firstChapter = chapterContainer->GetFirstChapter();
    ASSERT_UNEQUAL_NULL_PTR(firstChapter);

    ASSERT_EQUAL(firstChapter->GetKey(), 10001);

    for (auto i = 10001; i < 10007; ++i)
    {
        auto chapter = chapterContainer->GetChapter(i);
        ASSERT_UNEQUAL_NULL_PTR(chapter);

        ASSERT_EQUAL(chapter->GetKey(), i);
    }

    auto container = chapterContainer->GetContainer();
    ASSERT_EQUAL(container.size(), 6u);

    for (const auto& chapter : container)
    {
        ASSERT_UNEQUAL_NULL_PTR(chapter);
    }

    firstChapter = chapterContainer->GetFirstChapter([](const auto& value) noexcept {
        if (10001 < value->GetKey() && value->GetKey() < 10004)
            return true;
        else
            return false;
    });

    ASSERT_UNEQUAL_NULL_PTR(firstChapter);
    ASSERT_EQUAL(firstChapter->GetKey(), 10002);

    auto chapter = chapterContainer->GetChapter([](const auto& value) noexcept {
        if (10001 < value->GetKey() && value->GetKey() < 10004)
            return true;
        else
            return false;
    });
    ASSERT_EQUAL(chapter.size(), 2u);
}

void CoreTools::CSVConfigureTesting::EquipContainerTest()
{
    CSVConfigure::CSVConfigureContainer csvConfigureContainer{ SYSTEM_TEXT("Resource/CSVConfigure"s) };

    auto equipContainer = csvConfigureContainer.GetEquipContainer();

    for (auto i = 10001; i < 10007; ++i)
    {
        auto equip = equipContainer->GetEquip(i);

        ASSERT_EQUAL(equip.size(), 1u);
        ASSERT_EQUAL(equip.at(0)->GetKey(), i);

        auto firstEquip = equipContainer->GetFirstEquip(i);
        ASSERT_EQUAL(firstEquip->GetKey(), i);
    }

    auto container = equipContainer->GetContainer();
    ASSERT_EQUAL(container.size(), 6u);

    for (const auto& equip : container)
    {
        ASSERT_UNEQUAL_NULL_PTR(equip);
    }

    auto firstEquip = equipContainer->GetFirstEquip([](const auto& value) noexcept {
        if (10001 < value->GetKey() && value->GetKey() < 10004)
            return true;
        else
            return false;
    });

    ASSERT_UNEQUAL_NULL_PTR(firstEquip);
    ASSERT_EQUAL(firstEquip->GetKey(), 10002);

    auto equip = equipContainer->GetEquip([](const auto& value) noexcept {
        if (10001 < value->GetKey() && value->GetKey() < 10004)
            return true;
        else
            return false;
    });
    ASSERT_EQUAL(equip.size(), 2u);
}

void CoreTools::CSVConfigureTesting::HeroContainerTest()
{
    CSVConfigure::CSVConfigureContainer csvConfigureContainer{ SYSTEM_TEXT("Resource/CSVConfigure"s) };

    auto heroContainer = csvConfigureContainer.GetHeroContainer();

    auto firstHero = heroContainer->GetFirstHero();
    ASSERT_UNEQUAL_NULL_PTR(firstHero);

    ASSERT_EQUAL(firstHero->GetKey(), 10001);

    for (auto i = 10001; i < 10007; ++i)
    {
        auto hero = heroContainer->GetHero(i);
        ASSERT_UNEQUAL_NULL_PTR(hero);

        ASSERT_EQUAL(hero->GetKey(), i);
    }

    auto container = heroContainer->GetContainer();
    ASSERT_EQUAL(container.size(), 6u);

    for (const auto& hero : container)
    {
        ASSERT_UNEQUAL_NULL_PTR(hero.second);
    }

    firstHero = heroContainer->GetFirstHero([](const auto& value) noexcept {
        if (10001 < value->GetKey() && value->GetKey() < 10004)
            return true;
        else
            return false;
    });

    ASSERT_UNEQUAL_NULL_PTR(firstHero);
    ASSERT_EQUAL(firstHero->GetKey(), 10002);

    auto hero = heroContainer->GetHero([](const auto& value) noexcept {
        if (10001 < value->GetKey() && value->GetKey() < 10004)
            return true;
        else
            return false;
    });
    ASSERT_EQUAL(hero.size(), 2u);
}

void CoreTools::CSVConfigureTesting::SceneContainerTest()
{
    CSVConfigure::CSVConfigureContainer csvConfigureContainer{ SYSTEM_TEXT("Resource/CSVConfigure"s) };

    auto sceneContainer = csvConfigureContainer.GetSceneContainer();

    auto firstScene = sceneContainer->GetFirstScene();
    ASSERT_UNEQUAL_NULL_PTR(firstScene);

    ASSERT_EQUAL(firstScene->GetKey(), 10001);

    for (auto i = 10001; i < 10007; ++i)
    {
        auto scene = sceneContainer->GetScene(i);
        ASSERT_UNEQUAL_NULL_PTR(scene);

        ASSERT_EQUAL(scene->GetKey(), i);
    }

    auto container = sceneContainer->GetContainer();
    ASSERT_EQUAL(container.size(), 6u);

    for (const auto& scene : container)
    {
        ASSERT_UNEQUAL_NULL_PTR(scene.second);
    }

    firstScene = sceneContainer->GetFirstScene([](const auto& value) noexcept {
        if (10001 < value->GetKey() && value->GetKey() < 10004)
            return true;
        else
            return false;
    });

    ASSERT_UNEQUAL_NULL_PTR(firstScene);
    ASSERT_EQUAL(firstScene->GetKey(), 10002);

    auto scene = sceneContainer->GetScene([](const auto& value) noexcept {
        if (10001 < value->GetKey() && value->GetKey() < 10004)
            return true;
        else
            return false;
    });
    ASSERT_EQUAL(scene.size(), 2u);
}

void CoreTools::CSVConfigureTesting::SkillContainerTest()
{
    CSVConfigure::CSVConfigureContainer csvConfigureContainer{ SYSTEM_TEXT("Resource/CSVConfigure"s) };

    auto skillContainer = csvConfigureContainer.GetSkillContainer();

    auto firstSkill = skillContainer->GetFirstSkill();
    ASSERT_UNEQUAL_NULL_PTR(firstSkill);

    ASSERT_EQUAL(firstSkill->GetKey(), 10001 * 100 + 1);

    auto reward = 1;
    for (auto i = 10001; i < 10007; ++i)
    {
        auto skill = skillContainer->GetSkill(i, reward);
        ASSERT_UNEQUAL_NULL_PTR(skill);

        ASSERT_EQUAL(skill->GetKey(), i * 100 + reward);

        ++reward;
    }

    auto container = skillContainer->GetContainer();
    ASSERT_EQUAL(container.size(), 6u);

    for (const auto& skill : container)
    {
        ASSERT_UNEQUAL_NULL_PTR(skill);
    }

    firstSkill = skillContainer->GetFirstSkill([](const auto& value) noexcept {
        if (10001 < value->GetID() && value->GetID() < 10004)
            return true;
        else
            return false;
    });

    ASSERT_UNEQUAL_NULL_PTR(firstSkill);
    ASSERT_EQUAL(firstSkill->GetID(), 10002);

    auto skill = skillContainer->GetSkill([](const auto& value) noexcept {
        if (10001 < value->GetID() && value->GetID() < 10004)
            return true;
        else
            return false;
    });
    ASSERT_EQUAL(skill.size(), 2u);
}

void CoreTools::CSVConfigureTesting::SystemConstantContainerTest()
{
    CSVConfigure::CSVConfigureContainer csvConfigureContainer{ SYSTEM_TEXT("Resource/CSVConfigure"s) };

    auto systemConstantContainer = csvConfigureContainer.GetSystemConstantContainer();

    auto systemConstant = systemConstantContainer->GetSystemConstant();
    ASSERT_UNEQUAL_NULL_PTR(systemConstant);

    ASSERT_EQUAL(systemConstant->GetKey(), 10001);
}
