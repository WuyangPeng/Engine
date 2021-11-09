///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.4 (2021/10/15 14:17)

#include "CoreTools/CoreToolsExport.h"

#include "ExcelConversionCSV.h"
#include "Detail/ExcelConversionCSVFactory.h"
#include "Detail/ExcelConversionCSVImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::ExcelConversionCSV::ExcelConversionCSV(const std::string& xlsxFileName, const String& csvFileName, bool useOpenXLSX)
    : impl{ ImplCreateUseFactory::Default, xlsxFileName, csvFileName, useOpenXLSX }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ExcelConversionCSV)