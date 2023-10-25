///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 14:15)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_HEAD_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_CSV_HEAD_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Detail/FormatParsing.h"
#include "CoreTools/TextParsing/Detail/PathSplitParsing.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <vector>

namespace CoreTools
{
    /// 数据以,做分隔。
    /// 第一行：数据存储方式、数据映射、数据校验、默认值的设置。
    /// 格式类似于，存储方式：@default、@key = id * 100 + level。
    /// 数据映射：level。
    /// 数据校验：[ 1 - 4 ]、( 1 - 4 ]、( 1 - 4 )、> 0 、>= 5。
    /// { 1 | 2 | 5 }暂时不支持，后续考虑添加。
    /// 默认值：= 4。
    /// 第二行：标注每个字段的名称/说明。
    /// 第三行：标注字段数据类型。
    /// 枚举类型类似于enum|CSVType、enum[]|CSVType。
    /// 第四行：标注字段变量名。
    class CORE_TOOLS_HIDDEN_DECLARE CSVHeadImpl final
    {
    public:
        using ClassType = CSVHeadImpl;

        using String = System::String;
        using StringView = System::StringView;
        using FileContent = std::vector<String>;
        using KeyName = std::vector<String>;

    public:
        CSVHeadImpl(const String& path, const FileContent& fileContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD CSVFormatType GetCSVFormatType() const noexcept;
        NODISCARD String GetNameSpace() const;
        NODISCARD String GetCSVClassName() const;
        NODISCARD String GetCompleteClassName() const;
        NODISCARD String GetKey() const;
        NODISCARD KeyName GetKeyName() const;
        NODISCARD int GetCount() const;
        NODISCARD String GetMapping(int index) const;
        NODISCARD bool HasMapping() const noexcept;
        NODISCARD String GetScope(int index) const;
        NODISCARD bool HasScope() const noexcept;
        NODISCARD String GetScopeExpression(int index) const;
        NODISCARD String GetDefaultValue(int index) const;
        NODISCARD String GetAnnotation(int index) const;
        NODISCARD CSVDataType GetDataType(int index) const;
        NODISCARD CSVDataType GetDataType(const String& field) const;
        NODISCARD String GetActualType(int index) const;
        NODISCARD String GetAbbreviation(int index) const;
        NODISCARD String GetValueType(int index) const;
        NODISCARD String GetActualTypeByNameSpace(int index) const;
        NODISCARD String GetAbbreviationByNameSpace(int index, const String& className) const;
        NODISCARD int GetDataIndex(const String& field) const;
        NODISCARD int GetDataIndex(const StringView& field) const;
        NODISCARD bool HasDataField(const String& field) const;
        NODISCARD bool HasDataField(const StringView& field) const;
        NODISCARD String GetEnumTypeName(int index) const;
        NODISCARD String GetVariableName(int index) const;
        NODISCARD String GetUpperVariableName(int index) const;
        NODISCARD String GetFunctionVariableName(int index) const;
        NODISCARD String GetFunctionName(int index) const;
        NODISCARD bool HasDataType(CSVDataType csvDataType) const;
        NODISCARD bool HasVectorArrayDataType() const;
        NODISCARD bool HasArrayDataType() const;

    private:
        using Annotation = std::vector<String>;
        using DataType = std::vector<CSVDataType>;
        using VariableName = std::vector<String>;
        using EnumTypeName = std::vector<String>;

    private:
        void Init();
        void Parsing();
        void ParsingFormatType();
        void ParsingAnnotation();
        void ParsingVariableName();
        void ParsingDataType();

        NODISCARD CSVDataType ParsingDataType(const String& element);
        void ParsingEnumTypeName(CSVDataType type, const String& element);

    private:
        PathSplitParsing pathSplitParsing;
        FileContent fileContent;
        CSVFormatType formatType;
        FormatParsing formatParsing;
        Annotation annotation;
        DataType dataType;
        EnumTypeName enumTypeName;
        VariableName variableName;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_HEAD_IMPL_H