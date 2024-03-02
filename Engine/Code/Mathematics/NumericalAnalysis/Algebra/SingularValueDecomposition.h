/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/27 13:55)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_SINGULAR_VALUE_DECOMPOSITION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_SINGULAR_VALUE_DECOMPOSITION_H

#include "Mathematics/MathematicsDll.h"

#include "GivensRotation.h"
#include "SingularInfo.h"
#include "Mathematics/Base/Math.h"

#include <vector>

/// SingularValueDecomposition类是G. H. Golub和Charles F. Van Loan的“矩阵计算，第2版”中描述的算法8.3.2（SVD算法）的实现，
/// 约翰·霍普金斯出版社，马里兰州巴尔的摩，1993年第4版。
/// 算法5.4.2（Householder双对角化）用于将A缩减为双对角B。
/// 算法8.3.1（Golub-Kahan SVD步骤）用于从双对角到对角的迭代缩减。
/// 如果A是原始矩阵，S是对角项为奇异值的矩阵，U和V是相应的矩阵，那么理论上U^T*A*V = S。
/// 在数字上，我们有误差E = U^T*A*V-S。
/// 算法8.3.2提到，我们期望|E|近似为unitRoundOff*|A|，
/// 其中|A|表示A的Frobenius范数，
/// 其中对于Real=float，单位unitRoundOff is 2^{-23}，即
///   std::numeric_limits<float>::epsilon() = 1.192092896e-7f
/// 或2^{-52}表示Real=double，即
///   std::numeric_limits<double>::epsilon() = 2.2204460492503131e-16.
///
/// 在处理B的迭代期间，双对角化的A，
/// 当与它的相邻对角线和超对角线元素相比时，超对角线条目被确定为有效地为零，
///   |b(i,i+1)| <= e * (|b(i,i) + b(i+1,i+1)|)
/// Golub和van Loan建议是选择e作为单位舍入的小正倍数，
/// e = multiplier * unitRoundOff。
/// 对角线条目被确定为相对于B的范数有效地为零，
///   |b(i,i)| <= e * |B|
/// 实现使用|B|的L-无穷大范数，这是B的对角线和超对角线元素的最大绝对值。
///
/// 作者建议，一旦你有了双对角矩阵，
/// 一个实际的实现将把对角和超对角项存储在线性阵列中，
/// 忽略不在2带中的理论零值。
/// 这有利于缓存一致性。
/// 实现对Householder u向量使用单独的存储，
/// 因此这些向量的基本部分不存储在A的本地副本中（如Golub和van Loan所建议的），
/// 以使实现更具可读性。

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
        /// 求解器处理MxN个对称矩阵，其中M >= N > 1（'numRows'为M，'numCols'为N），矩阵按行主顺序存储。
        /// 必须指定最大迭代次数（“最大迭代次数”），
        /// 以将一个双对角矩阵简化为对角矩阵。
        /// 目标是计算MxM正交U、NxN正交V和MxN矩阵S，
        /// 其中 U^T*A*V = S。
        /// S的唯一非零项在对角线上；
        /// 对角项是原始矩阵的奇异值。
        SingularValueDecomposition(int numRows, int numCols, int maxIterations);

        CLASS_INVARIANT_DECLARE;

        /// MxN输入的副本是在内部制作的。
        /// 乘数是一个用于计算e的小正数，在该文件的前导注释中进行了描述。默认值为8，
        /// 但您可以根据应用程序的需要进行调整。
        /// 返回值是发生收敛时消耗的迭代次数，
        /// 或者是未发生收敛时的std::numeric_limits<int>::max() 。
        int Solve(const MatrixType& input, Real multiplier = Math::GetValue(8));

        /// 得到U-矩阵，它是MxM，并按行主顺序存储。
        NODISCARD MatrixType GetU() const;

        /// 得到V-矩阵，它是NxN，并按行主顺序存储。
        NODISCARD MatrixType GetV() const;

        /// 得到S-矩阵，它是MxN ，并按行主顺序存储。
        NODISCARD MatrixType GetS() const;

        NODISCARD Real GetSingularValue(int index) const;

        NODISCARD DiagonalType GetUColumn(int index) const;
        NODISCARD DiagonalType GetVColumn(int index) const;

        /// 获取奇异值，这是一个N元素数组。
        NODISCARD DiagonalType GetSingularValues() const;

    private:
        using GivensRotation = GivensRotation<Real>;
        using SingularInfo = SingularInfo<Real>;
        using HouseholderType = std::vector<DiagonalType>;
        using GivensRotationContainer = std::vector<GivensRotation>;
        using SingularInfoContainer = std::vector<SingularInfo>;

        static constexpr auto unitRoundOff = std::numeric_limits<Real>::epsilon();

        /// 算法5.1.1（Householder Vector）。
        /// 矩阵A的大小为numRows x numCols，
        /// 其中numRows >= numCols并且向量v的大小为numRows。
        static void ComputeHouseholderU(int numRows, int numCols, const MatrixType& a, int selectCol, DiagonalType& v);

        /// 算法5.1.1（Householder Vector）。
        /// 矩阵A的大小为numRows x numCols，
        /// 其中numRows >= numCols并且向量v的大小为numCols。
        static void ComputeHouseholderV(int numRows, int numCols, const MatrixType& a, int selectRow, DiagonalType& v);

        // 算法 5.1.2 (Householder 预乘)
        static void DoHouseholderPreMultiply(int numRows, int numCols, const DiagonalType& v, int selectCol, MatrixType& a);

        // 算法 5.1.3 (Householder 后乘法)
        static void DoHouseholderPostMultiply(int numRows, int numCols, const DiagonalType& v, int selectRow, MatrixType& a);

        /// 使用Householder反射进行双向适配。
        /// 在输入时，matrix是传递给Solve(...)的输入矩阵的副本。
        /// 在输出时，diagonal和superDiagonal对角线包含双向化的结果。
        void Bidiagonalize();

        void ComputeCutoffs(Real multiplier, Real& epsilon, Real& threshold) const;

        /// 当求解sn * x + cs * y = 0时，
        /// 用于稳健地生成Givens旋转正弦和余弦的辅助对象。
        void GetSinCos(Real x, Real y, Real& cs, Real& sn) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        /// 测试除了最后一个以外的所有对角线条目是否有效为零。
        /// 对于每个这样的条目，B矩阵解耦。
        /// 如果没有零值条目，则必须执行Golub Kahan步骤执行解耦。
        bool DiagonalEntriesNonzero(int iMin, int iMax, Real threshold);

        // 算法 8.3.1 (Golub-Kahan SVD 步骤).
        void DoGolubKahanStep(int iMin, int iMax);

        void ComputeOrthogonalMatrices();
        void ComputeUOrthogonal();
        void ComputeVOrthogonal();
        void EnsureNonnegativeSingularValues();
        void SortSingularValues();

    private:
        /// 要处理的矩阵的行数和列数。
        int numRows;
        int numCols;

        /// 将双对角矩阵简化为对角矩阵的最大迭代次数。
        int maxIterations;

        /// 传递给解算器的矩阵的内部副本。
        /// 这是按行主顺序存储的。
        MatrixType matrix;  // MxN 元素

        /// U*A*V^T = S的U矩阵、V矩阵和S矩阵。
        /// 它们按行主顺序存储。
        MatrixType uMatrix;  // MxM
        MatrixType vMatrix;  // NxN
        MatrixType sMatrix;  // MxN

        /// 二对角矩阵的对角线和超对角线。
        DiagonalType diagonal;  // N 元素
        DiagonalType superDiagonal;  // N-1 元素

        // Householder反射用于将输入矩阵简化为双向矩阵。
        HouseholderType lHouseholder;
        HouseholderType rHouseholder;

        GivensRotationContainer lGivens;
        GivensRotationContainer rGivens;
    };

    using SingularValueDecompositionF = SingularValueDecomposition<float>;
    using SingularValueDecompositionD = SingularValueDecomposition<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_SINGULAR_VALUE_DECOMPOSITION_H
