/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/02/20 09:16)

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

        // ����ת��Ϊ��λ����
        void MakeIdentity() noexcept;

        // ����ת��������ֵΪ1��
        void MakeUnitScale() noexcept;

        NODISCARD MatrixType GetRotationOrGeneralMatrix() const noexcept;
        NODISCARD APointType GetTranslate() const noexcept;
        NODISCARD APointType GetScale() const noexcept;
        void SetRotationOrGeneralMatrix(const MatrixType& aRotationOrGeneralMatrix) noexcept;
        void SetTranslate(const APointType& aTranslate) noexcept;
        void SetScale(const APointType& aScale) noexcept;

    private:
        MatrixType rotationOrGeneralMatrix;  // M (��ͨ) or R (��ת)
        APointType translate;  // T
        APointType scale;  // S
    };
}

#endif  // RENDERING_DATA_TYPES_AFFINE_MATRIX_H
