/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Parts.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/Json/JsonRow.h"

#include <algorithm>

using namespace std::literals;

JsonConfigure::PartsContainer::PartsContainer(const CoreTools::JsonRow& jsonRow)
    : data{}
{
    Parsing(jsonRow);

    USER_SELF_CLASS_IS_VALID_9;
}

void JsonConfigure::PartsContainer::Parsing(const CoreTools::JsonRow& jsonRow)
{
    const auto dataRow = jsonRow.GetJsonRowContainer(SYSTEM_TEXT("data"s));

    for (const auto& value : dataRow)
    {
        data.emplace_back(std::make_shared<Parts::Data>(value));
    }

    std::ranges::sort(data, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() < (*rhs).GetId();
    });

    const auto dataIter = std::ranges::unique(data, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() == (*rhs).GetId();
    });

    if (dataIter.begin() != dataIter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("parts表data字段存在重复主键。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        data.erase(dataIter.begin(), dataIter.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, PartsContainer)

JsonConfigure::PartsContainer::ConstDataSharedPtr JsonConfigure::PartsContainer::GetFirstData() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return data.at(0);
}

JsonConfigure::PartsContainer::ConstDataSharedPtr JsonConfigure::PartsContainer::GetData(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() < (*rhs).GetId();
    };

    const auto iter = std::ranges::lower_bound(data, std::make_shared<Parts::Data>(key), function);

    if (iter != data.cend() && (*iter)->GetId() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("parts表datadatas字段未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

JsonConfigure::PartsContainer::DataContainer JsonConfigure::PartsContainer::GetDataContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return data;
}

JsonConfigure::Parts::Data::Data(const CoreTools::JsonRow& jsonRow)
    : id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      name{ jsonRow.GetString(SYSTEM_TEXT("name"s)) },
      scenes{},
      passFlag{ jsonRow.GetInt(SYSTEM_TEXT("passFlag"s)) },
      passEvent{ jsonRow.GetInt(SYSTEM_TEXT("passEvent"s)) },
      runSpeedScale{ jsonRow.GetDouble(SYSTEM_TEXT("runSpeedScale"s)) },
      loop{ jsonRow.GetInt(SYSTEM_TEXT("loop"s)) }
{
    Parsing(jsonRow);

    USER_SELF_CLASS_IS_VALID_9;
}

void JsonConfigure::Parts::Data::Parsing(const CoreTools::JsonRow& jsonRow)
{
    const auto scenesRow = jsonRow.GetJsonRowContainer(SYSTEM_TEXT("scenes"s));

    for (const auto& value : scenesRow)
    {
        scenes.emplace_back(std::make_shared<Parts::Scenes>(value));
    }

    std::ranges::sort(scenes, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() < (*rhs).GetId();
    });

    const auto scenesIter = std::ranges::unique(scenes, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() == (*rhs).GetId();
    });

    if (scenesIter.begin() != scenesIter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("parts表scenes字段存在重复主键。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        scenes.erase(scenesIter.begin(), scenesIter.end());
    }
}

JsonConfigure::Parts::Data::Data(int id) noexcept
    : id{ id },
      name{},
      scenes{},
      passFlag{},
      passEvent{},
      runSpeedScale{},
      loop{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::Parts, Data)

int JsonConfigure::Parts::Data::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

System::String JsonConfigure::Parts::Data::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

JsonConfigure::Parts::Data::ConstScenesSharedPtr JsonConfigure::Parts::Data::GetFirstScenes() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return scenes.at(0);
}

JsonConfigure::Parts::Data::ConstScenesSharedPtr JsonConfigure::Parts::Data::GetScenes(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() < (*rhs).GetId();
    };

    const auto iter = std::ranges::lower_bound(scenes, std::make_shared<Parts::Scenes>(key), function);

    if (iter != scenes.cend() && (*iter)->GetId() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("parts表scenes字段未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

JsonConfigure::Parts::Data::ScenesContainer JsonConfigure::Parts::Data::GetScenesContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return scenes;
}

int JsonConfigure::Parts::Data::GetPassFlag() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return passFlag;
}

int JsonConfigure::Parts::Data::GetPassEvent() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return passEvent;
}

double JsonConfigure::Parts::Data::GetRunSpeedScale() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return runSpeedScale;
}

int JsonConfigure::Parts::Data::GetLoop() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return loop;
}

JsonConfigure::Parts::Scenes::Scenes(const CoreTools::JsonRow& jsonRow)
    : id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      nextPosition{ std::make_shared<NextPosition>(jsonRow.GetJsonRow(SYSTEM_TEXT("nextPosition"s))) },
      up{ std::make_shared<Up>(jsonRow.GetJsonRow(SYSTEM_TEXT("up"s))) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

JsonConfigure::Parts::Scenes::Scenes(int id) noexcept
    : id{ id },
      nextPosition{},
      up{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::Parts, Scenes)

int JsonConfigure::Parts::Scenes::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

JsonConfigure::Parts::Scenes::ConstNextPositionSharedPtr JsonConfigure::Parts::Scenes::GetNextPosition() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return nextPosition;
}

JsonConfigure::Parts::Scenes::ConstUpSharedPtr JsonConfigure::Parts::Scenes::GetUp() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return up;
}

JsonConfigure::Parts::NextPosition::NextPosition(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::Parts, NextPosition)

double JsonConfigure::Parts::NextPosition::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::Parts::NextPosition::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::Parts::NextPosition::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::Parts::Up::Up(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::Parts, Up)

double JsonConfigure::Parts::Up::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::Parts::Up::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::Parts::Up::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

