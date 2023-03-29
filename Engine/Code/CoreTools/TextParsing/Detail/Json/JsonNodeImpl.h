///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/10 13:40)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_NODE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_JSON_NODE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonNodeImpl final
    {
    public:
        using ClassType = JsonNodeImpl;
        using String = System::String;

    public:
        JsonNodeImpl(const String& typeName, JsonDataType jsonDataType);

        CLASS_INVARIANT_DECLARE;

        void AddJsonNode(const JsonNodeContainer& container);

        NODISCARD String GetTypeName() const;
        NODISCARD JsonDataType GetJsonDataType() const noexcept;
        void SetNewJsonDataType(JsonDataType jsonDataType) noexcept;
        void SetNewJsonNodeContainer(const JsonNodeContainer& jsonNodeContainer);
        NODISCARD JsonNodeContainer GetJsonNodeContainer() const noexcept;

        NODISCARD bool HasArray() const noexcept;
        NODISCARD bool HasBoolArray() const noexcept;

    private:
        String typeName;
        JsonDataType dataType;
        JsonNodeContainer nodeContainer;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_NODE_IMPL_H