/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 18:11)

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
        using Worksheet = OpenXLSX::XLWorksheet;
        using WorksheetContainer = std::vector<OpenXLSX::XLWorksheet>;

    public:
        explicit OpenXLSXDocument(const std::string& xlsxFileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Worksheet GetFirstWorksheet();
        NODISCARD WorksheetContainer GetWorksheet();

    private:
        using WorksheetNameContainer = std::vector<std::string>;
        using Document = OpenXLSX::XLDocument;

    private:
        void Init();

    private:
        std::string xlsxFileName;
        Document document;
        WorksheetNameContainer worksheetNames;
    };
}

#endif  // CORE_TOOLS_USE_OPEN_XLSX

#endif  // CORE_TOOLS_TEXT_PARSING_OPEN_XLSX_DOCUMENT_H