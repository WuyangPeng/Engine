/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/29 15:30)

#ifndef RENDERING_DATA_TYPES_TRANSFORM_MATRIX_H
#define RENDERING_DATA_TYPES_TRANSFORM_MATRIX_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Matrix.h"

namespace Mathematics
{
    template <typename Real>
    class TransformMatrix
    {
    public:
        using ClassType = TransformMatrix<Real>;

        using APoint = APoint<Real>;
        using Matrix = Matrix<Real>;

    public:
        TransformMatrix() noexcept;
        explicit TransformMatrix(Real scale) noexcept;
        TransformMatrix(Real s0, Real s1, Real s2) noexcept;

        CLASS_INVARIANT_DECLARE;

        void MakeIdentity() noexcept;
        void MakeUnitScale();

        NODISCARD bool IsIdentity() const noexcept;
        NODISCARD bool IsRotationOrScaleMatrix() const noexcept;
        NODISCARD bool IsUniformScale() const noexcept;

        void SetRotate(const Matrix& rotate, const APoint& scale) noexcept;
        void SetMatrix(const Matrix& matrix) noexcept;
        void SetTranslate(const APoint& translate) noexcept;
        void SetScale(const Matrix& rotate, const APoint& scale);
        void SetUniformScale(const Matrix& rotate, Real scale);

        NODISCARD Matrix GetMatrix() const noexcept;

        NODISCARD int GetStreamingSize() const noexcept;

    private:
        void Modification(const APoint& translate) noexcept;
        void Modification(const Matrix& matrix) noexcept;
        void Modification(const Matrix& rotate, const APoint& scale) noexcept;

    private:
        Matrix transformMatrix;

        bool isIdentity;
        bool isRotationOrScaleMatrix;
        bool isUniformScale;
    };

}

#endif  // RENDERING_DATA_TYPES_TRANSFORM_MATRIX_H
