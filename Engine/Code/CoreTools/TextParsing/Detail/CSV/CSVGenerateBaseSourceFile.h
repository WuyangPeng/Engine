/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 22:51)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_BASE_SOURCE_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_BASE_SOURCE_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateBaseSourceFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateBaseSourceFile;
        using ParentType = CSVGenerateImpl;

    public:
        CSVGenerateBaseSourceFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetSuffix() const override;
        NODISCARD String GetFilePrefix() const override;
        NODISCARD String GetFileSuffix() const override;
        NODISCARD String GetContent(const String& codeDirectory) const override;
        NODISCARD String GetBaseGetFunctionDefineContent() const;
        NODISCARD String GetBaseGetFunctionDefineContent(const CSVHead& head,
                                                         int index,
                                                         const String& functionVariableName,
                                                         CSVDataType dataType,
                                                         const String& actualType,
                                                         const String& valueType,
                                                         const String& abbreviation,
                                                         const String& upperVariableName) const;
        NODISCARD String GetCopyBaseGetFunctionDefine(const String& functionVariableName,
                                                      CSVDataType dataType,
                                                      const String& actualType,
                                                      const String& abbreviation) const;
        NODISCARD String GetBaseGetArrayFunctionDefineContent(CSVDataType dataType,
                                                                  const String& valueType,
                                                                  const String& abbreviation,
                                                                  const String& upperVariableName) const;
        NODISCARD String GetBaseGetMappingFunctionDefineContent(const CSVHead& head,
                                                                int index,
                                                                CSVDataType dataType,
                                                                const String& upperVariableName) const;
        NODISCARD String GetBaseGetFunctionDefine(CSVDataType dataType) const;

    private:
        String templateName;

        String baseGetFunctionDefine;
        String baseStringGetFunctionDefine;
        String baseArrayGetFunctionDefine;
        String baseEnumGetFunctionDefine;
        String baseGetCountArrayFunction;
        String baseGetValueArrayFunction;
        String baseGetBeginIterArrayFunction;
        String baseGetEndIterArrayFunction;
        String baseGetMappingFunction;
        String baseGetMappingArrayFunction;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_BASE_SOURCE_FILE_H