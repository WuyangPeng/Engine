///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:06)

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