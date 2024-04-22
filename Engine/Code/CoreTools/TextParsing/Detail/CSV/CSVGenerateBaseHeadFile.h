/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 22:51)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_BASE_HEAD_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_BASE_HEAD_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"

#include <gsl/pointers>
#include <map>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateBaseHeadFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateBaseHeadFile;
        using ParentType = CSVGenerateImpl;

    public:
        CSVGenerateBaseHeadFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using GetContentFunction = String (ClassType::*)(const String&) const;
        using Container = std::map<String, gsl::not_null<GetContentFunction>>;
        using StdIncludeContainer = std::vector<String>;
        using BaseClassUsingContainer = std::vector<std::pair<String, ReplaceType>>;

    private:
        NODISCARD String GetSuffix() const override;
        NODISCARD String GetFilePrefix() const override;
        NODISCARD String GetFileSuffix() const override;
        NODISCARD String GetContent(const String& codeDirectory) const override;

        NODISCARD String GetStdIncludeContent(const String& codeKey) const;
        NODISCARD String GetBaseClassUsingContent(const String& codeKey) const;
        NODISCARD String GetBaseGetFunctionContent(const String& codeKey) const;
        NODISCARD String GetBaseGetArrayFunctionContent(const String& valueType, const String& abbreviation, const String& upperVariableName) const;

        NODISCARD String GetBaseGetFunctionContent(const CSVHead& head, int index) const;
        NODISCARD String GetBaseGetFunctionHasMappingContent(CSVDataType dataType,
                                                             const String& upperVariableName,
                                                             const String& mapping) const;
        NODISCARD static StdIncludeContainer GetStdIncludeContainer(const CSVHead& csvHead);
        NODISCARD static BaseClassUsingContainer GetBaseClassUsingContainer(const CSVHead& csvHead);

    private:
        Container container;
        String templateName;
        StdIncludeContainer stdIncludeContainer;
        BaseClassUsingContainer baseClassUsingContainer;

        String baseGetFunction;
        String baseGetCountArrayFunction;
        String baseGetValueArrayFunction;
        String baseGetBeginIterArrayFunction;
        String baseGetEndIterArrayFunction;
        String baseGetMappingFunction;
        String baseGetMappingArrayFunction;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_BASE_HEAD_FILE_H