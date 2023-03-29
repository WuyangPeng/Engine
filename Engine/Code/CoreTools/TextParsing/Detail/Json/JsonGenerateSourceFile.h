///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/10 13:39)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_SOURCE_FILE_H
#define CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_SOURCE_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "JsonGenerateImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonGenerateSourceFile final : public JsonGenerateImpl
    {
    public:
        using ClassType = JsonGenerateSourceFile;
        using ParentType = JsonGenerateImpl;

    public:
        explicit JsonGenerateSourceFile(const JsonHead& jsonHead) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetSuffix() const noexcept override;
        NODISCARD String GetFilePrefix() const override;
        NODISCARD String GetFileSuffix() const override;
        NODISCARD String GetContent() const override;

        NODISCARD String GetContent(const JsonNodeContainer& jsonNodeContainer) const;
        NODISCARD String GetContent(const JsonNode& jsonNode) const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_SOURCE_FILE_H