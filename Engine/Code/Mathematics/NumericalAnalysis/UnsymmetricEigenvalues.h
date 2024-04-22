/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 14:42)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_UNSYMMETRIC_EIGENVALUES_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_UNSYMMETRIC_EIGENVALUES_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"

#include <array>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class UnsymmetricEigenvalues
    {
    public:
        using ClassType = UnsymmetricEigenvalues<Real>;

        using Math = Math<Real>;

    public:
        /// 求解器处理NxN个矩阵（不一定是对称的），
        /// 其中N>=3（“大小”为N），矩阵按行主顺序存储。
        /// 必须指定最大迭代次数（“最大迭代次数”），
        /// 以将上Hessenberg矩阵简化为上拟三角矩阵（对角块为1x1或2x2的块的上三角矩阵）。
        /// 目标是计算实值的特征值。
        UnsymmetricEigenvalues(int size, int maxIterations);

        CLASS_INVARIANT_DECLARE;

        /// NxN输入的副本是在内部制作的。
        /// 特征值的顺序由sortType指定：-1（递减）、0（无排序）或+1（递增）。
        /// 排序时，特征向量会相应排序。
        /// 返回值是发生收敛时消耗的迭代次数，当没有发生收敛时为0xFFFFFFFF，
        /// 或者当N<=1传递给构造函数时为0。
        NODISCARD int Solve(const std::vector<Real>& input, int sortType);

        /// 获取传递给Solve(...)的矩阵的实值特征值。
        /// 输入的“特征值”必须至少有N个元素。
        NODISCARD std::vector<Real> GetEigenvalues() const;

    private:
        /// matrix[]元素的2D访问器。
        NODISCARD const Real& A(int r, int c) const;

        NODISCARD Real& A(int r, int c);

        /// 计算(X[rMin],...,x[rMax])的Householder向量。
        /// 输入矢量存储在索引范围[rMin,rMax]中的x中。
        /// 输出矢量V被存储在索引范围[rMin,rMax]中的V中。
        /// 缩放后的矢量为S = (-2/Dot(V,V))*V，并存储在索引范围[rMin,rMax]中的scaledV中
        void House(int rMin, int rMax);

        /// 支持用P^T*A*P替换矩阵A，其中P是使用House(...)计算的Householder反射。
        void RowHouse(int rMin, int rMax, int cMin, int cMax);

        void ColHouse(int rMin, int rMax, int cMin, int cMax);

        void ReduceToUpperHessenberg();

        void FrancisQrStep(int rMin, int rMax);

        NODISCARD bool GetBlock(std::array<int, 2>& block);

    private:
        /// 要处理的矩阵的行和列的数量N。
        int size;
        int sizeM1;

        /// 将三对角矩阵简化为对角矩阵的最大迭代次数。
        int maxIterations;

        /// 传递给解算器的矩阵的内部副本
        std::vector<Real> matrix;  // NxN 元素

        /// 用于计算Householder反射的临时存储。
        std::vector<Real> x;
        std::vector<Real> v;
        std::vector<Real> scaledV;
        std::vector<Real> w;  // N 元素

        /// 关于子对角线项的零度的标志。
        /// 这用于检测未耦合的子矩阵，并将QR算法应用于相应的子问题。
        /// 存储器两端都用零填充，以避免在打包特征值以供调用方访问时出现额外的代码逻辑。
        std::vector<int> flagStorage;

        int numEigenvalues;
        std::vector<Real> eigenvalues;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_UNSYMMETRIC_EIGENVALUES_H
