/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:41)

#ifndef CORE_TOOLS_TEXT_PARSING_SIMPLE_CSV_DOCUMENT_H
#define CORE_TOOLS_TEXT_PARSING_SIMPLE_CSV_DOCUMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"

#include <string>
#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE SimpleCSVDocument final
    {
    public:
        using ClassType = SimpleCSVDocument;

        using String = System::String;
        using WorksheetContainer = std::vector<SimpleCSV::Worksheet>;

    public:
        explicit SimpleCSVDocument(const std::string& xlsxFileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD SimpleCSV::Worksheet GetFirstXLWorksheet();
        NODISCARD WorksheetContainer GetXLWorksheet();

    private:
        using DocumentSharedPtr = std::shared_ptr<SimpleCSV::Document>;
        using WorksheetNameContainer = std::vector<std::string>;

    private:
        void Init();

    private:
        std::string xlsxFileName;
        DocumentSharedPtr document;
        WorksheetNameContainer worksheetNames;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SIMPLE_CSV_DOCUMENT_H