/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:58)

#include "CoreTools/CoreToolsExport.h"

#include "SimpleCSVDocument.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"

CoreTools::SimpleCSVDocument::SimpleCSVDocument(const std::string& xlsxFileName)
    : xlsxFileName{ xlsxFileName }, document{ SimpleCSV::Document::Open(xlsxFileName) }, worksheetNames{}
{
    Init();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::SimpleCSVDocument::IsValid() const noexcept
{
    if (!xlsxFileName.empty())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::SimpleCSVDocument::Init()
{
    const auto workbook = document->GetWorkbook();
    worksheetNames = workbook.GetWorksheetNames();
}

CoreTools::SimpleCSV::Worksheet CoreTools::SimpleCSVDocument::GetFirstXLWorksheet()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto worksheetName = worksheetNames.at(0);

    auto workbook = document->GetWorkbook();
    auto worksheet = workbook.GetWorksheet(worksheetName);

    return worksheet;
}

CoreTools::SimpleCSVDocument::WorksheetContainer CoreTools::SimpleCSVDocument::GetXLWorksheet()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    WorksheetContainer result{};

    auto xlWorkbook = document->GetWorkbook();

    for (const auto& name : worksheetNames)
    {
        result.emplace_back(xlWorkbook.GetWorksheet(name));
    }

    return result;
}
