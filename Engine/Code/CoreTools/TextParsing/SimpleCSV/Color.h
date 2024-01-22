/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:48)

#ifndef CORE_TOOLS_TEXT_PARSING_COLOR_H
#define CORE_TOOLS_TEXT_PARSING_COLOR_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE Color final
    {
    public:
        using ClassType = Color;

    public:
        Color() noexcept = default;
        Color(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue) noexcept;
        Color(uint8_t red, uint8_t green, uint8_t blue) noexcept;
        explicit Color(const std::string& hexCode);

        CLASS_INVARIANT_DECLARE;

        void Set(uint8_t aAlpha, uint8_t aRed, uint8_t aGreen, uint8_t aBlue) noexcept;
        void Set(uint8_t aRed = 0, uint8_t aGreen = 0, uint8_t aBlue = 0) noexcept;
        void Set(const std::string& hexCode);

        NODISCARD uint8_t GetAlpha() const noexcept;
        NODISCARD uint8_t GetRed() const noexcept;
        NODISCARD uint8_t GetGreen() const noexcept;
        NODISCARD uint8_t GetBlue() const noexcept;

        NODISCARD std::string GetHex() const;

    private:
        static constexpr auto hexNumber = 16;

    private:
        uint8_t alpha{ 255 };
        uint8_t red{ 0 };
        uint8_t green{ 0 };
        uint8_t blue{ 0 };
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_COLOR_H
