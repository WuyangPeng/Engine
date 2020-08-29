//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/25 10:46)

#ifndef RENDERING_DATA_TYPES_TEXTURE_COLOUR_H
#define RENDERING_DATA_TYPES_TEXTURE_COLOUR_H

#include "ColourTextureFormatTraits.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <array>
#include <type_traits>

// 颜色类会将值截断为[sm_MinValue,sm_MaxValue]，
// 如果要求颜色类的平均值，先将Clamp值设置为false，然后再进行数值运算，之后将Clamp值重新设置为true。
namespace Rendering
{
    template <TextureFormat Format>
    class TextureColour : private boost::additive<TextureColour<Format>, boost::multipliable<TextureColour<Format>, boost::equality_comparable<TextureColour<Format>>>>
    {
    public:
        using ClassType = TextureColour<Format>;
        using ValueType = typename ColourTextureFormatTraits<Format>::ColourType;
        using Channel = typename ColourTextureFormatTraits<Format>::Channel;
        using MinType = decltype(ColourTextureFormatTraits<Format>::sm_MinValue);

        using RedType = typename ColourTextureFormatTraits<Format>::RedType;
        using GreenType = typename ColourTextureFormatTraits<Format>::GreenType;
        using BlueType = typename ColourTextureFormatTraits<Format>::BlueType;
        using AlphaType = typename ColourTextureFormatTraits<Format>::AlphaType;
        using LuminanceType = typename ColourTextureFormatTraits<Format>::LuminanceType;

        static constexpr auto sm_Red = System::EnumCastUnderlying(Channel::Red);
        static constexpr auto sm_Green = System::EnumCastUnderlying(Channel::Green);
        static constexpr auto sm_Blue = System::EnumCastUnderlying(Channel::Blue);
        static constexpr auto sm_Alpha = System::EnumCastUnderlying(Channel::Alpha);
        static constexpr auto sm_Luminance = System::EnumCastUnderlying(Channel::Luminance);

    public:
        constexpr TextureColour() noexcept
            : m_Colour{}, m_IsClamp{ true }
        {
        }

        constexpr TextureColour(ValueType red, ValueType green, ValueType blue, ValueType alpha) noexcept
            : m_Colour{}, m_IsClamp{ true }
        {
            static_assert(std::is_same_v<RedType, TrueType>, "RedType is TrueType!");
            static_assert(std::is_same_v<GreenType, TrueType>, "GreenType is TrueType!");
            static_assert(std::is_same_v<BlueType, TrueType>, "BlueType is TrueType!");
            static_assert(std::is_same_v<AlphaType, TrueType>, "AlphaType is TrueType!");
            static_assert(!std::is_same_v<LuminanceType, TrueType>, "LuminanceType isn't TrueType!");

            static_assert(0 <= sm_Red && sm_Red < sm_ArraySize);
            static_assert(0 <= sm_Green && sm_Green < sm_ArraySize);
            static_assert(0 <= sm_Blue && sm_Blue < sm_ArraySize);
            static_assert(0 <= sm_Alpha && sm_Alpha < sm_ArraySize);

            SetColour(red, green, blue, alpha);
        }

        // 如果存在alpha，则设为最大值
        TextureColour(ValueType red, ValueType green, ValueType blue) noexcept
            : m_Colour{}, m_IsClamp{ true }
        {
            static_assert(std::is_same_v<RedType, TrueType>, "RedType is TrueType!");
            static_assert(std::is_same_v<GreenType, TrueType>, "GreenType is TrueType!");
            static_assert(std::is_same_v<BlueType, TrueType>, "BlueType is TrueType!");
            static_assert(!std::is_same_v<LuminanceType, TrueType>, "LuminanceType isn't TrueType!");

            static_assert(0 <= sm_Red && sm_Red < sm_ArraySize);
            static_assert(0 <= sm_Green && sm_Green < sm_ArraySize);
            static_assert(0 <= sm_Blue && sm_Blue < sm_ArraySize);

            if constexpr (sm_Alpha != -1)
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
                m_Colour[sm_Alpha] = sm_AlphaMaxValue;
#include STSTEM_WARNING_POP
            }

            SetColour(red, green, blue);
        }

        TextureColour(ValueType value1, ValueType value2) noexcept;

        explicit TextureColour(ValueType value) noexcept;

        // 只有当成员是一致时（alpha成员除外），才允许转换
        template <TextureFormat RhsFormat>
        TextureColour(const TextureColour<RhsFormat>& colour);

        template <TextureFormat RhsFormat>
        TextureColour& operator=(const TextureColour<RhsFormat>& colour);

        CLASS_INVARIANT_DECLARE;

