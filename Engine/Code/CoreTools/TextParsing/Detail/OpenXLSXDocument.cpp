///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/15 14:22)

#include "CoreTools/CoreToolsExport.h"

#include "OpenXLSXDocument.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

#ifdef CORE_TOOLS_USE_OPENXLSX

using std::string;
using std::vector;
using namespace std::literals;

CoreTools::OpenXLSXDocument::OpenXLSXDocument(const string& xlsxFileName)
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

    auto xlWorkbook = document.workbook();
    worksheetNames = xlWorkbook.worksheetNames();
}

OpenXLSX::XLWorksheet CoreTools::OpenXLSXDocument::GetFirstXLWorksheet()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto worksheetName = worksheetNames.at(0);

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