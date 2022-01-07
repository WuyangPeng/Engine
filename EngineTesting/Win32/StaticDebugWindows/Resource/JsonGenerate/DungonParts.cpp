/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

#include "DungonParts.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/Json/JsonRow.h"

#include <algorithm>

using std::make_shared;
using namespace std::literals;

JsonConfigure::DungonPartsContainer::DungonPartsContainer(const CoreTools::JsonRow& jsonRow)
    : datas{}
{
    Parsing(jsonRow);

    USER_SELF_CLASS_IS_VALID_9;
}

void JsonConfigure::DungonPartsContainer::Parsing(const CoreTools::JsonRow& jsonRow)
{
    const auto datasSize = jsonRow.GetCount(SYSTEM_TEXT("datas"s));

    for (auto i = 0; i < datasSize; ++i)
    {
        datas.emplace_back(make_shared<DungonParts::Datas>(jsonRow.GetJsonRow(SYSTEM_TEXT("datas"s), i)));
    }

    std::sort(datas.begin(), datas.end(), [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetID() < (*rhs).GetID();
    });

    auto datasIter = unique(datas.begin(), datas.end(), [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetID() == (*rhs).GetID();
    });

    if (datasIter != datas.cend())
    {
         LOG_SINGLETON_ENGINE_APPENDER(Warn, User)
            << SYSTEM_TEXT("dungonParts表datas字段存在重复主键。")
            << LOG_SINGLETON_TRIGGER_ASSERT;

        datas.erase(datasIter, datas.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

JsonConfigure::DungonPartsContainer::ConstDatasSharedPtr JsonConfigure::DungonPartsContainer::GetFirstDatas() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return datas.at(0);
}

JsonConfigure::DungonPartsContainer::ConstDatasSharedPtr JsonConfigure::DungonPartsContainer::GetDatas(int id) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetID() < (*rhs).GetID();
    };

    const auto iter = lower_bound(datas.cbegin(), datas.cend(), make_shared<DungonParts::Datas>(id), function);

    if (iter != datas.cend() && (*iter)->GetID() == id)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("dungonParts表datasdatas字段未找到id = "s) + System::ToString(id) + SYSTEM_TEXT("的配置信息。"s));
    }
}

JsonConfigure::DungonPartsContainer::DatasContainer JsonConfigure::DungonPartsContainer::GetDatasContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return datas;
}

JsonConfigure::DungonParts::Datas::Datas(const CoreTools::JsonRow& jsonRow)
    : id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      name{ jsonRow.GetString(SYSTEM_TEXT("name"s)) },
      scenes{},
      groups{},
      passFlag{ jsonRow.GetInt(SYSTEM_TEXT("passFlag"s)) },
      passParams{},
      passEvent{ jsonRow.GetInt(SYSTEM_TEXT("passEvent"s)) },
      runSpeedSacle{ jsonRow.GetDouble(SYSTEM_TEXT("runSpeedSacle"s)) },
      loop{ jsonRow.GetInt(SYSTEM_TEXT("loop"s)) }
{
    Parsing(jsonRow);

    USER_SELF_CLASS_IS_VALID_9;
}

void JsonConfigure::DungonPartsContainer::Parsing(const CoreTools::JsonRow& jsonRow)
{
    const auto datasSize = jsonRow.GetCount(SYSTEM_TEXT("datas"s));

    for (auto i = 0; i < datasSize; ++i)
    {
        datas.emplace_back(make_shared<DungonParts::Datas>(jsonRow.GetJsonRow(SYSTEM_TEXT("datas"s), i)));
    }

    std::sort(datas.begin(), datas.end(), [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetID() < (*rhs).GetID();
    });

    auto datasIter = unique(datas.begin(), datas.end(), [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetID() == (*rhs).GetID();
    });

    if (datasIter != datas.cend())
    {
         LOG_SINGLETON_ENGINE_APPENDER(Warn, User)
            << SYSTEM_TEXT("dungonParts表datas字段存在重复主键。")
            << LOG_SINGLETON_TRIGGER_ASSERT;

        datas.erase(datasIter, datas.end());
    }
}

JsonConfigure::DungonParts::Datas::Datas(int id)
    : id{ id },
      name{},
      scenes{},
      groups{},
      passFlag{},
      passParams{},
      passEvent{},
      runSpeedSacle{},
      loop{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

int JsonConfigure::DungonParts::Datas::GetID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

System::String JsonConfigure::DungonParts::Datas::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

JsonConfigure::DungonParts::Datas::ConstScenesSharedPtr JsonConfigure::DungonParts::Datas::GetFirstScenes() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return scenes.at(0);
}

