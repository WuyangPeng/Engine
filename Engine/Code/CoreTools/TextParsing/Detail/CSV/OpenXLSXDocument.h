///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 11:52)

#ifndef CORE_TOOLS_TEXT_PARSING_OPENXLSX_DOCUMENT_H
#define CORE_TOOLS_TEXT_PARSING_OPENXLSX_DOCUMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/OpenXLSX.h"
#include "System/Helper/UnicodeUsing.h"

#include <set>
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

#endif CORE_TOOLS_USE_OPENXLSX

#endif  // CORE_TOOLS_TEXT_PARSING_OPENXLSX_DOCUMENT_H