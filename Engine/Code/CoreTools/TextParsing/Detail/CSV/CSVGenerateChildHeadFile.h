///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/09 10:46)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_BASE_CHILD_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_BASE_CHILD_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateChildHeadFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateChildHeadFile;
        using ParentType = CSVGenerateImpl;

    public:
        explicit CSVGenerateChildHeadFile(const CSVHead& csvHead) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetSuffix() const noexcept override;
        NODISCARD String GetFilePrefix() const override;
        NODISCARD String GetFileSuffix() const override;
        NODISCARD String GetContent() const override;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_BASE_CHILD_FILE_H