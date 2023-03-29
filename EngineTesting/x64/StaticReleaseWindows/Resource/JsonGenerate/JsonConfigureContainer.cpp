/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "JsonConfigureContainer.h"

#include "Monsters.h"
#include "Parts.h"
#include "Road.h"
#include "RunScenes.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Json/JsonRow.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"

#include <filesystem>

using namespace std::literals;

JsonConfigure::JsonConfigureContainer::JsonConfigureContainer(const System::String& directory)
    : monstersContainer{},
      partsContainer{},
      roadContainer{},
      runScenesContainer{}
{
    Parsing(directory);
    Verify();

    USER_SELF_CLASS_IS_VALID_1;
}

void JsonConfigure::JsonConfigureContainer::Parsing(const System::String& directory)
{
    const std::filesystem::path path{ directory };

    for (const auto& inputPath : std::filesystem::directory_iterator(path))
    {
        auto fileName = inputPath.path().native();

        if (fileName.find(SYSTEM_TEXT(".json"s)) != (fileName.size() - 5))
        {
            continue;
        }

        CoreTools::JsonRow::BasicTree basicTree{ fileName };
        read_json(CoreTools::StringConversion::StandardConversionMultiByte(fileName), basicTree);

        CoreTools::JsonRow jsonRow{ basicTree };
        CoreTools::JsonHead jsonHead{ fileName };
        const auto className = jsonHead.GetJsonClassName();

        if (className == SYSTEM_TEXT("Monsters"s))
        {
            monstersContainer = std::make_shared<MonstersContainer>(jsonRow);
        }
        else if (className == SYSTEM_TEXT("Parts"s))
        {
            partsContainer = std::make_shared<PartsContainer>(jsonRow);
        }
        else if (className == SYSTEM_TEXT("Road"s))
        {
            roadContainer = std::make_shared<RoadContainer>(jsonRow);
        }
        else if (className == SYSTEM_TEXT("RunScenes"s))
        {
            runScenesContainer = std::make_shared<RunScenesContainer>(jsonRow);
        }
    }
}

void JsonConfigure::JsonConfigureContainer::Verify() const
{
    if (!monstersContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("monsters表不存在。"s))
    }

    if (!partsContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("parts表不存在。"s))
    }

    if (!roadContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("road表不存在。"s))
    }

    if (!runScenesContainer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("runScenes表不存在。"s))
    }

}

#ifdef OPEN_CLASS_INVARIANT

bool JsonConfigure::JsonConfigureContainer::IsValid() const noexcept
{
    if (monstersContainer &&
        partsContainer &&
        roadContainer &&
        runScenesContainer)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

std::shared_ptr<const JsonConfigure::MonstersContainer> JsonConfigure::JsonConfigureContainer::GetMonstersContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return monstersContainer;
}

std::shared_ptr<const JsonConfigure::PartsContainer> JsonConfigure::JsonConfigureContainer::GetPartsContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return partsContainer;
}

std::shared_ptr<const JsonConfigure::RoadContainer> JsonConfigure::JsonConfigureContainer::GetRoadContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return roadContainer;
}

std::shared_ptr<const JsonConfigure::RunScenesContainer> JsonConfigure::JsonConfigureContainer::GetRunScenesContainer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_1;

    return runScenesContainer;
}

