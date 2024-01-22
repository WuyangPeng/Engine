/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "CSVConfigureContainer.h"

#include "ChapterContainer.h"
#include "EquipContainer.h"
#include "HeroContainer.h"
#include "SceneContainer.h"
#include "SkillContainer.h"
#include "SystemConstantContainer.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"

using namespace std::literals;

CSVConfigure::CSVConfigureContainer::CSVConfigureContainer(const String& directory)
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

void CSVConfigure::CSVConfigureContainer::Parsing(const String& directory)
{
    for (const std::filesystem::path path{ directory };
         const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        Parsing(inputPath);
    }
}

void CSVConfigure::CSVConfigureContainer::Parsing(const std::filesystem::directory_entry& inputPath)
{
    const auto fileName = inputPath.path().native();

    if (fileName.find(L".csv"s) != (fileName.size() - 4))
    {
        return;
    }

    const CoreTools::CSVContent csvContent{ CoreTools::StringConversion::WideCharConversionStandard(fileName) };

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

void CSVConfigure::CSVConfigureContainer::Verify() const
{
    if (chapterContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("chapter�����ڡ�"s))
    }

    if (equipContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("equip�����ڡ�"s))
    }

    if (heroContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("hero�����ڡ�"s))
    }

    if (sceneContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("scene�����ڡ�"s))
    }

    if (skillContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("skill�����ڡ�"s))
    }

    if (systemConstantContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("systemConstant�����ڡ�"s))
    }

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("CSVConfigure�������롭��"));
}

#ifdef OPEN_CLASS_INVARIANT

bool CSVConfigure::CSVConfigureContainer::IsValid() const noexcept
{
    if (chapterContainer != nullptr &&
        equipContainer != nullptr &&
        heroContainer != nullptr &&
        sceneContainer != nullptr &&
        skillContainer != nullptr &&
        systemConstantContainer != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

CSVConfigure::CSVConfigureContainer::ConstChapterContainerSharedPtr CSVConfigure::CSVConfigureContainer::GetChapterContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return chapterContainer;
}

CSVConfigure::CSVConfigureContainer::ConstEquipContainerSharedPtr CSVConfigure::CSVConfigureContainer::GetEquipContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return equipContainer;
}

CSVConfigure::CSVConfigureContainer::ConstHeroContainerSharedPtr CSVConfigure::CSVConfigureContainer::GetHeroContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return heroContainer;
}

CSVConfigure::CSVConfigureContainer::ConstSceneContainerSharedPtr CSVConfigure::CSVConfigureContainer::GetSceneContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return sceneContainer;
}

CSVConfigure::CSVConfigureContainer::ConstSkillContainerSharedPtr CSVConfigure::CSVConfigureContainer::GetSkillContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return skillContainer;
}

CSVConfigure::CSVConfigureContainer::ConstSystemConstantContainerSharedPtr CSVConfigure::CSVConfigureContainer::GetSystemConstantContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return systemConstantContainer;
}

