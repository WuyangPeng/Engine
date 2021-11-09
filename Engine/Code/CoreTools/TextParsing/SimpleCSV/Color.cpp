///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/07 0:42)

#include "CoreTools/CoreToolsExport.h"

#include "Color.h"
#include "SimpleCSVException.h"
#include "Flags/CSVExceptionFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

#include <algorithm>
#include <sstream>

using std::string;
using std::stringstream;

CoreTools::SimpleCSV::Color::Color(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue) noexcept
    : m_Alpha{ alpha }, m_Red{ red }, m_Green{ green }, m_Blue{ blue }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::Color::Color(uint8_t red, uint8_t green, uint8_t blue) noexcept
    : Color{ 255, red, green, blue }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::Color::Color(const string& hexCode)
    : Color{}
{
    Set(hexCode);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, Color)

void CoreTools::SimpleCSV::Color::Set(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Alpha = alpha;
    m_Red = red;
    m_Green = green;
    m_Blue = blue;
}

void CoreTools::SimpleCSV::Color::Set(uint8_t red, uint8_t green, uint8_t blue) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Red = red;
    m_Green = green;
    m_Blue = blue;
}

void CoreTools::SimpleCSV::Color::Set(const string& hexCode)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (8 < hexCode.size())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Input, SYSTEM_TEXT("无效颜色值"s));
    }

    auto alpha = hexCode.substr(0, 2);
    auto red = hexCode.substr(2, 2);
    auto green = hexCode.substr(4, 2);
    auto blue = hexCode.substr(6, 2);

    m_Alpha = boost::numeric_cast<uint8_t>(stoul(alpha, nullptr, hexNumber));
    m_Red = boost::numeric_cast<uint8_t>(stoul(red, nullptr, hexNumber));
    m_Green = boost::numeric_cast<uint8_t>(stoul(green, nullptr, hexNumber));
    m_Blue = boost::numeric_cast<uint8_t>(stoul(blue, nullptr, hexNumber));
}

uint8_t CoreTools::SimpleCSV::Color::GetAlpha() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Alpha;
}

uint8_t CoreTools::SimpleCSV::Color::GetRed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Red;
}

uint8_t CoreTools::SimpleCSV::Color::GetGreen() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Green;
}

uint8_t CoreTools::SimpleCSV::Color::GetBlue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Blue;
}

string CoreTools::SimpleCSV::Color::GetHex() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    stringstream ss{};

    if (m_Alpha < hexNumber)
    {
        ss << "0";
    }

    ss << std::hex << static_cast<int>(m_Alpha);

    if (m_Red < hexNumber)
    {
        ss << "0";
    }

    ss << std::hex << static_cast<int>(m_Red);

    if (m_Green < hexNumber)
    {
        ss << "0";
    }

    ss << std::hex << static_cast<int>(m_Green);

    if (m_Blue < hexNumber)
    {
        ss << "0";
    }

    ss << std::hex << static_cast<int>(m_Blue);

    return ss.str();
}