        constexpr void SetColour(ValueType red, ValueType green, ValueType blue, ValueType alpha) noexcept
        {
            static_assert(std::is_same_v<RedType, TrueType>, "RedType is TrueType!");
            static_assert(std::is_same_v<GreenType, TrueType>, "GreenType is TrueType!");
            static_assert(std::is_same_v<BlueType, TrueType>, "BlueType is TrueType!");
            static_assert(std::is_same_v<AlphaType, TrueType>, "AlphaType is TrueType!");
            static_assert(!std::is_same_v<LuminanceType, TrueType>, "LuminanceType isn't TrueType!");

            static_assert(0 <= sm_Red && sm_Red < sm_ArraySize);
            static_assert(0 <= sm_Green && sm_Green < sm_ArraySize);
            static_assert(0 <= sm_Blue && sm_Blue < sm_ArraySize);
            static_assert(0 <= sm_Alpha && sm_Alpha < sm_ArraySize);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
            m_Colour[sm_Red] = red;
            m_Colour[sm_Green] = green;
            m_Colour[sm_Blue] = blue;
            m_Colour[sm_Alpha] = alpha;
#include STSTEM_WARNING_POP

            Standardization();
        }

        constexpr void SetColour(ValueType red, ValueType green, ValueType blue) noexcept
        {
            static_assert(std::is_same_v<RedType, TrueType>, "RedType is TrueType!");
            static_assert(std::is_same_v<GreenType, TrueType>, "GreenType is TrueType!");
            static_assert(std::is_same_v<BlueType, TrueType>, "BlueType is TrueType!");
            static_assert(!std::is_same_v<LuminanceType, TrueType>, "LuminanceType isn't TrueType!");

            static_assert(0 <= sm_Red && sm_Red < sm_ArraySize);
            static_assert(0 <= sm_Green && sm_Green < sm_ArraySize);
            static_assert(0 <= sm_Blue && sm_Blue < sm_ArraySize);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
            m_Colour[sm_Red] = red;
            m_Colour[sm_Green] = green;
            m_Colour[sm_Blue] = blue;
#include STSTEM_WARNING_POP

            Standardization();
        }

        void SetColour(ValueType value1, ValueType value2) noexcept;

        void SetColour(ValueType value) noexcept;

        [[nodiscard]] bool IsClamp() const noexcept;
        void SetClamp(bool isClamp) noexcept;

        [[nodiscard]] ValueType GetRed() const noexcept;
        [[nodiscard]] ValueType GetGreen() const noexcept;
        [[nodiscard]] ValueType GetBlue() const noexcept;
        [[nodiscard]] ValueType GetAlpha() const noexcept;
        [[nodiscard]] ValueType GetLuminance() const noexcept;
        [[nodiscard]] const ValueType* GetPoint() const noexcept;
        [[nodiscard]] ValueType operator[](int index) const;

        void SetRed(ValueType red) noexcept;
        void SetGreen(ValueType green) noexcept;
        void SetBlue(ValueType blue) noexcept;
        void SetAlpha(ValueType alpha) noexcept;
        void SetLuminance(ValueType luminance) noexcept;

        TextureColour& operator+=(const TextureColour& rhs) noexcept;
        TextureColour& operator-=(const TextureColour& rhs) noexcept;
        TextureColour& operator*=(const TextureColour& rhs);

        template <typename RhsType>
        TextureColour& operator*=(RhsType rhs);
        template <typename RhsType>
        TextureColour& operator/=(RhsType rhs);

    private:
        static constexpr auto sm_MinValue = ColourTextureFormatTraits<Format>::sm_MinValue;
        static constexpr auto sm_RedMaxValue = ColourTextureFormatTraits<Format>::sm_RedMaxValue;
        static constexpr auto sm_GreenMaxValue = ColourTextureFormatTraits<Format>::sm_GreenMaxValue;
        static constexpr auto sm_BlueMaxValue = ColourTextureFormatTraits<Format>::sm_BlueMaxValue;
        static constexpr auto sm_AlphaMaxValue = ColourTextureFormatTraits<Format>::sm_AlphaMaxValue;
        static constexpr auto sm_LuminanceMaxValue = ColourTextureFormatTraits<Format>::sm_LuminanceMaxValue;

        static constexpr auto sm_IsFloatingPoint = ColourTextureFormatTraits<Format>::sm_IsFloatingPoint;
        static constexpr auto sm_ArraySize = ColourTextureFormatTraits<Format>::sm_ArraySize;
        static constexpr auto sm_MaxValue = ColourTextureFormatTraits<Format>::sm_MaxValue;

        static_assert((sm_Red == -1) || (0 <= sm_Red && sm_Red < sm_ArraySize));
        static_assert((sm_Green == -1) || (0 <= sm_Green && sm_Green < sm_ArraySize));
        static_assert((sm_Blue == -1) || (0 <= sm_Blue && sm_Blue < sm_ArraySize));
        static_assert((sm_Alpha == -1) || (0 <= sm_Alpha && sm_Alpha < sm_ArraySize));
        static_assert((sm_Luminance == -1) || (0 <= sm_Luminance && sm_Luminance < sm_ArraySize));

    private:
        static constexpr ValueType Clamp(ValueType colour, ValueType maxValue) noexcept
        {
            if (colour < sm_MinValue)
                return sm_MinValue;
            else if (maxValue < colour)
                return maxValue;
            else
                return colour;
        }

