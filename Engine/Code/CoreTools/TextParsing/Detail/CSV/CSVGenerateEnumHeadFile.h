///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 11:03)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_HEAD_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_HEAD_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateEnumHeadFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateEnumHeadFile;
        using ParentType = CSVGenerateImpl;

    public:
        explicit CSVGenerateEnumHeadFile(const CSVContent& csvContent);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetSuffix() const noexcept override;
        NODISCARD String GetFilePrefix() const override;
        NODISCARD String GetFileSuffix() const override;
        NODISCARD String GetContent() const override;

    private:
        CSVContent csvContent;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_HEAD_FILE_H