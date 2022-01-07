///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/18 21:31)

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