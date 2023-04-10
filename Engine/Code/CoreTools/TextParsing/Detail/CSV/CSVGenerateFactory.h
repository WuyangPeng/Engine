///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:03)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_FACTORY_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

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