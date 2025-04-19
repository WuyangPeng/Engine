/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/02/20 09:16)

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

        using APointType = APoint<Real>;
        using MatrixType = Matrix<Real>;

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

        void SetRotate(const MatrixType& rotate, const APointType& scale) noexcept;
        void SetMatrix(const MatrixType& matrix) noexcept;
        void SetTranslate(const APointType& translate) noexcept;
        void SetScale(const MatrixType& rotate, const APointType& scale);
        void SetUniformScale(const MatrixType& rotate, Real scale);

        NODISCARD MatrixType GetMatrix() const noexcept;

        NODISCARD int GetStreamingSize() const noexcept;

    private:
        /// ÿ�����matrix��translate��scale֮һ�����仯ʱ��
        /// ����дtransformMatrix����Ŀ��
        void Modification(const APointType& translate) noexcept;
        void Modification(const MatrixType& matrix) noexcept;
        void Modification(const MatrixType& rotate, const APointType& scale) noexcept;

    private:
        MatrixType transformMatrix;

        bool isIdentity;
        bool isRotationOrScaleMatrix;
        bool isUniformScale;
    };

}

#endif  // RENDERING_DATA_TYPES_TRANSFORM_MATRIX_H
