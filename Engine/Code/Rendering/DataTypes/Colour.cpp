//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/18 13:25)

#include "Rendering/RenderingExport.h"

#ifdef RENDERING_EXPORT_TEMPLATE

    #ifndef RENDERING_INCLUDED_COLOUR_ACHIEVE
        #define RENDERING_INCLUDED_COLOUR_ACHIEVE
    #endif  // RENDERING_INCLUDED_COLOUR_ACHIEVE

#endif  // RENDERING_EXPORT_TEMPLATE

#include "ColourDetail.h"

#ifdef RENDERING_EXPORT_TEMPLATE

namespace Rendering
{
    template RENDERING_TEMPLATE_DEFAULT_DECLARE class Colour<uint8_t>;
    template RENDERING_TEMPLATE_DEFAULT_DECLARE class Colour<int>;
    template RENDERING_TEMPLATE_DEFAULT_DECLARE class Colour<uint32_t>;
    template RENDERING_TEMPLATE_DEFAULT_DECLARE class Colour<float>;
    template RENDERING_TEMPLATE_DEFAULT_DECLARE class Colour<double>;
}

#endif  // RENDERING_EXPORT_TEMPLATE

using std::ostream;

ostream& Rendering::operator<<(ostream& os, const Colour<uint8_t>& colour)
{
    os << "red = " << static_cast<int>(colour.GetRed())
       << " green = " << static_cast<int>(colour.GetGreen())
       << " blue = " << static_cast<int>(colour.GetBlue())
       << " alpha = " << static_cast<int>(colour.GetAlpha());

    return os;
}

#ifdef RENDERING_TEMPLATE_TEST

using std::cout;

namespace Rendering
{
    void ColourTemplateTest()
    {
        IntColour colour1{};
        IntColour colour2{ 10, 20, 30 };
        IntColour colour3{ 10, 20, 30, 40 };
        FloatColour colour4{ colour3 };
        colour2 = colour4;

        colour1.SetClamp(false);
        [[maybe_unused]] const auto isClamp = colour2.IsClamp();

        colour1.SetRed(30);
        colour2.SetGreen(50);
        colour3.SetBlue(20);
        colour4.SetAlpha(0.5f);

        [[maybe_unused]] const auto red = colour1.GetRed();
        [[maybe_unused]] const auto greeen = colour2.GetGreen();
        [[maybe_unused]] const auto blue = colour3.GetBlue();
        [[maybe_unused]] const auto alpha = colour4.GetAlpha();

        [[maybe_unused]] const auto point = colour1.GetPoint();

        colour1 += colour2;
        colour2 -= colour3;
        colour3 *= colour1;

        colour1 *= 5;
        colour2 /= 4;

        auto result = Approximate(colour4, colour4, Mathematics::FloatMath::GetZeroTolerance());
        result = (colour1 == colour2);
        result = (colour1 != colour2);

        auto colour5 = colour4 * 0.3f;
        colour5 = 0.2f * colour4;
        colour5 = colour4 / 0.3f;

        auto colour6 = colour1 + colour2;
        colour6 = colour1 - colour2;
        colour6 = colour1 * colour2;

        cout << colour1;
    }
}

#else  // !RENDERING_TEMPLATE_TEST

namespace Rendering
{
    void ColourTemplateTest() noexcept
    {
    }
}

#endif  // RENDERING_TEMPLATE_TEST