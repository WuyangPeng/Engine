///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/29 16:55)

#ifndef RENDERING_DATA_TYPES_TRANSFORM_MATRIX_H
#define RENDERING_DATA_TYPES_TRANSFORM_MATRIX_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Matrix.h"

namespace Rendering
{
    template <typename Real>
    class TransformMatrix
    {
    public:
        using ClassType = TransformMatrix<Real>;
        using APoint = Mathematics::APoint<Real>;
        using Matrix = Mathematics::Matrix<Real>;

    public:
        constexpr TransformMatrix() noexcept
            : transformMatrix{ Mathematics::MatrixInitType::Identity }, isIdentity{ true }, isRotationOrScaleMatrix{ true }, isUniformScale{ true }
        {
        }

        CLASS_INVARIANT_DECLARE;

        void MakeIdentity() noexcept;
        void MakeUnitScale(const Matrix& rotate) noexcept(gAssert < 2 || gRenderingAssert < 2);

        NODISCARD bool IsIdentity() const noexcept;
        NODISCARD bool IsRotationOrScaleMatrix() const noexcept;
        NODISCARD bool IsUniformScale() const noexcept;

        void SetRotate(const Matrix& rotate, const APoint& scale) noexcept;
        void SetMatrix(const Matrix& matrix) noexcept;
        void SetTranslate(const APoint& translate) noexcept;
        void SetScale(const Matrix& rotate, const APoint& scale) noexcept(gAssert < 2 || gRenderingAssert < 2);
        void SetUniformScale(const Matrix& rotate, Real scale) noexcept(gAssert < 2 || gRenderingAssert < 2);

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
