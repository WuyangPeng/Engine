///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/11/01 11:57)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_SOURCE_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_SOURCE_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"
#include "CoreTools/TextParsing/CSVContent.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateEnumSourceFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateEnumSourceFile;
        using ParentType = CSVGenerateImpl;

    public:
        explicit CSVGenerateEnumSourceFile(const CSVContent& csvContent);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetSuffix() const noexcept final;
        NODISCARD String GetFilePrefix() const final;
        NODISCARD String GetFileSuffix() const final;
        NODISCARD String GetContent() const final;

        NODISCARD String GenerateEnumFunctionDefinition() const;
        NODISCARD String GetFindFunctionDefinition(const String& variable) const;

        NODISCARD String GetColumn(const String& describe, const String& space, CSVPoistionType csvPoistionType) const;

        NODISCARD String GetStringCastEnum(int nameIndex) const;
        NODISCARD String GetStringCastEnumColumn(const String& column, int nameIndex, const String& space, CSVPoistionType csvPoistionType) const;
        NODISCARD String GetStringCastEnumColumn(const String& name) const;

        NODISCARD String GetEnumCastString(int nameIndex) const;
        NODISCARD String GetEnumCastStringColumn(const String& column, int nameIndex, const String& space, CSVPoistionType csvPoistionType) const;
        NODISCARD String GetEnumCastStringColumn(const String& name) const;

        NODISCARD String GetEnumDescribe(int nameIndex, int describeIndex) const;
        NODISCARD String GetEnumDescribeColumn(const String& column, int nameIndex, int describeIndex, const String& space, CSVPoistionType csvPoistionType) const;
        NODISCARD String GetEnumDescribeColumn(const String& name, const String& describe) const;

    private:
        CSVContent csvContent;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_SOURCE_FILE_H