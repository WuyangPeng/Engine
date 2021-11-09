///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.5 (2021/10/21 11:22)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CONTAINER_HEAD_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CONTAINER_HEAD_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateContainerHeadFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateContainerHeadFile;
        using ParentType = CSVGenerateImpl;

    public:
        explicit CSVGenerateContainerHeadFile(const CSVHead& csvHead) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetSuffix() const final;
        NODISCARD String GetFilePrefix() const final;
        NODISCARD String GetFileSuffix() const final;
        NODISCARD String GetContent() const final;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CONTAINER_HEAD_FILE_H