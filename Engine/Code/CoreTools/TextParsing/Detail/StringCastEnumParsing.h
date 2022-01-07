///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 13:35)

#ifndef CORE_TOOLS_TEXT_PARSING_STRING_CAST_ENUM_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_STRING_CAST_ENUM_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "EnumFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE StringCastEnumParsing : public EnumFunctionDefinitionParsing
    {
    public:
        using ClassType = StringCastEnumParsing;
        using ParentType = EnumFunctionDefinitionParsing;

    public:
        StringCastEnumParsing(const CSVHead& csvHead, const CSVContent& csvContent, const String& className, int nameIndex);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        NODISCARD String GenerateHeader() const override;
        NODISCARD String GenerateDescribe() const override;
        NODISCARD String GenerateColumn(const String& space) const override;
        NODISCARD String GenerateFindFunctionDefinition() const override;

        NODISCARD String GetStringCastEnumColumn(const String& column, const String& space, CSVPoistionType csvPoistionType) const;
        NODISCARD String GetStringCastEnumColumn(const String& name) const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_STRING_CAST_ENUM_PARSING_H