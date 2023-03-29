///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/09 09:12)

#ifndef CORE_TOOLS_TEXT_PARSING_ENUM_DESCRIBE_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_ENUM_DESCRIBE_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "EnumFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE EnumDescribeParsing final : public EnumFunctionDefinitionParsing
    {
    public:
        using ClassType = EnumDescribeParsing;
        using ParentType = EnumFunctionDefinitionParsing;

    public:
        EnumDescribeParsing(const CSVHead& csvHead, const CSVContent& csvContent, const String& className, int nameIndex, int describeIndex);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        NODISCARD String GenerateHeader() const override;
        NODISCARD String GenerateDescribe() const override;
        NODISCARD String GenerateColumn(const String& space) const override;
        NODISCARD String GenerateFindFunctionDefinition() const override;

        NODISCARD String GetEnumDescribeColumn(const String& column, const String& space, CSVPositionType csvPositionType) const;
        NODISCARD String GetEnumDescribeColumn(const String& name, const String& describe) const;

    private:
        int describeIndex;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ENUM_DESCRIBE_PARSING_H