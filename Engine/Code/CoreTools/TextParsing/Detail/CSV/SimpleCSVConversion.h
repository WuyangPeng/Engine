///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 11:53)

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
        SimpleCSVConversion(const std::string& xlsxFileName, const String& csvFileName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void Conversion();

        void ObtainRelated(const SimpleCSV::Worksheet& xlWorksheet);
        NODISCARD std::string GetContent(bool isFirstPage, const SimpleCSV::Worksheet& xlWorksheet);
        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, const SimpleCSV::Row& xlRow);
        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, int columnIndex, const SimpleCSV::CellValue& xlCellValue);
        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, int columnIndex, const std::string& column);
        NODISCARD bool IsIgnore(const SimpleCSV::Worksheet& xlWorksheet);

        void SaveIntoFile(const std::string& content);

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