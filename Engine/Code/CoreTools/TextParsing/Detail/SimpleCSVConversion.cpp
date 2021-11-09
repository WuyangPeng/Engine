///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/15 14:22)

#include "CoreTools/CoreToolsExport.h"

#include "SimpleCSVConversion.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/CellValueDetail.h"
#include "CoreTools/TextParsing/SimpleCSV/CellValueProxyDetail.h"
#include "CoreTools/TextParsing/SimpleCSV/RowIterator.h"
#include "CoreTools/TextParsing/SimpleCSV/RowRange.h"

using std::string;
using std::vector;
using namespace std::literals;

CoreTools::SimpleCSVConversion::SimpleCSVConversion(const string& xlsxFileName, const String& csvFileName)
    : ParentType{}, document{ xlsxFileName }, csvFileName{ csvFileName }, exclude{}, stringField{}, bitField{}, bitArrayField{}
{
    Conversion();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, SimpleCSVConversion)

void CoreTools::SimpleCSVConversion::Conversion()
{
    auto firstXLWorksheet = document.GetFirstXLWorksheet();
    ObtainRelated(firstXLWorksheet);

    const auto& xlWorksheets = document.GetXLWorksheet();

    string content{};
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

bool CoreTools::SimpleCSVConversion::IsIgnore(const SimpleCSV::Worksheet& xlWorksheet)
{
    if (xlWorksheet.GetRowCount() == 0 || xlWorksheet.GetColumnCount() == 0)
    {
        return true;
    }

    const auto& xlCell = xlWorksheet.GetCell(System::EnumCastUnderlying(CSVType::Format), 1);

    const auto& xlCellValueProxy = xlCell->GetValue();

    if (xlCellValueProxy.GetType() == SimpleCSV::ValueType::String && xlCellValueProxy.Get<string>() == CSVTypeConversion::GetTypeDescribe(CSVFormatType::Ignore))
    {
        return true;
    }

    return false;
}

void CoreTools::SimpleCSVConversion::ObtainRelated(const SimpleCSV::Worksheet& xlWorksheet)
{
    const auto& dataTypeRow = xlWorksheet.GetRow(System::EnumCastUnderlying(CSVType::DataType));
    auto excludeIndex = 0;
    for (const auto& value : dataTypeRow->GetValues<vector<SimpleCSV::CellValue>>())
    {
        const auto valueType = value.GetType();
        if (valueType != SimpleCSV::ValueType::String && valueType != SimpleCSV::ValueType::Empty)
        {
            continue;
        }

        auto column = value.Get<string>();

        // 去除头尾空格
        boost::algorithm::trim(column);
        if (column.empty())
        {
            exclude.emplace(excludeIndex);
        }
        else if (column.find(CSVTypeConversion::GetTypeDescribe(CSVDataType::String)) != string::npos)
        {
            stringField.emplace(excludeIndex);
        }
        else if (column.find(CSVTypeConversion::GetTypeDescribe(CSVDataType::BitArray)) != string::npos)
        {
            bitArrayField.emplace(excludeIndex);
        }
        else if (column.find(CSVTypeConversion::GetTypeDescribe(CSVDataType::Bit)) != string::npos)
        {
            bitField.emplace(excludeIndex);
        }

        ++excludeIndex;
    }
}

string CoreTools::SimpleCSVConversion::GetContent(bool isFirstPage, const SimpleCSV::Worksheet& xlWorksheet)
{
    string content{};
    auto rowIndex = 0;
    for (const auto& xlRowRange : xlWorksheet.GetRows())
    {
        content += GetContent(isFirstPage, rowIndex, xlRowRange);
        ++rowIndex;
    }
    return content;
}

string CoreTools::SimpleCSVConversion::GetContent(bool isFirstPage, int rowIndex, const SimpleCSV::Row& xlRow)
{
    string content{};

    auto columnIndex = 0;
    const auto& xlCellValues = xlRow.GetValues<vector<SimpleCSV::CellValue>>();
    for (const auto& xlCellValue : xlCellValues)
    {
        if (exclude.find(columnIndex) != exclude.cend())
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

string CoreTools::SimpleCSVConversion::GetContent(bool isFirstPage, int rowIndex, int columnIndex, const SimpleCSV::CellValue& xlCellValue)
{
    const auto xlValueType = xlCellValue.GetType();

    switch (xlValueType)
    {
        case SimpleCSV::ValueType::Boolean:
        {
            auto column = xlCellValue.Get<bool>();

            return GetContent(isFirstPage, rowIndex, columnIndex, std::to_string(column));
        }
        break;
        case SimpleCSV::ValueType::Integer:
        {
            auto column = xlCellValue.Get<int64_t>();

            return GetContent(isFirstPage, rowIndex, columnIndex, std::to_string(column));
        }
        break;
        case SimpleCSV::ValueType::Float:
        {
            auto column = xlCellValue.Get<double>();

            return GetContent(isFirstPage, rowIndex, columnIndex, std::to_string(column));
        }
        break;
        case SimpleCSV::ValueType::String:
        {
            auto column = xlCellValue.Get<string>();
            boost::algorithm::trim(column);

            return GetContent(isFirstPage, rowIndex, columnIndex, column);
        }
        break;
        default:
            break;
    }

    return "";
}

string CoreTools::SimpleCSVConversion::GetContent(bool isFirstPage, int rowIndex, int columnIndex, const string& column)
{
    if (isFirstPage && rowIndex + 1 == System::EnumCastUnderlying(CSVType::DataType))
    {
        if (bitField.find(columnIndex) != bitField.cend())
        {
            return CSVTypeConversion::GetTypeDescribe(CSVDataType::Int);
        }
        else if (bitArrayField.find(columnIndex) != bitArrayField.cend())
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
    else if (stringField.find(columnIndex) != stringField.cend())
    {
        auto result = column;

        boost::replace_all(result, ","s, "\\,"s);

        return "\""s + result + "\""s;
    }
    else if (bitArrayField.find(columnIndex) != bitArrayField.cend())
    {
        vector<string> firstSplit{};
        boost::algorithm::split(firstSplit, column, boost::is_any_of("&"), boost::token_compress_on);
        string result{};
        auto index = 0u;
        for (const auto& value : firstSplit)
        {
            vector<string> secondSplit{};
            boost::algorithm::split(secondSplit, value, boost::is_any_of(" \t|"), boost::token_compress_on);
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
    else if (bitField.find(columnIndex) != bitField.cend())
    {
        vector<string> result{};
        boost::algorithm::split(result, column, boost::is_any_of(" \t|"), boost::token_compress_on);
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

void CoreTools::SimpleCSVConversion::SaveIntoFile(const string& content)
{
    FileManagerHelper::SaveIntoFile(csvFileName, false, boost::numeric_cast<int>(content.size()), content.c_str());
}
