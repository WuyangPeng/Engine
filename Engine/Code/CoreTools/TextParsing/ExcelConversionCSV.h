///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/15 14:17)

#ifndef CORE_TOOLS_TEXT_PARSING_EXCEL_CONVERSION_CSV_H
#define CORE_TOOLS_TEXT_PARSING_EXCEL_CONVERSION_CSV_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

CORE_TOOLS_NON_COPY_EXPORT_IMPL(ExcelConversionCSVImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ExcelConversionCSV final
    {
    public:
        NON_COPY_TYPE_DECLARE(ExcelConversionCSV);
        using String = System::String;

    public:
        ExcelConversionCSV(const std::string& xlsxFileName, const String& csvFileName, bool useOpenXLSX);

        CLASS_INVARIANT_DECLARE;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_EXCEL_CONVERSION_CSV_H