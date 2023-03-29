///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/10 14:13)

#include "CoreTools/CoreToolsExport.h"

#include "JsonNodeImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"

CoreTools::JsonNodeImpl::JsonNodeImpl(const String& typeName, JsonDataType jsonDataType)
    : typeName{ typeName }, dataType{ jsonDataType }, nodeContainer{ JsonNodeContainer::Create() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonNodeImpl)

void CoreTools::JsonNodeImpl::AddJsonNode(const JsonNodeContainer& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    nodeContainer.AddJsonNode(container);
}

CoreTools::JsonNodeImpl::String CoreTools::JsonNodeImpl::GetTypeName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return typeName;
}

CoreTools::JsonDataType CoreTools::JsonNodeImpl::GetJsonDataType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return dataType;
}

void CoreTools::JsonNodeImpl::SetNewJsonDataType(JsonDataType jsonDataType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    switch (jsonDataType)
    {
        case JsonDataType::String:
        {
            dataType = JsonDataType::String;
        }
        break;
        case JsonDataType::StringArray:
        {
            dataType = JsonDataType::StringArray;
        }
        break;
        case JsonDataType::Bool:
        {
            if (dataType == JsonDataType::Bool)
            {
                dataType = JsonDataType::Bool;
            }
            else
            {
                dataType = JsonDataType::String;
            }
        }
        break;
        case JsonDataType::BoolArray:
        {
            if (dataType == JsonDataType::BoolArray)
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
            if (dataType == JsonDataType::Int)
            {
                dataType = JsonDataType::Int;
            }
            else if (dataType == JsonDataType::Int64)
            {
                dataType = JsonDataType::Int64;
            }
            else
            {
                dataType = JsonDataType::String;
            }
        }
        break;
        case JsonDataType::IntArray:
        {
            if (dataType == JsonDataType::IntArray)
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
            if (dataType == JsonDataType::Int || dataType == JsonDataType::Int64)
            {
                dataType = JsonDataType::Int64;
            }
            else
            {
                dataType = JsonDataType::String;
            }
        }
        break;
        case JsonDataType::Int64Array:
        {
            if (dataType == JsonDataType::IntArray || dataType == JsonDataType::Int64Array)
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
            if (dataType == JsonDataType::Double)
            {
                dataType = JsonDataType::Double;
            }
            else
            {
                dataType = JsonDataType::String;
            }
        }
        break;
        case JsonDataType::DoubleArray:
        {
            if (dataType == JsonDataType::DoubleArray)
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

void CoreTools::JsonNodeImpl::SetNewJsonNodeContainer(const JsonNodeContainer& jsonNodeContainer)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (dataType != JsonDataType::Nested && dataType != JsonDataType::NestedArray)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("类型不一致！\n"s))
    }

    for (const auto& jsonNode : jsonNodeContainer)
    {
        if (nodeContainer.GetJsonDataType(jsonNode->GetTypeName()) == JsonDataType::Null)
        {
            nodeContainer.AddJsonNode(jsonNode);
        }
        else
        {
            if (auto container = jsonNode->GetJsonNodeContainer(); container.IsEmpty())
            {
                nodeContainer.SetNewJsonDataType(jsonNode->GetTypeName(), jsonNode->GetJsonDataType());
            }
            else
            {
                nodeContainer.SetNewJsonNodeContainer(jsonNode->GetTypeName(), container);
            }
        }
    }
}

CoreTools::JsonNodeContainer CoreTools::JsonNodeImpl::GetJsonNodeContainer() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return nodeContainer;
}

bool CoreTools::JsonNodeImpl::HasArray() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (JsonDataType::StringArray <= dataType && dataType <= JsonDataType::DoubleArray)
    {
        return true;
    }

    return nodeContainer.HasArray();
}

bool CoreTools::JsonNodeImpl::HasBoolArray() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (dataType == JsonDataType::BoolArray)
    {
        return true;
    }

    return nodeContainer.HasBoolArray();
}
