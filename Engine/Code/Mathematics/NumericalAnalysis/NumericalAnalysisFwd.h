///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 11:39)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_FWD_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_FWD_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    template <typename Real>
    class BandedMatrixInvert;

    template <typename ResultConstIter>
    class EquationResultConstIterator;

    class Equation;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Bisect1Root;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Bisect1;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Bisect2Root;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Bisect2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Bisect3Root;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Bisect3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE BrentsMethodRoot;

    template <typename Real, typename UserDataType>
    class BrentsMethodCalculate;

    template <typename Real, typename UserDataType>
    class BrentsMethod;

    template <typename Real>
    class EigenDecomposition;

    template <typename Real, typename UserDataType>
    class GaussianQuadrature;

    class SparseMatrixIndex;

    template <typename Real>
    class SparseMatrix;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE LinearSystem;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Minimize1Data;

    template <typename Real, typename UserDataType>
    class Minimize1;

    template <typename Real>
    class MinimizeNData;

    template <typename Real, typename UserDataType>
    class MinimizeN;

    template <typename Real, typename UserDataType>
    class MinimizeNGetMinimum;

    template <typename Real>
    class NoniterativeEigen3x3;

    template <typename Real, typename UserDataType>
    class OdeSolver;

    template <typename Real, typename UserDataType>
    class OdeEuler;

    template <typename Real, typename UserDataType>
    class OdeImplicitEuler;

    template <typename Real, typename UserDataType>
    class OdeMidpoint;

    template <typename Real, typename UserDataType>
    class OdeRungeKutta4;

    template <typename Real>
    class PolynomialRoots;

    template <typename Real>
    class PolynomialRootsRational;

    template <typename Real, typename UserDataType>
    class RombergIntegral;

    template <typename Real, typename UserDataType>
    class TrapezoidRule;

    template <typename Real>
    class SingularValueDecomposition;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix3Tools;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE SingularValue;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE PolarDecompositionValue;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QDUDecompositionValue;

    enum class Bisect2StorageType;
    enum class Bisect3StorageType;
    enum class QuantityType;
    enum class BisectRootType;
    enum class BrentsMethodRootType;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_FWD_H