/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "RunScenes.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/Json/JsonRow.h"

#include <algorithm>

using namespace std::literals;

JsonConfigure::RunScenesContainer::RunScenesContainer(const CoreTools::JsonRow& jsonRow)
    : data{}
{
    Parsing(jsonRow);

    USER_SELF_CLASS_IS_VALID_9;
}

void JsonConfigure::RunScenesContainer::Parsing(const CoreTools::JsonRow& jsonRow)
{
    const auto dataRow = jsonRow.GetJsonRowContainer(SYSTEM_TEXT("data"s));

    for (const auto& value : dataRow)
    {
        data.emplace_back(std::make_shared<RunScenes::Data>(value));
    }

    std::ranges::sort(data, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() < (*rhs).GetId();
    });

    const auto dataIter = std::ranges::unique(data, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() == (*rhs).GetId();
    });

    if (dataIter.begin() != dataIter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("runScenes表data字段存在重复主键。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        data.erase(dataIter.begin(), dataIter.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, RunScenesContainer)

JsonConfigure::RunScenesContainer::ConstDataSharedPtr JsonConfigure::RunScenesContainer::GetFirstData() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return data.at(0);
}

JsonConfigure::RunScenesContainer::ConstDataSharedPtr JsonConfigure::RunScenesContainer::GetData(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() < (*rhs).GetId();
    };

    const auto iter = std::ranges::lower_bound(data, std::make_shared<RunScenes::Data>(key), function);

    if (iter != data.cend() && (*iter)->GetId() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("runScenes表data字段未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

JsonConfigure::RunScenesContainer::DataContainer JsonConfigure::RunScenesContainer::GetDataContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return data;
}

JsonConfigure::RunScenes::Data::Data(const CoreTools::JsonRow& jsonRow)
    : id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      name{ jsonRow.GetString(SYSTEM_TEXT("name"s)) },
      nextLinkPosition{ std::make_shared<NextLinkPosition>(jsonRow.GetJsonRow(SYSTEM_TEXT("nextLinkPosition"s))) },
      centerPosition{ std::make_shared<CenterPosition>(jsonRow.GetJsonRow(SYSTEM_TEXT("centerPosition"s))) },
      checkSize{ jsonRow.GetDouble(SYSTEM_TEXT("checkSize"s)) },
      bounds{},
      anchorPosition{ std::make_shared<AnchorPosition>(jsonRow.GetJsonRow(SYSTEM_TEXT("anchorPosition"s))) },
      cameraLock{ std::make_shared<CameraLock>(jsonRow.GetJsonRow(SYSTEM_TEXT("cameraLock"s))) },
      moveGap{ jsonRow.GetInt(SYSTEM_TEXT("moveGap"s)) },
      terrains{},
      ropeStart{ std::make_shared<RopeStart>(jsonRow.GetJsonRow(SYSTEM_TEXT("ropeStart"s))) }
{
    Parsing(jsonRow);

    USER_SELF_CLASS_IS_VALID_9;
}

void JsonConfigure::RunScenes::Data::Parsing(const CoreTools::JsonRow& jsonRow)
{
    const auto boundsRow = jsonRow.GetJsonRowContainer(SYSTEM_TEXT("bounds"s));

    for (const auto& value : boundsRow)
    {
        bounds.emplace_back(std::make_shared<RunScenes::Bounds>(value));
    }

    std::ranges::sort(bounds, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() < (*rhs).GetId();
    });

    const auto boundsIter = std::ranges::unique(bounds, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() == (*rhs).GetId();
    });

    if (boundsIter.begin() != boundsIter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("runScenes表bounds字段存在重复主键。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        bounds.erase(boundsIter.begin(), boundsIter.end());
    }
    const auto terrainsRow = jsonRow.GetJsonRowContainer(SYSTEM_TEXT("terrains"s));

    for (const auto& value : terrainsRow)
    {
        terrains.emplace_back(std::make_shared<RunScenes::Terrains>(value));
    }

    std::ranges::sort(terrains, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() < (*rhs).GetId();
    });

    const auto terrainsIter = std::ranges::unique(terrains, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() == (*rhs).GetId();
    });

    if (terrainsIter.begin() != terrainsIter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("runScenes表terrains字段存在重复主键。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        terrains.erase(terrainsIter.begin(), terrainsIter.end());
    }
}

