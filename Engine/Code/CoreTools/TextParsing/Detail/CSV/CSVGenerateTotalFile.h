///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 11:06)

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
        explicit CSVGenerateTotalFile(const CSVHead& csvHead) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void GenerateFile(const String& directory) const override;

    private:
        using CSVGenerateSharedPtr = std::shared_ptr<CSVGenerateImpl>;
        using Container = std::vector<CSVGenerateSharedPtr>;

    private:
        NODISCARD String GetSuffix() const noexcept override;
        NODISCARD String GetFilePrefix() const noexcept override;
        NODISCARD String GetFileSuffix() const noexcept override;
        NODISCARD String GetContent() const noexcept override;

        void GenerateDefaultFile(const String& directory) const;
        void GenerateMapFile(const String& directory) const;
        void GenerateUniqueFile(const String& directory) const;

        void GenerateFile(const Container& container, const String& directory) const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_TOTAL_FILE_H