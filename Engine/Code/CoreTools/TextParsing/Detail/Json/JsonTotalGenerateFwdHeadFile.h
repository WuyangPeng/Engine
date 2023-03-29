///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/09 11:08)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_TOTAL_GENERATE_FWD_HEAD_FILE_H
#define CORE_TOOLS_TEXT_PARSING_JSON_TOTAL_GENERATE_FWD_HEAD_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "JsonTotalGenerateImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonTotalGenerateFwdHeadFile final : public JsonTotalGenerateImpl
    {
    public:
        using ClassType = JsonTotalGenerateFwdHeadFile;
        using ParentType = JsonTotalGenerateImpl;

    public:
        JsonTotalGenerateFwdHeadFile(const String& nameSpace, const JsonHeadContainer& jsonHeadContainer);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetFileSuffix() const override;
        NODISCARD String GetContent() const override;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_TOTAL_GENERATE_FWD_HEAD_FILE_H