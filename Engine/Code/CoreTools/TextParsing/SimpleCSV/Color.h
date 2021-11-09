///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.4 (2021/10/07 0:42)

#ifndef CORE_TOOLS_TEXT_PARSING_COLOR_H
#define CORE_TOOLS_TEXT_PARSING_COLOR_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    namespace SimpleCSV
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

            void Set(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue) noexcept;
            void Set(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0) noexcept;
            void Set(const std::string& hexCode);

            NODISCARD uint8_t GetAlpha() const noexcept;
            NODISCARD uint8_t GetRed() const noexcept;
            NODISCARD uint8_t GetGreen() const noexcept;
            NODISCARD uint8_t GetBlue() const noexcept;

            NODISCARD std::string GetHex() const;

        private:
            static constexpr auto hexNumber = 16;

        private:
            uint8_t m_Alpha{ 255 };
            uint8_t m_Red{ 0 };
            uint8_t m_Green{ 0 };
            uint8_t m_Blue{ 0 };
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_COLOR_H
