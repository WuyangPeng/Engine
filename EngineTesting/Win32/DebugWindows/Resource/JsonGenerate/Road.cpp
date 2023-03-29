/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Road.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/Json/JsonRow.h"

#include <algorithm>

using namespace std::literals;

JsonConfigure::RoadContainer::RoadContainer(const CoreTools::JsonRow& jsonRow)
    : data{}
{
    Parsing(jsonRow);

    USER_SELF_CLASS_IS_VALID_9;
}

void JsonConfigure::RoadContainer::Parsing(const CoreTools::JsonRow& jsonRow)
{
    const auto dataRow = jsonRow.GetJsonRowContainer(SYSTEM_TEXT("data"s));

    for (const auto& value : dataRow)
    {
        data.emplace_back(std::make_shared<Road::Data>(value));
    }

    std::ranges::sort(data, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() < (*rhs).GetId();
    });

    const auto dataIter = std::ranges::unique(data, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() == (*rhs).GetId();
    });

    if (dataIter.begin() != dataIter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("road表data字段存在重复主键。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        data.erase(dataIter.begin(), dataIter.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure, RoadContainer)

JsonConfigure::RoadContainer::ConstDataSharedPtr JsonConfigure::RoadContainer::GetFirstData() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return data.at(0);
}

JsonConfigure::RoadContainer::ConstDataSharedPtr JsonConfigure::RoadContainer::GetData(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetId() < (*rhs).GetId();
    };

    const auto iter = std::ranges::lower_bound(data, std::make_shared<Road::Data>(key), function);

    if (iter != data.cend() && (*iter)->GetId() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("road表datadatas字段未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

JsonConfigure::RoadContainer::DataContainer JsonConfigure::RoadContainer::GetDataContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return data;
}

JsonConfigure::Road::Data::Data(const CoreTools::JsonRow& jsonRow)
    : id{ jsonRow.GetInt(SYSTEM_TEXT("id"s)) },
      file{ jsonRow.GetInt(SYSTEM_TEXT("file"s)) },
      name{ jsonRow.GetString(SYSTEM_TEXT("name"s)) },
      passFlag{ jsonRow.GetInt(SYSTEM_TEXT("passFlag"s)) },
      passRelation{ jsonRow.GetInt(SYSTEM_TEXT("passRelation"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

JsonConfigure::Road::Data::Data(int id) noexcept
    : id{ id },
      file{},
      name{},
      passFlag{},
      passRelation{}
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(JsonConfigure::Road, Data)

int JsonConfigure::Road::Data::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int JsonConfigure::Road::Data::GetFile() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return file;
}

System::String JsonConfigure::Road::Data::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

int JsonConfigure::Road::Data::GetPassFlag() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return passFlag;
}

int JsonConfigure::Road::Data::GetPassRelation() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return passRelation;
}

