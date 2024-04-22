/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 22:52)

#ifndef CORE_TOOLS_TEXT_PARSING_OPEN_XLSX_CONVERSION_H
#define CORE_TOOLS_TEXT_PARSING_OPEN_XLSX_CONVERSION_H

#include "CoreTools/CoreToolsDll.h"

#include "ExcelConversionCSVImpl.h"
#include "OpenXLSXDocument.h"
#include "System/Helper/PragmaWarning/OpenXLSX.h"
#include "System/Helper/UnicodeUsing.h"

#include <set>
#include <string>

#ifdef CORE_TOOLS_USE_OPEN_XLSX

namespace CoreTools
{
    /// Excel转换CSV格式
    /// 第一行：数据存储方式、数据映射、数据校验的设置。
    /// 第二行：标注每个字段的名称/说明。
    /// 第三行：标注字段数据类型。
    /// 第四行：标注字段变量名。
    /// 导出数据以,做分隔。
    /// 数据类型为空时，数据不导出。对于字符串类型，导出时头尾加上"。
    /// 导出时不检验数据是否合法，字符串类型名为“string”。
    class CORE_TOOLS_HIDDEN_DECLARE OpenXLSXConversion final : public ExcelConversionCSVImpl
    {
    public:
        using ClassType = OpenXLSXConversion;
        using ParentType = ExcelConversionCSVImpl;

        using String = System::String;
        using Row = OpenXLSX::XLRow;
        using CellValue = OpenXLSX::XLCellValue;
        using Worksheet = OpenXLSX::XLWorksheet;

    public:
        OpenXLSXConversion(const std::string& xlsxFileName, String csvFileName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using IndexContainer = std::set<int>;
        using Container = std::vector<std::string>;

    private:
        void Conversion();

        void ObtainRelated(const Worksheet& worksheet);
        NODISCARD std::string GetContent(bool isFirstPage, const Worksheet& worksheet) const;
        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, const Row& row) const;
        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, int columnIndex, const CellValue& xlCellValue) const;

        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, int columnIndex, const std::string& column) const;
        NODISCARD static bool IsIgnore(const Worksheet& worksheet);

        void SaveIntoFile(const std::string& content) const;

        void ObtainRelated(int excludeIndex, const CellValue& element);
        NODISCARD std::string GetFirstPageBitFieldContent(int columnIndex, const std::string& column) const;
        NODISCARD static std::string GetStringFieldContent(const std::string& column);

        NODISCARD static std::string GetBitArrayFieldContent(const std::string& column);
        NODISCARD static std::string GetBitFieldContent(const std::string& column);
        NODISCARD static std::string GetBitArrayFieldContent(bool isEnd, const std::string& element);

    private:
        OpenXLSXDocument document;
        String csvFileName;
        IndexContainer exclude;
        IndexContainer stringField;
        IndexContainer bitField;
        IndexContainer bitArrayField;
    };
}

#endif  // CORE_TOOLS_USE_OPEN_XLSX

#endif  // CORE_TOOLS_TEXT_PARSING_OPEN_XLSX_CONVERSION_H`