///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/10 09:06)

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
        ExcelConversionCSV(const std::string& xlsxFileName, const String& csvFileName, bool useOpenXlsx);

        CLASS_INVARIANT_DECLARE;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_EXCEL_CONVERSION_CSV_H