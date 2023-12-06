/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/28 19:51)

#ifndef RENDERING_DATA_TYPES_AFFINE_MATRIX_H
#define RENDERING_DATA_TYPES_AFFINE_MATRIX_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Matrix.h"

namespace Mathematics
{
    template <typename Real>
    class AffineMatrix
    {
    public:
        using ClassType = AffineMatrix<Real>;

        using Math = Math<Real>;
        using APoint = APoint<Real>;
        using Matrix = Matrix<Real>;

    public:
        AffineMatrix() noexcept;
        explicit AffineMatrix(Real scale) noexcept;
        AffineMatrix(Real s0, Real s1, Real s2) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 设置转换为单位矩阵。
        void MakeIdentity() noexcept;

        // 设置转换的缩放值为1。
        void MakeUnitScale() noexcept;

        NODISCARD Matrix GetRotationOrGeneralMatrix() const noexcept;
        NODISCARD APoint GetTranslate() const noexcept;
        NODISCARD APoint GetScale() const noexcept;
        void SetRotationOrGeneralMatrix(const Matrix& aRotationOrGeneralMatrix) noexcept;
        void SetTranslate(const APoint& aTranslate) noexcept;
        void SetScale(const APoint& aScale) noexcept;

    private:
        Matrix rotationOrGeneralMatrix;  // M (普通) or R (旋转)
        APoint translate;  // T
        APoint scale;  // S
    };
}

#endif  // RENDERING_DATA_TYPES_AFFINE_MATRIX_H
