///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/18 20:43)

#ifndef MATHEMATICS_INTERPOLATION_FWD_H
#define MATHEMATICS_INTERPOLATION_FWD_H

namespace Mathematics
{
    template <typename Real>
    class IntpAkima1;

    template <typename Real>
    class IntpAkimaNonuniform1;

    template <typename Real>
    class IntpAkimaUniform1;

    template <typename Real>
    class IntpAkimaUniform2;

    template <typename Real>
    class IntpAkimaUniform3;

    template <typename Real>
    class IntpBicubic2;

    template <typename Real>
    class IntpBilinear2;

    template <typename Real>
    class IntpBSplineUniform;

    template <typename Real>
    class IntpBSplineUniform1;

    template <typename Real>
    class IntpBSplineUniform2;

    template <typename Real>
    class IntpBSplineUniform3;

    template <typename Real>
    class IntpBSplineUniform4;

    template <typename Real>
    class IntpLinearNonuniform2;

    template <typename Real>
    class IntpLinearNonuniform3;

    template <typename Real>
    class IntpQdrNonuniform2;

    template <typename Real>
    class IntpSphere2;

    template <typename Real>
    class IntpTrilinear3;

    template <typename Real>
    class IntpVectorField2;
}

#endif  // MATHEMATICS_INTERPOLATION_FWD_H