/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:44)

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

    namespace Algebra
    {
        template <typename Real>
        requires(std::is_arithmetic_v<Real>)
        class SingularValueDecomposition;

        template <typename Real>
        requires(std::is_arithmetic_v<Real>)
        class SingularInfo;

        template <typename Real>
        requires(std::is_arithmetic_v<Real>)
        class GivensRotation;

        template <typename T>
        class Minimize1;

        template <typename T>
        class MinimizeN;

        template <typename Real, typename TVector>
        class OdeSolver;

        template <typename Real, typename UserDataType>
        class OdeEuler;

        template <typename Real, typename TVector, typename TMatrix>
        class OdeImplicitEuler;

        template <typename Real, typename TVector>
        class OdeMidpoint;

        template <typename Real, typename TVector>
        class OdeRungeKutta4;

        template <typename Real>
        class PolynomialRoot;
    }

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class SymmetricEigensolver;

    template <typename Real, int N>
    requires(std::is_arithmetic_v<Real> && 0 <= N)
    class CholeskyDecomposition;

    template <typename Real, int BlockSize, int NumBlocks>
    requires(std::is_arithmetic_v<Real> && 0 <= BlockSize && 0 <= NumBlocks)
    class BlockCholeskyDecomposition;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class CubicRootsQr;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class GaussNewtonMinimizer;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class GaussNewtonMinimizerResult;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class Integration;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class RootsPolynomial;

    template <typename Real, int... Dimensions>
    requires(std::is_arithmetic_v<Real>)
    class LinearComplementarityProblemSolver;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class LinearComplementarityProblemSolverShared;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class LinearComplementarityProblemSolverVariable;

    template <typename T, int...>
    class LdltDecomposition;

    template <typename T>
    class LevenbergMarquardtMinimizer;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class QuarticRootsQr;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class RootsBisection;

    template <typename Real>
    class RootsBisection1;

    template <typename Real>
    class RootsBisection2;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class RootsBrentsMethod;

    template <typename T>
    class RootsCubic;

    template <typename T>
    class RootsLinear;

    template <typename T>
    class RootsQuadratic;

    enum class Bisect2StorageType;
    enum class Bisect3StorageType;
    enum class QuantityType;
    enum class BisectRootType;
    enum class BrentsMethodRootType;
    enum class LinearComplementarityProblemSolverType;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_FWD_H