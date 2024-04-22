/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 10:44)

#include "CoreTools/CoreToolsExport.h"

#include "SimpleCSVConversion.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/CellValueDetail.h"
#include "CoreTools/TextParsing/SimpleCSV/CellValueProxyDetail.h"
#include "CoreTools/TextParsing/SimpleCSV/RowIterator.h"
#include "CoreTools/TextParsing/SimpleCSV/RowRange.h"

CoreTools::SimpleCSVConversion::SimpleCSVConversion(const std::string& xlsxFileName, String csvFileName)
    : ParentType{}, document{ xlsxFileName }, csvFileName{ std::move(csvFileName) }, exclude{}, stringField{}, bitField{}, bitArrayField{}
{
    Conversion();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, SimpleCSVConversion)

void CoreTools::SimpleCSVConversion::Conversion()
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

bool CoreTools::SimpleCSVConversion::IsIgnore(const Worksheet& worksheet)
{
    if (worksheet.GetRowCount() == 0 || worksheet.GetColumnCount() == 0)
    {
        return true;
    }

    const auto& cell = worksheet.GetCell(System::EnumCastUnderlying(CSVType::Format), 1);

    const auto& xlCellValueProxy = cell->GetValue();

    return xlCellValueProxy.GetType() == SimpleCSV::ValueType::String &&
           xlCellValueProxy.Get<std::string>() == CSVTypeConversion::GetTypeDescribe(CSVFormatType::Ignore);
}

void CoreTools::SimpleCSVConversion::ObtainRelated(const Worksheet& worksheet)
{
    const auto& dataTypeRow = worksheet.GetRow(System::EnumCastUnderlying(CSVType::DataType));
    auto excludeIndex = 0;
    for (const auto& element : dataTypeRow->GetValues<std::vector<SimpleCSV::CellValue>>())
    {
        if (const auto valueType = element.GetType();
            valueType != SimpleCSV::ValueType::String && valueType != SimpleCSV::ValueType::Empty)
        {
            continue;
        }

        ObtainRelated(excludeIndex, element);

        ++excludeIndex;
    }
}

void CoreTools::SimpleCSVConversion::ObtainRelated(int excludeIndex, const CellValue& element)
{
    auto column = element.Get<std::string>();

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

std::string CoreTools::SimpleCSVConversion::GetContent(bool isFirstPage, const Worksheet& worksheet) const
{
    std::string content{};
    auto rowIndex = 0;
    for (const auto& xlRowRange : worksheet.GetRows())
    {
        content += GetContent(isFirstPage, rowIndex, xlRowRange);
        ++rowIndex;
    }
    return content;
}

std::string CoreTools::SimpleCSVConversion::GetContent(bool isFirstPage, int rowIndex, const Row& row) const
{
    std::string content{};

    auto columnIndex = 0;

    const auto& xlCellValues = row.GetValues<std::vector<SimpleCSV::CellValue>>();
    if (xlCellValues.empty() || (xlCellValues.at(0).GetType() == SimpleCSV::ValueType::Empty))
    {
        return content;
    }

    for (const auto& xlCellValue : xlCellValues)
    {
        if (exclude.contains(columnIndex))
        {
            ++columnIndex;
            continue;
        }

        content += GetContent(isFirstPage, rowIndex, columnIndex, xlCellValue);
        ++columnIndex;

        if (columnIndex != boost::numeric_cast<int>(row.GetCellCount()))
        {
            content += ',';
        }
    }

    content += '\n';

    return content;
}

std::string CoreTools::SimpleCSVConversion::GetContent(bool isFirstPage, int rowIndex, int columnIndex, const CellValue& cellValue) const
{
    switch (const auto xlValueType = cellValue.GetType();
            xlValueType)
    {
        case SimpleCSV::ValueType::Boolean:
        {
            const auto column = cellValue.Get<bool>();

            return GetContent(isFirstPage, rowIndex, columnIndex, std::to_string(column));
        }
        case SimpleCSV::ValueType::Integer:
        {
            const auto column = cellValue.Get<int64_t>();

            return GetContent(isFirstPage, rowIndex, columnIndex, std::to_string(column));
        }
        case SimpleCSV::ValueType::Float:
        {
            const auto column = cellValue.Get<double>();

            return GetContent(isFirstPage, rowIndex, columnIndex, std::to_string(column));
        }
        case SimpleCSV::ValueType::String:
        {
            auto column = cellValue.Get<std::string>();
            boost::algorithm::trim(column);

            return GetContent(isFirstPage, rowIndex, columnIndex, column);
        }
        default:
            break;
    }

    return "";
}

std::string CoreTools::SimpleCSVConversion::GetContent(bool isFirstPage, int rowIndex, int columnIndex, const std::string& column) const
{
    if (isFirstPage)
    {
        if (rowIndex + 1 == System::EnumCastUnderlying(CSVType::DataType))
        {
            return GetFirstPageBitFieldContent(columnIndex, column);
        }
        else if (rowIndex < System::EnumCastUnderlying(CSVType::VariableName))
        {
            return column;
        }
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

std::string CoreTools::SimpleCSVConversion::GetFirstPageBitFieldContent(int columnIndex, const std::string& column) const
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

std::string CoreTools::SimpleCSVConversion::GetStringFieldContent(const std::string& column)
{
    auto result = column;

    boost::replace_all(result, ",", "\\,");

    return "\"" + result + "\"";
}

std::string CoreTools::SimpleCSVConversion::GetBitArrayFieldContent(const std::string& column)
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

std::string CoreTools::SimpleCSVConversion::GetBitArrayFieldContent(bool isEnd, const std::string& element)
{
    Container container{};
    split(container, element, boost::is_any_of(" \t|"), boost::token_compress_on);

    std::string result{};
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

std::string CoreTools::SimpleCSVConversion::GetBitFieldContent(const std::string& column)
{
    Container result{};
    split(result, column, boost::is_any_of(" \t|"), boost::token_compress_on);

    int bit = 0;
    for (const auto& bitValue : result)
    {
        bit |= (1 << (boost::lexical_cast<int>(bitValue) - 1));
    }

    return std::to_string(bit);
}

void CoreTools::SimpleCSVConversion::SaveIntoFile(const std::string& content) const
{
    FileManagerHelper::SaveIntoFile(csvFileName, false, boost::numeric_cast<int>(content.size()), content.c_str());
}