JsonConfigure::DungonParts::Datas::ConstScenesSharedPtr JsonConfigure::DungonParts::Datas::GetScenes(int id) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetID() < (*rhs).GetID();
    };

    const auto iter = lower_bound(scenes.cbegin(), scenes.cend(), make_shared<DungonParts::Scenes>(id), function);

    if (iter != scenes.cend() && (*iter)->GetID() == id)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("dungonParts表scenes字段未找到id = "s) + System::ToString(id) + SYSTEM_TEXT("的配置信息。"s));
    }
}

JsonConfigure::DungonParts::Datas::ScenesContainer JsonConfigure::DungonParts::Datas::GetScenesContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return scenes;
}

JsonConfigure::DungonParts::Datas::ConstGroupsSharedPtr JsonConfigure::DungonParts::Datas::GetFirstGroups() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return groups.at(0);
}

JsonConfigure::DungonParts::Datas::ConstGroupsSharedPtr JsonConfigure::DungonParts::Datas::GetGroups(int id) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetID() < (*rhs).GetID();
    };

    const auto iter = lower_bound(groups.cbegin(), groups.cend(), make_shared<DungonParts::Groups>(id), function);

    if (iter != groups.cend() && (*iter)->GetID() == id)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("dungonParts表groups字段未找到id = "s) + System::ToString(id) + SYSTEM_TEXT("的配置信息。"s));
    }
}

JsonConfigure::DungonParts::Datas::GroupsContainer JsonConfigure::DungonParts::Datas::GetGroupsContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return groups;
}

int JsonConfigure::DungonParts::Datas::GetPassFlag() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return passFlag;
}

JsonConfigure::DungonParts::Datas::ConstPassParamsSharedPtr JsonConfigure::DungonParts::Datas::GetFirstPassParams() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return passParams.at(0);
}

JsonConfigure::DungonParts::Datas::ConstPassParamsSharedPtr JsonConfigure::DungonParts::Datas::GetPassParams(int id) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetID() < (*rhs).GetID();
    };

    const auto iter = lower_bound(passParams.cbegin(), passParams.cend(), make_shared<DungonParts::PassParams>(id), function);

    if (iter != passParams.cend() && (*iter)->GetID() == id)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("dungonParts表passParams字段未找到id = "s) + System::ToString(id) + SYSTEM_TEXT("的配置信息。"s));
    }
}

JsonConfigure::DungonParts::Datas::PassParamsContainer JsonConfigure::DungonParts::Datas::GetPassParamsContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return passParams;
}

int JsonConfigure::DungonParts::Datas::GetPassEvent() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return passEvent;
}

double JsonConfigure::DungonParts::Datas::GetRunSpeedSacle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return runSpeedSacle;
}

int JsonConfigure::DungonParts::Datas::GetLoop() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return loop;
}

JsonConfigure::DungonParts::Scenes::Scenes(const CoreTools::JsonRow& jsonRow)
    : id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      nextPos{ make_shared<NextPos>(jsonRow.GetJsonRow(SYSTEM_TEXT("nextPos"s))) },
      up{ make_shared<Up>(jsonRow.GetJsonRow(SYSTEM_TEXT("up"s))) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

JsonConfigure::DungonParts::Scenes::Scenes(int id)
    : id{ id },
      nextPos{},
      up{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

int JsonConfigure::DungonParts::Scenes::GetID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

JsonConfigure::DungonParts::Scenes::ConstNextPosSharedPtr JsonConfigure::DungonParts::Scenes::GetNextPos() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return nextPos;
}

JsonConfigure::DungonParts::Scenes::ConstUpSharedPtr JsonConfigure::DungonParts::Scenes::GetUp() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return up;
}

