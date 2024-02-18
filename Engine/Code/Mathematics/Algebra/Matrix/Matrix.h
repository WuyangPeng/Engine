/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/01/31 10:25)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Detail/Matrix/MatrixTable.h"
#include "Mathematics/Algebra/Vector/Vector.h"
#include "Mathematics/Base/MathDetail.h"

#include <array>

namespace Mathematics::Algebra
{
    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    class Matrix
    {
    public:
        using ClassType = Matrix<NumRows, NumColumns, Real>;

        using Math = Math<Real>;
        using MatrixTable = MatrixTable<NumRows, NumColumns, Real>;
        static constexpr auto numElements = NumRows * NumColumns;
        using Container = std::array<Real, numElements>;
        using BaseContainer = std::vector<Real>;

    public:
        Matrix() noexcept;

        /// �ñ���ȫ�������ʼ����
        /// ���ۻ�洢�����Ƿ���MATHEMATICS_USE_ROW_MAJOR��
        /// �����밴����˳��ָ����ֵ����
        explicit Matrix(const Container& values);
        explicit Matrix(const BaseContainer& values);

        /// ����0 <= row < NumRows and 0 <= column < NumColumns��
        /// Ԫ��(row,column) Ϊ1����������Ԫ�ؾ�Ϊ0��
        /// ���row��column�е��κ�һ����Ч���򴴽������
        /// ��Ϊ������׼ŷ����û������ṩ�˱�����
        /// ����μ�MakeUnit(int,int)��Unit(int,int)��
        Matrix(int row, int column);

        CLASS_INVARIANT_DECLARE;

        NODISCARD BaseContainer GetBaseContainer() const;

        /// �洢��ʾ��ʽ͸���ĳ�Ա���ʡ�
        /// ����row����column�еľ�����Ŀ��A(row,column)��
        /// ��һ��operator()���ص���const���ã�������Realֵ��
        /// ��֧��ͨ����Ҫָ�����ݵĳ���ָ��ı�׼�ļ���������д�롣
        NODISCARD const Real& operator()(int row, int column) const;
        NODISCARD Real& operator()(int row, int column);

        /// ���л��з��ʳ�Ա��
        void SetRow(int row, const Vector<NumColumns, Real>& vector);
        void SetColumn(int column, const Vector<NumRows, Real>& vector);

        NODISCARD Vector<NumColumns, Real> GetRow(int row) const;
        NODISCARD Vector<NumRows, Real> GetColumn(int column) const;

        /// ͨ��һά�������ʳ�Ա��
        /// ע�����洢���������洢�����������洢���޹ؽ�Ҫʱ����Щ���������ھ�����Ĳ����ǳ����á�
        /// ��Ҫʹ�ù����洢Լ���Ľṹ����matrix[column + NumColumns * row]��matrix[row + NumRows * column]��
        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);

        /// ���������ͼ�������ıȽϡ�
        NODISCARD bool operator==(const Matrix& rhs) const;
        NODISCARD bool operator!=(const Matrix& rhs) const;
        NODISCARD bool operator<(const Matrix& rhs) const;
        NODISCARD bool operator<=(const Matrix& rhs) const;
        NODISCARD bool operator>(const Matrix& rhs) const;
        NODISCARD bool operator>=(const Matrix& rhs) const;

        /// �������

        /// ���������Ϊ0��
        void MakeZero();

        /// ����(row,column)Ϊ1�������Ϊ�㡣
        void MakeUnit(int row, int column);

        /// �Խ�����Ŀ1��������Ŀ0����ʹ����������
        void MakeIdentity();

        static Matrix Zero() noexcept;
        static Matrix Unit(int row, int column);
        static Matrix Identity();

        /// һԪ���㡣
        NODISCARD Matrix operator+() const noexcept;
        NODISCARD Matrix operator-() const;

        /// ���Դ������㡣
        Matrix& operator+=(const Matrix& rhs);
        Matrix& operator-=(const Matrix& rhs);
        Matrix& operator*=(Real scalar);
        Matrix& operator/=(Real scalar);

