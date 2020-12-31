///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/11 15:19)

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2D;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3D;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector4D;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2DOrthonormalize;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2DOrthonormalBasis;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3DOrthonormalize;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3DOrthonormalBasis;

    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox2D;

    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox3D;

    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox4D;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2DTools;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3DTools;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector4DTools;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2DInformation;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3DInformation;

    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE APoint;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AVectorOrthonormalize;

    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AVectorOrthonormalBasis;

    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AVector;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE VariableLengthVector;

    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Plane;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Polynomial;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE PolynomialDivide;

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE VariableMatrix;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE BandedMatrix;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE BandedMatrixSolve;

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

    template <typename Real>
    bool operator==(const Vector2D<Real>& lhs, const Vector2D<Real>& rhs);

    template <typename Real>
    bool operator<(const Vector2D<Real>& lhs, const Vector2D<Real>& rhs) noexcept;

    template <typename Real>
    bool operator==(const Vector3D<Real>& lhs, const Vector3D<Real>& rhs);

    template <typename Real>
    bool operator<(const Vector3D<Real>& lhs, const Vector3D<Real>& rhs);

    template <typename Real>
    bool operator==(const Vector4D<Real>& lhs, const Vector4D<Real>& rhs);

    template <typename Real>
    bool operator<(const Vector4D<Real>& lhs, const Vector4D<Real>& rhs);
}

#endif  // MATHEMATICS_ALGEBRA_FWD_H