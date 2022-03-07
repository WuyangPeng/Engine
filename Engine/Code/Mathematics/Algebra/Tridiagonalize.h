///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/07 16:56)

#ifndef MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_H
#define MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "Matrix3.h"
#include "Vector2.h"
#include "Vector3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Tridiagonalize final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Tridiagonalize<Real>;
        using Math = Math<Real>;
        using Matrix3 = Matrix3<Real>;
        using Vector2 = Vector2<Real>;
        using Vector3 = Vector3<Real>;

    public:
        explicit Tridiagonalize(const Matrix3& matrix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsReflection() const noexcept;
        NODISCARD Matrix3 GetRotation() const noexcept;
        NODISCARD Vector3 GetDiagonal() const noexcept;

    private:
        // ֧�������ֽ⡣��Tridiagonalize�����ɽ�Householder�任����
        // �������ת����identity�������Ѿ���tridiagonal�����򷵻�ֵ��'false'��
        // ����ת����һ������ͷ���ֵ��'true'��
        // QLAlgorithm���ء�true�����ҽ���QL��������������
        void Init();
        NODISCARD bool QLAlgorithm();
        NODISCARD static bool IsValueNear(Real subdiagonal, Real lhsDiagonal, Real rhsDiagonal) noexcept;
        void UpdateDiagonal(int lhsIndex, int rhsIndex);
        void GivensRotation(int lhsIndex, int rhsIndex, Real cosValue, Real sinValue);

    private:
        Matrix3 inputMatrix;
        Matrix3 outputMatrix;
        Vector3 diagonal;
        Vector2 subdiagonal;
        bool reflection;
    };
}

#endif  // MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_H
