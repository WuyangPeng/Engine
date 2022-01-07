/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

#include "DungonMonsters.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/Json/JsonRow.h"

#include <algorithm>

using std::make_shared;
using namespace std::literals;

JsonConfigure::DungonMonstersContainer::DungonMonstersContainer(const CoreTools::JsonRow& jsonRow)
    : system{ jsonRow.GetInt(SYSTEM_TEXT("system"s)) },
      coreTools{ jsonRow.GetInt(SYSTEM_TEXT("coreTools"s)) },
      network{ jsonRow.GetString(SYSTEM_TEXT("network"s)) },
      test{ jsonRow.GetIntArray(SYSTEM_TEXT("test"s)) },
      consoleTest{ jsonRow.GetStringArray(SYSTEM_TEXT("consoleTest"s)) },
      datas{}
{
    Parsing(jsonRow);

    USER_SELF_CLASS_IS_VALID_9;
}

void JsonConfigure::DungonMonstersContainer::Parsing(const CoreTools::JsonRow& jsonRow)
{
    const auto datasSize = jsonRow.GetCount(SYSTEM_TEXT("datas"s));

    for (auto i = 0; i < datasSize; ++i)
    {
        datas.emplace_back(make_shared<DungonMonsters::Datas>(jsonRow.GetJsonRow(SYSTEM_TEXT("datas"s), i)));
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
            << SYSTEM_TEXT("dungonMonsters表datas字段存在重复主键。")
            << LOG_SINGLETON_TRIGGER_ASSERT;

        datas.erase(datasIter, datas.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonMonstersContainer)

int JsonConfigure::DungonMonstersContainer::GetSystem() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return system;
}

int JsonConfigure::DungonMonstersContainer::GetCoreTools() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return coreTools;
}

System::String JsonConfigure::DungonMonstersContainer::GetNetwork() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return network;
}

JsonConfigure::DungonMonstersContainer::Test JsonConfigure::DungonMonstersContainer::GetTest() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return test;
}

int JsonConfigure::DungonMonstersContainer::GetTestSize() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(test.size());
}

JsonConfigure::DungonMonstersContainer::TestConstIter JsonConfigure::DungonMonstersContainer::GetTestBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return test.begin();
}

JsonConfigure::DungonMonstersContainer::TestConstIter JsonConfigure::DungonMonstersContainer::GetTestEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return test.end();
}

JsonConfigure::DungonMonstersContainer::ConsoleTest JsonConfigure::DungonMonstersContainer::GetConsoleTest() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return consoleTest;
}

int JsonConfigure::DungonMonstersContainer::GetConsoleTestSize() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(consoleTest.size());
}

JsonConfigure::DungonMonstersContainer::ConsoleTestConstIter JsonConfigure::DungonMonstersContainer::GetConsoleTestBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return consoleTest.begin();
}

JsonConfigure::DungonMonstersContainer::ConsoleTestConstIter JsonConfigure::DungonMonstersContainer::GetConsoleTestEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return consoleTest.end();
}

JsonConfigure::DungonMonstersContainer::ConstDatasSharedPtr JsonConfigure::DungonMonstersContainer::GetFirstDatas() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return datas.at(0);
}

JsonConfigure::DungonMonstersContainer::ConstDatasSharedPtr JsonConfigure::DungonMonstersContainer::GetDatas(int id) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetID() < (*rhs).GetID();
    };

    const auto iter = lower_bound(datas.cbegin(), datas.cend(), make_shared<DungonMonsters::Datas>(id), function);

    if (iter != datas.cend() && (*iter)->GetID() == id)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("dungonMonsters表datasdatas字段未找到id = "s) + System::ToString(id) + SYSTEM_TEXT("的配置信息。"s));
    }
}

JsonConfigure::DungonMonstersContainer::DatasContainer JsonConfigure::DungonMonstersContainer::GetDatasContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return datas;
}

JsonConfigure::DungonMonsters::Datas::Datas(const CoreTools::JsonRow& jsonRow)
    : name{ jsonRow.GetString(SYSTEM_TEXT("name"s)) },
      id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      elements{}
{
    Parsing(jsonRow);

    USER_SELF_CLASS_IS_VALID_9;
}

void JsonConfigure::DungonMonstersContainer::Parsing(const CoreTools::JsonRow& jsonRow)
{
    const auto datasSize = jsonRow.GetCount(SYSTEM_TEXT("datas"s));

    for (auto i = 0; i < datasSize; ++i)
    {
        datas.emplace_back(make_shared<DungonMonsters::Datas>(jsonRow.GetJsonRow(SYSTEM_TEXT("datas"s), i)));
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
            << SYSTEM_TEXT("dungonMonsters表datas字段存在重复主键。")
            << LOG_SINGLETON_TRIGGER_ASSERT;

        datas.erase(datasIter, datas.end());
    }
}

JsonConfigure::DungonMonsters::Datas::Datas(int id)
    : name{},
      id{ id },
      elements{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonMonstersContainer)

System::String JsonConfigure::DungonMonsters::Datas::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

int JsonConfigure::DungonMonsters::Datas::GetID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

JsonConfigure::DungonMonsters::Datas::ConstElementsSharedPtr JsonConfigure::DungonMonsters::Datas::GetFirstElements() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return elements.at(0);
}

