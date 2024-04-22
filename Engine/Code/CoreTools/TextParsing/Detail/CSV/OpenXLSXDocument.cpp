/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 10:43)

#include "CoreTools/CoreToolsExport.h"

#include "OpenXLSXDocument.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#ifdef CORE_TOOLS_USE_OPEN_XLSX

CoreTools::OpenXLSXDocument::OpenXLSXDocument(const std::string& xlsxFileName)
    : xlsxFileName{ xlsxFileName }, document{}, worksheetNames{}
{
    Init();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

    #ifdef OPEN_CLASS_INVARIANT

bool CoreTools::OpenXLSXDocument::IsValid() const noexcept
{
    return !xlsxFileName.empty();
}

    #endif  // OPEN_CLASS_INVARIANT

void CoreTools::OpenXLSXDocument::Init()
{
    document.open(xlsxFileName);

    const auto xlWorkbook = document.workbook();
    worksheetNames = xlWorkbook.worksheetNames();
}

CoreTools::OpenXLSXDocument::Worksheet CoreTools::OpenXLSXDocument::GetFirstWorksheet()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto worksheetName = worksheetNames.at(0);

    auto xlWorkbook = document.workbook();
    auto xlWorksheet = xlWorkbook.worksheet(worksheetName);

    return xlWorksheet;
}

CoreTools::OpenXLSXDocument::WorksheetContainer CoreTools::OpenXLSXDocument::GetWorksheet()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    WorksheetContainer result{};

    auto xlWorkbook = document.workbook();

    for (const auto& name : worksheetNames)
    {
        result.emplace_back(xlWorkbook.worksheet(name));
    }

    return result;
}

#endif  // CORE_TOOLS_USE_OPEN_XLSX