///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:10)

#ifndef CORE_TOOLS_TEXT_PARSING_STRING_CAST_ENUM_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_STRING_CAST_ENUM_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "Parsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE StringCastEnumDefinitionParsing final : public Parsing
    {
    public:
        using ClassType = StringCastEnumDefinitionParsing;
        using ParentType = Parsing;

    public:
        StringCastEnumDefinitionParsing(CSVHead csvHead, String className) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD String GenerateStringCastEnumDefinition() const;
        NODISCARD String GenerateStringCastEnumFunction() const;

    private:
        NODISCARD String GenerateStringCastEnum(bool isDefinition) const;
        NODISCARD String GenerateDescribe() const;

    private:
        String className;
        CSVHead head;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_STRING_CAST_ENUM_DEFINITION_PARSING_H