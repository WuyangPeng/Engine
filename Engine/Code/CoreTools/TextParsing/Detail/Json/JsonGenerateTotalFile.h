///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/10 13:39)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_TOTAL_FILE_H
#define CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_TOTAL_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "JsonGenerateImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonGenerateTotalFile final : public JsonGenerateImpl
    {
    public:
        using ClassType = JsonGenerateTotalFile;
        using ParentType = JsonGenerateImpl;

    public:
        explicit JsonGenerateTotalFile(const JsonHead& jsonHead) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void GenerateFile(const String& directory) const override;

    private:
        NODISCARD String GetSuffix() const noexcept override;
        NODISCARD String GetFilePrefix() const noexcept override;
        NODISCARD String GetFileSuffix() const noexcept override;
        NODISCARD String GetContent() const noexcept override;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_TOTAL_FILE_H