JsonConfigure::DungonParts::NextPos::NextPos(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::NextPos::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::NextPos::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::NextPos::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::Up::Up(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::Up::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Up::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Up::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::Groups::Groups(const CoreTools::JsonRow& jsonRow)
    : weight{ jsonRow.GetInt(SYSTEM_TEXT("weight"s)) },
      count{ jsonRow.GetInt(SYSTEM_TEXT("count"s)) },
      must{ jsonRow.GetBool(SYSTEM_TEXT("must"s)) },
      ,
      ,
      elements{},
      ,
      elements{},
      ,
      elements{},
      ,
      ,
      elements{},
      
{
    Parsing(jsonRow);

    USER_SELF_CLASS_IS_VALID_9;
}

void JsonConfigure::DungonPartsContainer::Parsing(const CoreTools::JsonRow& jsonRow)
{
    const auto datasSize = jsonRow.GetCount(SYSTEM_TEXT("datas"s));

    for (auto i = 0; i < datasSize; ++i)
    {
        datas.emplace_back(make_shared<DungonParts::Datas>(jsonRow.GetJsonRow(SYSTEM_TEXT("datas"s), i)));
    }

    std::sort(datas.begin(), datas.end(), [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetID() < (*rhs).GetID();
    });

    auto datasIter = unique(datas.begin(), datas.end(), [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetID() == (*rhs).GetID();
    });

    if (datasIter != datas.cend())
    {
         LOG_SINGLETON_ENGINE_APPENDER(Warn, User)
            << SYSTEM_TEXT("dungonParts表datas字段存在重复主键。")
            << LOG_SINGLETON_TRIGGER_ASSERT;

        datas.erase(datasIter, datas.end());
    }
}

JsonConfigure::DungonParts::Groups::Groups(int id)
    : weight{},
      count{},
      must{},
      elements{},
      monsters{},
      elements{},
      monsters{},
      elements{},
      monsters{},
      elements{},
      monsters{},
      monsters{},
      elements{},
      monsters{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

int JsonConfigure::DungonParts::Groups::GetWeight() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return weight;
}

int JsonConfigure::DungonParts::Groups::GetCount() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return count;
}

bool JsonConfigure::DungonParts::Groups::IsMust() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return must;
}

JsonConfigure::DungonParts::Groups::ConstElementsSharedPtr JsonConfigure::DungonParts::Groups::GetFirstElements() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return elements.at(0);
}

JsonConfigure::DungonParts::Groups::ConstElementsSharedPtr JsonConfigure::DungonParts::Groups::GetElements(int id) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetID() < (*rhs).GetID();
    };

    const auto iter = lower_bound(elements.cbegin(), elements.cend(), make_shared<DungonParts::Elements>(id), function);

    if (iter != elements.cend() && (*iter)->GetID() == id)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("dungonParts表elements字段未找到id = "s) + System::ToString(id) + SYSTEM_TEXT("的配置信息。"s));
    }
}

JsonConfigure::DungonParts::Groups::ElementsContainer JsonConfigure::DungonParts::Groups::GetElementsContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return elements;
}

JsonConfigure::DungonParts::Groups::ConstElementsSharedPtr JsonConfigure::DungonParts::Groups::GetFirstElements() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return elements.at(0);
}

JsonConfigure::DungonParts::Groups::ConstElementsSharedPtr JsonConfigure::DungonParts::Groups::GetElements(int id) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetID() < (*rhs).GetID();
    };

    const auto iter = lower_bound(elements.cbegin(), elements.cend(), make_shared<DungonParts::Elements>(id), function);

    if (iter != elements.cend() && (*iter)->GetID() == id)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("dungonParts表elements字段未找到id = "s) + System::ToString(id) + SYSTEM_TEXT("的配置信息。"s));
    }
}

JsonConfigure::DungonParts::Groups::ElementsContainer JsonConfigure::DungonParts::Groups::GetElementsContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return elements;
}

JsonConfigure::DungonParts::Groups::ConstElementsSharedPtr JsonConfigure::DungonParts::Groups::GetFirstElements() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return elements.at(0);
}

JsonConfigure::DungonParts::Groups::ConstElementsSharedPtr JsonConfigure::DungonParts::Groups::GetElements(int id) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetID() < (*rhs).GetID();
    };

    const auto iter = lower_bound(elements.cbegin(), elements.cend(), make_shared<DungonParts::Elements>(id), function);

    if (iter != elements.cend() && (*iter)->GetID() == id)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("dungonParts表elements字段未找到id = "s) + System::ToString(id) + SYSTEM_TEXT("的配置信息。"s));
    }
}

JsonConfigure::DungonParts::Groups::ElementsContainer JsonConfigure::DungonParts::Groups::GetElementsContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return elements;
}

JsonConfigure::DungonParts::Groups::ConstElementsSharedPtr JsonConfigure::DungonParts::Groups::GetFirstElements() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return elements.at(0);
}

