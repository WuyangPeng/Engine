/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 18:11)

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
        using Row = SimpleCSV::Row;
        using CellValue = SimpleCSV::CellValue;
        using Worksheet = SimpleCSV::Worksheet;

    public:
        SimpleCSVConversion(const std::string& xlsxFileName, String csvFileName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using IndexContainer = std::set<int>;
        using Container = std::vector<std::string>;

    private:
        void Conversion();

        void ObtainRelated(const Worksheet& worksheet);
        NODISCARD std::string GetContent(bool isFirstPage, const Worksheet& worksheet) const;
        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, const Row& row) const;
        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, int columnIndex, const CellValue& cellValue) const;

        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, int columnIndex, const std::string& column) const;
        NODISCARD static bool IsIgnore(const Worksheet& worksheet);

        void ObtainRelated(int excludeIndex, const CellValue& element);
        NODISCARD std::string GetFirstPageBitFieldContent(int columnIndex, const std::string& column) const;
        NODISCARD static std::string GetStringFieldContent(const std::string& column);
        NODISCARD static std::string GetBitArrayFieldContent(const std::string& column);
        NODISCARD static std::string GetBitFieldContent(const std::string& column);
        NODISCARD static std::string GetBitArrayFieldContent(bool isEnd, const std::string& element);

        void SaveIntoFile(const std::string& content) const;

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