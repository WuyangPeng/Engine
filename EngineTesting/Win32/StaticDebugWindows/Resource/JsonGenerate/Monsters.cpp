/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Monsters.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/Json/JsonRow.h"

#include <algorithm>

using namespace std::literals;

JsonConfigure::MonstersContainer::MonstersContainer(const CoreTools::JsonRow& jsonRow)
    : system{ jsonRow.GetInt(SYSTEM_TEXT("system"s)) },
      coreTools{ jsonRow.GetInt(SYSTEM_TEXT("coreTools"s)) },
      network{ jsonRow.GetString(SYSTEM_TEXT("network"s)) },
      test{ jsonRow.GetIntArray(SYSTEM_TEXT("test"s)) },
      consoleTest{ jsonRow.GetStringArray(SYSTEM_TEXT("consoleTest"s)) },
      data{}
{
    Parsing(jsonRow);

    USER_SELF_CLASS_IS_VALID_9;
}

void JsonConfigure::MonstersContainer::Parsing(const CoreTools::JsonRow& jsonRow)
{
    const auto dataRow = jsonRow.GetJsonRowContainer(SYSTEM_TEXT("data"s));

    for (const auto& value : dataRow)
    {
        data.emplace_back(std::make_shared<Monsters::Data>(value));
    }

    std::ranges::sort(data, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() < (*rhs).GetId();
    });

    const auto dataIter = std::ranges::unique(data, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() == (*rhs).GetId();
    });

    if (dataIter.begin() != dataIter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("monsters表data字段存在重复主键。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        data.erase(dataIter.begin(), dataIter.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, MonstersContainer)

int JsonConfigure::MonstersContainer::GetSystem() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return system;
}

int JsonConfigure::MonstersContainer::GetCoreTools() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return coreTools;
}

System::String JsonConfigure::MonstersContainer::GetNetwork() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return network;
}

JsonConfigure::MonstersContainer::Test JsonConfigure::MonstersContainer::GetTest() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return test;
}

int JsonConfigure::MonstersContainer::GetTestSize() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(test.size());
}

JsonConfigure::MonstersContainer::TestConstIter JsonConfigure::MonstersContainer::GetTestBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return test.begin();
}

JsonConfigure::MonstersContainer::TestConstIter JsonConfigure::MonstersContainer::GetTestEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return test.end();
}

JsonConfigure::MonstersContainer::ConsoleTest JsonConfigure::MonstersContainer::GetConsoleTest() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return consoleTest;
}

int JsonConfigure::MonstersContainer::GetConsoleTestSize() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(consoleTest.size());
}

JsonConfigure::MonstersContainer::ConsoleTestConstIter JsonConfigure::MonstersContainer::GetConsoleTestBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return consoleTest.begin();
}

JsonConfigure::MonstersContainer::ConsoleTestConstIter JsonConfigure::MonstersContainer::GetConsoleTestEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return consoleTest.end();
}

JsonConfigure::MonstersContainer::ConstDataSharedPtr JsonConfigure::MonstersContainer::GetFirstData() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return data.at(0);
}

JsonConfigure::MonstersContainer::ConstDataSharedPtr JsonConfigure::MonstersContainer::GetData(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() < (*rhs).GetId();
    };

    const auto iter = std::ranges::lower_bound(data, std::make_shared<Monsters::Data>(key), function);

    if (iter != data.cend() && (*iter)->GetId() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("monsters表data字段未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

JsonConfigure::MonstersContainer::DataContainer JsonConfigure::MonstersContainer::GetDataContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return data;
}

JsonConfigure::Monsters::Data::Data(const CoreTools::JsonRow& jsonRow)
    : name{ jsonRow.GetString(SYSTEM_TEXT("name"s)) },
      id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      elements{}
{
    Parsing(jsonRow);

    USER_SELF_CLASS_IS_VALID_9;
}

void JsonConfigure::Monsters::Data::Parsing(const CoreTools::JsonRow& jsonRow)
{
    const auto elementsRow = jsonRow.GetJsonRowContainer(SYSTEM_TEXT("elements"s));

    for (const auto& value : elementsRow)
    {
        elements.emplace_back(std::make_shared<Monsters::Elements>(value));
    }

    std::ranges::sort(elements, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() < (*rhs).GetId();
    });

    const auto elementsIter = std::ranges::unique(elements, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() == (*rhs).GetId();
    });

    if (elementsIter.begin() != elementsIter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("monsters表elements字段存在重复主键。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        elements.erase(elementsIter.begin(), elementsIter.end());
    }
}

JsonConfigure::Monsters::Data::Data(int id) noexcept
    : name{},
      id{ id },
      elements{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::Monsters, Data)

System::String JsonConfigure::Monsters::Data::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

int JsonConfigure::Monsters::Data::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

JsonConfigure::Monsters::Data::ConstElementsSharedPtr JsonConfigure::Monsters::Data::GetFirstElements() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return elements.at(0);
}

