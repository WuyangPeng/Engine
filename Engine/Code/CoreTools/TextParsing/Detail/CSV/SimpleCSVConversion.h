///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 14:16)

#ifndef CORE_TOOLS_TEXT_PARSING_SIMPLE_CSV_CONVERSION_H
#define CORE_TOOLS_TEXT_PARSING_SIMPLE_CSV_CONVERSION_H

#include "CoreTools/CoreToolsDll.h"

#include "ExcelConversionCSVImpl.h"
#include "SimpleCSVDocument.h"
#include "System/Helper/UnicodeUsing.h"

#include <set>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE SimpleCSVConversion final : public ExcelConversionCSVImpl
    {
    public:
        using ClassType = SimpleCSVConversion;
        using ParentType = ExcelConversionCSVImpl;

        using String = System::String;

    public:
        SimpleCSVConversion(const std::string& xlsxFileName, String csvFileName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void Conversion();

        void ObtainRelated(const SimpleCSV::Worksheet& xlWorksheet);
        NODISCARD std::string GetContent(bool isFirstPage, const SimpleCSV::Worksheet& xlWorksheet) const;
        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, const SimpleCSV::Row& xlRow) const;
        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, int columnIndex, const SimpleCSV::CellValue& xlCellValue) const;
        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, int columnIndex, const std::string& column) const;
        NODISCARD bool IsIgnore(const SimpleCSV::Worksheet& xlWorksheet) const;

        void SaveIntoFile(const std::string& content) const;

    private:
        using IndexContainer = std::set<int>;

    private:
        SimpleCSVDocument document;
        String csvFileName;
        IndexContainer exclude;
        IndexContainer stringField;
        IndexContainer bitField;
        IndexContainer bitArrayField;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SIMPLE_CSV_CONVERSION_H