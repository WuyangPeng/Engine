///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/10 08:57)

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

using namespace std::literals;

CoreTools::SimpleCSVConversion::SimpleCSVConversion(const std::string& xlsxFileName, const String& csvFileName)
    : ParentType{}, document{ xlsxFileName }, csvFileName{ csvFileName }, exclude{}, stringField{}, bitField{}, bitArrayField{}
{
    Conversion();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, SimpleCSVConversion)

void CoreTools::SimpleCSVConversion::Conversion()
{
    const auto firstXlWorksheet = document.GetFirstXLWorksheet();
    ObtainRelated(firstXlWorksheet);

    const auto xlWorksheets = document.GetXLWorksheet();

    std::string content{};
    auto isFirstPage = true;
    for (const auto& xlWorksheet : xlWorksheets)
    {
        if (IsIgnore(xlWorksheet))
        {
            continue;
        }

        content += GetContent(isFirstPage, xlWorksheet);
        isFirstPage = false;
    }

    content.pop_back();

    SaveIntoFile(content);
}

bool CoreTools::SimpleCSVConversion::IsIgnore(const SimpleCSV::Worksheet& xlWorksheet) const
{
    if (xlWorksheet.GetRowCount() == 0 || xlWorksheet.GetColumnCount() == 0)
    {
        return true;
    }

    const auto& xlCell = xlWorksheet.GetCell(System::EnumCastUnderlying(CSVType::Format), 1);

    if (const auto& xlCellValueProxy = xlCell->GetValue();
        xlCellValueProxy.GetType() == SimpleCSV::ValueType::String && xlCellValueProxy.Get<std::string>() == CSVTypeConversion::GetTypeDescribe(CSVFormatType::Ignore))
    {
        return true;
    }

    return false;
}

void CoreTools::SimpleCSVConversion::ObtainRelated(const SimpleCSV::Worksheet& xlWorksheet)
{
    const auto& dataTypeRow = xlWorksheet.GetRow(System::EnumCastUnderlying(CSVType::DataType));
    auto excludeIndex = 0;
    for (const auto& value : dataTypeRow->GetValues<std::vector<SimpleCSV::CellValue>>())
    {
        if (const auto valueType = value.GetType();
            valueType != SimpleCSV::ValueType::String && valueType != SimpleCSV::ValueType::Empty)
        {
            continue;
        }

        auto column = value.Get<std::string>();

        // 去除头尾空格
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

        ++excludeIndex;
    }
}

std::string CoreTools::SimpleCSVConversion::GetContent(bool isFirstPage, const SimpleCSV::Worksheet& xlWorksheet) const
{
    std::string content{};
    auto rowIndex = 0;
    for (const auto& xlRowRange : xlWorksheet.GetRows())
    {
        content += GetContent(isFirstPage, rowIndex, xlRowRange);
        ++rowIndex;
    }
    return content;
}

std::string CoreTools::SimpleCSVConversion::GetContent(bool isFirstPage, int rowIndex, const SimpleCSV::Row& xlRow) const
{
    std::string content{};

    auto columnIndex = 0;

    for (const auto& xlCellValues = xlRow.GetValues<std::vector<SimpleCSV::CellValue>>();
         const auto& xlCellValue : xlCellValues)
    {
        if (exclude.contains(columnIndex))
        {
            ++columnIndex;
            continue;
        }

        content += GetContent(isFirstPage, rowIndex, columnIndex, xlCellValue);
        ++columnIndex;

        if (columnIndex != boost::numeric_cast<int>(xlRow.GetCellCount()))
        {
            content += ',';
        }
    }

    content += '\n';

    return content;
}

std::string CoreTools::SimpleCSVConversion::GetContent(bool isFirstPage, int rowIndex, int columnIndex, const SimpleCSV::CellValue& xlCellValue) const
{
    switch (const auto xlValueType = xlCellValue.GetType(); xlValueType)
    {
        case SimpleCSV::ValueType::Boolean:
        {
            const auto column = xlCellValue.Get<bool>();

            return GetContent(isFirstPage, rowIndex, columnIndex, std::to_string(column));
        }
        case SimpleCSV::ValueType::Integer:
        {
            const auto column = xlCellValue.Get<int64_t>();

            return GetContent(isFirstPage, rowIndex, columnIndex, std::to_string(column));
        }
        case SimpleCSV::ValueType::Float:
        {
            const auto column = xlCellValue.Get<double>();

            return GetContent(isFirstPage, rowIndex, columnIndex, std::to_string(column));
        }
        case SimpleCSV::ValueType::String:
        {
            auto column = xlCellValue.Get<std::string>();
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
    if (isFirstPage && rowIndex + 1 == System::EnumCastUnderlying(CSVType::DataType))
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
    if (isFirstPage && rowIndex < System::EnumCastUnderlying(CSVType::VariableName))
    {
        return column;
    }
    else if (stringField.contains(columnIndex))
    {
        auto result = column;

        boost::replace_all(result, ","s, "\\,"s);

        return "\""s + result + "\""s;
    }
    else if (bitArrayField.contains(columnIndex))
    {
        std::vector<std::string> firstSplit{};
        split(firstSplit, column, boost::is_any_of("&"), boost::token_compress_on);
        std::string result{};
        auto index = 0u;
        for (const auto& value : firstSplit)
        {
            std::vector<std::string> secondSplit{};
            split(secondSplit, value, boost::is_any_of(" \t|"), boost::token_compress_on);
            auto bit = 0;
            for (const auto& bitValue : secondSplit)
            {
                bit |= (1 << (boost::lexical_cast<int>(bitValue) - 1));
            }
            result += std::to_string(bit);
            ++index;
            if (index != firstSplit.size())
            {
                result += "&";
            }
        }

        return result;
    }
    else if (bitField.contains(columnIndex))
    {
        std::vector<std::string> result{};
        split(result, column, boost::is_any_of(" \t|"), boost::token_compress_on);
        int bit = 0;
        for (const auto& bitValue : result)
        {
            bit |= (1 << (boost::lexical_cast<int>(bitValue) - 1));
        }
        return std::to_string(bit);
    }
    else
    {
        return column;
    }
}

void CoreTools::SimpleCSVConversion::SaveIntoFile(const std::string& content) const
{
    FileManagerHelper::SaveIntoFile(csvFileName, false, boost::numeric_cast<int>(content.size()), content.c_str());
}
