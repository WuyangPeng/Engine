///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/08 11:27)

#include "CoreTools/CoreToolsExport.h"

#include "Color.h"
#include "SimpleCSVException.h"
#include "Flags/CSVExceptionFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

#include <sstream>

CoreTools::SimpleCSV::Color::Color(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue) noexcept
    : alpha{ alpha }, red{ red }, green{ green }, blue{ blue }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::Color::Color(uint8_t red, uint8_t green, uint8_t blue) noexcept
    : Color{ 255, red, green, blue }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::Color::Color(const std::string& hexCode)
    : Color{}
{
    Set(hexCode);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, Color)

void CoreTools::SimpleCSV::Color::Set(uint8_t aAlpha, uint8_t aRed, uint8_t aGreen, uint8_t aBlue) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    alpha = aAlpha;
    red = aRed;
    green = aGreen;
    blue = aBlue;
}

void CoreTools::SimpleCSV::Color::Set(uint8_t aRed, uint8_t aGreen, uint8_t aBlue) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    red = aRed;
    green = aGreen;
    blue = aBlue;
}

void CoreTools::SimpleCSV::Color::Set(const std::string& hexCode)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (8 < hexCode.size())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Input, SYSTEM_TEXT("无效颜色值"s));
    }

    const auto hexCodeAlpha = hexCode.substr(0, 2);
    const auto hexCodeRed = hexCode.substr(2, 2);
    const auto hexCodeGreen = hexCode.substr(4, 2);
    const auto hexCodeBlue = hexCode.substr(6, 2);

    alpha = boost::numeric_cast<uint8_t>(std::stoul(hexCodeAlpha, nullptr, hexNumber));
    red = boost::numeric_cast<uint8_t>(std::stoul(hexCodeRed, nullptr, hexNumber));
    green = boost::numeric_cast<uint8_t>(std::stoul(hexCodeGreen, nullptr, hexNumber));
    blue = boost::numeric_cast<uint8_t>(std::stoul(hexCodeBlue, nullptr, hexNumber));
}

uint8_t CoreTools::SimpleCSV::Color::GetAlpha() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return alpha;
}

uint8_t CoreTools::SimpleCSV::Color::GetRed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return red;
}

uint8_t CoreTools::SimpleCSV::Color::GetGreen() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return green;
}

uint8_t CoreTools::SimpleCSV::Color::GetBlue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return blue;
}

std::string CoreTools::SimpleCSV::Color::GetHex() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    std::stringstream ss{};

    if (alpha < hexNumber)
    {
        ss << "0";
    }

    ss << std::hex << static_cast<int>(alpha);

    if (red < hexNumber)
    {
        ss << "0";
    }

    ss << std::hex << static_cast<int>(red);

    if (green < hexNumber)
    {
        ss << "0";
    }

    ss << std::hex << static_cast<int>(green);

    if (blue < hexNumber)
    {
        ss << "0";
    }

    ss << std::hex << static_cast<int>(blue);

    return ss.str();
}
