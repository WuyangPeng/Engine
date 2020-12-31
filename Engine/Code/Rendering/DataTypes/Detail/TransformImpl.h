//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.1 (2020/09/06 1:09)

#ifndef RENDERING_DATA_TYPES_TRANSFORM_IMPL_H
#define RENDERING_DATA_TYPES_TRANSFORM_IMPL_H

#include "Rendering/RenderingDll.h"

#include "TransformMatrixDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"

namespace Rendering
{
    template <typename Real>
    class TransformImpl
    {
    public:
        using ClassType = TransformImpl<Real>;
        using Math = Mathematics::Math<Real>;
        using APoint = Mathematics::APoint<Real>;
        using AVector = Mathematics::AVector<Real>;
        using Matrix = Mathematics::Matrix<Real>;

    public:
        TransformImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void MakeIdentity() noexcept;
        void MakeUnitScale() noexcept(g_Assert < 2 || g_RenderingAssert < 2);

        [[nodiscard]] bool IsIdentity() const noexcept;
        [[nodiscard]] bool IsRotationOrScaleMatrix() const noexcept;
        [[nodiscard]] bool IsUniformScale() const noexcept;

        void SetRotate(const Matrix& rotate) noexcept;
        void SetMatrix(const Matrix& matrix) noexcept;
        void SetTranslate(const APoint& translate) noexcept;
        void SetScale(const APoint& scale) noexcept(g_Assert < 2 || g_RenderingAssert < 2);
        void SetUniformScale(Real scale) noexcept(g_Assert < 2 || g_RenderingAssert < 2);
        [[nodiscard]] const Matrix GetRotate() const noexcept(g_Assert < 2 || g_RenderingAssert < 2);
        [[nodiscard]] const Matrix GetMatrix() const noexcept;
        [[nodiscard]] const APoint GetTranslate() const noexcept;
        [[nodiscard]] const APoint GetScale() const noexcept(g_Assert < 2 || g_RenderingAssert < 2);
        [[nodiscard]] Real GetUniformScale() const noexcept(g_Assert < 2 || g_RenderingAssert < 2);

        [[nodiscard]] Real GetNorm() const noexcept;

        [[nodiscard]] APoint operator*(const APoint& point) const noexcept;
        [[nodiscard]] AVector operator*(const AVector& vector) const noexcept;
        TransformImpl& operator*=(const TransformImpl& transform);

        [[nodiscard]] const Matrix GetHomogeneousMatrix() const noexcept;

        [[nodiscard]] const Matrix GetInverseMatrix(float epsilon = Math::GetZeroTolerance()) const;

        [[nodiscard]] const TransformImpl GetInverseTransform(float epsilon = Math::GetZeroTolerance()) const;

        [[nodiscard]] int GetStreamingSize() const noexcept;

    private:
        // 完整的4x4齐次矩阵H = {{M,T},{0,1}}和它的逆矩阵为H^{-1} = {M^{-1},-M^{-1}*T},{0,1}}。 逆矩阵只在需要时计算。
        TransformMatrix<Real> m_TransformMatrix;

        Matrix m_RotationOrGeneralMatrix;  // M (普通) or R (旋转)
        APoint m_Translate;  // T
        APoint m_Scale;  // S

        mutable Matrix m_InverseMatrix;
        mutable bool m_InverseNeedsUpdate;
    };

    template <typename Real>
    const TransformImpl<Real> operator*(const TransformImpl<Real>& lhs, const TransformImpl<Real>& rhs);
}

#endif  // RENDERING_DATA_TYPES_TRANSFORM_IMPL_H
