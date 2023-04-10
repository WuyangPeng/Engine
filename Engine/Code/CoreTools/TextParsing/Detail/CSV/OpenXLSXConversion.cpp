///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 17:23)

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

using namespace std::literals;

CoreTools::OpenXLSXConversion::OpenXLSXConversion(const std::string& xlsxFileName, String csvFileName)
    : ParentType{}, document{ xlsxFileName }, csvFileName{ std::move(csvFileName) }, exclude{}, stringField{}, bitField{}, bitArrayField{}
{
    Conversion();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, OpenXLSXConversion)

void CoreTools::OpenXLSXConversion::Conversion()
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

bool CoreTools::OpenXLSXConversion::IsIgnore(const OpenXLSX::XLWorksheet& xlWorksheet) const
{
    if (xlWorksheet.rowCount() == 0 || xlWorksheet.columnCount() == 0)
    {
        return true;
    }

    const auto& xlCell = xlWorksheet.cell(System::EnumCastUnderlying(CSVType::Format), 1);

    if (const auto& xlCellValueProxy = xlCell.value(); xlCellValueProxy.type() == OpenXLSX::XLValueType::String && xlCellValueProxy.get<std::string>() == CSVTypeConversion::GetTypeDescribe(CSVFormatType::Ignore))
    {
        return true;
    }

    return false;
}

void CoreTools::OpenXLSXConversion::ObtainRelated(const OpenXLSX::XLWorksheet& xlWorksheet)
{
    const auto& dataTypeRow = xlWorksheet.row(System::EnumCastUnderlying(CSVType::DataType));
    auto excludeIndex = 0;
    for (const auto& value : dataTypeRow.values<std::vector<OpenXLSX::XLCellValue>>())
    {
        if (const auto valueType = value.type(); valueType != OpenXLSX::XLValueType::String && valueType != OpenXLSX::XLValueType::Empty)
        {
            continue;
        }

        auto column = value.get<std::string>();

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

std::string CoreTools::OpenXLSXConversion::GetContent(bool isFirstPage, const OpenXLSX::XLWorksheet& xlWorksheet)
{
    std::string content{};
    auto rowIndex = 0;
    for (const auto& xlRowRange : xlWorksheet.rows())
    {
        content += GetContent(isFirstPage, rowIndex, xlRowRange);
        ++rowIndex;
    }
    return content;
}

std::string CoreTools::OpenXLSXConversion::GetContent(bool isFirstPage, int rowIndex, const OpenXLSX::XLRow& xlRow)
{
    std::string content{};

    auto columnIndex = 0;

    for (const auto& xlCellValues = xlRow.values<std::vector<OpenXLSX::XLCellValue>>(); const auto& xlCellValue : xlCellValues)
    {
        if (exclude.contains(columnIndex))
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

std::string CoreTools::OpenXLSXConversion::GetContent(bool isFirstPage, int rowIndex, int columnIndex, const OpenXLSX::XLCellValue& xlCellValue)
{
    switch (const auto xlValueType = xlCellValue.type(); xlValueType)
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

std::string CoreTools::OpenXLSXConversion::GetContent(bool isFirstPage, int rowIndex, int columnIndex, const std::string& column)
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

void CoreTools::OpenXLSXConversion::SaveIntoFile(const std::string& content) const
{
    FileManagerHelper::SaveIntoFile(csvFileName, false, boost::numeric_cast<int>(content.size()), content.c_str());
}

#endif  // CORE_TOOLS_USE_OPENXLSX