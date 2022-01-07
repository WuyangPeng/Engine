///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 11:54)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_HEAD_FILE_H
#define CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_HEAD_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "JsonGenerateImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonGenerateHeadFile final : public JsonGenerateImpl
    {
    public:
        using ClassType = JsonGenerateHeadFile;
        using ParentType = JsonGenerateImpl;

    public:
        explicit JsonGenerateHeadFile(const JsonHead& jsonHead) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetSuffix() const noexcept final;
        NODISCARD String GetFilePrefix() const final;
        NODISCARD String GetFileSuffix() const final;
        NODISCARD String GetContent() const final;

        NODISCARD String GetContent(const JsonNodeContainer& jsonNodeContainer) const;
        NODISCARD String GetContent(const JsonNode& jsonNode) const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_HEAD_FILE_H