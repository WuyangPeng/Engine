/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 22:51)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_DATA_HEAD_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_DATA_HEAD_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"

#include <gsl/pointers>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateDataHeadFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateDataHeadFile;
        using ParentType = CSVGenerateImpl;

    public:
        CSVGenerateDataHeadFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using GetContentFunction = String (ClassType::*)(const String&) const;
        using Container = std::map<String, gsl::not_null<GetContentFunction>>;
        using StdIncludeContainer = std::vector<String>;
        using BaseClassUsingContainer = std::vector<std::pair<String, ReplaceType>>;

    private:
        NODISCARD String GetSuffix() const noexcept override;
        NODISCARD String GetFilePrefix() const override;
        NODISCARD String GetFileSuffix() const override;
        NODISCARD String GetContent(const String& codeDirectory) const override;

        NODISCARD String GetStdIncludeContent(const String& codeKey) const;
        NODISCARD String GetBaseClassUsingContent(const String& codeKey) const;
        NODISCARD String GetDataGetFunctionContent(const String& codeKey) const;

        NODISCARD String GetDataCheckingFunctionContent(const String& codeKey) const;
        NODISCARD String GetDataMemberContent(const String& codeKey) const;

        NODISCARD String GetDataGetFunctionContent(const CSVHead& head, int index) const;
        NODISCARD String GetDataGetArrayFunctionContent(const String& valueType,
                                                        const String& abbreviation,
                                                        const String& upperVariableName) const;
        NODISCARD String GetDataGetFunctionHasMappingContent(CSVDataType dataType,
                                                             const String& upperVariableName,
                                                             const String& mapping) const;
        NODISCARD static String GetDataMemberContent(const CSVHead& head,
                                                     const String& dataMember,
                                                     int index);

        NODISCARD static StdIncludeContainer GetStdIncludeContainer(const CSVHead& csvHead);
        NODISCARD static BaseClassUsingContainer GetBaseClassUsingContainer(const CSVHead& csvHead);

    private:
        String templateName;
        Container container;
        StdIncludeContainer stdIncludeContainer;
        BaseClassUsingContainer baseClassUsingContainer;

        String dataGetFunction;
        String dataGetCountArrayFunction;
        String dataGetValueArrayFunction;
        String dataGetBeginIterArrayFunction;
        String dataGetEndIterArrayFunction;
        String dataGetMappingFunction;
        String dataGetMappingArrayFunction;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_DATA_HEAD_FILE_H