        constexpr void Standardization() noexcept
        {
            Standardization<sm_Red>(std::is_same<RedType, TrueType>(), sm_RedMaxValue);
            Standardization<sm_Green>(std::is_same<GreenType, TrueType>(), sm_GreenMaxValue);
            Standardization<sm_Blue>(std::is_same<BlueType, TrueType>(), sm_BlueMaxValue);
            Standardization<sm_Alpha>(std::is_same<AlphaType, TrueType>(), sm_AlphaMaxValue);
            Standardization<sm_Luminance>(std::is_same<LuminanceType, TrueType>(), sm_LuminanceMaxValue);
        }

        template <int Index>
        constexpr void Standardization(const std::false_type&, [[maybe_unused]] ValueType maxValue) noexcept
        {
        }

        template <int Index>
        constexpr void Standardization(const std::true_type&, ValueType maxValue) noexcept
        {
            if (m_IsClamp)
            {
                static_assert(0 <= Index && Index < sm_ArraySize, "index is crossing!");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
                m_Colour[Index] = Clamp(m_Colour[Index], maxValue);
#include STSTEM_WARNING_POP
            }
        }

        template <TextureFormat RhsFormat>
        void ConvertingColourFormat(const TextureColour<RhsFormat>& colour);

        template <TextureFormat RhsFormat, int Index, int RhsIndex, bool HaveBit>
        void Converting(const TextureColour<RhsFormat>& colour, MinType maxValue,
                        typename TextureColour<RhsFormat>::MinType rhsMaxValue,
                        const std::integral_constant<bool, HaveBit>&);

        template <TextureFormat RhsFormat, int Index, int RhsIndex>
        void Converting(const TextureColour<RhsFormat>& colour, MinType maxValue,
                        typename TextureColour<RhsFormat>::MinType rhsMaxValue,
                        const std::false_type&) noexcept;

        template <TextureFormat RhsFormat, bool HaveAlpha, bool RhsHaveAlpha>
        void ConvertingAlpha(const TextureColour<RhsFormat>& colour,
                             const std::integral_constant<bool, HaveAlpha>&,
                             const std::integral_constant<bool, RhsHaveAlpha>&) noexcept;

        template <TextureFormat RhsFormat>
        void ConvertingAlpha(const TextureColour<RhsFormat>& colour, const std::true_type&, const std::true_type&);

        template <TextureFormat RhsFormat>
        void ConvertingAlpha(const TextureColour<RhsFormat>& colour, const std::true_type&, const std::false_type&) noexcept;

        template <TextureFormat RhsFormat, int Index, int RhsIndex, bool IsFloatingPoint, bool RhsIsFloatingPoint>
        void ConvertingBit(const TextureColour<RhsFormat>& colour, MinType maxValue,
                           typename TextureColour<RhsFormat>::MinType rhsMinValue,
                           typename TextureColour<RhsFormat>::MinType rhsMaxValue,
                           const std::integral_constant<bool, IsFloatingPoint>&,
                           const std::integral_constant<bool, RhsIsFloatingPoint>&);

        template <TextureFormat RhsFormat, int Index, int RhsIndex>
        void ConvertingBit(const TextureColour<RhsFormat>& colour, MinType maxValue,
                           typename TextureColour<RhsFormat>::MinType rhsMinValue,
                           typename TextureColour<RhsFormat>::MinType rhsMaxValue,
                           const std::false_type&, const std::true_type&);

        template <int Index, bool HaveBit>
        void Multiply(const std::integral_constant<bool, HaveBit>&, MinType maxValue, const TextureColour& colour);
        template <int Index>
        void Multiply(const std::false_type&, MinType maxValue, const TextureColour& colour) noexcept;

        template <typename RhsType, bool RhsIsFloatingPoint>
        void Divide(RhsType rhs, const std::integral_constant<bool, RhsIsFloatingPoint>&);

        template <typename RhsType>
        void Divide(RhsType rhs, const std::false_type&);

    private:
        std::array<ValueType, sm_ArraySize> m_Colour{};
        bool m_IsClamp{ true };
    };

    template <TextureFormat Format>
    [[nodiscard]] bool Approximate(const TextureColour<Format>& lhs, const TextureColour<Format>& rhs, typename TextureColour<Format>::ValueType epsilon);

    template <TextureFormat Format>
    [[nodiscard]] bool operator==(const TextureColour<Format>& lhs, const TextureColour<Format>& rhs);

    template <TextureFormat LhsFormat, typename RhsType>
    [[nodiscard]] const TextureColour<LhsFormat> operator*(const TextureColour<LhsFormat>& lhs, RhsType rhs);
    template <typename LhsType, TextureFormat RhsFormat>
    [[nodiscard]] const TextureColour<RhsFormat> operator*(LhsType lhs, const TextureColour<RhsFormat>& rhs);
    template <TextureFormat LhsFormat, typename RhsType>
    [[nodiscard]] const TextureColour<LhsFormat> operator/(const TextureColour<LhsFormat>& lhs, RhsType rhs);
}

#endif  // RENDERING_DATA_TYPES_TEXTURE_COLOUR_H
