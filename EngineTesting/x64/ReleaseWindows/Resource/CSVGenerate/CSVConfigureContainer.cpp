/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "CSVConfigureContainer.h"

#include "ChapterContainer.h"
#include "EquipContainer.h"
#include "HeroContainer.h"
#include "SceneContainer.h"
#include "SkillContainer.h"
#include "SystemConstantContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"

#include <filesystem>

using namespace std::literals;

CSVConfigure::CSVConfigureContainer::CSVConfigureContainer(const System::String& directory)
    : chapterContainer{},
      equipContainer{},
      heroContainer{},
      sceneContainer{},
      skillContainer{},
      systemConstantContainer{}
{
    Parsing(directory);
    Verify();

    USER_SELF_CLASS_IS_VALID_1;
}

void CSVConfigure::CSVConfigureContainer::Parsing(const System::String& directory)
{
    const std::filesystem::path path{ directory };

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        auto fileName = inputPath.path().native();

        if (fileName.find(SYSTEM_TEXT(".csv"s)) != (fileName.size() - 4))
        {
            continue;
        }

        CoreTools::CSVContent csvContent{ fileName };

        const auto csvClassName = csvContent.GetCSVClassName();

        if (csvClassName == SYSTEM_TEXT("Chapter"s))
        {
            chapterContainer = std::make_shared<ChapterContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Equip"s))
        {
            equipContainer = std::make_shared<EquipContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Hero"s))
        {
            heroContainer = std::make_shared<HeroContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Scene"s))
        {
            sceneContainer = std::make_shared<SceneContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Skill"s))
        {
            skillContainer = std::make_shared<SkillContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("SystemConstant"s))
        {
            systemConstantContainer = std::make_shared<SystemConstantContainer>(csvContent);
        }
    }
}

void CSVConfigure::CSVConfigureContainer::Verify() const
{
    if (!chapterContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("chapter表不存在。"s))
    }

    if (!equipContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("equip表不存在。"s))
    }

    if (!heroContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("hero表不存在。"s))
    }

    if (!sceneContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("scene表不存在。"s))
    }

    if (!skillContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("skill表不存在。"s))
    }

    if (!systemConstantContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("systemConstant表不存在。"s))
    }

}

#ifdef OPEN_CLASS_INVARIANT

bool CSVConfigure::CSVConfigureContainer::IsValid() const noexcept
{
    if (chapterContainer &&
        equipContainer &&
        heroContainer &&
        sceneContainer &&
        skillContainer &&
        systemConstantContainer)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

std::shared_ptr<const CSVConfigure::ChapterContainer> CSVConfigure::CSVConfigureContainer::GetChapterContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return chapterContainer;
}

std::shared_ptr<const CSVConfigure::EquipContainer> CSVConfigure::CSVConfigureContainer::GetEquipContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return equipContainer;
}

std::shared_ptr<const CSVConfigure::HeroContainer> CSVConfigure::CSVConfigureContainer::GetHeroContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return heroContainer;
}

std::shared_ptr<const CSVConfigure::SceneContainer> CSVConfigure::CSVConfigureContainer::GetSceneContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return sceneContainer;
}

std::shared_ptr<const CSVConfigure::SkillContainer> CSVConfigure::CSVConfigureContainer::GetSkillContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return skillContainer;
}

std::shared_ptr<const CSVConfigure::SystemConstantContainer> CSVConfigure::CSVConfigureContainer::GetSystemConstantContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return systemConstantContainer;
}

