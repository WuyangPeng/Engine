///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 13:39)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_NODE_CONTAINER_H
#define CORE_TOOLS_TEXT_PARSING_JSON_NODE_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>
#include <vector>

CORE_TOOLS_COPY_UNSHARED_EXPORT_IMPL(JsonNodeContainer, JsonNodeContainerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE JsonNodeContainer final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(JsonNodeContainer);
        using String = System::String;
        using JsonNodeSharedPtr = std::shared_ptr<JsonNode>;
        using Container = std::vector<JsonNodeSharedPtr>;
        using ContainerConstIter = Container::const_iterator;
        using ContainerIter = Container::iterator;

    public:
        NODISCARD static JsonNodeContainer Create();

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
        explicit JsonNodeContainer(MAYBE_UNUSED DisableNotThrow disableNotThrow);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_NODE_CONTAINER_H