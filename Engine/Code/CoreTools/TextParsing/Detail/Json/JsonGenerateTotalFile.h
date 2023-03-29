///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/10 13:39)

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