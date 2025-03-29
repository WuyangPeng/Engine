///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/29 15:17)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SYMMETRIC_EIGENSOLVER_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SYMMETRIC_EIGENSOLVER_H

#include "Mathematics/MathematicsDll.h"

#include "GivensRotation.h"
#include "SortItem.h"
#include "Mathematics/Base/Math.h"

#include <vector>

/// SymmetricEigensolver类是G.H.Golub和C.F.Van Loan的“矩阵计算，第二版”中描述的算法8.2.3（对称QR算法）的实现，
/// 约翰霍普金斯大学出版社，马里兰州巴尔的摩，1993年第四版。
/// 算法8.2.1（Householder三对角化）用于将矩阵A缩减为三对角T。
/// 算法8.2.2（带Wilkinson移位的隐式对称QR步长）用于从三对角到对角的迭代缩减。
/// 如果A是原始矩阵，D是特征值的对角矩阵，Q是特征向量的正交矩阵，那么理论上Q^T*A*Q = D。
/// 从数字上讲，我们有误差E = Q^T*A*Q - D。
/// 算法8.2.3提到，我们期望|E|近似为u*|A|，
/// 其中|M|表示M的Frobenius范数，其中u是浮点运算的单位舍入：
/// 2^{-23}对于'float'，即FLT_EPSILON = 1.192092896e-7f，
/// 2^{-52}表示'double'，即DBL_EPSILON = 2.2204460492503131e-16。
///
/// 用于确定何时归约解耦到较小问题的条件|a(i,i+1)| <= epsilon*(|a(i,i) + a(i+1,i+1)|)被实现为：
/// sum = |a(i,i)| + |a(i+1,i+1)|; sum + |a(i,i+1)| == sum。
/// 其思想是，超对角项相对于其对角邻居较小，因此它实际上为零。
/// 单元测试表明，这种对解耦的解释是有效的。
///
/// 作者建议，一旦你有了三对角矩阵，一个实际的实现将把对角和超对角条目存储在线性阵列中，忽略不在3带中的理论零值。
/// 这有利于缓存一致性。
/// 作者还建议将Householder向量存储在矩阵的下三角部分以节省内存。
/// 实施过程中使用了这两个建议。
///
/// 对于[0,1]中具有随机生成值的矩阵，单元测试产生N乘N矩阵的以下信息。
///
///  N  |A|     |E|        |E|/|A|    迭代
/// -------------------------------------------
///  2  1.2332 5.5511e-17 4.5011e-17  1
///  3  2.0024 1.1818e-15 5.9020e-16  5
///  4  2.8708 9.9287e-16 3.4585e-16  7
///  5  2.9040 2.5958e-15 8.9388e-16  9
///  6  4.0427 2.2434e-15 5.5493e-16 12
///  7  5.0276 3.2456e-15 6.4555e-16 15
///  8  5.4468 6.5626e-15 1.2048e-15 15
///  9  6.1510 4.0317e-15 6.5545e-16 17
/// 10  6.7523 4.9334e-15 7.3062e-16 21
/// 11  7.1322 7.1347e-15 1.0003e-15 22
/// 12  7.8324 5.6106e-15 7.1633e-16 24
/// 13  8.1073 5.1366e-15 6.3357e-16 25
/// 14  8.6257 8.3496e-15 9.6798e-16 29
/// 15  9.2603 6.9526e-15 7.5080e-16 31
/// 16  9.9853 6.5807e-15 6.5904e-16 32
/// 17 10.5388 8.0931e-15 7.6793e-16 35
/// 18 11.2377 1.1149e-14 9.9218e-16 38
/// 19 11.7105 1.0711e-14 9.1470e-16 42
/// 20 12.2227 1.7723e-14 1.4500e-15 42
/// 21 12.7411 1.2515e-14 9.8231e-16 47
/// 22 13.4462 1.2645e-14 9.4046e-16 50
/// 23 13.9541 1.2899e-14 9.2444e-16 47
/// 24 14.3298 1.6337e-14 1.1400e-15 53
/// 25 14.8050 1.4760e-14 9.9701e-16 54
/// 26 15.3914 1.7076e-14 1.1094e-15 57
/// 27 15.8430 1.9714e-14 1.2443e-15 60
/// 28 16.4771 1.7148e-14 1.0407e-15 60
/// 29 16.9909 1.7309e-14 1.0187e-15 60
/// 30 17.4456 2.1453e-14 1.2297e-15 64
/// 31 17.9909 2.2069e-14 1.2267e-15 68
///
/// 将特征值和|E|/|A|值与Mathematica Version 9.0生成的值进行比较；
/// Wolfram Research，股份有限公司，伊利诺伊州香槟市，2012年。
/// 这些结果都与符合大量小数位数的特征值相当。
///
/// 英特尔（R）酷睿（TM）i7-3930K CPU 3.20 GHZ时的计时（秒）：
/// N    |E|/|A|    iters tridiag QR     evecs    evec[N]  comperr
/// --------------------------------------------------------------
///  512 4.4149e-15 1017   0.180  0.005    1.151    0.848    2.166
/// 1024 6.1691e-15 1990   1.775  0.031   11.894   12.759   21.179
/// 2048 8.5108e-15 3849  16.592  0.107  119.744  116.56   212.227
///
/// 其中，iters是所采取的QR步数，
/// tridag是Householder反射向量的计算，
/// evec是Householder反射和Givens旋转的组合，
/// 以获得特征向量的矩阵，
/// evec[N]是N个单独获取特征向量的调用，
/// comperr是计算E = Q^T*A*Q - D。
/// 当然，构建完整的特征向量矩阵是非常昂贵的。
/// 如果只需要少量的特征向量，请使用函数GetEigenvector(int,Real*)。
namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class SymmetricEigensolver
    {
    public:
        using ClassType = SymmetricEigensolver<Real>;

        using MathType = Math<Real>;
        using GivensRotation = GivensRotation<Real>;
        using MatrixType = std::vector<Real>;
        using DiagonalType = std::vector<Real>;
        using GivensRotationContainer = std::vector<GivensRotation>;
        using PermutationType = std::vector<int>;
        using VisitedType = std::vector<int>;

    public:
        /// 求解器处理NxN个对称矩阵，其中 N > 1 ('size'为N)，矩阵按行主顺序存储。
        /// 必须指定将三对角矩阵简化为对角矩阵的最大迭代次数（“最大迭代次数”）。
        /// 目标是计算NxN正交Q和NxN对角D，其中Q^T*A*Q = D。
        SymmetricEigensolver(int size, int maxIterations);

        CLASS_INVARIANT_DECLARE;

        /// NxN对称输入的副本是在内部制作的。
        /// 特征值的顺序由sortType指定：-1（递减）、0（无排序）或+1（递增）。
        /// 排序时，特征向量会相应排序。
        /// 返回值是发生收敛时消耗的迭代次数，当没有发生收敛时为-1，
        /// 或者当N<=1传递给构造函数时为0。
        int Solve(const MatrixType& input, int sortType);

        /// 获取传递给Solve(...)的矩阵的特征值。
        /// 输入的“特征值”必须有N个元素。
        NODISCARD DiagonalType GetEigenvalues() const;

        /// 累加Householder反射和Givens旋转，生成正交矩阵Q，其中Q^T*A*Q = D。
        /// 输入的“特征向量”必须有N*N个元素。
        /// 数组被填充，就好像特征向量矩阵是按行的主要顺序存储的一样。
        /// 第i个特征向量是(eigenvectors[i+size*0], ... eigenvectors[i+size*(size - 1)])，
        /// 它是作为按行主序存储的NxN矩阵的“特征向量”的第i列。
        NODISCARD MatrixType GetEigenvectors() const;

        /// 特征向量矩阵是旋转（返回+1）或反射（返回0）。
        /// 如果构造函数的输入“size”为0，
        /// 或者GetEigenvectors的输入'eigenvectors'为null，则返回值为-1。
        NODISCARD int GetEigenvectorMatrixType() const noexcept;

        /// 计算单个特征向量，相当于矩阵Q的计算列c。
        /// 反射和旋转是增量应用的。
        /// 当您只需要少量的特征向量时，这很有用。
        NODISCARD DiagonalType GetEigenvector(int c) const;

        NODISCARD Real GetEigenvalue(int c) const;

    private:
        /// 使用Householder反射进行三对角化。
        /// 在输入时，matrix是输入矩阵的副本。
        /// 在输出时，包括对角线的matrix的上三角部分存储三对角。
        /// 下三角部分包含用于计算特征向量的2/Dot(v,v)，
        /// 次三角下面的部分存储Householder向量v的基本部分（领先的1值分量之后的v元素）。
        void TriDiagonalize();

        /// 一个生成Givens旋转正弦和余弦稳健的助手。
        void GetSinCos(Real x, Real y, Real& cs, Real& sn) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        /// 带有隐式移位的QR步骤。
        /// 一般来说，初始T是非退化的三对角（所有的子对角项都是非零的）。
        /// 如果QR步骤导致超对角项变为零，则矩阵解耦为具有两个三对角块的块对角矩阵。
        /// 这些块可以彼此独立地减少，这允许算法的并行化。
        /// 输入iMin和iMax标识要处理的T的子块。
        /// 该块具有左上元素 T(iMin,iMin)和右下元素T(iMax,iMax)。
        void DoQrImplicitShift(int iMin, int iMax);

        /// 对特征值进行排序，并计算存储特征值的阵列的索引的相应排列。
        /// 置换用于对GetEigenvalues(...) 和 GetEigenvectors(...)的调用中的特征值和特征向量进行重新排序。
        void ComputePermutation(int sortType);

    private:
        using SortItemType = SortItem<Real>;
        using SortItemContainer = std::vector<SortItemType>;

    private:
        // 要处理的矩阵的行和列的数量N。
        int size;

        // 将三对角矩阵简化为对角矩阵的最大迭代次数。
        int maxIterations;

        /// 传递给解算器的矩阵的内部副本。
        /// 关于矩阵中存储的内容，请参阅关于函数TriDiagonalize()的注释。
        MatrixType matrix;  // NxN 元素

        /// 在Householder反射的初始三对角化之后，我们不再需要完整的matrix。
        /// 将对角线和超对角线条目复制到线性阵列中，以便缓存友好。
        DiagonalType diagonal;  // N 元素
        DiagonalType superDiagonal;  // N-1 元素

        GivensRotationContainer givens;  // K*(N-1) 元素

        /// 当请求排序时，与排序相关联的排列被存储在permutation中。
        /// 当未请求排序时，permutation[0]设置为-1。
        /// visited用于查找排列中的循环。
        /// 如果GetEigenvectors返回旋转矩阵，则eigenvectorMatrixType为+1，
        /// 如果GetEigenvectors返返回反射矩阵，则为0，
        /// 如果构造函数或GetEigenvectors的输入无效，则为-1。
        PermutationType permutation;  // N 元素
        mutable VisitedType visited;  // N 元素
        mutable int eigenvectorMatrixType;

        /// 用于计算Householder反射和支持特征向量排序的临时存储。
        mutable DiagonalType pVector;  // N 元素
        mutable DiagonalType vVector;  // N 元素
        mutable DiagonalType wVector;  // N 元素
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SYMMETRIC_EIGENSOLVER_H
