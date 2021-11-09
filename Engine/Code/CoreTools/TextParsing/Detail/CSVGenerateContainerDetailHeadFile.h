///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/10/22 10:07)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CONTAINER_DETAIL_HEAD_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CONTAINER_DETAIL_HEAD_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateContainerDetailHeadFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateContainerDetailHeadFile;
        using ParentType = CSVGenerateImpl;

    public:
        explicit CSVGenerateContainerDetailHeadFile(const CSVHead& csvHead) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetSuffix() const final;
        NODISCARD String GetFilePrefix() const final;
        NODISCARD String GetFileSuffix() const final;
        NODISCARD String GetContent() const final;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CONTAINER_DETAIL_HEAD_FILE_H