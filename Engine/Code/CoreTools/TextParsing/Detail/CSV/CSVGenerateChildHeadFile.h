/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/02 22:51)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_BASE_CHILD_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_BASE_CHILD_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"

#include <gsl/pointers>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateChildHeadFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateChildHeadFile;
        using ParentType = CSVGenerateImpl;

    public:
        CSVGenerateChildHeadFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
    private:
        using GetContentFunction = String (ClassType::*)(const String&) const;
        using Container = std::map<String, gsl::not_null<GetContentFunction>>;

    private:
        NODISCARD String GetSuffix() const noexcept override;
        NODISCARD String GetFilePrefix() const override;
        NODISCARD String GetFileSuffix() const override;
        NODISCARD String GetContent(const String& codeDirectory) const override;

        NODISCARD String GenerateKeyParameter() const;
        NODISCARD static String GetKeyParameter(const CSVHead& head, const String& element, bool isEnd);

        NODISCARD String GetSubclassGetFunctionContent(const String& codeKey) const;
        NODISCARD String GetSubclassGetArrayFunctionContent(CSVDataType dataType,
                                                            const String& valueType,
                                                            const String& abbreviation,
                                                            const String& upperVariableName) const;
        NODISCARD String GetSubclassGetMappingFunctionContent(const CSVHead& head,
                                                              int index,
                                                              CSVDataType dataType,
                                                              const String& upperVariableName) const;
        NODISCARD String GetGenerateKeyFunctionContent(const String& codeKey) const;
        NODISCARD String GetSubclassCheckingFunctionContent(const String& codeKey) const;
        NODISCARD String GetSubclassMemberContent(const String& codeKey) const;

        NODISCARD String GetSubclassGetFunctionContent(const String& subclassGetFunction,
                                                       const CSVHead& head,
                                                       int index,
                                                       const String& functionVariableName,
                                                       CSVDataType dataType,
                                                       const String& valueType,
                                                       const String& abbreviation,
                                                       const String& upperVariableName) const;

    private:
        Container container;
        String templateName;

        String subclassGetCountArrayFunction;
        String subclassGetValueArrayFunction;
        String subclassGetBeginIterArrayFunction;
        String subclassGetEndIterArrayFunction;
        String subclassGetMappingFunction;
        String subclassGetMappingArrayFunction;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_BASE_CHILD_FILE_H