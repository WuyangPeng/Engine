///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:12)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_NODE_H
#define CORE_TOOLS_TEXT_PARSING_JSON_NODE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

CORE_TOOLS_DELAY_COPY_UNSHARED_EXPORT_IMPL(JsonNode, JsonNodeImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE JsonNode final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(JsonNode);
        using String = System::String;

    public:
        JsonNode(const String& typeName, JsonDataType jsonDataType);

        CLASS_INVARIANT_DECLARE;

        void AddJsonNode(const JsonNodeContainer& container);

        NODISCARD String GetTypeName() const;
        NODISCARD JsonDataType GetJsonDataType() const noexcept;
        void SetNewJsonDataType(JsonDataType jsonDataType);
        void SetNewJsonNodeContainer(const JsonNodeContainer& jsonNodeContainer);
        NODISCARD JsonNodeContainer GetJsonNodeContainer() const noexcept;

        NODISCARD bool HasArray() const noexcept;
        NODISCARD bool HasBoolArray() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_NODE_H