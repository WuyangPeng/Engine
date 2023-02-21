///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/24 21:43)

#include "Mathematics/MathematicsExport.h"

#include "NormalCompression.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "Mathematics/Base/MathDetail.h"

static constexpr auto gsN = 127;
static constexpr auto temp1 = 2 * gsN + 1;
static constexpr auto gsB = static_cast<double>(temp1);
static constexpr auto gsB2 = gsB * gsB;
static constexpr auto temp2 = (gsN - 1);

auto getGSFactor() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    static auto value = temp2 * Mathematics::MathD::Sqrt(0.5);

    return value;
}

auto getInvFactor() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    static auto value = 1.0 / getGSFactor();

    return value;
}

void Mathematics::CompressNormal(double x, double y, double z, uint16_t& index)
{
    index = 0;
    if (x < 0.0)
    {
        index |= 0x8000;
        x = -x;
    }
    if (y < 0.0)
    {
        index |= 0x4000;
        y = -y;
    }
    if (z < 0.0)
    {
        index |= 0x2000;
        z = -z;
    }

    const auto usX = boost::numeric_cast<uint16_t>(MathD::Floor(getGSFactor() * x));
    const auto usY = boost::numeric_cast<uint16_t>(MathD::Floor(getGSFactor() * y));
    auto mantissa = boost::numeric_cast<uint16_t>(usX + ((usY * (255 - usY)) >> 1));
    index |= mantissa;
}

void Mathematics::UncompressNormal(uint16_t index, double& x, double& y, double& z)
{
    const auto mantissa = boost::numeric_cast<uint16_t>(index & 0x1FFF);

    const auto a = 8 * mantissa;
    auto temp = gsB2 - a;
    auto usY = boost::numeric_cast<uint16_t>(MathD::Floor(0.5 * (gsB - MathD::Sqrt(MathD::FAbs(temp)))));
    auto usX = boost::numeric_cast<uint16_t>(mantissa - ((usY * (255 - usY)) >> 1));

    x = usX * getInvFactor();
    y = usY * getInvFactor();
    temp = 1.0 - x * x - y * y;
    z = MathD::Sqrt(MathD::FAbs(temp));

    if (index & 0x8000)
    {
        x = -x;
    }
    if (index & 0x4000)
    {
        y = -y;
    }
    if (index & 0x2000)
    {
        z = -z;
    }
}