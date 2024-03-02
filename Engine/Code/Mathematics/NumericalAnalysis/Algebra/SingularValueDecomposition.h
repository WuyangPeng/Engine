/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/02/27 13:55)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_SINGULAR_VALUE_DECOMPOSITION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_SINGULAR_VALUE_DECOMPOSITION_H

#include "Mathematics/MathematicsDll.h"

#include "GivensRotation.h"
#include "SingularInfo.h"
#include "Mathematics/Base/Math.h"

#include <vector>

/// SingularValueDecomposition����G. H. Golub��Charles F. Van Loan�ġ�������㣬��2�桱���������㷨8.3.2��SVD�㷨����ʵ�֣�
/// Լ�������ս�˹�����磬�������ݰͶ���Ħ��1993���4�档
/// �㷨5.4.2��Householder˫�Խǻ������ڽ�A����Ϊ˫�Խ�B��
/// �㷨8.3.1��Golub-Kahan SVD���裩���ڴ�˫�Խǵ��Խǵĵ���������
/// ���A��ԭʼ����S�ǶԽ���Ϊ����ֵ�ľ���U��V����Ӧ�ľ�����ô������U^T*A*V = S��
/// �������ϣ����������E = U^T*A*V-S��
/// �㷨8.3.2�ᵽ����������|E|����ΪunitRoundOff*|A|��
/// ����|A|��ʾA��Frobenius������
/// ���ж���Real=float����λunitRoundOff is 2^{-23}����
///   std::numeric_limits<float>::epsilon() = 1.192092896e-7f
/// ��2^{-52}��ʾReal=double����
///   std::numeric_limits<double>::epsilon() = 2.2204460492503131e-16.
///
/// �ڴ���B�ĵ����ڼ䣬˫�Խǻ���A��
/// �����������ڶԽ��ߺͳ��Խ���Ԫ�����ʱ�����Խ�����Ŀ��ȷ��Ϊ��Ч��Ϊ�㣬
///   |b(i,i+1)| <= e * (|b(i,i) + b(i+1,i+1)|)
/// Golub��van Loan������ѡ��e��Ϊ��λ�����С��������
/// e = multiplier * unitRoundOff��
/// �Խ�����Ŀ��ȷ��Ϊ�����B�ķ�����Ч��Ϊ�㣬
///   |b(i,i)| <= e * |B|
/// ʵ��ʹ��|B|��L-�������������B�ĶԽ��ߺͳ��Խ���Ԫ�ص�������ֵ��
///
/// ���߽��飬һ��������˫�ԽǾ���
/// һ��ʵ�ʵ�ʵ�ֽ��ѶԽǺͳ��Խ���洢�����������У�
/// ���Բ���2���е�������ֵ��
/// �������ڻ���һ���ԡ�
/// ʵ�ֶ�Householder u����ʹ�õ����Ĵ洢��
/// �����Щ�����Ļ������ֲ��洢��A�ı��ظ����У���Golub��van Loan������ģ���
/// ��ʹʵ�ָ��߿ɶ��ԡ�

