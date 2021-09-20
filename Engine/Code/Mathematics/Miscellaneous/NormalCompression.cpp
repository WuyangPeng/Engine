// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 13:35)

#include "Mathematics/MathematicsExport.h"

#include "NormalCompression.h"
#include "System/Helper/PragmaWarning.h"
#include "Mathematics/Base/MathDetail.h"
#include <gsl/narrow>
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26440)
static int gsN = 127;  // N(N+1)/2 = 8128 < 2^{13}
static auto temp1 = 2 * gsN + 1;
static double gsB = temp1;
static double gsB2 = gsB * gsB;
static auto temp2 = (gsN - 1);
static double gsFactor = temp2 * Mathematics::DoubleMath::Sqrt(0.5);
static double gsInvFactor = 1.0 / gsFactor;

void Mathematics ::CompressNormal(double x, double y, double z, unsigned short& index) noexcept
{
    // assert:  x*x + y*y + z*z = 1

    // Determine octant.
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

    // Determine mantissa.
    const unsigned short usX = gsl::narrow_cast<unsigned short>(DoubleMath::Floor(gsFactor * x));
    const unsigned short usY = gsl::narrow_cast<unsigned short>(DoubleMath::Floor(gsFactor * y));
    unsigned short mantissa = usX + ((usY * (255 - usY)) >> 1);
    index |= mantissa;
}

void Mathematics ::UncompressNormal(unsigned short index, double& x, double& y, double& z)
{
    const unsigned short mantissa = index & 0x1FFF;

    // Extract triangular indices.
    const auto a = 8 * mantissa;
    double temp = gsB2 - a;
    unsigned short usY = gsl::narrow_cast<unsigned short>(DoubleMath::Floor(0.5 * (gsB - DoubleMath::Sqrt(DoubleMath::FAbs(temp)))));
    unsigned short usX = mantissa - ((usY * (255 - usY)) >> 1);

    // Build approximate normal.
    x = usX * gsInvFactor;
    y = usY * gsInvFactor;
    temp = 1.0 - x * x - y * y;
    z = DoubleMath::Sqrt(DoubleMath::FAbs(temp));

    // Determine octant.
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

#include STSTEM_WARNING_POP