///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/25 11:20)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_H

#include "Mathematics/MathematicsDll.h"

#include "SparseMatrix.h"
#include "Mathematics/Algebra/BandedMatrix.h"
#include "Mathematics/Algebra/VariableLengthVector.h"
#include "Mathematics/Algebra/VariableMatrix.h"
#include "Mathematics/Base/MathDetail.h"

#include <map>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE LinearSystem final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = LinearSystem<Real>;
        using Math = Math<Real>;
        using RealContainer = std::vector<Real>;
        using Vector2 = std::array<Real, 2>;
        using Matrix2 = std::array<Vector2, 2>;
        using Vector3 = std::array<Real, 3>;
        using Matrix3 = std::array<Vector3, 3>;
        using BandedMatrix = BandedMatrix<Real>;
        using SparseMatrix = SparseMatrix<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;

    public:
        explicit LinearSystem(Real zeroTolerance = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetZeroTolerance(Real zeroTolerance) noexcept;

        // 2��2��3x3ϵͳ�������˸�˹��Ԫ�Ŀ�����
        [[nodiscard]] Vector2 Solve2(const Matrix2& matrix, const Vector2& vector) const;

        [[nodiscard]] Vector3 Solve3(const Matrix3& matrix, const Vector3& vector) const;

        // ����:
        //     matrix[iSize][iSize], ���� matrix[row][col]
        // ���:
        //     �������ʧ���׳��쳣�����򷵻������
        [[nodiscard]] const VariableMatrix Inverse(const VariableMatrix& matrix) const;

        // ����:
        //     A[iSize][iSize] ϵ���������� A[row][col]
        //     B[iSize] ����, ���� B[row]
        // ���:
        //     �������ʧ���׳��쳣�����򷵻�X[iSize]��
        //     X[iSize] �ǽ�X �� AX = B

        // ���뱣֤����vector�����vector��СΪiSize��һά���顣
        [[nodiscard]] RealContainer Solve(const VariableMatrix& matrix, const RealContainer& vector) const;

        // ����:
        //     ���������ԽǾ���
        //     �¶Խ��� lower[size - 1]
        //     ���Խ��� main[size]
        //     �϶Խ��� upper[size - 1]
        //     ���ֱ� right[size]
        // ���:
        //     ���ʧ���׳��쳣�����򷵻�U[size]���ǽ⡣

        // ���뱣֤lower��upper��СΪsize - 1��һά���顣
        // main��right��output��СΪsize��һά���顣
        [[nodiscard]] RealContainer SolveTridiagonal(int size, const RealContainer& lower, const RealContainer& mainDdiagonal, const RealContainer& upper, const RealContainer& right) const;

        // ����:
        //     ���������ԽǾ���
        //     �¶Խ����ǳ���lower
        //     ���Խ����ǳ���main
        //     �϶Խ����ǳ���upper
        //     ���ֱ� right[size]
        // ���:
        //     ���ʧ���׳��쳣�����򷵻�U[size]���ǽ⡣

        // ���뱣֤right��output��СΪsize��һά���顣
        [[nodiscard]] RealContainer SolveConstTridiagonal(int size, Real lower, Real mainDdiagonal, Real upper, const RealContainer& right) const;

        // ����������ù����ݶȷ���
        // ����:
        //    A[size][size] Symmetrix�������� A[row][col]
        //    B[size] ����, ���� B[row]
        // ���:
        //    X[size] �ǽ� x Ϊ Ax = B

        // ���뱣֤inputVector��outputVectorΪ��СΪsize��һά���顣
        [[nodiscard]] RealContainer SolveSymmetricConjugateGradient(const VariableMatrix& matrix, const RealContainer& vector) const;

        // ϡ��Գƾ������ݶȷ���
        // ����:
        // ��Symmetrix����matrix�ķ�����Ŀ�洢��һ��ӳ�䣬�����(i,j)����ֵ��ʵ����
        // һ��(i,j)Ϊ���������е�ֵ��λ�á�
        // ֻ��(i,j) ��(j,i)Ӧ��ţ���Ϊmatrix�ǶԳƵġ�
        // �ô���ٶ���֪����ô����matrix.
        // ��ʸ��vector���洢Ϊ����ֵ�����顣
        // ���:
        //    X[size] �ǽ� x Ϊ Ax = B

        // ���뱣֤inputVector��outputVectorΪ��СΪsize��һά���顣
        [[nodiscard]] RealContainer SolveSymmetricConjugateGradient(const SparseMatrix& matrix, const RealContainer& vector) const;

        // ����״����ϵͳ��
        // ����:
        //     matrix, һ����״����
        //     vector[size] ����,���� vector[row]
        // ���:
        //     ���ʧ���׳��쳣��
        //     ����X[size] �ǽ� X �� AX = B

        // ���뱣֤inputVector��outputVectorΪ��СΪsize��һά���顣
        [[nodiscard]] RealContainer SolveBanded(const BandedMatrix& matrix, const RealContainer& vector) const;

        // ���״�������
        // ����:
        //     matrix, ��״����
        // ���:
        //     ����ʧ���׳��쳣�����򷵻������
        [[nodiscard]] const VariableMatrix Invert(const BandedMatrix& matrix) const;

    private:
        // ����ϵͳ����ݲ
        // Ĭ�� = Math<Real>::GetZeroTolerance()
        Real m_ZeroTolerance;
    };

    using FloatLinearSystem = LinearSystem<float>;
    using DoubleLinearSystem = LinearSystem<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_H