    private:
        MatrixTable table;
    };

    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> operator+(const Matrix<NumRows, NumColumns, Real>& lhs, const Matrix<NumRows, NumColumns, Real>& rhs);

    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> operator-(const Matrix<NumRows, NumColumns, Real>& lhs, const Matrix<NumRows, NumColumns, Real>& rhs);

    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> operator*(const Matrix<NumRows, NumColumns, Real>& lhs, Real scalar);

    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> operator*(Real scalar, const Matrix<NumRows, NumColumns, Real>& rhs);

    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> operator/(const Matrix<NumRows, NumColumns, Real>& lhs, Real scalar);

    /// �������㡣
    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Real L1Norm(const Matrix<NumRows, NumColumns, Real>& matrix);

    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Real L2Norm(const Matrix<NumRows, NumColumns, Real>& matrix);

    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Real LInfinityNorm(const Matrix<NumRows, NumColumns, Real>& matrix);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<N, N, Real> Inverse(const Matrix<N, N, Real>& matrix, bool* reportInvertibility = nullptr);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Real Determinant(const Matrix<N, N, Real>& matrix);

    /// M^T
    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumColumns, NumRows, Real> Transpose(const Matrix<NumRows, NumColumns, Real>& matrix);

    /// M*V
    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<NumRows, Real> operator*(const Matrix<NumRows, NumColumns, Real>& matrix, const Vector<NumColumns, Real>& vector);

    /// V^T*M
    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<NumColumns, Real> operator*(const Vector<NumRows, Real>& vector, const Matrix<NumRows, NumColumns, Real>& matrix);

    /// A*B
    template <int NumRows, int NumColumns, int NumCommon, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> operator*(const Matrix<NumRows, NumCommon, Real>& lhs, const Matrix<NumCommon, NumColumns, Real>& rhs);

    template <int NumRows, int NumColumns, int NumCommon, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> Multiply(const Matrix<NumRows, NumCommon, Real>& lhs, const Matrix<NumCommon, NumColumns, Real>& rhs);

    /// A*B^T
    template <int NumRows, int NumColumns, int NumCommon, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> MultiplyTransposition(const Matrix<NumRows, NumCommon, Real>& lhs, const Matrix<NumCommon, NumColumns, Real>& rhs);

    /// A^T*B
    template <int NumRows, int NumColumns, int NumCommon, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> TranspositionMultiply(const Matrix<NumRows, NumCommon, Real>& lhs, const Matrix<NumCommon, NumColumns, Real>& rhs);

    /// A^T*B^T
    template <int NumRows, int NumColumns, int NumCommon, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> TranspositionMultiplyTransposition(const Matrix<NumRows, NumCommon, Real>& lhs, const Matrix<NumCommon, NumColumns, Real>& rhs);

    /// M*D, D �ǶԽ��� NumColumns-by-NumColumns
    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> Multiply(const Matrix<NumRows, NumColumns, Real>& matrix, const Vector<NumColumns, Real>& diagonal);

    /// D*M, D �ǶԽ��� NumRows-by-NumRows
    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> Multiply(const Vector<NumRows, Real>& diagonal, const Matrix<NumRows, NumColumns, Real>& matrix);

    /// U*V^T, U �� NumRows-by-1, V �� Num-Cols-by-1, ����� NumRows-by-NumCols.
    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<NumRows, NumColumns, Real> OuterProduct(const Vector<NumRows, Real>& u, const Vector<NumColumns, Real>& v);

    /// �ԽǾ���ĳ�ʼ������Խ�����D�ķ�����
    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<N, N, Real> MakeDiagonal(const Vector<N, Real>& diagonal);

    /// ͨ�����ϲ�N-by-N������Ϊ����N-by-N����
    /// ���������һ�к����һ����Ŀ����Ϊ1֮�������������Ŀ����Ϊ0��
    /// ����(N+1)-by-(N+1)����H��
    template <int N, typename Real>
    requires(1 <= N && N <= 3 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<N + 1, N + 1, Real> HomogeneousLift(const Matrix<N, N, Real>& matrix);

    /// ��ȡ����N-by-N �������(N-1)-by-(N-1)�顣
    template <int N, typename Real>
    requires(2 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Matrix<N - 1, N - 1, Real> HomogeneousProject(const Matrix<N, N, Real>& matrix);
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_H
