///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.5 (2021/10/23 0:29)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_CSV_GENERATE_CONTAINER_SOURCE_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_CSV_GENERATE_CONTAINER_SOURCE_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateContainerSourceFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateContainerSourceFile;
        using ParentType = CSVGenerateImpl;

    public:
        explicit CSVGenerateContainerSourceFile(const CSVHead& csvHead) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetSuffix() const final;
        NODISCARD String GetFilePrefix() const final;
        NODISCARD String GetFileSuffix() const final;
        NODISCARD String GetContent() const final;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_CSV_GENERATE_CONTAINER_SOURCE_FILE_H