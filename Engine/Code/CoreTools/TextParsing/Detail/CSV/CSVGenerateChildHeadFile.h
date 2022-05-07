///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 11:48)

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
        NODISCARD String GetSuffix() const noexcept final;
        NODISCARD String GetFilePrefix() const final;
        NODISCARD String GetFileSuffix() const final;
        NODISCARD String GetContent() const final;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_BASE_CHILD_FILE_H