JsonConfigure::DungonParts::Groups::ConstElementsSharedPtr JsonConfigure::DungonParts::Groups::GetElements(int id) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetID() < (*rhs).GetID();
    };

    const auto iter = lower_bound(elements.cbegin(), elements.cend(), make_shared<DungonParts::Elements>(id), function);

    if (iter != elements.cend() && (*iter)->GetID() == id)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("dungonParts表elements字段未找到id = "s) + System::ToString(id) + SYSTEM_TEXT("的配置信息。"s));
    }
}

JsonConfigure::DungonParts::Groups::ElementsContainer JsonConfigure::DungonParts::Groups::GetElementsContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return elements;
}

JsonConfigure::DungonParts::Elements::Elements(const CoreTools::JsonRow& jsonRow)
    : id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      offset{ make_shared<Offset>(jsonRow.GetJsonRow(SYSTEM_TEXT("offset"s))) },
      count{ jsonRow.GetInt(SYSTEM_TEXT("count"s)) },
      must{ jsonRow.GetBool(SYSTEM_TEXT("must"s)) },
      weight{ jsonRow.GetInt(SYSTEM_TEXT("weight"s)) },
      element{ make_shared<Element>(jsonRow.GetJsonRow(SYSTEM_TEXT("element"s))) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

JsonConfigure::DungonParts::Elements::Elements(int id)
    : id{ id },
      offset{},
      count{},
      must{},
      weight{},
      element{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

int JsonConfigure::DungonParts::Elements::GetID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

JsonConfigure::DungonParts::Elements::ConstOffsetSharedPtr JsonConfigure::DungonParts::Elements::GetOffset() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return offset;
}

int JsonConfigure::DungonParts::Elements::GetCount() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return count;
}

bool JsonConfigure::DungonParts::Elements::IsMust() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return must;
}

int JsonConfigure::DungonParts::Elements::GetWeight() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return weight;
}

JsonConfigure::DungonParts::Elements::ConstElementSharedPtr JsonConfigure::DungonParts::Elements::GetElement() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return element;
}

JsonConfigure::DungonParts::Offset::Offset(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::Offset::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Offset::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Offset::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::Element::Element(const CoreTools::JsonRow& jsonRow)
    : name{ jsonRow.GetString(SYSTEM_TEXT("name"s)) },
      id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      { make_shared<>(jsonRow.GetJsonRow(SYSTEM_TEXT(""s))) },
      
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

System::String JsonConfigure::DungonParts::Element::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

int JsonConfigure::DungonParts::Element::GetID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

JsonConfigure::DungonParts::Element::ConstSharedPtr JsonConfigure::DungonParts::Element::Get() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return ;
}

JsonConfigure::DungonParts::Elements::Elements(const CoreTools::JsonRow& jsonRow)
    : position{ make_shared<Position>(jsonRow.GetJsonRow(SYSTEM_TEXT("position"s))) },
      eulerAngle{ make_shared<EulerAngle>(jsonRow.GetJsonRow(SYSTEM_TEXT("eulerAngle"s))) },
      transfer{ make_shared<Transfer>(jsonRow.GetJsonRow(SYSTEM_TEXT("transfer"s))) },
      id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      targetRadius{ jsonRow.GetDouble(SYSTEM_TEXT("targetRadius"s)) },
      ,
      ,
      terrainY{ jsonRow.GetBool(SYSTEM_TEXT("terrainY"s)) },
      ,
      
{
    USER_SELF_CLASS_IS_VALID_9;
}

JsonConfigure::DungonParts::Elements::Elements(int id)
    : position{},
      eulerAngle{},
      transfer{},
      id{ id },
      targetRadius{},
      targetFilters{},
      triggerParam{},
      terrainY{},
      targetFilters{},
      triggerParam{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

JsonConfigure::DungonParts::Elements::ConstPositionSharedPtr JsonConfigure::DungonParts::Elements::GetPosition() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return position;
}

JsonConfigure::DungonParts::Elements::ConstEulerAngleSharedPtr JsonConfigure::DungonParts::Elements::GetEulerAngle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return eulerAngle;
}

JsonConfigure::DungonParts::Elements::ConstTransferSharedPtr JsonConfigure::DungonParts::Elements::GetTransfer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return transfer;
}

int JsonConfigure::DungonParts::Elements::GetID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

double JsonConfigure::DungonParts::Elements::GetTargetRadius() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return targetRadius;
}

bool JsonConfigure::DungonParts::Elements::IsTerrainY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return terrainY;
}

