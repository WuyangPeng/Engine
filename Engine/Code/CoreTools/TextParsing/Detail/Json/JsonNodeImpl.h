///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 12:02)

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
        JsonDataType m_JsonDataType;
        JsonNodeContainer m_JsonNodeContainer;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_NODE_IMPL_H