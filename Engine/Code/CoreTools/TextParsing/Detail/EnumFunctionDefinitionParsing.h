///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:08)

#ifndef CORE_TOOLS_TEXT_PARSING_ENUM_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_ENUM_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "Parsing.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE EnumFunctionDefinitionParsing : public Parsing
    {
    public:
        using ClassType = EnumFunctionDefinitionParsing;
        using ParentType = Parsing;
        using StringView = System::StringView;

    public:
        EnumFunctionDefinitionParsing(CSVHead csvHead, CSVContent csvContent, String className, int nameIndex) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD String GenerateEnumFunctionDefinition() const;

    protected:
        NODISCARD CSVHead GetCSVHead() const noexcept;
        NODISCARD CSVContent GetCSVContent() const noexcept;
        NODISCARD int GetNameIndex() const noexcept;

        NODISCARD static String GetColumn(const String& describe, const String& space, CSVPositionType csvPositionType);
        NODISCARD String GetFindFunctionDefinition(const StringView& variable) const;

    private:
        NODISCARD virtual String GenerateHeader() const = 0;
        NODISCARD virtual String GenerateDescribe() const = 0;
        NODISCARD virtual String GenerateColumn(const String& space) const = 0;
        NODISCARD virtual String GenerateFindFunctionDefinition() const = 0;

        NODISCARD String GenerateFindTypeDescribe(const StringView& variable) const;
        NODISCARD String GenerateIterTypeDescribe() const;
        NODISCARD String GenerateTypeDescribeNotFind() const;

    private:
        CSVHead head;
        CSVContent csvContent;
        String className;
        int nameIndex;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ENUM_FUNCTION_DEFINITION_PARSING_H