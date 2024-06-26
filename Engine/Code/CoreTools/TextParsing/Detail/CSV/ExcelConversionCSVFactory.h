/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 22:52)

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