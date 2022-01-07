///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:21)

#include "CoreTools/CoreToolsExport.h"

#include "ExcelConversionCSVFactory.h"
#include "OpenXLSXConversion.h"
#include "SimpleCSVConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;
using std::string;

CoreTools::ExcelConversionCSVFactory::ExcelConversionCSVSharedPtr CoreTools::ExcelConversionCSVFactory::Create(const string& xlsxFileName, const String& csvFileName, MAYBE_UNUSED bool useOpenXLSX)
{
#ifdef CORE_TOOLS_USE_OPENXLSX

    if (useOpenXLSX)
        return make_shared<OpenXLSXConversion>(xlsxFileName, csvFileName);
    else
        return make_shared<SimpleCSVConversion>(xlsxFileName, csvFileName);

#else  // !CORE_TOOLS_USE_OPENXLSX

    return make_shared<SimpleCSVConversion>(xlsxFileName, csvFileName);

#endif  // CORE_TOOLS_USE_OPENXLSX
}
