/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 22:51)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_CSV_GENERATE_DATA_SOURCE_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_CSV_GENERATE_DATA_SOURCE_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"

#include <set>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateDataSourceFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateDataSourceFile;
        using ParentType = CSVGenerateImpl;

    public:
        CSVGenerateDataSourceFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using SubclassIncludeContainer = std::set<String>;

    private:
        NODISCARD String GetSuffix() const noexcept override;
        NODISCARD String GetFilePrefix() const override;
        NODISCARD String GetFileSuffix() const override;

        NODISCARD String GetContent(const String& codeDirectory) const override;

        NODISCARD String GetDataIncludeContent() const;

        NODISCARD String GetDataClassMemberContent() const;
        NODISCARD String GetDataCheckingDefine() const;
        NODISCARD String GetDataIsValidDefine() const;
        NODISCARD String GetDataGetFunctionDefineContent() const;

        NODISCARD SubclassIncludeContainer GetDataIncludeContainer() const;

        NODISCARD SubclassIncludeContainer GetDataIncludeMappingContainer() const;

        NODISCARD String GetDataIncludeMappingContainer(const CSVHead& head, int index) const;
        NODISCARD String GetDataClassMemberContent(const CSVHead& head, int index) const;
        NODISCARD String GetDataCheckingCondition() const;
        NODISCARD String GetDataCheckingCondition(const CSVHead& head, bool isFirst, int index) const;
        NODISCARD String GetCheckingIsValidConditionContent() const;
        NODISCARD static String GetCheckingIsValidConditionContent(const CSVHead& head, bool isFirst, int index);
        NODISCARD String GetDataGetFunctionDefineContent(const CSVHead& head,
                                                         int index,
                                                         const String& functionVariableName,
                                                         CSVDataType dataType,
                                                         const String& actualType,
                                                         const String& valueType,
                                                         const String& abbreviation,
                                                         const String& upperVariableName,
                                                         const String& variableName) const;
        NODISCARD String GetDataGetArrayFunctionDefineContent(const String& valueType,
                                                              const String& abbreviation,
                                                              const String& upperVariableName,
                                                              const String& variableName) const;
        NODISCARD String GetDataGetMappingFunctionDefineContent(CSVDataType dataType,
                                                                const String& upperVariableName,
                                                                const String& variableName,
                                                                const String& mapping) const;

    private:
        String templateName;

        String dataCheckingCall;
        String dataIsValidStubDefine;
        String includeUserClassInvariantMacro;
        String exceptionMacroInclude;
        String numericCastInclude;
        String includeChildClass;
        String includeNamespaceContainer;
        String includeMappingContainer;
        String beginDataClassMember;
        String dataClassMember;
        String endDataClassMember;
        String dataCheckingDefine;
        String dataCheckingCondition;
        String dataIsValidDefine;
        String dataGetFunctionDefine;
        String dataGetCountArrayFunctionDefine;
        String dataGetValueArrayFunctionDefine;
        String dataGetBeginIterArrayFunctionDefine;
        String dataGetEndIterArrayFunctionDefine;
        String dataGetMappingFunctionDefine;
        String dataGetMappingArrayFunctionDefine;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_CSV_GENERATE_DATA_SOURCE_FILE_H