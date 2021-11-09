///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/15 14:18)

#ifndef CORE_TOOLS_TEXT_PARSING_OPENXLSX_CONVERSION_H
#define CORE_TOOLS_TEXT_PARSING_OPENXLSX_CONVERSION_H

#include "CoreTools/CoreToolsDll.h"

#include "ExcelConversionCSVImpl.h"
#include "OpenXLSXDocument.h"
#include "System/Helper/PragmaWarning/OpenXLSX.h"
#include "System/Helper/UnicodeUsing.h"

#include <set>
#include <string>

#ifdef CORE_TOOLS_USE_OPENXLSX

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

    public:
        OpenXLSXConversion(const std::string& xlsxFileName, const String& csvFileName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void Conversion();

        void ObtainRelated(const OpenXLSX::XLWorksheet& xlWorksheet);
        NODISCARD std::string GetContent(bool isFirstPage, const OpenXLSX::XLWorksheet& xlWorksheet);
        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, const OpenXLSX::XLRow& xlRow);
        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, int columnIndex, const OpenXLSX::XLCellValue& xlCellValue);
        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, int columnIndex, const std::string& column);
        NODISCARD bool IsIgnore(const OpenXLSX::XLWorksheet& xlWorksheet);

        void SaveIntoFile(const std::string& content);

    private:
        using IndexContainer = std::set<int>;

    private:
        OpenXLSXDocument document;
        String csvFileName;
        IndexContainer exclude;
        IndexContainer stringField;
        IndexContainer bitField;
        IndexContainer bitArrayField;
    };
}

#endif CORE_TOOLS_USE_OPENXLSX

#endif  // CORE_TOOLS_TEXT_PARSING_OPENXLSX_CONVERSION_H