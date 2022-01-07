///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 11:50)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_FACTORY_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

#include <memory>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateFactory final
    {
    public:
        using ClassType = CSVGenerateFactory;
        using CSVGenerateSharedPtr = std::shared_ptr<CSVGenerateImpl>;
        using String = System::String;

    public:
        NODISCARD static CSVGenerateSharedPtr Create(const CSVHead& csvHead, CSVGenerateType csvGenerateType);
        NODISCARD static CSVGenerateSharedPtr Create(const CSVContent& csvContent, CSVGenerateType csvGenerateType);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_FACTORY_H