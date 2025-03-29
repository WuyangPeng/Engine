/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 15:59)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BLOCK_CHOLESKY_DECOMPOSITION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BLOCK_CHOLESKY_DECOMPOSITION_H

#include "Mathematics/MathematicsDll.h"

#include "CholeskyDecomposition.h"
#include "Mathematics/Algebra/Matrix/Matrix.h"

#include <array>

namespace Mathematics
{
    /// 编译时已知大小的实现
    template <typename Real, int BlockSize = 0, int NumBlocks = 0>
    requires(std::is_arithmetic_v<Real> && 0 <= BlockSize && 0 <= NumBlocks)
    class BlockCholeskyDecomposition
    {
    public:
        using ClassType = BlockCholeskyDecomposition<Real, BlockSize, NumBlocks>;

        /// 设B表示块大小，N表示块的数量。
        /// 矩阵A是(N*B)-by-(N*B)），但被划分为N乘N的块矩阵，
        /// 每个块的大小为B乘B。值N*B是NumDimensions。

        static constexpr auto numDimensions = NumBlocks * BlockSize;

        using Vector = Algebra::Vector<BlockSize, Real>;
        using Matrix = Algebra::Matrix<BlockSize, BlockSize, Real>;

        using BlockVector = std::array<Vector, NumBlocks>;
        using BlockMatrix = std::array<std::array<Matrix, NumBlocks>, NumBlocks>;

    public:
        BlockCholeskyDecomposition() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 将矩阵视为具有NUM_DIMENSIONS行和NUM_DIMENSIONS列的标量的2D表，
        /// 查找存储请求元素的正确块并返回引用。
        NODISCARD Real Get(const BlockMatrix& m, int row, int col);

        void Set(BlockMatrix& m, int row, int col, Real value);

        NODISCARD bool Factor(BlockMatrix& a);

        /// 求解L*Y = B，其中L是可逆的下三角块矩阵，其对角块是下三角矩阵。
        /// 输入B是具有相应大小的块矢量。Y的输入值是B。在输出时，Y是解。
        NODISCARD BlockVector SolveLower(const BlockMatrix& l);

        /// 求解L^T*X = Y，其中L是可逆的下三角块矩阵（L^T是上三角块矩阵），
        /// 其对角块是下三角矩阵。X的输入值是Y。在输出时，X是解。
        NODISCARD BlockVector SolveUpper(const BlockMatrix& l);

    private:
        /// 求解G(c,c)*G(r,c)^T = A(r,c)^T 的G(r,c)。
        /// 矩阵G(r,c)和A(r,c) 是已知的量，
        /// 并且G(c,c)占据A(c,c)的下三角部分。
        /// 解算器将其结果存储在适当位置，因此A(r,c)存储 G(r,c) 结果。
        void LowerTriangularSolver(int r, int c, BlockMatrix& a);

        void SubtractiveUpdate(int r, int k, int c, BlockMatrix& a);

    private:
        using CholeskyDecompositionType = CholeskyDecomposition<Real, BlockSize>;

    private:
        CholeskyDecompositionType decomposer;
    };

    /// 仅在运行时才知道大小的实现。
    template <typename Real>
    class BlockCholeskyDecomposition<Real, 0, 0>
    {
    public:
        using ClassType = BlockCholeskyDecomposition<Real, 0, 0>;

        using VariableLengthVectorType = VariableLengthVector<Real>;
        using VariableMatrixType = VariableMatrix<Real>;

        /// BlockVector对象中的元素数必须为NumBlocks，
        /// 并且每个GVector元素都有BlockSize组件。
        using BlockVector = std::vector<VariableLengthVectorType>;

        /// BlockMatrix是NumBlocks乘NumBlocks矩阵的数组。
        /// 每个块矩阵按行主顺序存储。
        /// BlockMatrix元素本身按行的主要顺序存储。
        /// 块矩阵元素 M = BlockMatrix[col + NumBlocks * row]的大小为BlockSize乘BlockSize（按行主顺序），
        /// 并且位于块的完整矩阵的（row，col）位置。
        using BlockMatrix = std::vector<VariableMatrixType>;

    public:
        BlockCholeskyDecomposition(int blockSize, int numBlocks);

        CLASS_INVARIANT_DECLARE;

        /// 将矩阵视为具有NumDimensions行和NumDimension列的标量的2D表，
        /// 查找存储请求元素的正确块并返回引用。
        NODISCARD Real Get(const BlockMatrix& m, int row, int col);

        void Set(BlockMatrix& m, int row, int col, Real value);

        NODISCARD bool Factor(BlockMatrix& a);

        /// 求解L*Y=B，其中L是可逆的下三角块矩阵，其对角块是下三角矩阵。
        /// 输入B是具有相应大小的块矢量。Y的输入值是B。在输出时，Y是解。
        NODISCARD BlockVector SolveLower(const BlockMatrix& l);

        /// 求解L^T*X = Y，其中L是可逆的下三角块矩阵（L^T是上三角块矩阵），
        /// 其对角块是下三角矩阵。X的输入值是Y。在输出时，X是解。
        NODISCARD BlockVector SolveUpper(const BlockMatrix& l);

    private:
        using CholeskyDecompositionType = CholeskyDecomposition<Real>;

    private:
        /// 计算二维BlockMatrix对象中块矩阵的一维索引。
        NODISCARD int GetIndex(int row, int col) const noexcept;

        /// 求解G(c,c)*G(r,c)^T = A(r,c)^T 的G(r,c)。
        /// 矩阵G(r,c)和A(r,c) 是已知的量，
        /// 并且G(c,c)占据A(c,c)的下三角部分。
        /// 解算器将其结果存储在适当位置，因此A(r,c)存储 G(r,c) 结果。
        void LowerTriangularSolver(int r, int c, BlockMatrix& a);

        void SubtractiveUpdate(int r, int k, int c, BlockMatrix& a);

    private:
        /// 设B表示块大小，N表示块的数量。矩阵A是(N*B)-by-(N*B)，
        /// 但被划分为N乘N的块矩阵，每个块的大小为B乘B。
        /// 值N*B是NumDimensions。
        const int blockSize;
        const int numBlocks;
        const int numDimensions;

        /// 分解器的大小为BlockSize。
        CholeskyDecompositionType decomposer;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BLOCK_CHOLESKY_DECOMPOSITION_H
