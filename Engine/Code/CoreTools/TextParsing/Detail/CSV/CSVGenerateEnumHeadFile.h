///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 11:49)

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
        NODISCARD String GetSuffix() const noexcept final;
        NODISCARD String GetFilePrefix() const final;
        NODISCARD String GetFileSuffix() const final;
        NODISCARD String GetContent() const final;

    private:
        CSVContent csvContent;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_HEAD_FILE_H