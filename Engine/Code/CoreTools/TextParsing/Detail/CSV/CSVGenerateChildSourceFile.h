/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 22:51)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CHILD_SOURCE_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CHILD_SOURCE_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"

#include <set>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateChildSourceFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateChildSourceFile;
        using ParentType = CSVGenerateImpl;

    public:
        CSVGenerateChildSourceFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using SubclassIncludeContainer = std::set<String>;

    private:
        NODISCARD String GetSuffix() const noexcept override;
        NODISCARD String GetFilePrefix() const override;
        NODISCARD String GetFileSuffix() const override;

        NODISCARD String GetContent(const String& codeDirectory) const override;

        NODISCARD SubclassIncludeContainer GetSubclassIncludeContainer() const;
        NODISCARD String GetSubclassIncludeContent() const;
        NODISCARD String GetSubclassClassMemberContent() const;
        NODISCARD String GetSubclassGetFunctionDefineContent() const;
        NODISCARD String GetSubclassGetMappingFunctionDefineContent(CSVDataType dataType,
                                                                    const String& upperVariableName,
                                                                    const String& variableName,
                                                                    const String& mapping) const;
        NODISCARD String GetSubclassGetArrayFunctionDefineContent(const String& valueType,
                                                                  const String& abbreviation,
                                                                  const String& upperVariableName,
                                                                  const String& variableName) const;
        NODISCARD String GetSubclassIsValidDefine() const;
        NODISCARD static String GetCheckingIsValidConditionContent(bool isFirst, const CSVHead& head, int index);
        NODISCARD String GetSubclassCheckingDefine() const;
        NODISCARD String GetCheckingConditionContent(bool isFirst, const CSVHead& head, int index) const;
        NODISCARD String GetSubclassGetFunctionDefineContent(const CSVHead& head,
                                                             int index,
                                                             const String& functionVariableName,
                                                             CSVDataType dataType,
                                                             const String& actualType,
                                                             const String& valueType,
                                                             const String& abbreviation,
                                                             const String& upperVariableName,
                                                             const String& variableName) const;

        NODISCARD String GetSubclassIncludeContainer(const CSVHead& head, int index) const;
        NODISCARD SubclassIncludeContainer GetSubclassIncludeMappingContainer() const;
        NODISCARD String GetCheckingIsValidConditionContent() const;
        NODISCARD String GetCheckingConditionContent() const;

    private:
        String templateName;

        String subclassCheckingCall;
        String subclassIsValidStubDefine;
        String includeUserClassInvariantMacro;
        String exceptionMacroInclude;
        String numericCastInclude;
        String includeChildClass;
        String includeNamespaceContainer;
        String includeMappingContainer;
        String subclassClassMember;
        String endSubclassClassMember;
        String subclassGetFunctionDefine;
        String subclassGetCountArrayFunctionDefine;
        String subclassGetValueArrayFunctionDefine;
        String subclassGetBeginIterArrayFunctionDefine;
        String subclassGetEndIterArrayFunctionDefine;
        String subclassGetMappingFunctionDefine;
        String subclassGetMappingArrayFunctionDefine;
        String subclassIsValidDefine;
        String subclassCheckingDefine;
        String checkingCondition;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CHILD_SOURCE_FILE_H