JsonConfigure::RunScenes::Data::Data(int id) noexcept
    : id{ id },
      name{},
      nextLinkPosition{},
      centerPosition{},
      checkSize{},
      bounds{},
      anchorPosition{},
      cameraLock{},
      moveGap{},
      terrains{},
      ropeStart{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::RunScenes, Data)

int JsonConfigure::RunScenes::Data::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

System::String JsonConfigure::RunScenes::Data::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

JsonConfigure::RunScenes::Data::ConstNextLinkPositionSharedPtr JsonConfigure::RunScenes::Data::GetNextLinkPosition() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return nextLinkPosition;
}

JsonConfigure::RunScenes::Data::ConstCenterPositionSharedPtr JsonConfigure::RunScenes::Data::GetCenterPosition() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return centerPosition;
}

double JsonConfigure::RunScenes::Data::GetCheckSize() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return checkSize;
}

JsonConfigure::RunScenes::Data::ConstBoundsSharedPtr JsonConfigure::RunScenes::Data::GetFirstBounds() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return bounds.at(0);
}

JsonConfigure::RunScenes::Data::ConstBoundsSharedPtr JsonConfigure::RunScenes::Data::GetBounds(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() < (*rhs).GetId();
    };

    const auto iter = std::ranges::lower_bound(bounds, std::make_shared<RunScenes::Bounds>(key), function);

    if (iter != bounds.cend() && (*iter)->GetId() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("runScenes表bounds字段未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

JsonConfigure::RunScenes::Data::BoundsContainer JsonConfigure::RunScenes::Data::GetBoundsContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return bounds;
}

JsonConfigure::RunScenes::Data::ConstAnchorPositionSharedPtr JsonConfigure::RunScenes::Data::GetAnchorPosition() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return anchorPosition;
}

JsonConfigure::RunScenes::Data::ConstCameraLockSharedPtr JsonConfigure::RunScenes::Data::GetCameraLock() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return cameraLock;
}

int JsonConfigure::RunScenes::Data::GetMoveGap() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return moveGap;
}

JsonConfigure::RunScenes::Data::ConstTerrainsSharedPtr JsonConfigure::RunScenes::Data::GetFirstTerrains() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return terrains.at(0);
}

JsonConfigure::RunScenes::Data::ConstTerrainsSharedPtr JsonConfigure::RunScenes::Data::GetTerrains(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() < (*rhs).GetId();
    };

    const auto iter = std::ranges::lower_bound(terrains, std::make_shared<RunScenes::Terrains>(key), function);

    if (iter != terrains.cend() && (*iter)->GetId() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("runScenes表terrains字段未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

JsonConfigure::RunScenes::Data::TerrainsContainer JsonConfigure::RunScenes::Data::GetTerrainsContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return terrains;
}

JsonConfigure::RunScenes::Data::ConstRopeStartSharedPtr JsonConfigure::RunScenes::Data::GetRopeStart() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return ropeStart;
}

JsonConfigure::RunScenes::NextLinkPosition::NextLinkPosition(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::RunScenes, NextLinkPosition)

double JsonConfigure::RunScenes::NextLinkPosition::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::RunScenes::NextLinkPosition::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::RunScenes::NextLinkPosition::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::RunScenes::CenterPosition::CenterPosition(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::RunScenes, CenterPosition)

