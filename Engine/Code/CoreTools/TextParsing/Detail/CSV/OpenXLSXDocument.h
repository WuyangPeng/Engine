/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:41)

#ifndef CORE_TOOLS_TEXT_PARSING_OPEN_XLSX_DOCUMENT_H
#define CORE_TOOLS_TEXT_PARSING_OPEN_XLSX_DOCUMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/OpenXLSX.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>
#include <vector>

#ifdef CORE_TOOLS_USE_OPEN_XLSX

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE OpenXLSXDocument final
    {
    public:
        using ClassType = OpenXLSXDocument;

        using String = System::String;
        using XLWorksheetContainer = std::vector<OpenXLSX::XLWorksheet>;

    public:
        explicit OpenXLSXDocument(const std::string& xlsxFileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD OpenXLSX::XLWorksheet GetFirstXLWorksheet();
        NODISCARD XLWorksheetContainer GetXLWorksheet();

    private:
        using WorksheetNameContainer = std::vector<std::string>;

    private:
        void Init();

    private:
        std::string xlsxFileName;
        OpenXLSX::XLDocument document;
        WorksheetNameContainer worksheetNames;
    };
}

#endif  // CORE_TOOLS_USE_OPEN_XLSX

#endif  // CORE_TOOLS_TEXT_PARSING_OPEN_XLSX_DOCUMENT_H