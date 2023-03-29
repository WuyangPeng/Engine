///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 11:12)

#ifndef CORE_TOOLS_TEXT_PARSING_OPEN_XLSX_DOCUMENT_H
#define CORE_TOOLS_TEXT_PARSING_OPEN_XLSX_DOCUMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/OpenXLSX.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>
#include <vector>

#ifdef CORE_TOOLS_USE_OPENXLSX

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

#endif  // CORE_TOOLS_USE_OPENXLSX

#endif  // CORE_TOOLS_TEXT_PARSING_OPEN_XLSX_DOCUMENT_H