///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 11:52)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_FWD_HEAD_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_FWD_HEAD_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVTotalGenerateImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVTotalGenerateFwdHeadFile final : public CSVTotalGenerateImpl
    {
    public:
        using ClassType = CSVTotalGenerateFwdHeadFile;
        using ParentType = CSVTotalGenerateImpl;

    public:
        explicit CSVTotalGenerateFwdHeadFile(const String& nameSpace, const CSVHeadContainer& csvHeadContainer);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetFileSuffix() const final;
        NODISCARD String GetContent() const final;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_FWD_HEAD_FILE_H