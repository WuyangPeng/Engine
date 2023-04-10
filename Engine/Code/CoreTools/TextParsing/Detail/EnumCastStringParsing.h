///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:08)

#ifndef CORE_TOOLS_TEXT_PARSING_ENUM_CAST_STRING_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_ENUM_CAST_STRING_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "EnumFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE EnumCastStringParsing final : public EnumFunctionDefinitionParsing
    {
    public:
        using ClassType = EnumCastStringParsing;
        using ParentType = EnumFunctionDefinitionParsing;

    public:
        EnumCastStringParsing(const CSVHead& csvHead, const CSVContent& csvContent, const String& className, int nameIndex);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        NODISCARD String GenerateHeader() const override;
        NODISCARD String GenerateDescribe() const override;
        NODISCARD String GenerateColumn(const String& space) const override;
        NODISCARD String GenerateFindFunctionDefinition() const override;

        NODISCARD String GetEnumCastStringColumn(const String& column, const String& space, CSVPositionType csvPositionType) const;
        NODISCARD String GetEnumCastStringColumn(const String& name) const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ENUM_CAST_STRING_PARSING_H