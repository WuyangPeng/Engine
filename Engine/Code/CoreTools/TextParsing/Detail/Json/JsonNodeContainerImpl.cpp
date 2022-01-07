///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:49)

#include "CoreTools/CoreToolsExport.h"

#include "JsonNodeContainerImpl.h"
#include "JsonNodeImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"

CoreTools::JsonNodeContainerImpl::JsonNodeContainerImpl() noexcept
    : m_JsonNodeContainer{}, m_JsonDataType{ JsonDataType::Nested }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonNodeContainerImpl)

void CoreTools::JsonNodeContainerImpl::AddJsonNode(const JsonNodeContainer& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (const auto& value : container)
    {
        m_JsonNodeContainer.emplace_back(value);
    }

    if (IsNestedArray())
    {
        m_JsonDataType = JsonDataType::NestedArray;
    }
    else if (!IsEmpty())
    {
        m_JsonDataType = JsonDataType::Nested;
    }
}

void CoreTools::JsonNodeContainerImpl::AddJsonNode(const JsonNodeSharedPtr& jsonNode)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_JsonNodeContainer.emplace_back(jsonNode);

    if (IsNestedArray())
    {
        m_JsonDataType = JsonDataType::NestedArray;
    }
    else
    {
        m_JsonDataType = JsonDataType::Nested;
    }
}

CoreTools::JsonDataType CoreTools::JsonNodeContainerImpl::GetJsonDataType(const String& key) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    for (const auto& value : m_JsonNodeContainer)
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

    return m_JsonDataType;
}

void CoreTools::JsonNodeContainerImpl::SetNewJsonDataType(const String& key, JsonDataType jsonDataType)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (const auto& value : m_JsonNodeContainer)
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

    for (const auto& value : m_JsonNodeContainer)
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

    return m_JsonNodeContainer.begin();
}

CoreTools::JsonNodeContainerImpl::ContainerIter CoreTools::JsonNodeContainerImpl::begin() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_JsonNodeContainer.begin();
}

CoreTools::JsonNodeContainerImpl::ContainerConstIter CoreTools::JsonNodeContainerImpl::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_JsonNodeContainer.end();
}

CoreTools::JsonNodeContainerImpl::ContainerIter CoreTools::JsonNodeContainerImpl::end() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_JsonNodeContainer.end();
}

bool CoreTools::JsonNodeContainerImpl::IsEmpty() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_JsonNodeContainer.empty();
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
                m_JsonDataType = JsonDataType::StringArray;
            }
            break;
            case JsonDataType::Bool:
            {
                if (m_JsonDataType == JsonDataType::BoolArray || m_JsonDataType == JsonDataType::Nested)
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
                if (m_JsonDataType == JsonDataType::IntArray || m_JsonDataType == JsonDataType::Nested)
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
                if (m_JsonDataType == JsonDataType::IntArray || m_JsonDataType == JsonDataType::Int64Array || m_JsonDataType == JsonDataType::Nested)
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
                if (m_JsonDataType == JsonDataType::DoubleArray || m_JsonDataType == JsonDataType::Nested)
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
}

bool CoreTools::JsonNodeContainerImpl::IsNestedArray() const
{
    if (m_JsonNodeContainer.size() == 1)
    {
        const auto& value = m_JsonNodeContainer.back();

        if (value->GetTypeName().empty() &&
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

    if (m_JsonDataType == JsonDataType::Nested || m_JsonDataType == JsonDataType::NestedArray)
        return true;
    else
        return false;
}

bool CoreTools::JsonNodeContainerImpl::HasArray() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (JsonDataType::StringArray <= m_JsonDataType && m_JsonDataType <= JsonDataType::DoubleArray)
    {
        return true;
    }

    for (const auto& value : m_JsonNodeContainer)
    {
        if (value->HasArray())
        {
            return true;
        }
    }

    return false;
}

bool CoreTools::JsonNodeContainerImpl::HasBoolArray() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (m_JsonDataType == JsonDataType::BoolArray)
    {
        return true;
    }

    for (const auto& value : m_JsonNodeContainer)
    {
        if (value->HasBoolArray())
        {
            return true;
        }
    }

    return false;
}

int CoreTools::JsonNodeContainerImpl::GetSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_JsonNodeContainer.size());
}
