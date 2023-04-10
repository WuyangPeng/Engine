///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:03)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_TOTAL_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_TOTAL_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateEnumTotalFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateEnumTotalFile;
        using ParentType = CSVGenerateImpl;

    public:
        explicit CSVGenerateEnumTotalFile(const CSVContent& csvContent);

        CLASS_INVARIANT_FINAL_DECLARE;

        void GenerateFile(const String& directory) const override;

    private:
        NODISCARD String GetSuffix() const noexcept override;
        NODISCARD String GetFilePrefix() const noexcept override;
        NODISCARD String GetFileSuffix() const noexcept override;
        NODISCARD String GetContent() const noexcept override;

    private:
        CSVContent csvContent;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_TOTAL_FILE_H