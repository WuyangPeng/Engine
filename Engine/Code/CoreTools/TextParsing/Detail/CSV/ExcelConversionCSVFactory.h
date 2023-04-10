///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:04)

#ifndef CORE_TOOLS_TEXT_PARSING_EXCEL_CONVERSION_CSV_FACTORY_H
#define CORE_TOOLS_TEXT_PARSING_EXCEL_CONVERSION_CSV_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

#include <memory>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ExcelConversionCSVFactory final
    {
    public:
        using ClassType = ExcelConversionCSVFactory;
        using ExcelConversionCSVSharedPtr = std::shared_ptr<ExcelConversionCSVImpl>;
        using String = System::String;

    public:
        NODISCARD static ExcelConversionCSVSharedPtr Create(const std::string& xlsxFileName, const String& csvFileName, bool useOpenXlsx);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_EXCEL_CONVERSION_CSV_FACTORY_H