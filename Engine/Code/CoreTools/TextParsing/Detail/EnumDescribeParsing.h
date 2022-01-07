///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:31)

#ifndef CORE_TOOLS_TEXT_PARSING_ENUM_DESCRIBE_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_ENUM_DESCRIBE_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "EnumFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE EnumDescribeParsing : public EnumFunctionDefinitionParsing
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

        NODISCARD String GetEnumDescribeColumn(const String& column, const String& space, CSVPoistionType csvPoistionType) const;
        NODISCARD String GetEnumDescribeColumn(const String& name, const String& describe) const;

    private:
        int describeIndex;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ENUM_DESCRIBE_PARSING_H