JsonConfigure::DungonMonsters::Datas::ConstElementsSharedPtr JsonConfigure::DungonMonsters::Datas::GetElements(int id) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetID() < (*rhs).GetID();
    };

    const auto iter = lower_bound(elements.cbegin(), elements.cend(), make_shared<DungonMonsters::Elements>(id), function);

    if (iter != elements.cend() && (*iter)->GetID() == id)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("dungonMonsters表elements字段未找到id = "s) + System::ToString(id) + SYSTEM_TEXT("的配置信息。"s));
    }
}

JsonConfigure::DungonMonsters::Datas::ElementsContainer JsonConfigure::DungonMonsters::Datas::GetElementsContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return elements;
}

JsonConfigure::DungonMonsters::Elements::Elements(const CoreTools::JsonRow& jsonRow)
    : id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      moveType{ jsonRow.GetInt(SYSTEM_TEXT("moveType"s)) },
      speedScale{ jsonRow.GetDouble(SYSTEM_TEXT("speedScale"s)) },
      direction{ make_shared<Direction>(jsonRow.GetJsonRow(SYSTEM_TEXT("direction"s))) },
      scale{ make_shared<Scale>(jsonRow.GetJsonRow(SYSTEM_TEXT("scale"s))) },
      spawnPos{ make_shared<SpawnPos>(jsonRow.GetJsonRow(SYSTEM_TEXT("spawnPos"s))) },
      targetOffestPos{ make_shared<TargetOffestPos>(jsonRow.GetJsonRow(SYSTEM_TEXT("targetOffestPos"s))) },
      userData{ make_shared<UserData>(jsonRow.GetJsonRow(SYSTEM_TEXT("userData"s))) },
      rodeRandom{ make_shared<RodeRandom>(jsonRow.GetJsonRow(SYSTEM_TEXT("rodeRandom"s))) },
      externLevel{ jsonRow.GetInt(SYSTEM_TEXT("externLevel"s)) },
      useGravity{ jsonRow.GetBool(SYSTEM_TEXT("useGravity"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

JsonConfigure::DungonMonsters::Elements::Elements(int id)
    : id{ id },
      moveType{},
      speedScale{},
      direction{},
      scale{},
      spawnPos{},
      targetOffestPos{},
      userData{},
      rodeRandom{},
      externLevel{},
      useGravity{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonMonstersContainer)

int JsonConfigure::DungonMonsters::Elements::GetID() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int JsonConfigure::DungonMonsters::Elements::GetMoveType() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return moveType;
}

double JsonConfigure::DungonMonsters::Elements::GetSpeedScale() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return speedScale;
}

JsonConfigure::DungonMonsters::Elements::ConstDirectionSharedPtr JsonConfigure::DungonMonsters::Elements::GetDirection() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return direction;
}

JsonConfigure::DungonMonsters::Elements::ConstScaleSharedPtr JsonConfigure::DungonMonsters::Elements::GetScale() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return scale;
}

JsonConfigure::DungonMonsters::Elements::ConstSpawnPosSharedPtr JsonConfigure::DungonMonsters::Elements::GetSpawnPos() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return spawnPos;
}

JsonConfigure::DungonMonsters::Elements::ConstTargetOffestPosSharedPtr JsonConfigure::DungonMonsters::Elements::GetTargetOffestPos() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return targetOffestPos;
}

JsonConfigure::DungonMonsters::Elements::ConstUserDataSharedPtr JsonConfigure::DungonMonsters::Elements::GetUserData() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return userData;
}

JsonConfigure::DungonMonsters::Elements::ConstRodeRandomSharedPtr JsonConfigure::DungonMonsters::Elements::GetRodeRandom() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return rodeRandom;
}

int JsonConfigure::DungonMonsters::Elements::GetExternLevel() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return externLevel;
}

bool JsonConfigure::DungonMonsters::Elements::IsUseGravity() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return useGravity;
}

JsonConfigure::DungonMonsters::Direction::Direction(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonMonstersContainer)

double JsonConfigure::DungonMonsters::Direction::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonMonsters::Direction::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonMonsters::Direction::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonMonsters::Scale::Scale(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonMonstersContainer)

double JsonConfigure::DungonMonsters::Scale::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonMonsters::Scale::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonMonsters::Scale::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonMonsters::SpawnPos::SpawnPos(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonMonstersContainer)

double JsonConfigure::DungonMonsters::SpawnPos::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonMonsters::SpawnPos::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonMonsters::SpawnPos::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonMonsters::TargetOffestPos::TargetOffestPos(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonMonstersContainer)

double JsonConfigure::DungonMonsters::TargetOffestPos::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonMonsters::TargetOffestPos::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonMonsters::TargetOffestPos::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::DungonMonsters::UserData::UserData(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) },
      w{ jsonRow.GetDouble(SYSTEM_TEXT("w"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonMonstersContainer)

double JsonConfigure::DungonMonsters::UserData::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::DungonMonsters::UserData::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::DungonMonsters::UserData::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

double JsonConfigure::DungonMonsters::UserData::GetW() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return w;
}

JsonConfigure::DungonMonsters::RodeRandom::RodeRandom(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetInt(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetInt(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetInt(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, DungonMonstersContainer)

int JsonConfigure::DungonMonsters::RodeRandom::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

int JsonConfigure::DungonMonsters::RodeRandom::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

int JsonConfigure::DungonMonsters::RodeRandom::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

