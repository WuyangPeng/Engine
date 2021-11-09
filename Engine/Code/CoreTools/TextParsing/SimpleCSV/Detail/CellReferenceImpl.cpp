///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/12 23:05)

#include "CoreTools/CoreToolsExport.h"

#include "CellReferenceImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Constants.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

#include <array>
#include <charconv>

using std::array;
using std::string;
using namespace std::literals;

constexpr auto alphabetSize = 26;
constexpr auto asciiOffset = 'A' - 1;

CoreTools::SimpleCSV::CellReferenceImpl::CellReferenceImpl(const string& cellAddress)
    : m_Row{ 1 }, m_Column{ 1 }, m_CellAddress{ "A1"s }
{
    if (!cellAddress.empty())
    {
        SetAddress(cellAddress);
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::SimpleCSV::CellReferenceImpl::CellReferenceImpl(int row, int column)
    : m_Row{ row }, m_Column{ column }, m_CellAddress{ GetColumnAsString(column) + GetRowAsString(row) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::SimpleCSV::CellReferenceImpl::CellReferenceImpl(int row, const string& column)
    : m_Row{ row }, m_Column(GetColumnAsNumber(column)), m_CellAddress(column + GetRowAsString(row))
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::SimpleCSV::CellReferenceImpl::IsValid() const noexcept
{
    if (0 < m_Row && 0 < m_Column && !m_CellAddress.empty())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int CoreTools::SimpleCSV::CellReferenceImpl::GetRow() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Row;
}

// 设置CellReference对象的行。如果数字大于16384（最大值），该行设置为 16384。
void CoreTools::SimpleCSV::CellReferenceImpl::SetRow(int row)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_Row = GetInScope(row, 1, g_MaxRows);
    m_CellAddress = GetColumnAsString(m_Column) + GetRowAsString(m_Row);
}

int CoreTools::SimpleCSV::CellReferenceImpl::GetColumn() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Column;
}

// 设置CellReference对象的列。如果数字大于1048576（最大值），该列设置为1048576。
void CoreTools::SimpleCSV::CellReferenceImpl::SetColumn(int column)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_Column = GetInScope(column, 1, g_MaxColumns);
    m_CellAddress = GetColumnAsString(m_Column) + GetRowAsString(m_Row);
}

void CoreTools::SimpleCSV::CellReferenceImpl::SetRowAndColumn(int row, int column)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_Row = GetInScope(row, 1, g_MaxRows);
    m_Column = GetInScope(column, 1, g_MaxColumns);
    m_CellAddress = GetColumnAsString(m_Column) + GetRowAsString(m_Row);
}

string CoreTools::SimpleCSV::CellReferenceImpl::GetAddress() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_CellAddress;
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

/// 设置CellReference对象的地址，例如 'B2'。
/// 检查行和列是否小于或等于Excel允许的最大行数和列数。
void CoreTools::SimpleCSV::CellReferenceImpl::SetAddress(const string& address)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto coordinates = GetCoordinatesFromAddress(address);

    m_Row = coordinates.first;
    m_Column = coordinates.second;
    m_CellAddress = GetColumnAsString(m_Column) + GetRowAsString(m_Row);
}

string CoreTools::SimpleCSV::CellReferenceImpl::GetRowAsString(int row)
{
    if (row <= 0)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Input, SYSTEM_TEXT("行数小于或等于0。"s));
    }

    return std::to_string(row);
}

int CoreTools::SimpleCSV::CellReferenceImpl::GetRowAsNumber(const string& row)
{
    return boost::numeric_cast<int>(stoul(row));
}

string CoreTools::SimpleCSV::CellReferenceImpl::GetColumnAsString(int column)
{
    string result{};

    // 如果列名中有一个字母：
    if (column <= alphabetSize)
    {
        result += boost::numeric_cast<char>(column + asciiOffset);
    }
    // 如果列名中有两个字母：
    else if (column > alphabetSize && column <= alphabetSize * (alphabetSize + 1))
    {
        result += boost::numeric_cast<char>((column - (alphabetSize + 1)) / alphabetSize + asciiOffset + 1);
        result += boost::numeric_cast<char>((column - (alphabetSize + 1)) % alphabetSize + asciiOffset + 1);
    }
    // 如果列名中有三个字母：
    else
    {
        constexpr auto step = (alphabetSize * (alphabetSize + 1)) + 1;

        result += boost::numeric_cast<char>((column - step) / (alphabetSize * alphabetSize) + asciiOffset + 1);
        result += boost::numeric_cast<char>(((column - step) / alphabetSize) % alphabetSize + asciiOffset + 1);
        result += boost::numeric_cast<char>((column - step) % alphabetSize + asciiOffset + 1);
    }

    return result;
}

int CoreTools::SimpleCSV::CellReferenceImpl::GetColumnAsNumber(const string& column)
{
    auto result = 0;

    auto pow = 0;
    for (auto iter = column.rbegin(); iter != column.rend(); ++iter)
    {
        const auto number = *iter - asciiOffset;
        result += boost::numeric_cast<int>(number * std::pow(alphabetSize, pow));
        ++pow;
    }

    return result;
}

CoreTools::SimpleCSV::CellReferenceImpl::Coordinates CoreTools::SimpleCSV::CellReferenceImpl::GetCoordinatesFromAddress(const string& address)
{
    auto letterCount = 0u;
    for (auto letter : address)
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