JsonConfigure::DungonParts::Position::Position(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::Position::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Position::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Position::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::EulerAngle::EulerAngle(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::EulerAngle::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::EulerAngle::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::EulerAngle::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::Transfer::Transfer(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) },
      x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) },
      x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) },
      serializedVersion{ jsonRow.GetInt(SYSTEM_TEXT("serializedVersion"s)) },
      ,
      preInfinity{ jsonRow.GetInt(SYSTEM_TEXT("preInfinity"s)) },
      postInfinity{ jsonRow.GetInt(SYSTEM_TEXT("postInfinity"s)) },
      rotationOrder{ jsonRow.GetInt(SYSTEM_TEXT("rotationOrder"s)) },
      
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::Transfer::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Transfer::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Transfer::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Transfer::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Transfer::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

double JsonConfigure::DungonParts::Transfer::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Transfer::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Transfer::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

double JsonConfigure::DungonParts::Transfer::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Transfer::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Transfer::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

int JsonConfigure::DungonParts::Transfer::GetSerializedVersion() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return serializedVersion;
}

int JsonConfigure::DungonParts::Transfer::GetPreInfinity() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return preInfinity;
}

int JsonConfigure::DungonParts::Transfer::GetPostInfinity() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return postInfinity;
}

int JsonConfigure::DungonParts::Transfer::GetRotationOrder() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return rotationOrder;
}

JsonConfigure::DungonParts::SpeedDelta::SpeedDelta(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::SpeedDelta::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::SpeedDelta::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

JsonConfigure::DungonParts::TransferEnd::TransferEnd(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::TransferEnd::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::TransferEnd::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::TransferEnd::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::TransferTanOut::TransferTanOut(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::TransferTanOut::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::TransferTanOut::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::TransferTanOut::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::TransferTanIn::TransferTanIn(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::TransferTanIn::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::TransferTanIn::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::TransferTanIn::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::Speed::Speed(const CoreTools::JsonRow& jsonRow)
    : serializedVersion{ jsonRow.GetInt(SYSTEM_TEXT("serializedVersion"s)) },
      ,
      preInfinity{ jsonRow.GetInt(SYSTEM_TEXT("preInfinity"s)) },
      postInfinity{ jsonRow.GetInt(SYSTEM_TEXT("postInfinity"s)) },
      rotationOrder{ jsonRow.GetInt(SYSTEM_TEXT("rotationOrder"s)) },
      
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

int JsonConfigure::DungonParts::Speed::GetSerializedVersion() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return serializedVersion;
}

int JsonConfigure::DungonParts::Speed::GetPreInfinity() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return preInfinity;
}

int JsonConfigure::DungonParts::Speed::GetPostInfinity() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return postInfinity;
}

int JsonConfigure::DungonParts::Speed::GetRotationOrder() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return rotationOrder;
}

JsonConfigure::DungonParts::Elements::Elements(const CoreTools::JsonRow& jsonRow)
    : id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      offset{ make_shared<Offset>(jsonRow.GetJsonRow(SYSTEM_TEXT("offset"s))) },
      count{ jsonRow.GetInt(SYSTEM_TEXT("count"s)) },
      must{ jsonRow.GetBool(SYSTEM_TEXT("must"s)) },
      weight{ jsonRow.GetInt(SYSTEM_TEXT("weight"s)) },
      element{ make_shared<Element>(jsonRow.GetJsonRow(SYSTEM_TEXT("element"s))) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

JsonConfigure::DungonParts::Elements::Elements(int id)
    : id{ id },
      offset{},
      count{},
      must{},
      weight{},
      element{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

int JsonConfigure::DungonParts::Elements::GetID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

JsonConfigure::DungonParts::Elements::ConstOffsetSharedPtr JsonConfigure::DungonParts::Elements::GetOffset() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return offset;
}

int JsonConfigure::DungonParts::Elements::GetCount() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return count;
}

bool JsonConfigure::DungonParts::Elements::IsMust() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return must;
}

int JsonConfigure::DungonParts::Elements::GetWeight() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return weight;
}

JsonConfigure::DungonParts::Elements::ConstElementSharedPtr JsonConfigure::DungonParts::Elements::GetElement() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return element;
}

