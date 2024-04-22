/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/03 09:14)

#include "CoreTools/CoreToolsExport.h"

#include "ExcelConversionCSV.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Detail/CSV/ExcelConversionCSVFactory.h"
#include "CoreTools/TextParsing/Detail/CSV/ExcelConversionCSVImpl.h"

CoreTools::ExcelConversionCSV::ExcelConversionCSV(const std::string& xlsxFileName, const String& csvFileName, bool useOpenXlsx)
    : impl{ ImplCreateUseFactory::Default, xlsxFileName, csvFileName, useOpenXlsx }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ExcelConversionCSV)