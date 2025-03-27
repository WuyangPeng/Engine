/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/20 09:16)

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

        using MathType = Math<Real>;
        using APointType = APoint<Real>;
        using MatrixType = Matrix<Real>;

    public:
        AffineMatrix() noexcept;
        explicit AffineMatrix(Real scale) noexcept;
        AffineMatrix(Real s0, Real s1, Real s2) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 设置转换为单位矩阵。
        void MakeIdentity() noexcept;

        // 设置转换的缩放值为1。
        void MakeUnitScale() noexcept;

        NODISCARD MatrixType GetRotationOrGeneralMatrix() const noexcept;
        NODISCARD APointType GetTranslate() const noexcept;
        NODISCARD APointType GetScale() const noexcept;
        void SetRotationOrGeneralMatrix(const MatrixType& aRotationOrGeneralMatrix) noexcept;
        void SetTranslate(const APointType& aTranslate) noexcept;
        void SetScale(const APointType& aScale) noexcept;

    private:
        MatrixType rotationOrGeneralMatrix;  // M (普通) or R (旋转)
        APointType translate;  // T
        APointType scale;  // S
    };
}

#endif  // RENDERING_DATA_TYPES_AFFINE_MATRIX_H