JsonConfigure::DungonParts::Offset::Offset(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::Offset::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Offset::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Offset::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::Element::Element(const CoreTools::JsonRow& jsonRow)
    : ,
      id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      ,
      
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

int JsonConfigure::DungonParts::Element::GetID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

JsonConfigure::DungonParts::Elements::Elements(const CoreTools::JsonRow& jsonRow)
    : id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      offset{ make_shared<Offset>(jsonRow.GetJsonRow(SYSTEM_TEXT("offset"s))) },
      count{ jsonRow.GetInt(SYSTEM_TEXT("count"s)) },
      must{ jsonRow.GetBool(SYSTEM_TEXT("must"s)) },
      weight{ jsonRow.GetInt(SYSTEM_TEXT("weight"s)) },
      element{ make_shared<Element>(jsonRow.GetJsonRow(SYSTEM_TEXT("element"s))) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

JsonConfigure::DungonParts::Elements::Elements(int id)
    : id{ id },
      offset{},
      count{},
      must{},
      weight{},
      element{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

int JsonConfigure::DungonParts::Elements::GetID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

JsonConfigure::DungonParts::Elements::ConstOffsetSharedPtr JsonConfigure::DungonParts::Elements::GetOffset() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return offset;
}

int JsonConfigure::DungonParts::Elements::GetCount() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return count;
}

bool JsonConfigure::DungonParts::Elements::IsMust() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return must;
}

int JsonConfigure::DungonParts::Elements::GetWeight() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return weight;
}

JsonConfigure::DungonParts::Elements::ConstElementSharedPtr JsonConfigure::DungonParts::Elements::GetElement() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return element;
}

JsonConfigure::DungonParts::Offset::Offset(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::Offset::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Offset::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Offset::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::Element::Element(const CoreTools::JsonRow& jsonRow)
    : name{ jsonRow.GetString(SYSTEM_TEXT("name"s)) },
      id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      { make_shared<>(jsonRow.GetJsonRow(SYSTEM_TEXT(""s))) },
      ,
      
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

System::String JsonConfigure::DungonParts::Element::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

int JsonConfigure::DungonParts::Element::GetID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

JsonConfigure::DungonParts::Element::ConstSharedPtr JsonConfigure::DungonParts::Element::Get() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return ;
}

JsonConfigure::DungonParts::Elements::Elements(const CoreTools::JsonRow& jsonRow)
    : position{ make_shared<Position>(jsonRow.GetJsonRow(SYSTEM_TEXT("position"s))) },
      eulerAngle{ make_shared<EulerAngle>(jsonRow.GetJsonRow(SYSTEM_TEXT("eulerAngle"s))) },
      transfer{ make_shared<Transfer>(jsonRow.GetJsonRow(SYSTEM_TEXT("transfer"s))) },
      id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      targetRadius{ jsonRow.GetDouble(SYSTEM_TEXT("targetRadius"s)) },
      ,
      ,
      terrainY{ jsonRow.GetBool(SYSTEM_TEXT("terrainY"s)) },
      ,
      
{
    USER_SELF_CLASS_IS_VALID_9;
}

JsonConfigure::DungonParts::Elements::Elements(int id)
    : position{},
      eulerAngle{},
      transfer{},
      id{ id },
      targetRadius{},
      targetFilters{},
      triggerParam{},
      terrainY{},
      targetFilters{},
      triggerParam{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

JsonConfigure::DungonParts::Elements::ConstPositionSharedPtr JsonConfigure::DungonParts::Elements::GetPosition() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return position;
}

JsonConfigure::DungonParts::Elements::ConstEulerAngleSharedPtr JsonConfigure::DungonParts::Elements::GetEulerAngle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return eulerAngle;
}

JsonConfigure::DungonParts::Elements::ConstTransferSharedPtr JsonConfigure::DungonParts::Elements::GetTransfer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return transfer;
}

int JsonConfigure::DungonParts::Elements::GetID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

double JsonConfigure::DungonParts::Elements::GetTargetRadius() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return targetRadius;
}

bool JsonConfigure::DungonParts::Elements::IsTerrainY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return terrainY;
}

JsonConfigure::DungonParts::Position::Position(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::Position::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Position::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Position::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::EulerAngle::EulerAngle(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::EulerAngle::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::EulerAngle::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::EulerAngle::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::Transfer::Transfer(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) },
      x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) },
      x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) },
      serializedVersion{ jsonRow.GetInt(SYSTEM_TEXT("serializedVersion"s)) },
      ,
      preInfinity{ jsonRow.GetInt(SYSTEM_TEXT("preInfinity"s)) },
      postInfinity{ jsonRow.GetInt(SYSTEM_TEXT("postInfinity"s)) },
      rotationOrder{ jsonRow.GetInt(SYSTEM_TEXT("rotationOrder"s)) },
      
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::Transfer::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Transfer::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Transfer::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Transfer::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Transfer::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

