/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 10:20)

#include "CoreTools/CoreToolsExport.h"

#include "OpenXLSXConversion.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

#ifdef CORE_TOOLS_USE_OPEN_XLSX

CoreTools::OpenXLSXConversion::OpenXLSXConversion(const std::string& xlsxFileName, String csvFileName)
    : ParentType{},
      document{ xlsxFileName },
      csvFileName{ std::move(csvFileName) },
      exclude{},
      stringField{},
      bitField{},
      bitArrayField{}
{
    Conversion();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, OpenXLSXConversion)

void CoreTools::OpenXLSXConversion::Conversion()
{
    const auto firstWorksheet = document.GetFirstWorksheet();
    ObtainRelated(firstWorksheet);

    const auto worksheets = document.GetWorksheet();

    std::string content{};
    auto isFirstPage = true;
    for (const auto& worksheet : worksheets)
    {
        if (IsIgnore(worksheet))
        {
            continue;
        }

        content += GetContent(isFirstPage, worksheet);
        isFirstPage = false;
    }

    content.pop_back();

    SaveIntoFile(content);
}

bool CoreTools::OpenXLSXConversion::IsIgnore(const Worksheet& worksheet)
{
    if (worksheet.rowCount() == 0 || worksheet.columnCount() == 0)
    {
        return true;
    }

    const auto& cell = worksheet.cell(System::EnumCastUnderlying(CSVType::Format), 1);

    const auto& cellValueProxy = cell.value();

    return cellValueProxy.type() == OpenXLSX::XLValueType::String &&
           cellValueProxy.get<std::string>() == CSVTypeConversion::GetTypeDescribe(CSVFormatType::Ignore);
}

void CoreTools::OpenXLSXConversion::ObtainRelated(const Worksheet& worksheet)
{
    const auto& dataTypeRow = worksheet.row(System::EnumCastUnderlying(CSVType::DataType));
    auto excludeIndex = 0;
    for (const auto& element : dataTypeRow.values<std::vector<OpenXLSX::XLCellValue>>())
    {
        if (const auto valueType = element.type();
            valueType != OpenXLSX::XLValueType::String &&
            valueType != OpenXLSX::XLValueType::Empty)
        {
            continue;
        }

        ObtainRelated(excludeIndex, element);

        ++excludeIndex;
    }
}

void CoreTools::OpenXLSXConversion::ObtainRelated(int excludeIndex, const CellValue& element)
{
    auto column = element.get<std::string>();

    /// 去除头尾空格
    boost::algorithm::trim(column);
    if (column.empty())
    {
        exclude.emplace(excludeIndex);
    }
    else if (column.find(CSVTypeConversion::GetTypeDescribe(CSVDataType::String)) != std::string::npos)
    {
        stringField.emplace(excludeIndex);
    }
    else if (column.find(CSVTypeConversion::GetTypeDescribe(CSVDataType::BitArray)) != std::string::npos)
    {
        bitArrayField.emplace(excludeIndex);
    }
    else if (column.find(CSVTypeConversion::GetTypeDescribe(CSVDataType::Bit)) != std::string::npos)
    {
        bitField.emplace(excludeIndex);
    }
}

std::string CoreTools::OpenXLSXConversion::GetContent(bool isFirstPage, const Worksheet& worksheet) const
{
    std::string content{};
    auto rowIndex = 0;
    for (const auto& rowRange : worksheet.rows())
    {
        content += GetContent(isFirstPage, rowIndex, rowRange);
        ++rowIndex;
    }
    return content;
}

std::string CoreTools::OpenXLSXConversion::GetContent(bool isFirstPage, int rowIndex, const Row& row) const
{
    std::string content{};

    auto columnIndex = 0;

    const auto& cellValues = row.values<std::vector<OpenXLSX::XLCellValue>>();
    if (cellValues.empty() ||
        (cellValues.at(0).type() == OpenXLSX::XLValueType::Empty))
    {
        return content;
    }

    for (const auto& cellValue : cellValues)
    {
        if (exclude.contains(columnIndex))
        {
            ++columnIndex;
            continue;
        }

        content += GetContent(isFirstPage, rowIndex, columnIndex, cellValue);
        ++columnIndex;

        if (columnIndex != boost::numeric_cast<int>(row.cellCount()))
        {
            content += ',';
        }
    }

    content += '\n';

    return content;
}

