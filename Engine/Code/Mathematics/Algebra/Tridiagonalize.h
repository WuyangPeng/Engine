///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 15:02)

#ifndef MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_H
#define MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "Matrix3.h"
#include "Vector2.h"
#include "Vector3.h"

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Tridiagonalize final
    {
    public:
        using ClassType = Tridiagonalize<Real>;

        using MathType = Math<Real>;
        using Matrix3Type = Matrix3<Real>;
        using Vector2Type = Vector2<Real>;
        using Vector3Type = Vector3<Real>;

    public:
        explicit Tridiagonalize(const Matrix3Type& matrix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsReflection() const noexcept;
        NODISCARD Matrix3Type GetRotation() const noexcept;
        NODISCARD Vector3Type GetDiagonal() const noexcept;

    private:
        // ֧�������ֽ⡣��Tridiagonalize�����ɽ�Householder�任����
        // �������ת����identity�������Ѿ���tridiagonal�����򷵻�ֵ��'false'��
        // ����ת����һ������ͷ���ֵ��'true'��
        // QLAlgorithm���ء�true�����ҽ���QL��������������
        void Init();
        NODISCARD bool QLAlgorithm();
        NODISCARD static bool IsValueNear(Real subDiagonal, Real lhsDiagonal, Real rhsDiagonal) noexcept;
        void UpdateDiagonal(int lhsIndex, int rhsIndex);
        void GivensRotation(int lhsIndex, int rhsIndex, Real cosValue, Real sinValue);

    private:
        Matrix3Type inputMatrix;
        Matrix3Type outputMatrix;
        Vector3Type diagonal;
        Vector2Type subDiagonal;
        bool reflection;
    };
}

#endif  // MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_H
