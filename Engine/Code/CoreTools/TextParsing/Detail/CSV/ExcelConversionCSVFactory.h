///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 11:52)

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
        NODISCARD static ExcelConversionCSVSharedPtr Create(const std::string& xlsxFileName, const String& csvFileName, MAYBE_UNUSED bool useOpenXLSX);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_EXCEL_CONVERSION_CSV_FACTORY_H