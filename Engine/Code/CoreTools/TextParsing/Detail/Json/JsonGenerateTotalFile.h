///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 11:54)

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

        void GenerateFile(const String& directory) const final;

    private:
        NODISCARD String GetSuffix() const noexcept final;
        NODISCARD String GetFilePrefix() const noexcept final;
        NODISCARD String GetFileSuffix() const noexcept final;
        NODISCARD String GetContent() const noexcept final;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_TOTAL_FILE_H