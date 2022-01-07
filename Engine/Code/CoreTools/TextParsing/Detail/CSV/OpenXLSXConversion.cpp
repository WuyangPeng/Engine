///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:22)

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

#ifdef CORE_TOOLS_USE_OPENXLSX

using std::string;
using std::vector;
using namespace std::literals;

CoreTools::OpenXLSXConversion::OpenXLSXConversion(const string& xlsxFileName, const String& csvFileName)
    : ParentType{}, document{ xlsxFileName }, csvFileName{ csvFileName }, exclude{}, stringField{}, bitField{}, bitArrayField{}
{
    Conversion();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, OpenXLSXConversion)

void CoreTools::OpenXLSXConversion::Conversion()
{
    auto firstXLWorksheet = document.GetFirstXLWorksheet();
    ObtainRelated(firstXLWorksheet);

    const auto xlWorksheets = document.GetXLWorksheet();

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

bool CoreTools::OpenXLSXConversion::IsIgnore(const OpenXLSX::XLWorksheet& xlWorksheet)
{
    if (xlWorksheet.rowCount() == 0 || xlWorksheet.columnCount() == 0)
    {
        return true;
    }

    const auto& xlCell = xlWorksheet.cell(System::EnumCastUnderlying(CSVType::Format), 1);

    const auto& xlCellValueProxy = xlCell.value();

    if (xlCellValueProxy.type() == OpenXLSX::XLValueType::String && xlCellValueProxy.get<string>() == CSVTypeConversion::GetTypeDescribe(CSVFormatType::Ignore))
    {
        return true;
    }

    return false;
}

void CoreTools::OpenXLSXConversion::ObtainRelated(const OpenXLSX::XLWorksheet& xlWorksheet)
{
    const auto& dataTypeRow = xlWorksheet.row(System::EnumCastUnderlying(CSVType::DataType));
    auto excludeIndex = 0;
    for (const auto& value : dataTypeRow.values<vector<OpenXLSX::XLCellValue>>())
    {
        const auto valueType = value.type();
        if (valueType != OpenXLSX::XLValueType::String && valueType != OpenXLSX::XLValueType::Empty)
        {
            continue;
        }

        auto column = value.get<string>();

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

string CoreTools::OpenXLSXConversion::GetContent(bool isFirstPage, const OpenXLSX::XLWorksheet& xlWorksheet)
{
    string content{};
    auto rowIndex = 0;
    for (const auto& xlRowRange : xlWorksheet.rows())
    {
        content += GetContent(isFirstPage, rowIndex, xlRowRange);
        ++rowIndex;
    }
    return content;
}

string CoreTools::OpenXLSXConversion::GetContent(bool isFirstPage, int rowIndex, const OpenXLSX::XLRow& xlRow)
{
    string content{};

    auto columnIndex = 0;
    const auto& xlCellValues = xlRow.values<vector<OpenXLSX::XLCellValue>>();
    for (const auto& xlCellValue : xlCellValues)
    {
        if (exclude.find(columnIndex) != exclude.cend())
        {
            ++columnIndex;
            continue;
        }

        content += GetContent(isFirstPage, rowIndex, columnIndex, xlCellValue);
        ++columnIndex;

        if (columnIndex != boost::numeric_cast<int>(xlRow.cellCount()))
        {
            content += ',';
        }
    }

    content += '\n';

    return content;
}

string CoreTools::OpenXLSXConversion::GetContent(bool isFirstPage, int rowIndex, int columnIndex, const OpenXLSX::XLCellValue& xlCellValue)
{
    const auto xlValueType = xlCellValue.type();

    switch (xlValueType)
    {
        case OpenXLSX::XLValueType::Boolean:
        {
            auto column = xlCellValue.get<bool>();

            return GetContent(isFirstPage, rowIndex, columnIndex, std::to_string(column));
        }
        break;
        case OpenXLSX::XLValueType::Integer:
        {
            auto column = xlCellValue.get<int64_t>();

            return GetContent(isFirstPage, rowIndex, columnIndex, std::to_string(column));
        }
        break;
        case OpenXLSX::XLValueType::Float:
        {
            auto column = xlCellValue.get<double>();

            return GetContent(isFirstPage, rowIndex, columnIndex, std::to_string(column));
        }
        break;
        case OpenXLSX::XLValueType::String:
        {
            auto column = xlCellValue.get<string>();
            boost::algorithm::trim(column);

            return GetContent(isFirstPage, rowIndex, columnIndex, column);
        }
        break;
        default:
            break;
    }

    return "";
}

string CoreTools::OpenXLSXConversion::GetContent(bool isFirstPage, int rowIndex, int columnIndex, const string& column)
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
        auto bit = 0;
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

void CoreTools::OpenXLSXConversion::SaveIntoFile(const string& content)
{
    FileManagerHelper::SaveIntoFile(csvFileName, false, boost::numeric_cast<int>(content.size()), content.c_str());
}

#endif  // CORE_TOOLS_USE_OPENXLSX