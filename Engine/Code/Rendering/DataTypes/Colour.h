//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/19 12:48)

#ifndef RENDERING_DATA_TYPES_COLOUR_H
#define RENDERING_DATA_TYPES_COLOUR_H

#include "Rendering/RenderingDll.h"

#include "ColourDefaultTraits.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <array>
#include <iosfwd>
#include <type_traits>

// 颜色类会将值截断为[sm_MinValue,sm_MaxValue]，
// 如果要求颜色类的平均值，先将Clamp值设置为false，然后再进行数值运算，之后将Clamp值重新设置为true。
namespace Rendering
{
    template <typename T>
    class RENDERING_TEMPLATE_DEFAULT_DECLARE Colour : private boost::additive<Colour<T>, boost::multipliable<Colour<T>, boost::equality_comparable<Colour<T>>>>
    {
    public:
        static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

        using ClassType = Colour<T>;
        using ValueType = T;

        static constexpr auto sm_ArraySize = 4;
        using ArrayType = std::array<T, sm_ArraySize>;

    public:
        constexpr Colour() noexcept
            : Colour{ sm_MinValue, sm_MinValue, sm_MinValue, sm_MaxValue }
        {
        }

        constexpr Colour(T red, T green, T blue, T alpha = sm_MaxValue) noexcept
            : m_Red{ red }, m_Green{ green }, m_Blue{ blue }, m_Alpha{ alpha }, m_IsClamp{ true }
        {
            Standardization();
        }

        template <typename RhsType>
        Colour(const Colour<RhsType>& colour);

        template <typename RhsType>
        Colour& operator=(const Colour<RhsType>& colour);

        CLASS_INVARIANT_DECLARE;

        void SetClamp(bool isClamp) noexcept;
        [[nodiscard]] bool IsClamp() const noexcept;

        [[nodiscard]] T GetRed() const noexcept;
        [[nodiscard]] T GetGreen() const noexcept;
        [[nodiscard]] T GetBlue() const noexcept;
        [[nodiscard]] T GetAlpha() const noexcept;
        [[nodiscard]] const ArrayType GetPoint() const noexcept;

        void SetColour(T red, T green, T blue, T alpha = sm_MaxValue) noexcept;
        void SetRed(T red) noexcept;
        void SetGreen(T green) noexcept;
        void SetBlue(T blue) noexcept;
        void SetAlpha(T alpha) noexcept;

        Colour& operator+=(const Colour& rhs) noexcept;
        Colour& operator-=(const Colour& rhs) noexcept;
        Colour& operator*=(const Colour& rhs) noexcept(std::is_floating_point_v<T>);

        template <typename RhsType>
        Colour& operator*=(RhsType rhs);
        template <typename RhsType>
        Colour& operator/=(RhsType rhs);

    private:
        static constexpr T Clamp(T colour) noexcept
        {
            if (colour < sm_MinValue)
                return sm_MinValue;
            else if (sm_MaxValue < colour)
                return sm_MaxValue;
            else
                return colour;
        }

        constexpr void Standardization() noexcept
        {
            StandardizationRed();
            StandardizationGreen();
            StandardizationBlue();
            StandardizationAlpha();
        }

        constexpr void StandardizationRed() noexcept
        {
            if (m_IsClamp)
            {
                m_Red = Clamp(m_Red);
            }
        }

        constexpr void StandardizationGreen()
        {
            if (m_IsClamp)
            {
                m_Green = Clamp(m_Green);
            }
        }

        constexpr void StandardizationBlue()
        {
            if (m_IsClamp)
            {
                m_Blue = Clamp(m_Blue);
            }
        }

        constexpr void StandardizationAlpha()
        {
            if (m_IsClamp)
            {
                m_Alpha = Clamp(m_Alpha);
            }
        }

        template <typename RhsType>
        static T ConvertingIntegralToFloatingPoint(RhsType rhs);

        template <typename RhsType>
        static T ConvertingFloatingPointToIntegral(RhsType rhs);

        void InitColour(T red, T green, T blue, T alpha) noexcept;

        template <typename RhsType, bool TIsFloatingPoint, bool RhsIsFloatingPoint>
        void ConvertingColourFormat(const Colour<RhsType>& colour, const std::integral_constant<bool, TIsFloatingPoint>&,
                                    const std::integral_constant<bool, RhsIsFloatingPoint>&);

        template <typename RhsType>
        void ConvertingColourFormat(const Colour<RhsType>& colour, const std::true_type&, const std::false_type&);

        template <typename RhsType>
        void ConvertingColourFormat(const Colour<RhsType>& colour, const std::false_type&, const std::true_type&);

        template <typename RhsType, bool RhsIsFloatingPoint>
        void Divide(RhsType rhs, const std::integral_constant<bool, RhsIsFloatingPoint>&);

        template <typename RhsType>
        void Divide(RhsType rhs, const std::false_type&);

    private:
        static constexpr auto sm_MinValue = static_cast<T>(ColourDefaultTraits<T>::sm_MinValue);
        static constexpr auto sm_MaxValue = static_cast<T>(ColourDefaultTraits<T>::sm_MaxValue);

        T m_Red{};
        T m_Green{};
        T m_Blue{};
        T m_Alpha{};
        bool m_IsClamp{ true };
    };

    template <typename T>
    [[nodiscard]] bool Approximate(const Colour<T>& lhs, const Colour<T>& rhs, T epsilon) noexcept;

    template <typename T>
    [[nodiscard]] bool operator==(const Colour<T>& lhs, const Colour<T>& rhs) noexcept;

    template <typename LhsType, typename RhsType>
    [[nodiscard]] const Colour<LhsType> operator*(const Colour<LhsType>& lhs, RhsType rhs);
    template <typename LhsType, typename RhsType>
    [[nodiscard]] const Colour<RhsType> operator*(LhsType lhs, const Colour<RhsType>& rhs);
    template <typename LhsType, typename RhsType>
    [[nodiscard]] const Colour<LhsType> operator/(const Colour<LhsType>& lhs, RhsType rhs);

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Colour<T>& colour);

    RENDERING_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& os, const Colour<uint8_t>& colour);
}

#endif  // RENDERING_DATA_TYPES_COLOUR_H
