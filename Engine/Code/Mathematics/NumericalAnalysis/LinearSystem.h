/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 13:45)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_H

#include "Mathematics/MathematicsDll.h"

#include "SparseMatrix.h"
#include "CoreTools/MemoryTools/LexicoArray2.h"
#include "Mathematics/Algebra/BandedMatrix.h"
#include "Mathematics/Algebra/Matrix/Matrix2x2.h"
#include "Mathematics/Algebra/Matrix/Matrix3x3.h"
#include "Mathematics/Algebra/Matrix/Matrix4x4.h"
#include "Mathematics/Algebra/VariableLengthVector.h"
#include "Mathematics/Algebra/VariableMatrix.h"
#include "Mathematics/Algebra/Vector/Vector2.h"
#include "Mathematics/Base/MathDetail.h"

/// ������AΪNxN�����Է����顣
/// ��a����ʱ�������ķ���ֵΪ��true����
/// ����������£��������X�ͽ����������Ч�ġ�
/// �������ֵΪ'false'����A�����棬X��Y��Ч����˲�Ҫʹ�����ǡ�
/// �����󱻴���ΪReal*ʱ���洢˳�򱻼ٶ�Ϊ����ѡ���MATHEMATICS_USE_ROW_MAJOR��!MATHEMATICS_USE_ROW_MAJORһ�¡�
//
/// ʹ�ù����ݶ��㷨���������������G.H.Golub��Charles F.Van Loan�ڡ�������㣬�ڶ��桱�е����ۣ�
/// Լ�����ս�˹�����磬�Ͷ���ĦҽѧԺ��1993����İ档
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
        using Vector3Type = std::array<Real, 3>;
        using Matrix3 = std::array<Vector3Type, 3>;
        using BandedMatrix = BandedMatrix<Real>;
        using SparseMatrix = SparseMatrix<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;

        using Matrix2x2 = Algebra::Matrix2x2<Real>;
        using Matrix3x3 = Algebra::Matrix3x3<Real>;
        using Matrix4x4 = Algebra::Matrix4x4<Real>;
        using AlgebraVector2 = Algebra::Vector2<Real>;
        using AlgebraVector3 = Algebra::Vector3<Real>;
        using AlgebraVector4 = Algebra::Vector4<Real>;
        using AlgebraSparseMatrix = std::map<std::array<int, 2>, Real>;

    public:
        explicit LinearSystem(Real zeroTolerance = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetZeroTolerance(Real newZeroTolerance) noexcept;

        // 2��2��3x3ϵͳ�������˸�˹��Ԫ�Ŀ�����
        NODISCARD Vector2 Solve2(const Matrix2& matrix, const Vector2& vector) const;

        NODISCARD Vector3Type Solve3(const Matrix3& matrix, const Vector3Type& vector) const;

        // ����:
        //     matrix[iSize][iSize], ���� matrix[row][col]
        // ���:
        //     �������ʧ���׳��쳣�����򷵻������
        NODISCARD VariableMatrix Inverse(const VariableMatrix& matrix) const;

        // ����:
        //     A[iSize][iSize] ϵ���������� A[row][col]
        //     B[iSize] ����, ���� B[row]
        // ���:
        //     �������ʧ���׳��쳣�����򷵻�X[iSize]��
        //     X[iSize] �ǽ�X �� AX = B

        // ���뱣֤����vector�����vector��СΪiSize��һά���顣
        NODISCARD RealContainer Solve(const VariableMatrix& matrix, const RealContainer& vector) const;

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
        NODISCARD RealContainer SolveTriDiagonal(int size, const RealContainer& lower, const RealContainer& mainDdiagonal, const RealContainer& upper, const RealContainer& right) const;

        // ����:
        //     ���������ԽǾ���
        //     �¶Խ����ǳ���lower
        //     ���Խ����ǳ���main
        //     �϶Խ����ǳ���upper
        //     ���ֱ� right[size]
        // ���:
        //     ���ʧ���׳��쳣�����򷵻�U[size]���ǽ⡣

        // ���뱣֤right��output��СΪsize��һά���顣
        NODISCARD RealContainer SolveConstTridiagonal(int size, Real lower, Real mainDdiagonal, Real upper, const RealContainer& right) const;

        // ����������ù����ݶȷ���
        // ����:
        //    A[size][size] Symmetrix�������� A[row][col]
        //    B[size] ����, ���� B[row]
        // ���:
        //    X[size] �ǽ� x Ϊ Ax = B

        // ���뱣֤inputVector��outputVectorΪ��СΪsize��һά���顣
        NODISCARD RealContainer SolveSymmetricConjugateGradient(const VariableMatrix& matrix, const RealContainer& vector) const;

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
        NODISCARD RealContainer SolveSymmetricConjugateGradient(const SparseMatrix& matrix, const RealContainer& vector) const;

        // ����״����ϵͳ��
        // ����:
        //     matrix, һ����״����
        //     vector[size] ����,���� vector[row]
        // ���:
        //     ���ʧ���׳��쳣��
        //     ����X[size] �ǽ� X �� AX = B

        // ���뱣֤inputVector��outputVectorΪ��СΪsize��һά���顣
        NODISCARD RealContainer SolveBanded(const BandedMatrix& matrix, const RealContainer& vector) const;

        // ���״�������
        // ����:
        //     matrix, ��״����
        // ���:
        //     ����ʧ���׳��쳣�����򷵻������
        NODISCARD VariableMatrix Invert(const BandedMatrix& matrix) const;

        /// ͨ��ֱ�ӷ�ת���������2x2��3x3��4x4ϵͳ��
        /// ���������Сά���и�˹�����Ŀ�����
        NODISCARD static bool Solve(const Matrix2x2& a, const AlgebraVector2& b, AlgebraVector2& x);

        NODISCARD static bool Solve(const Matrix3x3& a, const AlgebraVector3& b, AlgebraVector3& x);

        NODISCARD static bool Solve(const Matrix4x4& a, const AlgebraVector4& b, AlgebraVector4& x);

        /// ���A*X = B������BΪNx1����XΪNx1��
        NODISCARD static bool Solve(int n, const RealContainer& a, const RealContainer& b, RealContainer& x);

        /// ���A*X = B������BΪNxM����XΪNxM��
        NODISCARD static bool Solve(int n, int m, const RealContainer& a, const RealContainer& b, RealContainer& x);

        /// ���A*X = B������A�����Խǵġ�
        /// ������ҪA�ĴζԽ��ߡ��Խ��ߺͳ��Խ��ߡ�
        /// �Խ������������N��Ԫ�ء�
        /// �ζԽ��ߺͳ��Խ�������������N-1��Ԫ�ء�
        NODISCARD static bool SolveTriDiagonal(int n, const RealContainer& subDiagonal, const RealContainer& diagonal, const RealContainer& superDiagonal, const RealContainer& b, RealContainer& x);

        /// ���A*X = B������A�����Խǵġ�
        /// �ú�������A��subDiagonal���Խ��ߺ�superDiagonal��
        /// ���⣬subDiagonalԪ���ǳ������Խ���Ԫ���ǳ�����superDiagonalԪ���ǳ�����
        NODISCARD static bool SolveConstantTriDiagonal(int n, Real subDiagonal, Real diagonal, Real superDiagonal, const RealContainer& b, RealContainer& x);

        /// ʹ�ù����ݶȷ����A*X=B������A�ǶԳƵġ�
        /// ������ָ������������������ֹ�������ݲ
        /// ����ĺ���ѡ����1e-06f ��ʾ 'float��1e-08 ��ʾ 'double'
        NODISCARD static int SolveSymmetricConjugateGradient(int n, RealContainer& a, const RealContainer& b, RealContainer& x, int maxIterations, Real tolerance);

        /// ʹ�ù����ݶȷ����A*X = B������A��ϡ��ͶԳƵġ�
        /// �Գƾ���A�ķ�����洢��ӳ���У���ӳ��ļ��Ƕ�(i,j)��
        /// ������ֵ��ʵ������(i,j)��ֵ�������е�λ�á�
        /// ����A�ǶԳƵģ����ֻӦ�洢(i,j)��(j,i) �е�һ����
        /// ������B���洢Ϊ����ֵ�����顣
        /// ������ָ������������������ֹ�������ݲ
        /// ����ĺ���ѡ����1e-06f ��ʾ 'float��1e-08 ��ʾ 'double'
        NODISCARD static int SolveSymmetricConjugateGradient(int n, const AlgebraSparseMatrix& a, const RealContainer& b, RealContainer& x, int maxIterations, Real tolerance);

#if defined(MATHEMATICS_USE_ROW_MAJOR)

        using LexicoArray2 = CoreTools::LexicoArray2<true, typename RealContainer::iterator>;

#else  // !MATHEMATICS_USE_ROW_MAJOR

        using LexicoArray2 = CoreTools::LexicoArray2<false, typename RealContainer::iterator>;

#endif  // MATHEMATICS_USE_ROW_MAJOR

    private:
        /// ֧�ֹ����ݶȷ���
        NODISCARD static Real Dot(int n, const RealContainer& u, const RealContainer& v);

        static void Mul(int n, RealContainer& a, const RealContainer& x, RealContainer& p);

        static void Mul(const AlgebraSparseMatrix& a, const RealContainer& x, RealContainer& p);

        static void UpdateX(int n, RealContainer& x, Real alpha, const RealContainer& p);

        static void UpdateR(int n, RealContainer& r, Real alpha, const RealContainer& w);

        static void UpdateP(int n, RealContainer& p, Real beta, const RealContainer& r);

    private:
        // ����ϵͳ����ݲ
        // Ĭ�� = MathType<Real>::GetZeroTolerance()
        Real zeroTolerance;
    };

    using LinearSystemF = LinearSystem<float>;
    using LinearSystemD = LinearSystem<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_H
