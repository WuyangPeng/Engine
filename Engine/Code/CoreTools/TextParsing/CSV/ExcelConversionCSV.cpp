///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/10 09:09)

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