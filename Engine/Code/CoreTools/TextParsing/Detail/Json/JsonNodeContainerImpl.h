///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 12:02)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_NODE_CONTAINER_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_JSON_NODE_CONTAINER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

#include <memory>
#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonNodeContainerImpl final
    {
    public:
        using ClassType = JsonNodeContainerImpl;
        using String = System::String;
        using JsonNodeSharedPtr = std::shared_ptr<JsonNode>;
        using Container = std::vector<JsonNodeSharedPtr>;
        using ContainerConstIter = Container::const_iterator;
        using ContainerIter = Container::iterator;

    public:
        JsonNodeContainerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void AddJsonNode(const JsonNodeContainer& container);
        void AddJsonNode(const JsonNodeSharedPtr& jsonNode);
        void SetNewJsonDataType(const String& key, JsonDataType jsonDataType);
        void SetNewJsonNodeContainer(const String& key, const JsonNodeContainer& jsonNodeContainer);

        NODISCARD JsonDataType GetJsonDataType(const String& key) const;

        NODISCARD ContainerConstIter begin() const noexcept;
        NODISCARD ContainerConstIter end() const noexcept;

        NODISCARD ContainerIter begin() noexcept;
        NODISCARD ContainerIter end() noexcept;

        NODISCARD bool IsEmpty() const noexcept;

        NODISCARD JsonDataType GetJsonDataType() const noexcept;
        void SetJsonDataType(JsonDataType jsonDataType) noexcept;

        NODISCARD bool HasNested() const noexcept;
        NODISCARD bool HasArray() const noexcept;
        NODISCARD bool HasBoolArray() const noexcept;

        NODISCARD int GetSize() const;

    private:
        NODISCARD bool IsNestedArray() const;

    private:
        Container m_JsonNodeContainer;
        JsonDataType m_JsonDataType;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_NODE_CONTAINER_IMPL_H