JsonConfigure::Monsters::Data::ConstElementsSharedPtr JsonConfigure::Monsters::Data::GetElements(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() < (*rhs).GetId();
    };

    const auto iter = std::ranges::lower_bound(elements, std::make_shared<Monsters::Elements>(key), function);

    if (iter != elements.cend() && (*iter)->GetId() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("monsters表elements字段未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

JsonConfigure::Monsters::Data::ElementsContainer JsonConfigure::Monsters::Data::GetElementsContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return elements;
}

JsonConfigure::Monsters::Elements::Elements(const CoreTools::JsonRow& jsonRow)
    : id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      moveType{ jsonRow.GetInt(SYSTEM_TEXT("moveType"s)) },
      speedScale{ jsonRow.GetDouble(SYSTEM_TEXT("speedScale"s)) },
      direction{ std::make_shared<Direction>(jsonRow.GetJsonRow(SYSTEM_TEXT("direction"s))) },
      scale{ std::make_shared<Scale>(jsonRow.GetJsonRow(SYSTEM_TEXT("scale"s))) },
      spawnPosition{ std::make_shared<SpawnPosition>(jsonRow.GetJsonRow(SYSTEM_TEXT("spawnPosition"s))) },
      targetPosition{ std::make_shared<TargetPosition>(jsonRow.GetJsonRow(SYSTEM_TEXT("targetPosition"s))) },
      userData{ std::make_shared<UserData>(jsonRow.GetJsonRow(SYSTEM_TEXT("userData"s))) },
      rodeRandom{ std::make_shared<RodeRandom>(jsonRow.GetJsonRow(SYSTEM_TEXT("rodeRandom"s))) },
      externLevel{ jsonRow.GetInt(SYSTEM_TEXT("externLevel"s)) },
      useGravity{ jsonRow.GetBool(SYSTEM_TEXT("useGravity"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

JsonConfigure::Monsters::Elements::Elements(int id) noexcept
    : id{ id },
      moveType{},
      speedScale{},
      direction{},
      scale{},
      spawnPosition{},
      targetPosition{},
      userData{},
      rodeRandom{},
      externLevel{},
      useGravity{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::Monsters, Elements)

int JsonConfigure::Monsters::Elements::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int JsonConfigure::Monsters::Elements::GetMoveType() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return moveType;
}

double JsonConfigure::Monsters::Elements::GetSpeedScale() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return speedScale;
}

JsonConfigure::Monsters::Elements::ConstDirectionSharedPtr JsonConfigure::Monsters::Elements::GetDirection() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return direction;
}

JsonConfigure::Monsters::Elements::ConstScaleSharedPtr JsonConfigure::Monsters::Elements::GetScale() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return scale;
}

JsonConfigure::Monsters::Elements::ConstSpawnPositionSharedPtr JsonConfigure::Monsters::Elements::GetSpawnPosition() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return spawnPosition;
}

JsonConfigure::Monsters::Elements::ConstTargetPositionSharedPtr JsonConfigure::Monsters::Elements::GetTargetPosition() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return targetPosition;
}

JsonConfigure::Monsters::Elements::ConstUserDataSharedPtr JsonConfigure::Monsters::Elements::GetUserData() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return userData;
}

JsonConfigure::Monsters::Elements::ConstRodeRandomSharedPtr JsonConfigure::Monsters::Elements::GetRodeRandom() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return rodeRandom;
}

int JsonConfigure::Monsters::Elements::GetExternLevel() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return externLevel;
}

bool JsonConfigure::Monsters::Elements::IsUseGravity() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return useGravity;
}

JsonConfigure::Monsters::Direction::Direction(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::Monsters, Direction)

double JsonConfigure::Monsters::Direction::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::Monsters::Direction::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::Monsters::Direction::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::Monsters::Scale::Scale(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::Monsters, Scale)

double JsonConfigure::Monsters::Scale::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::Monsters::Scale::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::Monsters::Scale::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::Monsters::SpawnPosition::SpawnPosition(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::Monsters, SpawnPosition)

double JsonConfigure::Monsters::SpawnPosition::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::Monsters::SpawnPosition::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::Monsters::SpawnPosition::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::Monsters::TargetPosition::TargetPosition(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::Monsters, TargetPosition)

double JsonConfigure::Monsters::TargetPosition::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::Monsters::TargetPosition::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::Monsters::TargetPosition::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::Monsters::UserData::UserData(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) },
      w{ jsonRow.GetDouble(SYSTEM_TEXT("w"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::Monsters, UserData)

double JsonConfigure::Monsters::UserData::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::Monsters::UserData::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::Monsters::UserData::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

double JsonConfigure::Monsters::UserData::GetW() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return w;
}

JsonConfigure::Monsters::RodeRandom::RodeRandom(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetInt(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetInt(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetInt(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::Monsters, RodeRandom)

int JsonConfigure::Monsters::RodeRandom::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

int JsonConfigure::Monsters::RodeRandom::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

int JsonConfigure::Monsters::RodeRandom::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

