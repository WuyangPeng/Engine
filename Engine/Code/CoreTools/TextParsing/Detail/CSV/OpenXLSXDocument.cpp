///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/04 17:23)

#include "CoreTools/CoreToolsExport.h"

#include "OpenXLSXDocument.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#ifdef CORE_TOOLS_USE_OPENXLSX

CoreTools::OpenXLSXDocument::OpenXLSXDocument(const std::string& xlsxFileName)
    : xlsxFileName{ xlsxFileName }, document{}, worksheetNames{}
{
    Init();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

    #ifdef OPEN_CLASS_INVARIANT

bool CoreTools::OpenXLSXDocument::IsValid() const noexcept
{
    if (!xlsxFileName.empty())
        return true;
    else
        return false;
}

    #endif  // OPEN_CLASS_INVARIANT

void CoreTools::OpenXLSXDocument::Init()
{
    document.open(xlsxFileName);

    const auto xlWorkbook = document.workbook();
    worksheetNames = xlWorkbook.worksheetNames();
}

OpenXLSX::XLWorksheet CoreTools::OpenXLSXDocument::GetFirstXLWorksheet()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto worksheetName = worksheetNames.at(0);

    auto xlWorkbook = document.workbook();
    auto xlWorksheet = xlWorkbook.worksheet(worksheetName);

    return xlWorksheet;
}

CoreTools::OpenXLSXDocument::XLWorksheetContainer CoreTools::OpenXLSXDocument::GetXLWorksheet()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    XLWorksheetContainer result{};

    auto xlWorkbook = document.workbook();

    for (const auto& name : worksheetNames)
    {
        result.emplace_back(xlWorkbook.worksheet(name));
    }

    return result;
}

#endif  // CORE_TOOLS_USE_OPENXLSX