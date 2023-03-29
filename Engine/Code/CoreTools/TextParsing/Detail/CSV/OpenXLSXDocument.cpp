///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/10 08:56)

#include "CoreTools/CoreToolsExport.h"

#include "OpenXLSXDocument.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#ifdef CORE_TOOLS_USE_OPENXLSX

using namespace std::literals;

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