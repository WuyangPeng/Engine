/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++17
/// �Զ�����

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
#include "CoreTools/TextParsing/CSV/CSVHead.h"

#include <filesystem>

using std::make_shared;
using std::shared_ptr;
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
    std::filesystem::path path{ directory };

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        auto fileName = inputPath.path().native();

        if (fileName.find(SYSTEM_TEXT(".csv"s)) != (fileName.size() - 4))
        {
            continue;
        }

        CoreTools::CSVContent csvContent{ fileName };

        auto csvClassName = csvContent.GetCSVClassName();

        if (csvClassName == SYSTEM_TEXT("Chapter"s))
        {
            chapterContainer = make_shared<ChapterContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Equip"s))
        {
            equipContainer = make_shared<EquipContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Hero"s))
        {
            heroContainer = make_shared<HeroContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Scene"s))
        {
            sceneContainer = make_shared<SceneContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("Skill"s))
        {
            skillContainer = make_shared<SkillContainer>(csvContent);
        }
        else if (csvClassName == SYSTEM_TEXT("SystemConstant"s))
        {
            systemConstantContainer = make_shared<SystemConstantContainer>(csvContent);
        }
    }
}

void CSVConfigure::CSVConfigureContainer::Verify()
{
    if (!chapterContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("chapter������"s));
    }

    if (!equipContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("equip������"s));
    }

    if (!heroContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("hero������"s));
    }

    if (!sceneContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("scene������"s));
    }

    if (!skillContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("skill������"s));
    }

    if (!systemConstantContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("systemConstant������"s));
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

shared_ptr<const CSVConfigure::ChapterContainer> CSVConfigure::CSVConfigureContainer::GetChapterContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return chapterContainer;
}

shared_ptr<const CSVConfigure::EquipContainer> CSVConfigure::CSVConfigureContainer::GetEquipContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return equipContainer;
}

shared_ptr<const CSVConfigure::HeroContainer> CSVConfigure::CSVConfigureContainer::GetHeroContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return heroContainer;
}

shared_ptr<const CSVConfigure::SceneContainer> CSVConfigure::CSVConfigureContainer::GetSceneContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return sceneContainer;
}

shared_ptr<const CSVConfigure::SkillContainer> CSVConfigure::CSVConfigureContainer::GetSkillContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return skillContainer;
}

shared_ptr<const CSVConfigure::SystemConstantContainer> CSVConfigure::CSVConfigureContainer::GetSystemConstantContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return systemConstantContainer;
}