double JsonConfigure::RunScenes::CenterPosition::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::RunScenes::CenterPosition::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::RunScenes::CenterPosition::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::RunScenes::Bounds::Bounds(const CoreTools::JsonRow& jsonRow)
    : id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      offset{ std::make_shared<Offset>(jsonRow.GetJsonRow(SYSTEM_TEXT("offset"s))) },
      size{ std::make_shared<Size>(jsonRow.GetJsonRow(SYSTEM_TEXT("size"s))) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

JsonConfigure::RunScenes::Bounds::Bounds(int id) noexcept
    : id{ id },
      offset{},
      size{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::RunScenes, Bounds)

int JsonConfigure::RunScenes::Bounds::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

JsonConfigure::RunScenes::Bounds::ConstOffsetSharedPtr JsonConfigure::RunScenes::Bounds::GetOffset() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return offset;
}

JsonConfigure::RunScenes::Bounds::ConstSizeSharedPtr JsonConfigure::RunScenes::Bounds::GetSize() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return size;
}

JsonConfigure::RunScenes::Offset::Offset(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::RunScenes, Offset)

double JsonConfigure::RunScenes::Offset::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::RunScenes::Offset::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::RunScenes::Offset::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::RunScenes::Size::Size(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::RunScenes, Size)

double JsonConfigure::RunScenes::Size::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::RunScenes::Size::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::RunScenes::Size::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::RunScenes::AnchorPosition::AnchorPosition(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::RunScenes, AnchorPosition)

double JsonConfigure::RunScenes::AnchorPosition::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::RunScenes::AnchorPosition::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::RunScenes::AnchorPosition::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::RunScenes::CameraLock::CameraLock(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::RunScenes, CameraLock)

double JsonConfigure::RunScenes::CameraLock::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::RunScenes::CameraLock::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::RunScenes::CameraLock::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::RunScenes::Terrains::Terrains(const CoreTools::JsonRow& jsonRow)
    : id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      type{ jsonRow.GetInt(SYSTEM_TEXT("type"s)) },
      startPosition{ std::make_shared<StartPosition>(jsonRow.GetJsonRow(SYSTEM_TEXT("startPosition"s))) },
      speedAdd{ jsonRow.GetDouble(SYSTEM_TEXT("speedAdd"s)) },
      moveGap{ jsonRow.GetDouble(SYSTEM_TEXT("moveGap"s)) },
      maxMoveGap{ jsonRow.GetDouble(SYSTEM_TEXT("maxMoveGap"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

JsonConfigure::RunScenes::Terrains::Terrains(int id) noexcept
    : id{ id },
      type{},
      startPosition{},
      speedAdd{},
      moveGap{},
      maxMoveGap{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::RunScenes, Terrains)

int JsonConfigure::RunScenes::Terrains::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int JsonConfigure::RunScenes::Terrains::GetType() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return type;
}

JsonConfigure::RunScenes::Terrains::ConstStartPositionSharedPtr JsonConfigure::RunScenes::Terrains::GetStartPosition() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return startPosition;
}

double JsonConfigure::RunScenes::Terrains::GetSpeedAdd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return speedAdd;
}

double JsonConfigure::RunScenes::Terrains::GetMoveGap() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return moveGap;
}

double JsonConfigure::RunScenes::Terrains::GetMaxMoveGap() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return maxMoveGap;
}

JsonConfigure::RunScenes::StartPosition::StartPosition(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::RunScenes, StartPosition)

double JsonConfigure::RunScenes::StartPosition::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::RunScenes::StartPosition::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::RunScenes::StartPosition::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

JsonConfigure::RunScenes::RopeStart::RopeStart(const CoreTools::JsonRow& jsonRow)
    : x{ jsonRow.GetDouble(SYSTEM_TEXT("x"s)) },
      y{ jsonRow.GetDouble(SYSTEM_TEXT("y"s)) },
      z{ jsonRow.GetDouble(SYSTEM_TEXT("z"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::RunScenes, RopeStart)

double JsonConfigure::RunScenes::RopeStart::GetX() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return x;
}

double JsonConfigure::RunScenes::RopeStart::GetY() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return y;
}

double JsonConfigure::RunScenes::RopeStart::GetZ() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return z;
}

