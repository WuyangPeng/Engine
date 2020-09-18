//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/24 21:28)

#include "Rendering/RenderingExport.h"

#include "TextureColourDetail.h"

using std::is_same_v;

template <>
void Rendering::TextureColour<Rendering::TextureFormat::A8L8>::SetColour(ValueType alpha, ValueType luminance) noexcept
{
    static_assert(!is_same_v<RedType, TrueType>, "RedType isn't TrueType!");
    static_assert(!is_same_v<GreenType, TrueType>, "GreenType isn't TrueType!");
    static_assert(!is_same_v<BlueType, TrueType>, "BlueType isn't TrueType!");
    static_assert(is_same_v<AlphaType, TrueType>, "AlphaType is TrueType!");
    static_assert(is_same_v<LuminanceType, TrueType>, "LuminanceType is TrueType!");

    static_assert(0 <= sm_Alpha && sm_Alpha < sm_ArraySize);
    static_assert(0 <= sm_Luminance && sm_Luminance < sm_ArraySize);

    RENDERING_CLASS_IS_VALID_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    m_Colour[sm_Alpha] = alpha;
    m_Colour[sm_Luminance] = luminance;
#include STSTEM_WARNING_POP

    Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::G16R16>::SetColour(ValueType green, ValueType red) noexcept
{
    static_assert(is_same_v<RedType, TrueType>, "RedType is TrueType!");
    static_assert(is_same_v<GreenType, TrueType>, "GreenType is TrueType!");
    static_assert(!is_same_v<BlueType, TrueType>, "BlueType isn't TrueType!");
    static_assert(!is_same_v<AlphaType, TrueType>, "AlphaType isn't TrueType!");
    static_assert(!is_same_v<LuminanceType, TrueType>, "LuminanceType isn't TrueType!");

    static_assert(0 <= sm_Red && sm_Red < sm_ArraySize);
    static_assert(0 <= sm_Green && sm_Green < sm_ArraySize);

    RENDERING_CLASS_IS_VALID_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    m_Colour[sm_Green] = green;
    m_Colour[sm_Red] = red;
#include STSTEM_WARNING_POP

    Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::G16R16F>::SetColour(ValueType green, ValueType red) noexcept
{
    static_assert(is_same_v<RedType, TrueType>, "RedType is TrueType!");
    static_assert(is_same_v<GreenType, TrueType>, "GreenType is TrueType!");
    static_assert(!is_same_v<BlueType, TrueType>, "BlueType isn't TrueType!");
    static_assert(!is_same_v<AlphaType, TrueType>, "AlphaType isn't TrueType!");
    static_assert(!is_same_v<LuminanceType, TrueType>, "LuminanceType isn't TrueType!");

    static_assert(0 <= sm_Red && sm_Red < sm_ArraySize);
    static_assert(0 <= sm_Green && sm_Green < sm_ArraySize);

    RENDERING_CLASS_IS_VALID_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    m_Colour[sm_Green] = green;
    m_Colour[sm_Red] = red;
#include STSTEM_WARNING_POP

    Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::G32R32F>::SetColour(ValueType green, ValueType red) noexcept
{
    static_assert(is_same_v<RedType, TrueType>, "RedType is TrueType!");
    static_assert(is_same_v<GreenType, TrueType>, "GreenType is TrueType!");
    static_assert(!is_same_v<BlueType, TrueType>, "BlueType isn't TrueType!");
    static_assert(!is_same_v<AlphaType, TrueType>, "AlphaType isn't TrueType!");
    static_assert(!is_same_v<LuminanceType, TrueType>, "LuminanceType isn't TrueType!");

    static_assert(0 <= sm_Red && sm_Red < sm_ArraySize);
    static_assert(0 <= sm_Green && sm_Green < sm_ArraySize);

    RENDERING_CLASS_IS_VALID_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    m_Colour[sm_Green] = green;
    m_Colour[sm_Red] = red;
#include STSTEM_WARNING_POP

    Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::A8>::SetColour(ValueType alpha) noexcept
{
    static_assert(!is_same_v<RedType, TrueType>, "RedType isn't TrueType!");
    static_assert(!is_same_v<GreenType, TrueType>, "GreenType isn't TrueType!");
    static_assert(!is_same_v<BlueType, TrueType>, "BlueType isn't TrueType!");
    static_assert(is_same_v<AlphaType, TrueType>, "AlphaType is TrueType!");
    static_assert(!is_same_v<LuminanceType, TrueType>, "LuminanceType isn't TrueType!");

    static_assert(0 <= sm_Alpha && sm_Alpha < sm_ArraySize);

    RENDERING_CLASS_IS_VALID_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    m_Colour[sm_Alpha] = alpha;
#include STSTEM_WARNING_POP

    Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::L8>::SetColour(ValueType luminance) noexcept
{
    static_assert(!is_same_v<RedType, TrueType>, "RedType isn't TrueType!");
    static_assert(!is_same_v<GreenType, TrueType>, "GreenType isn't TrueType!");
    static_assert(!is_same_v<BlueType, TrueType>, "BlueType isn't TrueType!");
    static_assert(!is_same_v<AlphaType, TrueType>, "AlphaType isn't TrueType!");
    static_assert(is_same_v<LuminanceType, TrueType>, "LuminanceType is TrueType!");

    static_assert(0 <= sm_Luminance && sm_Luminance < sm_ArraySize);

    RENDERING_CLASS_IS_VALID_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    m_Colour[sm_Luminance] = luminance;
#include STSTEM_WARNING_POP

    Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::L16>::SetColour(ValueType luminance) noexcept
{
    static_assert(!is_same_v<RedType, TrueType>, "RedType isn't TrueType!");
    static_assert(!is_same_v<GreenType, TrueType>, "GreenType isn't TrueType!");
    static_assert(!is_same_v<BlueType, TrueType>, "BlueType isn't TrueType!");
    static_assert(!is_same_v<AlphaType, TrueType>, "AlphaType isn't TrueType!");
    static_assert(is_same_v<LuminanceType, TrueType>, "LuminanceType is TrueType!");

    static_assert(0 <= sm_Luminance && sm_Luminance < sm_ArraySize);

    RENDERING_CLASS_IS_VALID_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    m_Colour[sm_Luminance] = luminance;
#include STSTEM_WARNING_POP

    Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::R16F>::SetColour(ValueType red) noexcept
{
    static_assert(is_same_v<RedType, TrueType>, "RedType is TrueType!");
    static_assert(!is_same_v<GreenType, TrueType>, "GreenType isn't TrueType!");
    static_assert(!is_same_v<BlueType, TrueType>, "BlueType isn't TrueType!");
    static_assert(!is_same_v<AlphaType, TrueType>, "AlphaType isn't TrueType!");
    static_assert(!is_same_v<LuminanceType, TrueType>, "LuminanceType isn't TrueType!");

    static_assert(0 <= sm_Red && sm_Red < sm_ArraySize);

    RENDERING_CLASS_IS_VALID_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    m_Colour[sm_Red] = red;
#include STSTEM_WARNING_POP

    Standardization();
}

template <>
void Rendering::TextureColour<Rendering::TextureFormat::R32F>::SetColour(ValueType red) noexcept
{
    static_assert(is_same_v<RedType, TrueType>, "RedType is TrueType!");
    static_assert(!is_same_v<GreenType, TrueType>, "GreenType isn't TrueType!");
    static_assert(!is_same_v<BlueType, TrueType>, "BlueType isn't TrueType!");
    static_assert(!is_same_v<AlphaType, TrueType>, "AlphaType isn't TrueType!");
    static_assert(!is_same_v<LuminanceType, TrueType>, "LuminanceType isn't TrueType!");

    static_assert(0 <= sm_Red && sm_Red < sm_ArraySize);

    RENDERING_CLASS_IS_VALID_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    m_Colour[sm_Red] = red;
#include STSTEM_WARNING_POP

    Standardization();
}

#ifdef RENDERING_TEMPLATE_TEST

namespace Rendering
{
    void TextureColourTemplateTest()
    {
        using DefaultColour = TextureColour<TextureFormat::DefaultColour>;
        using A8L8Colour = TextureColour<TextureFormat::A8L8>;
        using A8Colour = TextureColour<TextureFormat::A8>;
        using A32B32G32R32FColour = TextureColour<TextureFormat::A32B32G32R32F>;
        using R8G8B8Colour = TextureColour<TextureFormat::R8G8B8>;
        using G16R16Colour = TextureColour<TextureFormat::G16R16>;
        using G16R16FColour = TextureColour<TextureFormat::G16R16F>;
        using G32R32FColour = TextureColour<TextureFormat::G32R32F>;
        using L8Colour = TextureColour<TextureFormat::L8>;
        using L16Colour = TextureColour<TextureFormat::L16>;
        using R16FColour = TextureColour<TextureFormat::R16F>;
        using R32FColour = TextureColour<TextureFormat::R32F>;

        DefaultColour colour1{};
        DefaultColour colour2{ 128, 100, 110, 210 };
        DefaultColour colour3{ 128, 100, 110 };
        A8L8Colour colour4{ 128, 100 };
        A8Colour colour5{ 128 };
        A32B32G32R32FColour colour6{ colour2 };
        const R8G8B8Colour colour7{ colour2 };
        colour2 = colour6;
        colour2 = colour7;

        colour6.SetClamp(false);
        [[maybe_unused]] const auto isClamp = colour2.IsClamp();

        colour1.SetRed(30);
        colour2.SetGreen(50);
        colour3.SetBlue(20);
        colour5.SetAlpha(5);
        colour4.SetLuminance(2);

        [[maybe_unused]] const auto red = colour1.GetRed();
        [[maybe_unused]] const auto greeen = colour2.GetGreen();
        [[maybe_unused]] const auto blue = colour3.GetBlue();
        [[maybe_unused]] const auto alpha = colour5.GetAlpha();
        [[maybe_unused]] const auto luminance = colour4.GetLuminance();

        [[maybe_unused]] const auto point = colour1.GetPoint();
        [[maybe_unused]] const auto value = colour1[1];

        colour3 += colour2;
        colour2 -= colour1;
        colour2 *= colour3;

        colour1 *= 5;
        colour2 /= 4;
        colour6 /= 3.0f;

        auto colour8 = colour1 + colour2;
        colour8 = colour1 - colour2;
        colour8 = colour1 * colour2;

        auto result = Approximate(colour6, colour6, Mathematics::FloatMath::GetZeroTolerance());
        result = (colour1 == colour2);
        result = (colour1 != colour2);

        auto colour9 = colour2 * 0.3f;
        colour9 = 0.2f * colour2;
        colour9 = colour2 / 0.3f;

        const G16R16Colour colour10{ 10, 12 };
        const G16R16FColour colour11{ 0.2f, 0.2f };
        const G32R32FColour colour12{ 0.2f, 0.2f };
        const L8Colour colour13{ 5 };
        const L16Colour colour14{ 5 };
        const R16FColour colour15{ 0.4f };
        const R32FColour colour16{ 0.4f };
    }
}

#else  // !RENDERING_TEMPLATE_TEST

namespace Rendering
{
    void TextureColourTemplateTest() noexcept
    {
    }
}

#endif  // RENDERING_TEMPLATE_TEST