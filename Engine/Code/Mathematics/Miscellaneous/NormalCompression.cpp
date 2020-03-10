// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 13:35)

#include "Mathematics/MathematicsExport.h"

#include "NormalCompression.h"
#include "Mathematics/Base/MathDetail.h"

static int gsN = 127;  // N(N+1)/2 = 8128 < 2^{13}
static double gsB = 2*gsN + 1;
static double gsB2 = gsB*gsB;
static double gsFactor = (gsN - 1)*Mathematics::Mathd::Sqrt(0.5);
static double gsInvFactor = 1.0/gsFactor;


void Mathematics
	::CompressNormal (double x, double y, double z,unsigned short& index)
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
    unsigned short usX = (unsigned short) Mathd::Floor(gsFactor*x);
    unsigned short usY = (unsigned short) Mathd::Floor(gsFactor*y);
    unsigned short mantissa = usX + ((usY*(255-usY)) >> 1);
    index |= mantissa;
}

void Mathematics
	::UncompressNormal (unsigned short index, double& x, double& y, double& z)
{
    unsigned short mantissa = index & 0x1FFF;

    // Extract triangular indices.
    double temp = gsB2 - 8*mantissa;
    unsigned short usY = (unsigned short) Mathd::Floor(0.5*(gsB - Mathd::Sqrt(Mathd::FAbs(temp))));
    unsigned short usX = mantissa - ((usY*(255 - usY)) >> 1);

    // Build approximate normal.
    x = usX*gsInvFactor;
    y = usY*gsInvFactor;
    temp = 1.0 - x*x - y*y;
    z = Mathd::Sqrt(Mathd::FAbs(temp));

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

