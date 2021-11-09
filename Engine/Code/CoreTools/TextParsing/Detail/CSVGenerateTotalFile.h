///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.5 (2021/10/22 16:35)

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

        void GenerateFile(const String& directory) const final;

    private:
        NODISCARD String GetSuffix() const noexcept final;
        NODISCARD String GetFilePrefix() const noexcept final;
        NODISCARD String GetFileSuffix() const noexcept final;
        NODISCARD String GetContent() const noexcept final;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_TOTAL_FILE_H