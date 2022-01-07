///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:50)

#include "CoreTools/CoreToolsExport.h"

#include "JsonNodeImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"

CoreTools::JsonNodeImpl::JsonNodeImpl(const String& typeName, JsonDataType jsonDataType)
    : typeName{ typeName }, m_JsonDataType{ jsonDataType }, m_JsonNodeContainer{ JsonNodeContainer::Create() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonNodeImpl)

void CoreTools::JsonNodeImpl::AddJsonNode(const JsonNodeContainer& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_JsonNodeContainer.AddJsonNode(container);
}

CoreTools::JsonNodeImpl::String CoreTools::JsonNodeImpl::GetTypeName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return typeName;
}

CoreTools::JsonDataType CoreTools::JsonNodeImpl::GetJsonDataType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_JsonDataType;
}

void CoreTools::JsonNodeImpl::SetNewJsonDataType(JsonDataType jsonDataType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    switch (jsonDataType)
    {
        case JsonDataType::String:
        {
            m_JsonDataType = JsonDataType::String;
        }
        break;
        case JsonDataType::StringArray:
        {
            m_JsonDataType = JsonDataType::StringArray;
        }
        break;
        case JsonDataType::Bool:
        {
            if (m_JsonDataType == JsonDataType::Bool)
            {
                m_JsonDataType = JsonDataType::Bool;
            }
            else
            {
                m_JsonDataType = JsonDataType::String;
            }
        }
        break;
        case JsonDataType::BoolArray:
        {
            if (m_JsonDataType == JsonDataType::BoolArray)
            {
                m_JsonDataType = JsonDataType::BoolArray;
            }
            else
            {
                m_JsonDataType = JsonDataType::StringArray;
            }
        }
        break;
        case JsonDataType::Int:
        {
            if (m_JsonDataType == JsonDataType::Int)
            {
                m_JsonDataType = JsonDataType::Int;
            }
            else if (m_JsonDataType == JsonDataType::Int64)
            {
                m_JsonDataType = JsonDataType::Int64;
            }
            else
            {
                m_JsonDataType = JsonDataType::String;
            }
        }
        break;
        case JsonDataType::IntArray:
        {
            if (m_JsonDataType == JsonDataType::IntArray)
            {
                m_JsonDataType = JsonDataType::IntArray;
            }
            else if (m_JsonDataType == JsonDataType::Int64Array)
            {
                m_JsonDataType = JsonDataType::Int64Array;
            }
            else
            {
                m_JsonDataType = JsonDataType::StringArray;
            }
        }
        break;
        case JsonDataType::Int64:
        {
            if (m_JsonDataType == JsonDataType::Int || m_JsonDataType == JsonDataType::Int64)
            {
                m_JsonDataType = JsonDataType::Int64;
            }
            else
            {
                m_JsonDataType = JsonDataType::String;
            }
        }
        break;
        case JsonDataType::Int64Array:
        {
            if (m_JsonDataType == JsonDataType::IntArray || m_JsonDataType == JsonDataType::Int64Array)
            {
                m_JsonDataType = JsonDataType::Int64Array;
            }
            else
            {
                m_JsonDataType = JsonDataType::StringArray;
            }
        }
        break;
        case JsonDataType::Double:
        {
            if (m_JsonDataType == JsonDataType::Double)
            {
                m_JsonDataType = JsonDataType::Double;
            }
            else
            {
                m_JsonDataType = JsonDataType::String;
            }
        }
        break;
        case JsonDataType::DoubleArray:
        {
            if (m_JsonDataType == JsonDataType::DoubleArray)
            {
                m_JsonDataType = JsonDataType::DoubleArray;
            }
            else
            {
                m_JsonDataType = JsonDataType::StringArray;
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

    if (m_JsonDataType != JsonDataType::Nested && m_JsonDataType != JsonDataType::NestedArray)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("类型不一致！\n"s));
    }

    for (const auto& jsonNode : jsonNodeContainer)
    {
        if (m_JsonNodeContainer.GetJsonDataType(jsonNode->GetTypeName()) == JsonDataType::Null)
        {
            m_JsonNodeContainer.AddJsonNode(jsonNode);
        }
        else
        {
            auto container = jsonNode->GetJsonNodeContainer();
            if (container.IsEmpty())
            {
                m_JsonNodeContainer.SetNewJsonDataType(jsonNode->GetTypeName(), jsonNode->GetJsonDataType());
            }
            else
            {
                m_JsonNodeContainer.SetNewJsonNodeContainer(jsonNode->GetTypeName(), container);
            }
        }
    }
}

CoreTools::JsonNodeContainer CoreTools::JsonNodeImpl::GetJsonNodeContainer() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_JsonNodeContainer;
}

bool CoreTools::JsonNodeImpl::HasArray() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (JsonDataType::StringArray <= m_JsonDataType && m_JsonDataType <= JsonDataType::DoubleArray)
    {
        return true;
    }

    return m_JsonNodeContainer.HasArray();
}

bool CoreTools::JsonNodeImpl::HasBoolArray() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (m_JsonDataType == JsonDataType::BoolArray)
    {
        return true;
    }

    return m_JsonNodeContainer.HasBoolArray();
}
