//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.1 (2020/09/04 11:13)

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
            : m_Matrix{ Mathematics::MatrixInitType::Identity }, m_IsIdentity{ true }, m_IsRotationOrScaleMatrix{ true }, m_IsUniformScale{ true }
        {
        }

        CLASS_INVARIANT_DECLARE;

        void MakeIdentity() noexcept;
        void MakeUnitScale(const Matrix& rotate) noexcept(g_Assert < 2 || g_RenderingAssert < 2);

        [[nodiscard]] bool IsIdentity() const noexcept;
        [[nodiscard]] bool IsRotationOrScaleMatrix() const noexcept;
        [[nodiscard]] bool IsUniformScale() const noexcept;

        void SetRotate(const Matrix& rotate, const APoint& scale) noexcept;
        void SetMatrix(const Matrix& matrix) noexcept;
        void SetTranslate(const APoint& translate) noexcept;
        void SetScale(const Matrix& rotate, const APoint& scale) noexcept(g_Assert < 2 || g_RenderingAssert < 2);
        void SetUniformScale(const Matrix& rotate, Real scale) noexcept(g_Assert < 2 || g_RenderingAssert < 2);

        [[nodiscard]] const Matrix GetMatrix() const noexcept;

        [[nodiscard]] int GetStreamingSize() const;

    private:
        void Modification(const APoint& translate) noexcept;
        void Modification(const Matrix& matrix) noexcept;
        void Modification(const Matrix& rotate, const APoint& scale) noexcept;

    private:
        Matrix m_Matrix;

        bool m_IsIdentity;
        bool m_IsRotationOrScaleMatrix;
        bool m_IsUniformScale;
    };
}

#endif  // RENDERING_DATA_TYPES_TRANSFORM_MATRIX_H
