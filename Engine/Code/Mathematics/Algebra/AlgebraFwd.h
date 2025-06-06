/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/27 19:28)

#ifndef MATHEMATICS_ALGEBRA_FWD_H
#define MATHEMATICS_ALGEBRA_FWD_H

#include "Mathematics/MathematicsDll.h"

#include <type_traits>

namespace Mathematics
{
    template <typename T>
    requires std::is_arithmetic_v<T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE HomogeneousPoint;

    template <typename Real, int WindowSize>
    requires std::is_arithmetic_v<Real> && (WindowSize == 3 || WindowSize == 4)
    class BarycentricCoordinates;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector4;

    template <typename Real, bool Robust>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2Orthonormalize;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2OrthonormalBasis;

    template <typename Real, bool Robust>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3Orthonormalize;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3OrthonormalBasis;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox2;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox3;

    template <typename T>
    requires std::is_arithmetic_v<T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox4;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2Tools;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3Tools;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector4Tools;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class Vector2Information;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class Vector3Information;

    template <typename T>
    requires std::is_arithmetic_v<T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE APoint;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AVectorOrthonormalize;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AVectorOrthonormalBasis;

    template <typename T>
    requires std::is_arithmetic_v<T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AVector;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class VariableLengthVector;

    template <typename T>
    requires std::is_arithmetic_v<T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Plane;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class Polynomial;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class PolynomialDivide;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix2;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix2EigenDecomposition;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix3;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxisAngle;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix3EigenDecomposition;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Tridiagonalize;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Euler;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix4;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class Matrix;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class VariableMatrix;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class BandedMatrix;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class BandedMatrixSolve;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Quaternion;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QuaternionFactor;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QuaternionConstraints;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QuaternionSwingTwist;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AQuaternion;

    template <typename Real>
    requires std::is_floating_point_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CylindricalCoordinates;

    template <typename Real>
    requires std::is_floating_point_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE SphereCoordinates;

    template <typename Real>
    requires std::is_floating_point_v<Real>
    class Transform;

    template <typename Real>
    requires std::is_floating_point_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE BoundingSphere;

    template <int N, typename Real>
    class ConvertCoordinates;

    namespace Algebra
    {
        template <int N, typename Real>
        requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
        class Vector;

        template <int NumRows, int NumColumns, typename Real>
        requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
        class Matrix;

        template <int N, typename Real>
        requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
        class AxisAngle;

        template <typename Real>
        requires(std::is_arithmetic_v<Real>)
        class EulerAngles;

        template <int N, typename Real>
        requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
        class Rotation;

        enum class RotationType;
    }

    enum class EulerResult;
    enum class ExtractEulerResultOrder;
    enum class MatrixInitType;
    enum class MatrixMajorFlags;
    enum class MatrixRotationAxis;
    enum class BandedMatrixSolveFlags;
    enum class QuaternionClosestAxis;
    enum class QuaternionFactorFlags;
}

#endif  // MATHEMATICS_ALGEBRA_FWD_H