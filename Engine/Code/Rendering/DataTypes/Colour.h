///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/29 14:27)

#ifndef RENDERING_DATA_TYPES_COLOUR_H
#define RENDERING_DATA_TYPES_COLOUR_H

#include "Rendering/RenderingDll.h"

#include "ColourDefaultTraits.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <array>
#include <iosfwd>
#include <type_traits>

// 颜色类会将值截断为[minValue,maxValue]，
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

        static constexpr auto arraySize = 4;
        using ArrayType = std::array<T, arraySize>;

    public:
        constexpr Colour() noexcept
            : Colour{ minValue, minValue, minValue, maxValue }
        {
        }

        constexpr Colour(T red, T green, T blue, T alpha = maxValue) noexcept
            : red{ red }, green{ green }, blue{ blue }, alpha{ alpha }, isClamp{ true }
        {
            Standardization();
        }

        template <typename RhsType>
        Colour(const Colour<RhsType>& colour);

        template <typename RhsType>
        Colour& operator=(const Colour<RhsType>& colour);

        CLASS_INVARIANT_DECLARE;

        void SetClamp(bool newIsClamp) noexcept;
        NODISCARD bool IsClamp() const noexcept;

        NODISCARD T GetRed() const noexcept;
        NODISCARD T GetGreen() const noexcept;
        NODISCARD T GetBlue() const noexcept;
        NODISCARD T GetAlpha() const noexcept;
        NODISCARD ArrayType GetPoint() const noexcept;

        void SetColour(T newRed, T newGreen, T newBlue, T newAlpha = maxValue) noexcept;
        void SetRed(T newRed) noexcept;
        void SetGreen(T newGreen) noexcept;
        void SetBlue(T newBlue) noexcept;
        void SetAlpha(T newAlpha) noexcept;

        Colour& operator+=(const Colour& rhs) noexcept;
        Colour& operator-=(const Colour& rhs) noexcept;
        Colour& operator*=(const Colour& rhs) noexcept(std::is_floating_point_v<T>);

        template <typename RhsType>
        Colour& operator*=(RhsType rhs);
        template <typename RhsType>
        Colour& operator/=(RhsType rhs);

    private:
        NODISCARD static constexpr T Clamp(T colour) noexcept
        {
            if (colour < minValue)
                return minValue;
            else if (maxValue < colour)
                return maxValue;
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
            if (isClamp)
            {
                red = Clamp(red);
            }
        }

        constexpr void StandardizationGreen()
        {
            if (isClamp)
            {
                green = Clamp(green);
            }
        }

        constexpr void StandardizationBlue()
        {
            if (isClamp)
            {
                blue = Clamp(blue);
            }
        }

        constexpr void StandardizationAlpha()
        {
            if (isClamp)
            {
                alpha = Clamp(alpha);
            }
        }

        template <typename RhsType>
        NODISCARD static T ConvertingIntegralToFloatingPoint(RhsType rhs);

        template <typename RhsType>
        NODISCARD static T ConvertingFloatingPointToIntegral(RhsType rhs);

        void InitColour(T red, T green, T blue, T alpha) noexcept;

        template <typename RhsType, bool TIsFloatingPoint, bool RhsIsFloatingPoint>
        void ConvertingColourFormat(const Colour<RhsType>& colour,
                                    const std::integral_constant<bool, TIsFloatingPoint>&,
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
        static constexpr auto minValue = static_cast<T>(ColourDefaultTraits<T>::minValue);
        static constexpr auto maxValue = static_cast<T>(ColourDefaultTraits<T>::maxValue);

        T red{};
        T green{};
        T blue{};
        T alpha{};
        bool isClamp{ true };
    };

    template <typename T>
    NODISCARD bool Approximate(const Colour<T>& lhs, const Colour<T>& rhs, T epsilon) noexcept;

    template <typename T>
    NODISCARD bool operator==(const Colour<T>& lhs, const Colour<T>& rhs) noexcept;

    template <typename LhsType, typename RhsType>
    NODISCARD const Colour<LhsType> operator*(const Colour<LhsType>& lhs, RhsType rhs);
    template <typename LhsType, typename RhsType>
    NODISCARD const Colour<RhsType> operator*(LhsType lhs, const Colour<RhsType>& rhs);
    template <typename LhsType, typename RhsType>
    NODISCARD const Colour<LhsType> operator/(const Colour<LhsType>& lhs, RhsType rhs);

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Colour<T>& colour);

    RENDERING_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& os, const Colour<uint8_t>& colour);

    using ByteColour = Colour<uint8_t>;
    using IntColour = Colour<int>;
    using FloatColour = Colour<float>;
    using DoubleColour = Colour<double>;
}

#endif  // RENDERING_DATA_TYPES_COLOUR_H
