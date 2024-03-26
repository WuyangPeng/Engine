/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/14 10:10)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BLOCK_LDLT_DECOMPOSITION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BLOCK_LDLT_DECOMPOSITION_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix/Matrix.h"
#include "Mathematics/Algebra/VariableMatrix.h"
#include "Mathematics/Algebra/Vector/Vector.h"

#include <array>

namespace Mathematics
{
    template <typename T, int...>
    class BlockLdltDecomposition;

    /// 编译时已知大小的实现。
    template <typename T, int BlockSize, int NumBlocks>
    requires(0 < BlockSize && 0 < NumBlocks)
    class BlockLdltDecomposition<T, BlockSize, NumBlocks>
    {
    public:
        using ClassType = BlockLdltDecomposition<T, BlockSize, NumBlocks>;

        /// 设B表示块大小，N表示块的数量。
        /// 矩阵A是(N*B)-by-(N*B)，但被划分为N乘N的块矩阵，每个块的大小为B乘B。
        /// 值N*B是NumDimensions。
        static constexpr auto numDimensions = NumBlocks * BlockSize;

        using Vector = Algebra::Vector<BlockSize, T>;
        using Matrix = Algebra::Matrix<BlockSize, BlockSize, T>;

        using BlockVector = std::array<Vector, NumBlocks>;
        using BlockMatrix = std::array<std::array<Matrix, NumBlocks>, NumBlocks>;

    public:
        BlockLdltDecomposition() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 将矩阵视为具有NumDimensions行和NumDimension列的标量的2D表，
        /// 查找存储请求元素的正确块并返回引用。
        void Get(const BlockMatrix& m, int row, int col, T& value);

        void Set(BlockMatrix& m, int row, int col, const T& value);

        /// 从矩阵转换为块矩阵。
        void Convert(const Algebra::Matrix<numDimensions, numDimensions, T>& m, BlockMatrix& mBlock) const;

        /// 从矢量转换为块矢量。
        void Convert(const Algebra::Vector<numDimensions, T>& v, BlockVector& vBlock) const;

        /// 从块矩阵转换为矩阵。
        void Convert(const BlockMatrix& mBlock, Algebra::Matrix<numDimensions, numDimensions, T>& m) const;

        /// 从块矢量转换为矢量。
        void Convert(const BlockVector& vBlock, Algebra::Vector<numDimensions, T>& v) const;

        /// 块矩阵A必须是正定的。该实现仅使用A的下三角块。
        /// 在输出时，块矩阵L是下单位三角形（对角块是BxB单位矩阵），
        /// 块矩阵D是对角的（对角块为BxB对角矩阵）。
        bool Factor(const BlockMatrix& a, BlockMatrix& l, BlockMatrix& d);

        /// 在调用前用因子分解法求解正定A = L * D * L^T 的A*X = B。
        void Solve(const BlockMatrix& l, const BlockMatrix& d, const BlockVector& b, BlockVector& x);

        /// 在调用过程中用因子分解法求解正定A = L * D * L^T 的A*X = B
        void Solve(const BlockMatrix& a, const BlockVector& b, BlockVector& x);
    };

    /// 仅在运行时才知道大小的实现。
    template <typename T>
    class BlockLdltDecomposition<T>
    {
    public:
        using ClassType = BlockLdltDecomposition<T>;

        using VariableLengthVector = VariableLengthVector<T>;
        using VariableMatrix = VariableMatrix<T>;

        /// BlockVector对象中的元素数必须为NumBlocks，
        /// 并且每个GVector元素都有BlockSize组件。
        using BlockVector = std::vector<VariableLengthVector>;

        /// BlockMatrix是NumBlocks乘NumBlocks矩阵的数组。
        /// 每个块矩阵按行主顺序存储。BlockMatrix元素本身按行的主要顺序存储。
        /// 块矩阵元素 M = BlockMatrix[col + numBlocks * row]的大小为BlockSize乘BlockSize（按行主顺序），
        /// 并且位于块的完整矩阵的(row,col)位置。
        using BlockMatrix = std::vector<VariableMatrix>;

    public:
        BlockLdltDecomposition(int blockSize, int numBlocks);

        CLASS_INVARIANT_DECLARE;

        /// 将矩阵视为具有numDimensions行和numDimension列的标量的2D表，
        /// 查找存储请求元素的正确块并返回引用。
        /// 注意：您负责确保M具有numBlocks by numBlocks元素，
        /// 每个M[]具有blockSize by blockSize元素。
        void Get(const BlockMatrix& m, int row, int col, T& value, bool verifySize = true);

        void Set(BlockMatrix& m, int row, int col, const T& value, bool verifySize = true);

        /// 从矩阵转换为块矩阵。
        void Convert(const VariableMatrix& m, BlockMatrix& mBlock, bool verifySize = true) const;

        /// 从矢量转换为块矢量。
        void Convert(const VariableLengthVector& v, BlockVector& vBlock, bool verifySize = true) const;

        /// 从块矩阵转换为矩阵。
        void Convert(const BlockMatrix& mBlock, VariableMatrix& m, bool verifySize = true) const;

        /// 从块矢量转换为矢量。
        void Convert(const BlockVector& vBlock, VariableLengthVector& v, bool verifySize = true) const;

        /// 块矩阵A必须是正定的。该实现仅使用A的下三角块。
        /// 在输出时，块矩阵L是下单位三角形（对角块是BxB单位矩阵），
        /// 块矩阵D是对角的（对角块为BxB对角矩阵）。
        bool Factor(const BlockMatrix& a, BlockMatrix& l, BlockMatrix& d, bool verifySize = true);

        /// 在调用前用因子分解法求解正定A = L * D * L^T的A*X = B。
        void Solve(const BlockMatrix& l, const BlockMatrix& d, const BlockVector& b, BlockVector& x, bool verifySize = true);

        /// 在调用过程中用因子分解法求解正定A = L * D * L^T的A*X = B 。
        void Solve(const BlockMatrix& a, const BlockVector& b, BlockVector& x, bool verifySize = true);

    private:
        /// 计算二维BlockMatrix对象中块矩阵的一维索引。
        NODISCARD int GetIndex(int row, int col) const noexcept;

    private:
        /// 设B表示块大小，N表示块的数量。矩阵A是(N*B)-by-(N*B)，
        /// 但被划分为块的N乘N矩阵，每个块的大小为B乘B，并按行主顺序存储。
        /// 值N*B为numDimensions。
        const int blockSize;
        const int numBlocks;
        const int numDimensions;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BLOCK_LDLT_DECOMPOSITION_H