double JsonConfigure::DungonParts::Transfer::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Transfer::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Transfer::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

double JsonConfigure::DungonParts::Transfer::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Transfer::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Transfer::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

int JsonConfigure::DungonParts::Transfer::GetSerializedVersion() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return serializedVersion;
}

int JsonConfigure::DungonParts::Transfer::GetPreInfinity() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return preInfinity;
}

int JsonConfigure::DungonParts::Transfer::GetPostInfinity() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return postInfinity;
}

int JsonConfigure::DungonParts::Transfer::GetRotationOrder() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return rotationOrder;
}

JsonConfigure::DungonParts::SpeedDelta::SpeedDelta(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::SpeedDelta::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::SpeedDelta::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

JsonConfigure::DungonParts::TransferEnd::TransferEnd(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::TransferEnd::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::TransferEnd::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::TransferEnd::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::TransferTanOut::TransferTanOut(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::TransferTanOut::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::TransferTanOut::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::TransferTanOut::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::TransferTanIn::TransferTanIn(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::TransferTanIn::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::TransferTanIn::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::TransferTanIn::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::Speed::Speed(const CoreTools::JsonRow& jsonRow)
    : serializedVersion{ jsonRow.GetInt(SYSTEM_TEXT("serializedVersion"s)) },
      ,
      preInfinity{ jsonRow.GetInt(SYSTEM_TEXT("preInfinity"s)) },
      postInfinity{ jsonRow.GetInt(SYSTEM_TEXT("postInfinity"s)) },
      rotationOrder{ jsonRow.GetInt(SYSTEM_TEXT("rotationOrder"s)) },
      
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

int JsonConfigure::DungonParts::Speed::GetSerializedVersion() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return serializedVersion;
}

int JsonConfigure::DungonParts::Speed::GetPreInfinity() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return preInfinity;
}

int JsonConfigure::DungonParts::Speed::GetPostInfinity() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return postInfinity;
}

int JsonConfigure::DungonParts::Speed::GetRotationOrder() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return rotationOrder;
}

JsonConfigure::DungonParts::Elements::Elements(const CoreTools::JsonRow& jsonRow)
    : id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      offset{ make_shared<Offset>(jsonRow.GetJsonRow(SYSTEM_TEXT("offset"s))) },
      count{ jsonRow.GetInt(SYSTEM_TEXT("count"s)) },
      must{ jsonRow.GetBool(SYSTEM_TEXT("must"s)) },
      weight{ jsonRow.GetInt(SYSTEM_TEXT("weight"s)) },
      element{ make_shared<Element>(jsonRow.GetJsonRow(SYSTEM_TEXT("element"s))) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

JsonConfigure::DungonParts::Elements::Elements(int id)
    : id{ id },
      offset{},
      count{},
      must{},
      weight{},
      element{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

int JsonConfigure::DungonParts::Elements::GetID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

JsonConfigure::DungonParts::Elements::ConstOffsetSharedPtr JsonConfigure::DungonParts::Elements::GetOffset() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return offset;
}

int JsonConfigure::DungonParts::Elements::GetCount() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return count;
}

bool JsonConfigure::DungonParts::Elements::IsMust() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return must;
}

int JsonConfigure::DungonParts::Elements::GetWeight() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return weight;
}

JsonConfigure::DungonParts::Elements::ConstElementSharedPtr JsonConfigure::DungonParts::Elements::GetElement() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return element;
}

JsonConfigure::DungonParts::Offset::Offset(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::Offset::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Offset::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Offset::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::Element::Element(const CoreTools::JsonRow& jsonRow)
    : name{ jsonRow.GetString(SYSTEM_TEXT("name"s)) },
      id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      { make_shared<>(jsonRow.GetJsonRow(SYSTEM_TEXT(""s))) },
      
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

System::String JsonConfigure::DungonParts::Element::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

int JsonConfigure::DungonParts::Element::GetID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

JsonConfigure::DungonParts::Element::ConstSharedPtr JsonConfigure::DungonParts::Element::Get() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return ;
}

