///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/10 14:11)

#include "CoreTools/CoreToolsExport.h"

#include "JsonNodeContainerImpl.h"
#include "JsonNodeImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"

CoreTools::JsonNodeContainerImpl::JsonNodeContainerImpl() noexcept
    : nodeContainer{}, dataType{ JsonDataType::Nested }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonNodeContainerImpl)

void CoreTools::JsonNodeContainerImpl::AddJsonNode(const JsonNodeContainer& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (const auto& value : container)
    {
        nodeContainer.emplace_back(value);
    }

    if (IsNestedArray())
    {
        dataType = JsonDataType::NestedArray;
    }
    else if (!IsEmpty())
    {
        dataType = JsonDataType::Nested;
    }
}

void CoreTools::JsonNodeContainerImpl::AddJsonNode(const JsonNodeSharedPtr& jsonNode)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    nodeContainer.emplace_back(jsonNode);

    if (IsNestedArray())
    {
        dataType = JsonDataType::NestedArray;
    }
    else
    {
        dataType = JsonDataType::Nested;
    }
}

CoreTools::JsonDataType CoreTools::JsonNodeContainerImpl::GetJsonDataType(const String& key) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    for (const auto& value : nodeContainer)
    {
        if (value->GetTypeName() == key)
        {
            return value->GetJsonDataType();
        }
    }

    return JsonDataType::Null;
}

CoreTools::JsonDataType CoreTools::JsonNodeContainerImpl::GetJsonDataType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return dataType;
}

void CoreTools::JsonNodeContainerImpl::SetNewJsonDataType(const String& key, JsonDataType jsonDataType)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (const auto& value : nodeContainer)
    {
        if (value->GetTypeName() == key)
        {
            value->SetNewJsonDataType(jsonDataType);
            break;
        }
    }
}

void CoreTools::JsonNodeContainerImpl::SetNewJsonNodeContainer(const String& key, const JsonNodeContainer& jsonNodeContainer)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (const auto& value : nodeContainer)
    {
        if (value->GetTypeName() == key)
        {
            value->SetNewJsonNodeContainer(jsonNodeContainer);
            break;
        }
    }
}

CoreTools::JsonNodeContainerImpl::ContainerConstIter CoreTools::JsonNodeContainerImpl::begin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return nodeContainer.begin();
}

CoreTools::JsonNodeContainerImpl::ContainerIter CoreTools::JsonNodeContainerImpl::begin() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return nodeContainer.begin();
}

CoreTools::JsonNodeContainerImpl::ContainerConstIter CoreTools::JsonNodeContainerImpl::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return nodeContainer.end();
}

CoreTools::JsonNodeContainerImpl::ContainerIter CoreTools::JsonNodeContainerImpl::end() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return nodeContainer.end();
}

bool CoreTools::JsonNodeContainerImpl::IsEmpty() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return nodeContainer.empty();
}

void CoreTools::JsonNodeContainerImpl::SetJsonDataType(JsonDataType jsonDataType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (IsEmpty())
    {
        switch (jsonDataType)
        {
            case JsonDataType::String:
            {
                dataType = JsonDataType::StringArray;
            }
            break;
            case JsonDataType::Bool:
            {
                if (dataType == JsonDataType::BoolArray || dataType == JsonDataType::Nested)
                {
                    dataType = JsonDataType::BoolArray;
                }
                else
                {
                    dataType = JsonDataType::StringArray;
                }
            }
            break;
            case JsonDataType::Int:
            {
                if (dataType == JsonDataType::IntArray || dataType == JsonDataType::Nested)
                {
                    dataType = JsonDataType::IntArray;
                }
                else if (dataType == JsonDataType::Int64Array)
                {
                    dataType = JsonDataType::Int64Array;
                }
                else
                {
                    dataType = JsonDataType::StringArray;
                }
            }
            break;
            case JsonDataType::Int64:
            {
                if (dataType == JsonDataType::IntArray || dataType == JsonDataType::Int64Array || dataType == JsonDataType::Nested)
                {
                    dataType = JsonDataType::Int64Array;
                }
                else
                {
                    dataType = JsonDataType::StringArray;
                }
            }
            break;
            case JsonDataType::Double:
            {
                if (dataType == JsonDataType::DoubleArray || dataType == JsonDataType::Nested)
                {
                    dataType = JsonDataType::DoubleArray;
                }
                else
                {
                    dataType = JsonDataType::StringArray;
                }
            }
            break;
            default:
                break;
        }
    }
}

bool CoreTools::JsonNodeContainerImpl::IsNestedArray() const
{
    if (nodeContainer.size() == 1)
    {
        if (const auto& value = nodeContainer.back();
            value->GetTypeName().empty() &&
            value->GetJsonDataType() == JsonDataType::Nested)
        {
            return true;
        }
    }

    return false;
}

bool CoreTools::JsonNodeContainerImpl::HasNested() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (dataType == JsonDataType::Nested || dataType == JsonDataType::NestedArray)
        return true;
    else
        return false;
}

bool CoreTools::JsonNodeContainerImpl::HasArray() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (JsonDataType::StringArray <= dataType && dataType <= JsonDataType::DoubleArray)
    {
        return true;
    }

    return std::ranges::any_of(nodeContainer, [](const auto& value) noexcept {
        return value->HasArray();
    });
}

bool CoreTools::JsonNodeContainerImpl::HasBoolArray() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (dataType == JsonDataType::BoolArray)
    {
        return true;
    }

    return std::ranges::any_of(nodeContainer, [](const auto& value) noexcept {
        return value->HasBoolArray();
    });
}

int CoreTools::JsonNodeContainerImpl::GetSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(nodeContainer.size());
}
