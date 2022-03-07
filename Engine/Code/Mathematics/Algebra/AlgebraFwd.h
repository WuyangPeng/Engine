///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/01/29 13:53)

#ifndef MATHEMATICS_ALGEBRA_FWD_H
#define MATHEMATICS_ALGEBRA_FWD_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE HomogeneousPoint;

    template <typename Real, int WindowSize>
    class BarycentricCoordinates;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector4;

    template <typename Real, bool Robust>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2Orthonormalize;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2OrthonormalBasis;

    template <typename Real, bool Robust>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3Orthonormalize;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3OrthonormalBasis;

    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox2;

    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox3;

    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox4;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2Tools;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3Tools;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector4Tools;

    template <typename Real>
    class Vector2Information;

    template <typename Real>
    class Vector3Information;

    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE APoint;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AVectorOrthonormalize;

    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AVectorOrthonormalBasis;

    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AVector;

    template <typename Real>
    class VariableLengthVector;

    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Plane;

    template <typename Real>
    class Polynomial;

    template <typename Real>
    class PolynomialDivide;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix2EigenDecomposition;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix3Extract;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix3EigenDecomposition;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Tridiagonalize;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Euler;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix4;

    template <typename Real>
    class Matrix;

    template <typename Real>
    class VariableMatrix;

    template <typename Real>
    class BandedMatrix;

    template <typename Real>
    class BandedMatrixSolve;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Quaternion;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QuaternionFactor;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QuaternionConstraints;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QuaternionSwingTwist;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AQuaternion;

    enum class ExtractEulerResultType;
    enum class ExtractEulerResultOrder;
    enum class MatrixInitType;
    enum class MatrixMajorFlags;
    enum class MatrixRotationAxis;
    enum class BandedMatrixSolveFlags;
    enum class QuaternionClosestAxis;
    enum class QuaternionFactorFlags;
}

#endif  // MATHEMATICS_ALGEBRA_FWD_H