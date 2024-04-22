/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 10:44)

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
    return !xlsxFileName.empty();
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::SimpleCSVDocument::Init()
{
    const auto workbook = document->GetWorkbook();
    worksheetNames = workbook.GetWorksheetNames();
}

CoreTools::SimpleCSV::Worksheet CoreTools::SimpleCSVDocument::GetFirstWorksheet()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto worksheetName = worksheetNames.at(0);

    auto workbook = document->GetWorkbook();
    auto worksheet = workbook.GetWorksheet(worksheetName);

    return worksheet;
}

CoreTools::SimpleCSVDocument::WorksheetContainer CoreTools::SimpleCSVDocument::GetWorksheet()
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
