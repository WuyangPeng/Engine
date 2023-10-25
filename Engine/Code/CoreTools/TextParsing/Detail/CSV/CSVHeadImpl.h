///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 14:15)

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
    /// ������,���ָ���
    /// ��һ�У����ݴ洢��ʽ������ӳ�䡢����У�顢Ĭ��ֵ�����á�
    /// ��ʽ�����ڣ��洢��ʽ��@default��@key = id * 100 + level��
    /// ����ӳ�䣺level��
    /// ����У�飺[ 1 - 4 ]��( 1 - 4 ]��( 1 - 4 )��> 0 ��>= 5��
    /// { 1 | 2 | 5 }��ʱ��֧�֣�����������ӡ�
    /// Ĭ��ֵ��= 4��
    /// �ڶ��У���עÿ���ֶε�����/˵����
    /// �����У���ע�ֶ��������͡�
    /// ö������������enum|CSVType��enum[]|CSVType��
    /// �����У���ע�ֶα�������
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