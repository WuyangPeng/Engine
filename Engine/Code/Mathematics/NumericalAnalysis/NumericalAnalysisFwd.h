///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 13:53)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_FWD_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_FWD_H

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE BandedMatrixInvert;

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE EigenDecomposition;

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

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE NoniterativeEigen3x3;

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE PolynomialRoots;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE PolynomialRootsRational;

    template <typename Real, typename UserDataType>
    class RombergIntegral;

    template <typename Real, typename UserDataType>
    class TrapezoidRule;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE SingularValueDecomposition;

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