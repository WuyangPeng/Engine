/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:39)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_FACTORY_H
#define CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVTotalGenerateFactory final
    {
    public:
        using ClassType = CSVTotalGenerateFactory;
        using CSVTotalGenerateSharedPtr = std::shared_ptr<CSVTotalGenerateImpl>;

        using String = System::String;
        using CSVHeadContainer = std::vector<CSVHead>;

    public:
        NODISCARD static CSVTotalGenerateSharedPtr Create(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, const CodeMappingAnalysis& codeMappingAnalysis, CSVTotalGenerateType csvTotalGenerateType);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_FACTORY_H