std::string CoreTools::OpenXLSXConversion::GetContent(bool isFirstPage, int rowIndex, int columnIndex, const CellValue& xlCellValue) const
{
    switch (const auto xlValueType = xlCellValue.type();
            xlValueType)
    {
        case OpenXLSX::XLValueType::Boolean:
        {
            const auto column = xlCellValue.get<bool>();

            return GetContent(isFirstPage, rowIndex, columnIndex, std::to_string(column));
        }
        case OpenXLSX::XLValueType::Integer:
        {
            const auto column = xlCellValue.get<int64_t>();

            return GetContent(isFirstPage, rowIndex, columnIndex, std::to_string(column));
        }
        case OpenXLSX::XLValueType::Float:
        {
            const auto column = xlCellValue.get<double>();

            return GetContent(isFirstPage, rowIndex, columnIndex, std::to_string(column));
        }
        case OpenXLSX::XLValueType::String:
        {
            auto column = xlCellValue.get<std::string>();
            boost::algorithm::trim(column);

            return GetContent(isFirstPage, rowIndex, columnIndex, column);
        }
        default:
            break;
    }

    return "";
}

std::string CoreTools::OpenXLSXConversion::GetContent(bool isFirstPage, int rowIndex, int columnIndex, const std::string& column) const
{
    if (isFirstPage)
    {
        if (rowIndex + 1 == System::EnumCastUnderlying(CSVType::DataType))
            return GetFirstPageBitFieldContent(columnIndex, column);
        else if (rowIndex < System::EnumCastUnderlying(CSVType::VariableName))
            return column;
    }

    if (stringField.contains(columnIndex))
    {
        return GetStringFieldContent(column);
    }
    else if (bitArrayField.contains(columnIndex))
    {
        return GetBitArrayFieldContent(column);
    }
    else if (bitField.contains(columnIndex))
    {
        return GetBitFieldContent(column);
    }
    else
    {
        return column;
    }
}

std::string CoreTools::OpenXLSXConversion::GetFirstPageBitFieldContent(int columnIndex, const std::string& column) const
{
    if (bitField.contains(columnIndex))
    {
        return CSVTypeConversion::GetTypeDescribe(CSVDataType::Int);
    }
    else if (bitArrayField.contains(columnIndex))
    {
        return CSVTypeConversion::GetTypeDescribe(CSVDataType::IntArray);
    }
    else
    {
        return column;
    }
}

std::string CoreTools::OpenXLSXConversion::GetStringFieldContent(const std::string& column)
{
    auto result = column;

    boost::replace_all(result, ",", "\\,");

    return "\"" + result + "\"";
}

std::string CoreTools::OpenXLSXConversion::GetBitArrayFieldContent(const std::string& column)
{
    Container container{};
    split(container, column, boost::is_any_of("&"), boost::token_compress_on);

    std::string result{};
    auto index = 0u;
    for (const auto& element : container)
    {
        ++index;
        result += GetBitArrayFieldContent(index == container.size(), element);
    }

    return result;
}

std::string CoreTools::OpenXLSXConversion::GetBitArrayFieldContent(bool isEnd, const std::string& element)
{
    std::string result{};

    Container container{};
    split(container, element, boost::is_any_of(" \t|"), boost::token_compress_on);

    auto bit = 0;
    for (const auto& bitValue : container)
    {
        bit |= (1 << (boost::lexical_cast<int>(bitValue) - 1));
    }
    result += std::to_string(bit);

    if (!isEnd)
    {
        result += "&";
    }

    return result;
}

std::string CoreTools::OpenXLSXConversion::GetBitFieldContent(const std::string& column)
{
    Container result{};
    split(result, column, boost::is_any_of(" \t|"), boost::token_compress_on);
    auto bit = 0;
    for (const auto& bitValue : result)
    {
        bit |= (1 << (boost::lexical_cast<int>(bitValue) - 1));
    }
    return std::to_string(bit);
}

void CoreTools::OpenXLSXConversion::SaveIntoFile(const std::string& content) const
{
    FileManagerHelper::SaveIntoFile(csvFileName, false, boost::numeric_cast<int>(content.size()), content.c_str());
}

#endif  // CORE_TOOLS_USE_OPEN_XLSX