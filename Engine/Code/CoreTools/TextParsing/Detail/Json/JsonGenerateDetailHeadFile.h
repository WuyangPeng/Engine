///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:05)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_DETAIL_HEAD_FILE_H
#define CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_DETAIL_HEAD_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "JsonGenerateImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonGenerateDetailHeadFile final : public JsonGenerateImpl
    {
    public:
        using ClassType = JsonGenerateDetailHeadFile;
        using ParentType = JsonGenerateImpl;

    public:
        explicit JsonGenerateDetailHeadFile(const JsonHead& jsonHead) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetSuffix() const noexcept override;
        NODISCARD String GetFilePrefix() const override;
        NODISCARD String GetFileSuffix() const override;
        NODISCARD String GetContent() const override;

        NODISCARD String GetContent(const String& className, const JsonNodeContainer& jsonNodeContainer) const;
        NODISCARD String GetContent(const String& className, const JsonNode& jsonNode) const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_DETAIL_HEAD_FILE_H