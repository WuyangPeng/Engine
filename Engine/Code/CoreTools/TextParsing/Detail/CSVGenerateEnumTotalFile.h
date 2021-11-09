///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.5 (2021/10/26 16:25)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_TOTAL_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_TOTAL_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"
#include "CoreTools/TextParsing/CSVContent.h"

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

        void GenerateFile(const String& directory) const final;

    private:
        NODISCARD String GetSuffix() const noexcept final;
        NODISCARD String GetFilePrefix() const noexcept final;
        NODISCARD String GetFileSuffix() const noexcept final;
        NODISCARD String GetContent() const noexcept final;

    private:
        CSVContent csvContent;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_TOTAL_FILE_H