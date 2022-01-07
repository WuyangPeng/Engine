///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 11:49)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_CSV_GENERATE_DATA_SOURCE_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_CSV_GENERATE_DATA_SOURCE_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateDataSourceFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateDataSourceFile;
        using ParentType = CSVGenerateImpl;

    public:
        explicit CSVGenerateDataSourceFile(const CSVHead& csvHead) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetSuffix() const noexcept final;
        NODISCARD String GetFilePrefix() const final;
        NODISCARD String GetFileSuffix() const final;
        NODISCARD String GetContent() const final;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_CSV_GENERATE_DATA_SOURCE_FILE_H