JsonConfigure::DungonParts::Elements::Elements(const CoreTools::JsonRow& jsonRow)
    : position{ make_shared<Position>(jsonRow.GetJsonRow(SYSTEM_TEXT("position"s))) },
      eulerAngle{ make_shared<EulerAngle>(jsonRow.GetJsonRow(SYSTEM_TEXT("eulerAngle"s))) },
      transfer{ make_shared<Transfer>(jsonRow.GetJsonRow(SYSTEM_TEXT("transfer"s))) },
      id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      targetRadius{ jsonRow.GetDouble(SYSTEM_TEXT("targetRadius"s)) },
      ,
      ,
      terrainY{ jsonRow.GetBool(SYSTEM_TEXT("terrainY"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

JsonConfigure::DungonParts::Elements::Elements(int id)
    : position{},
      eulerAngle{},
      transfer{},
      id{ id },
      targetRadius{},
      targetFilters{},
      triggerParam{},
      terrainY{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

JsonConfigure::DungonParts::Elements::ConstPositionSharedPtr JsonConfigure::DungonParts::Elements::GetPosition() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return position;
}

JsonConfigure::DungonParts::Elements::ConstEulerAngleSharedPtr JsonConfigure::DungonParts::Elements::GetEulerAngle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return eulerAngle;
}

JsonConfigure::DungonParts::Elements::ConstTransferSharedPtr JsonConfigure::DungonParts::Elements::GetTransfer() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return transfer;
}

int JsonConfigure::DungonParts::Elements::GetID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

double JsonConfigure::DungonParts::Elements::GetTargetRadius() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return targetRadius;
}

bool JsonConfigure::DungonParts::Elements::IsTerrainY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return terrainY;
}

JsonConfigure::DungonParts::Position::Position(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::Position::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Position::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Position::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::EulerAngle::EulerAngle(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::EulerAngle::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::EulerAngle::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::EulerAngle::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::Transfer::Transfer(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) },
      x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) },
      x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) },
      serializedVersion{ jsonRow.GetInt(SYSTEM_TEXT("serializedVersion"s)) },
      ,
      preInfinity{ jsonRow.GetInt(SYSTEM_TEXT("preInfinity"s)) },
      postInfinity{ jsonRow.GetInt(SYSTEM_TEXT("postInfinity"s)) },
      rotationOrder{ jsonRow.GetInt(SYSTEM_TEXT("rotationOrder"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::Transfer::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Transfer::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Transfer::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Transfer::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Transfer::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

double JsonConfigure::DungonParts::Transfer::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Transfer::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Transfer::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

double JsonConfigure::DungonParts::Transfer::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::Transfer::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::Transfer::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

int JsonConfigure::DungonParts::Transfer::GetSerializedVersion() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return serializedVersion;
}

int JsonConfigure::DungonParts::Transfer::GetPreInfinity() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return preInfinity;
}

int JsonConfigure::DungonParts::Transfer::GetPostInfinity() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return postInfinity;
}

int JsonConfigure::DungonParts::Transfer::GetRotationOrder() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return rotationOrder;
}

JsonConfigure::DungonParts::SpeedDelta::SpeedDelta(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::SpeedDelta::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::SpeedDelta::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

JsonConfigure::DungonParts::TransferEnd::TransferEnd(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::TransferEnd::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::TransferEnd::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::TransferEnd::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::TransferTanOut::TransferTanOut(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::TransferTanOut::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::TransferTanOut::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::TransferTanOut::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::TransferTanIn::TransferTanIn(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

double JsonConfigure::DungonParts::TransferTanIn::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonParts::TransferTanIn::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonParts::TransferTanIn::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonParts::Speed::Speed(const CoreTools::JsonRow& jsonRow)
    : serializedVersion{ jsonRow.GetInt(SYSTEM_TEXT("serializedVersion"s)) },
      ,
      preInfinity{ jsonRow.GetInt(SYSTEM_TEXT("preInfinity"s)) },
      postInfinity{ jsonRow.GetInt(SYSTEM_TEXT("postInfinity"s)) },
      rotationOrder{ jsonRow.GetInt(SYSTEM_TEXT("rotationOrder"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

int JsonConfigure::DungonParts::Speed::GetSerializedVersion() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return serializedVersion;
}

int JsonConfigure::DungonParts::Speed::GetPreInfinity() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return preInfinity;
}

int JsonConfigure::DungonParts::Speed::GetPostInfinity() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return postInfinity;
}

int JsonConfigure::DungonParts::Speed::GetRotationOrder() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return rotationOrder;
}

JsonConfigure::DungonParts::PassParams::PassParams(const CoreTools::JsonRow& jsonRow)
    : ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      ,
      
{
    USER_SELF_CLASS_IS_VALID_9;
}

JsonConfigure::DungonParts::PassParams::PassParams(int id)
    : values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{},
      values{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonPartsContainer)

