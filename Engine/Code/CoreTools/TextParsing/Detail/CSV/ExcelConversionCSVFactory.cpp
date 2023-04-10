///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/04 17:22)

#include "CoreTools/CoreToolsExport.h"

#include "ExcelConversionCSVFactory.h"
#include "OpenXLSXConversion.h"
#include "SimpleCSVConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::ExcelConversionCSVFactory::ExcelConversionCSVSharedPtr CoreTools::ExcelConversionCSVFactory::Create(const std::string& xlsxFileName, const String& csvFileName, bool useOpenXlsx)
{
#ifdef CORE_TOOLS_USE_OPENXLSX

    if (useOpenXlsx)
        return make_shared<OpenXLSXConversion>(xlsxFileName, csvFileName);
    else
        return make_shared<SimpleCSVConversion>(xlsxFileName, csvFileName);

#else  // !CORE_TOOLS_USE_OPENXLSX

    System::UnusedFunction(useOpenXlsx);

    return make_shared<SimpleCSVConversion>(xlsxFileName, csvFileName);

#endif  // CORE_TOOLS_USE_OPENXLSX
}
