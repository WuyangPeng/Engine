/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/02/23 09:19)

#ifndef MATHEMATICS_PRIMITIVES_ALIGNED_BOX_H
#define MATHEMATICS_PRIMITIVES_ALIGNED_BOX_H

#include "Mathematics/MathematicsDll.h"

#include "AlignedBoxCentered.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector/Vector.h"

/// �ÿ����׼��������룬��ʹ�����ܹ�ʹ����ÿ�������Сֵ�����ֵ����ʾ����
/// һЩ�㷨��ϲ�����ڶ����ľ��б�ʾ��
/// ����ΪC����ΧΪÿ�������᷽���ϵ�һ�볤�ȡ�
namespace Mathematics
{
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class AlignedBox
    {
    public:
        using ClassType = AlignedBox<N, Real>;

        using MathType = Math<Real>;
        using Vector = Algebra::Vector<N, Real>;
        using AlignedBoxCenteredType = AlignedBoxCentered<N, Real>;
        using VerticesType = std::array<Vector, (1 << N)>;

    public:
        /// Ĭ�Ϲ��캯������Сֵ����Ϊ-1�������ֵ����Ϊ+1��
        AlignedBox() noexcept requires(N == 2);
        AlignedBox() noexcept requires(N == 3);

        /// ��ȷ������i��inMin[i] <= inMax[i]��
        AlignedBox(const Vector& inMin, const Vector& inMax);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector GetMin() const noexcept;
        NODISCARD Vector GetMax() const noexcept;

        void Set(const Vector& aMin, const Vector& aMax);

        /// ������б�ʾ��
        /// ע�⣺���������Сֵ�����ֵ������C�ͷ�Χ��
        /// Ȼ�����¼�����Сֵ�����ֵ������ֵ���������ܻᵼ���뿪ʼʱ��ͬ�Ľ����
        NODISCARD AlignedBoxCenteredType GetCenteredForm() const;

        /// ���㳤����Ķ��㡣
        /// �������i���б���ģʽi = b[N-1]...b[0]��������i���Ľ���vertex[i]��
        /// ���е�b[d] = 0ʱ����vertex[i][d] = min[d] ��
        /// ���ߵ�b[d] = 1ʱ����vertex[i][d] = max[d]��
        NODISCARD VerticesType GetVertices() const;

    private:
        /// Ҫ��min[i] <= max[i]��
        Vector min;
        Vector max;
    };

    /// ��֧�����������ıȽϡ�
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator==(const AlignedBox<N, Real>& lhs, const AlignedBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator!=(const AlignedBox<N, Real>& lhs, const AlignedBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<(const AlignedBox<N, Real>& lhs, const AlignedBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<=(const AlignedBox<N, Real>& lhs, const AlignedBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>(const AlignedBox<N, Real>& lhs, const AlignedBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>=(const AlignedBox<N, Real>& lhs, const AlignedBox<N, Real>& rhs);

    /// Ϊ�����������ʹ��ģ�������
    template <typename T>
    using AlignedBox2 = AlignedBox<2, T>;

    template <typename T>
    using AlignedBox3 = AlignedBox<3, T>;
}

#endif  // MATHEMATICS_OBJECTS_3D_BOX3_H