namespace Mathematics::Algebra
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class SingularValueDecomposition
    {
    public:
        using ClassType = SingularValueDecomposition<Real>;

        using Math = Math<Real>;
        using MatrixType = std::vector<Real>;
        using DiagonalType = std::vector<Real>;

    public:
        /// ���������MxN���Գƾ�������M >= N > 1��'numRows'ΪM��'numCols'ΪN������������˳��洢��
        /// ����ָ��������������������������������
        /// �Խ�һ��˫�ԽǾ����Ϊ�ԽǾ���
        /// Ŀ���Ǽ���MxM����U��NxN����V��MxN����S��
        /// ���� U^T*A*V = S��
        /// S��Ψһ�������ڶԽ����ϣ�
        /// �Խ�����ԭʼ���������ֵ��
        SingularValueDecomposition(int numRows, int numCols, int maxIterations);

        CLASS_INVARIANT_DECLARE;

        /// MxN����ĸ��������ڲ������ġ�
        /// ������һ�����ڼ���e��С�������ڸ��ļ���ǰ��ע���н�����������Ĭ��ֵΪ8��
        /// �������Ը���Ӧ�ó������Ҫ���е�����
        /// ����ֵ�Ƿ�������ʱ���ĵĵ���������
        /// ������δ��������ʱ��std::numeric_limits<int>::max() ��
        int Solve(const MatrixType& input, Real multiplier = Math::GetValue(8));

        /// �õ�U-��������MxM����������˳��洢��
        NODISCARD MatrixType GetU() const;

        /// �õ�V-��������NxN����������˳��洢��
        NODISCARD MatrixType GetV() const;

        /// �õ�S-��������MxN ����������˳��洢��
        NODISCARD MatrixType GetS() const;

        NODISCARD Real GetSingularValue(int index) const;

        NODISCARD DiagonalType GetUColumn(int index) const;
        NODISCARD DiagonalType GetVColumn(int index) const;

        /// ��ȡ����ֵ������һ��NԪ�����顣
        NODISCARD DiagonalType GetSingularValues() const;

    private:
        using GivensRotation = GivensRotation<Real>;
        using SingularInfo = SingularInfo<Real>;
        using HouseholderType = std::vector<DiagonalType>;
        using GivensRotationContainer = std::vector<GivensRotation>;
        using SingularInfoContainer = std::vector<SingularInfo>;

        static constexpr auto unitRoundOff = std::numeric_limits<Real>::epsilon();

        /// �㷨5.1.1��Householder Vector����
        /// ����A�Ĵ�СΪnumRows x numCols��
        /// ����numRows >= numCols��������v�Ĵ�СΪnumRows��
        static void ComputeHouseholderU(int numRows, int numCols, const MatrixType& a, int selectCol, DiagonalType& v);

        /// �㷨5.1.1��Householder Vector����
        /// ����A�Ĵ�СΪnumRows x numCols��
        /// ����numRows >= numCols��������v�Ĵ�СΪnumCols��
        static void ComputeHouseholderV(int numRows, int numCols, const MatrixType& a, int selectRow, DiagonalType& v);

        // �㷨 5.1.2 (Householder Ԥ��)
        static void DoHouseholderPreMultiply(int numRows, int numCols, const DiagonalType& v, int selectCol, MatrixType& a);

        // �㷨 5.1.3 (Householder ��˷�)
        static void DoHouseholderPostMultiply(int numRows, int numCols, const DiagonalType& v, int selectRow, MatrixType& a);

        /// ʹ��Householder�������˫�����䡣
        /// ������ʱ��matrix�Ǵ��ݸ�Solve(...)���������ĸ�����
        /// �����ʱ��diagonal��superDiagonal�Խ��߰���˫�򻯵Ľ����
        void Bidiagonalize();

        void ComputeCutoffs(Real multiplier, Real& epsilon, Real& threshold) const;

        /// �����sn * x + cs * y = 0ʱ��
        /// �����Ƚ�������Givens��ת���Һ����ҵĸ�������
        void GetSinCos(Real x, Real y, Real& cs, Real& sn) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        /// ���Գ������һ����������жԽ�����Ŀ�Ƿ���ЧΪ�㡣
        /// ����ÿ����������Ŀ��B������
        /// ���û����ֵ��Ŀ�������ִ��Golub Kahan����ִ�н��
        bool DiagonalEntriesNonzero(int iMin, int iMax, Real threshold);

        // �㷨 8.3.1 (Golub-Kahan SVD ����).
        void DoGolubKahanStep(int iMin, int iMax);

        void ComputeOrthogonalMatrices();
        void ComputeUOrthogonal();
        void ComputeVOrthogonal();
        void EnsureNonnegativeSingularValues();
        void SortSingularValues();

    private:
        /// Ҫ����ľ����������������
        int numRows;
        int numCols;

        /// ��˫�ԽǾ����Ϊ�ԽǾ����������������
        int maxIterations;

        /// ���ݸ��������ľ�����ڲ�������
        /// ���ǰ�����˳��洢�ġ�
        MatrixType matrix;  // MxN Ԫ��

        /// U*A*V^T = S��U����V�����S����
        /// ���ǰ�����˳��洢��
        MatrixType uMatrix;  // MxM
        MatrixType vMatrix;  // NxN
        MatrixType sMatrix;  // MxN

        /// ���ԽǾ���ĶԽ��ߺͳ��Խ��ߡ�
        DiagonalType diagonal;  // N Ԫ��
        DiagonalType superDiagonal;  // N-1 Ԫ��

        // Householder�������ڽ���������Ϊ˫�����
        HouseholderType lHouseholder;
        HouseholderType rHouseholder;

        GivensRotationContainer lGivens;
        GivensRotationContainer rGivens;
    };

    using SingularValueDecompositionF = SingularValueDecomposition<float>;
    using SingularValueDecompositionD = SingularValueDecomposition<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_SINGULAR_VALUE_DECOMPOSITION_H
