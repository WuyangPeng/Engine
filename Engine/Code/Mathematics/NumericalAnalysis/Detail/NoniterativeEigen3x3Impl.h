///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/26 17:12)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_IMPL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/Algebra/Vector3D.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_HIDDEN_DECLARE NoniterativeEigen3x3Impl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = NoniterativeEigen3x3Impl<Real>;
        using Math = Math<Real>;
        using Matrix3 = Matrix3<Real>;
        using Vector3D = Vector3D<Real>;
        using Vector3DTools = Vector3DTools<Real>;

    public:
        // �����������ǶԳƵġ�
        explicit NoniterativeEigen3x3Impl(const Matrix3& matrix);

        CLASS_INVARIANT_DECLARE;

        // �õ���������������ֵ�Ե�����˳��洢��
        [[nodiscard]] Real GetEigenvalue(int index) const;
        [[nodiscard]] const Vector3D GetEigenvector(int index) const;

    private:
        [[nodiscard]] Real GetMaxValue(const Matrix3& matrix) const;
        void Compute(const Matrix3& matrix);
        void RescaleBack(Real maxValue) noexcept;

        // �������ζ���ʽ�ĸ���˫�������㱻ʹ����������С����Ӱ�����������������˳�򷵻ء�
        void ComputeRoots(const Matrix3& matrix);

        // ȷ��matrix�Ƿ��е������С�����matrix�������ֵ��Ŀ��
        // ����������Ҳ�����ء�
        [[nodiscard]] bool PositiveRank(Matrix3& matrix, Real& maxEntry, Vector3D& maxRow) const;

        // ��������������
        void ComputeVectors(const Matrix3& matrix, const Vector3D& vector, int index0, int index1, int index2);

    private:
        static constexpr auto sm_EigenMax = 3;

        using EigenValueType = std::array<Real, sm_EigenMax>;
        using EigenVectorType = std::array<Vector3D, sm_EigenMax>;
        using Container = std::vector<Real>;

        EigenValueType m_Eigenvalue;
        EigenVectorType m_Eigenvector;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_IMPL_H
