///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 14:15)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_TOTAL_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_TOTAL_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateTotalFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateTotalFile;
        using ParentType = CSVGenerateImpl;

    public:
        CSVGenerateTotalFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void GenerateFile(const String& codeDirectory, const String& directory) const override;

    private:
        using CSVGenerateSharedPtr = std::shared_ptr<CSVGenerateImpl>;
        using Container = std::vector<CSVGenerateSharedPtr>;

    private:
        NODISCARD String GetSuffix() const noexcept override;
        NODISCARD String GetFilePrefix() const noexcept override;
        NODISCARD String GetFileSuffix() const noexcept override;
        NODISCARD String GetContent(const String& codeDirectory) const noexcept override;

        void GenerateDefaultFile(const String& codeDirectory, const String& directory) const;
        void GenerateMapFile(const String& codeDirectory, const String& directory) const;
        void GenerateUniqueFile(const String& codeDirectory, const String& directory) const;

        void GenerateFile(const Container& container, const String& codeDirectory, const String& directory) const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_TOTAL_FILE_H