/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:58)

#include "CoreTools/CoreToolsExport.h"

#include "ExcelConversionCSVFactory.h"
#include "OpenXLSXConversion.h"
#include "SimpleCSVConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::ExcelConversionCSVFactory::ExcelConversionCSVSharedPtr CoreTools::ExcelConversionCSVFactory::Create(const std::string& xlsxFileName, const String& csvFileName, bool useOpenXlsx)
{
#ifdef CORE_TOOLS_USE_OPEN_XLSX

    if (useOpenXlsx)
        return make_shared<OpenXLSXConversion>(xlsxFileName, csvFileName);
    else
        return make_shared<SimpleCSVConversion>(xlsxFileName, csvFileName);

#else  // !CORE_TOOLS_USE_OPEN_XLSX

    System::UnusedFunction(useOpenXlsx);

    return make_shared<SimpleCSVConversion>(xlsxFileName, csvFileName);

#endif  // CORE_TOOLS_USE_OPEN_XLSX
}
