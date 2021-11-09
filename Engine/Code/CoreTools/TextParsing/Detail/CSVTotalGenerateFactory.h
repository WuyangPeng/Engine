///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.5 (2021/10/25 11:26)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_FACTORY_H
#define CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

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
        NODISCARD static CSVTotalGenerateSharedPtr Create(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, CSVTotalGenerateType csvTotalGenerateType);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_FACTORY_H