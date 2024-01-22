/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 11:05)

#include "CoreTools/CoreToolsExport.h"

#include "CellReferenceImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Constants.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

using namespace std::literals;

constexpr auto alphabetSize = 26;
constexpr auto asciiOffset = 'A' - 1;

CoreTools::SimpleCSV::CellReferenceImpl::CellReferenceImpl(const std::string& cellAddress)
    : row{ 1 }, column{ 1 }, cellAddress{ TextParsing::gDefaultCellAddress }
{
    if (!cellAddress.empty())
    {
        SetAddress(cellAddress);
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::SimpleCSV::CellReferenceImpl::CellReferenceImpl(int row, int column)
    : row{ row }, column{ column }, cellAddress{ GetColumnAsString(column) + GetRowAsString(row) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::SimpleCSV::CellReferenceImpl::CellReferenceImpl(int row, const std::string& column)
    : row{ row }, column(GetColumnAsNumber(column)), cellAddress(column + GetRowAsString(row))
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::SimpleCSV::CellReferenceImpl::IsValid() const noexcept
{
    if (0 < row && 0 < column && !cellAddress.empty())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int CoreTools::SimpleCSV::CellReferenceImpl::GetRow() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return row;
}

// ����CellReference������С�������ִ���16384�����ֵ������������Ϊ 16384��
void CoreTools::SimpleCSV::CellReferenceImpl::SetRow(int aRow)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    row = GetInScope(aRow, 1, gMaxRows);
    cellAddress = GetColumnAsString(column) + GetRowAsString(row);
}

int CoreTools::SimpleCSV::CellReferenceImpl::GetColumn() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return column;
}

// ����CellReference������С�������ִ���1048576�����ֵ������������Ϊ1048576��
void CoreTools::SimpleCSV::CellReferenceImpl::SetColumn(int aColumn)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    column = GetInScope(aColumn, 1, gMaxColumns);
    cellAddress = GetColumnAsString(column) + GetRowAsString(row);
}

void CoreTools::SimpleCSV::CellReferenceImpl::SetRowAndColumn(int aRow, int aColumn)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    row = GetInScope(aRow, 1, gMaxRows);
    column = GetInScope(aColumn, 1, gMaxColumns);
    cellAddress = GetColumnAsString(column) + GetRowAsString(row);
}

std::string CoreTools::SimpleCSV::CellReferenceImpl::GetAddress() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return cellAddress;
}

int CoreTools::SimpleCSV::CellReferenceImpl::GetInScope(int value, int minValue, int maxValue) noexcept
{
    if (value < minValue)
        return minValue;
    else if (maxValue < value)
        return maxValue;
    else
        return value;
}

/// ����CellReference����ĵ�ַ������ 'B2'��
/// ����к����Ƿ�С�ڻ����Excel��������������������
void CoreTools::SimpleCSV::CellReferenceImpl::SetAddress(const std::string& address)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto coordinates = GetCoordinatesFromAddress(address);

    row = coordinates.first;
    column = coordinates.second;
    cellAddress = GetColumnAsString(column) + GetRowAsString(row);
}

std::string CoreTools::SimpleCSV::CellReferenceImpl::GetRowAsString(int aRow)
{
    if (aRow <= 0)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Input, SYSTEM_TEXT("����С�ڻ����0��"s))
    }

    return std::to_string(aRow);
}

int CoreTools::SimpleCSV::CellReferenceImpl::GetRowAsNumber(const std::string& aRow)
{
    return boost::numeric_cast<int>(stoul(aRow));
}

std::string CoreTools::SimpleCSV::CellReferenceImpl::GetColumnAsString(int aColumn)
{
    std::string result{};

    // �����������һ����ĸ��
    if (aColumn <= alphabetSize)
    {
        result += boost::numeric_cast<char>(aColumn + asciiOffset);
    }
    // �����������������ĸ��
    else if (aColumn > alphabetSize && aColumn <= alphabetSize * (alphabetSize + 1))
    {
        result += boost::numeric_cast<char>((aColumn - (alphabetSize + 1)) / alphabetSize + asciiOffset + 1);
        result += boost::numeric_cast<char>((aColumn - (alphabetSize + 1)) % alphabetSize + asciiOffset + 1);
    }
    // �����������������ĸ��
    else
    {
        constexpr auto step = (alphabetSize * (alphabetSize + 1)) + 1;

        result += boost::numeric_cast<char>((aColumn - step) / (alphabetSize * alphabetSize) + asciiOffset + 1);
        result += boost::numeric_cast<char>(((aColumn - step) / alphabetSize) % alphabetSize + asciiOffset + 1);
        result += boost::numeric_cast<char>((aColumn - step) % alphabetSize + asciiOffset + 1);
    }

    return result;
}

int CoreTools::SimpleCSV::CellReferenceImpl::GetColumnAsNumber(const std::string& aColumn)
{
    auto result = 0;

    auto pow = 0;
    for (auto iter = aColumn.rbegin(); iter != aColumn.rend(); ++iter)
    {
        const auto number = *iter - asciiOffset;
        result += boost::numeric_cast<int>(number * std::pow(alphabetSize, pow));
        ++pow;
    }

    return result;
}

CoreTools::SimpleCSV::CellReferenceImpl::Coordinates CoreTools::SimpleCSV::CellReferenceImpl::GetCoordinatesFromAddress(const std::string& address)
{
    auto letterCount = 0u;
    for (const auto letter : address)
    {
        constexpr auto letterBegin = 'A' + 0;
        constexpr auto numberEnd = '9' + 0;
        if (letterBegin <= letter)
        {
            ++letterCount;
        }
        else if (letter <= numberEnd)
        {
            break;
        }
    }

    const auto numberCount = address.size() - letterCount;

    return { GetRowAsNumber(address.substr(letterCount, numberCount)), GetColumnAsNumber(address.substr(0, letterCount)) };
}