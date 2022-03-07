// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 13:27)

#ifndef MATHEMATICS_MISCELLANEOUS_NORMAL_COMPRESSION_H
#define MATHEMATICS_MISCELLANEOUS_NORMAL_COMPRESSION_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    // Compress unit-length normal vectors (x,y,z) to 16-bit quantities.  3 bits
    // are used to identify the octant containing the vector, the other 13 bits
    // are used for the mantissa.

     void CompressNormal(double x, double y, double z, unsigned short& index);

     void UncompressNormal(unsigned short index, double& x, double& y, double& z);

    // An example of how to use the compression.  This shows the maximum error is
    // about 10-degrees between the original and the compressed-then-uncompressed
    // vector.
    //
    //void TestCompression ()
    //{
    //    const int numSamples = 1024;
    //    double dotMin = 1.0;
    //    int xmin = numSamples, yMin = numSamples;
    //
    //    for (int y = 0; y < numSamples; ++y)
    //    {
    //        double y0 = y/(double)numSamples;
    //        for (int x = 0; x < numSamples; ++x)
    //        {
    //            double x0 = x/(double)numSamples;
    //            double z0 = 1.0 - x0*x0 - y0*yY0;
    //            if (z0 >= 0.0)
    //            {
    //                z0 = sqrt(z0);
    //
    //                unsigned short index;
    //                CompressNormal(x0, y0, z0, index);
    //                assert(index < 8192);
    //
    //                double x1, y1, z1;
    //                UncompressNormal(index, x1, y1, z1);
    //
    //                double dot = x0*x1 + y0*y1 + z0*z1;
    //                if (dot < dotMin)
    //                {
    //                    dotMin = dot;
    //                    xmin = x;
    //                    yMin = y;
    //                }
    //            }
    //        }
    //    }
    //
    //    // S = 16384, dotmin = 0.98474228151906 (about 10-degrees error)
    //}
}

#endif  // MATHEMATICS_MISCELLANEOUS_NORMAL_COMPRESSION_H
