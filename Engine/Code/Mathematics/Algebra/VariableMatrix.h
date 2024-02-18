/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/02/05 14:17)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_H
#define MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "VariableLengthVector.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

/// ��������MATHEMATICS_USE_MATRIX_VECTORʱ��
/// ��������Ӧ��Ϊ��ˡ�
/// ���磬�����ľ���M������V�������ʸ��ΪM * V��
/// Ҳ����˵��V������һ����������
/// һЩͼ��APIʹ��V * M������V����Ϊ��������
/// ����Щ�����У�����M����������M����ʾ��ת�á�
/// ���Ƶأ�Ӧ��2����������M0��M1���Ը�˳��
/// �����M1*M0��һ��������ת���ǣ�M1 * M0��* V = M1 *��M0* V����
/// һЩͼ��APIʹ��M0 * M1����ͬ����Щ������ָ��������ʾ��ת�á�
/// ��ˣ���һ��ҪС���������ͼ��API�ӿ���ת�����롣
///
/// ���󱻴���Ϊ�����򱣴棬matrix[row][col]��

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class VariableMatrix final : private boost::additive<VariableMatrix<Real>, boost::multiplicative<VariableMatrix<Real>, Real, boost::totally_ordered<VariableMatrix<Real>>>>
    {
    public:
        using ClassType = VariableMatrix<Real>;

        using Math = Math<Real>;
        using Matrix2 = Matrix2<Real>;
        using Matrix3 = Matrix3<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;
        using ContainerType = std::vector<Real>;
        using VectorContainerType = std::vector<VariableLengthVector>;

    public:
        /// ����Ϊ�㣬numRows��numCols����Ϊ�㡣
        VariableMatrix() noexcept = default;

        /// ����ΪnumRows * numCols��Ԫ�س�ʼ��Ϊ�㡣
        VariableMatrix(int rowsNumber, int columnsNumber);

        ///  ����0 <= row < numRows�� 0 <= column < numCols��
        ///  Ԫ��(row,column)Ϊ1����������Ԫ�ؾ�Ϊ0��
        ///  ���row��column�е��κ�һ����Ч���򴴽������
        ///  ��Ϊ������׼ŷ����û������ṩ�˱�����
        ///  ����μ�MakeUnit(int,int)��Unit(int,int)��
        VariableMatrix(int rowsNumber, int columnsNumber, int row, int column);

        VariableMatrix(int rowsNumber, int columnsNumber, const ContainerType& entry);
        explicit VariableMatrix(VectorContainerType matrix) noexcept;
        explicit VariableMatrix(const Matrix2& rhs);
        explicit VariableMatrix(const Matrix3& rhs);

        CLASS_INVARIANT_DECLARE;

        /// �洢��ʾ��ʽ͸���ĳ�Ա���ʡ�
        /// ����row����column�еľ�����Ŀ��A(row,column)��
        /// ��һ��operator()���ص���const���ã�������Realֵ��
        /// ��֧��ͨ����Ҫָ�����ݵĳ���ָ��ı�׼�ļ���������д�롣
        /// ʹ��SetSize����վ����ݡ�
        void SetSize(int rowsNumber, int columnsNumber);
        NODISCARD int GetRowsNumber() const;
        NODISCARD int GetColumnsNumber() const;
        NODISCARD int GetElementsNumber() const;
        NODISCARD const Real& operator()(int row, int column) const;
        NODISCARD Real& operator()(int row, int column);

        /// ͨ��һά�������ʳ�Ա��
        /// ע�����洢���������洢�����������洢���޹ؽ�Ҫʱ��
        /// ��Щ���������ھ�����Ĳ����ǳ����á�
        /// ��Ҫʹ�ù����洢Լ���Ľṹ����M[column+NumCols*row]��M[row+NumRows*column]��
        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);

        NODISCARD ContainerType GetContainer() const;
        void SetContainer(int rowsNumber, int columnsNumber, const ContainerType& entry);

        /// ���л��з��ʳ�Ա������������Ԫ����������������С����Ӧ��
        void SetRow(int row, const VariableLengthVector& vector);
        NODISCARD VariableLengthVector GetRow(int row) const;
        void SetColumn(int column, const VariableLengthVector& vector);
        NODISCARD VariableLengthVector GetColumn(int column) const;
        void ResetMatrix(const VectorContainerType& matrix);

        /// ֧�ֽ����к��С�
        void SwapRows(int lhsRow, int rhsRow);
        void SwapColumns(int lhsColumns, int rhsColumns);

        NODISCARD bool Equal(const VariableMatrix& rhs) const;
        NODISCARD bool Less(const VariableMatrix& rhs) const;

        /// ���ھ���˷�����this�������е���Ŀ�������rhs�����е���Ŀ
        VariableMatrix& operator*=(const VariableMatrix& rhs);

        /// һԪ���㡣
        NODISCARD VariableMatrix operator+() const;
        NODISCARD VariableMatrix operator-() const;

        /// ���Դ������㡣

        /// �����������ͬ�Ĵ�С����ͬ��������������
        /// ���ھ���ļӷ��ͼ������㡣
        VariableMatrix& operator+=(const VariableMatrix& rhs);
        VariableMatrix& operator-=(const VariableMatrix& rhs);
        VariableMatrix& operator*=(Real scalar);
        VariableMatrix& operator/=(Real scalar);

        /// �������㡣
        NODISCARD Real L1Norm() const;
        NODISCARD Real L2Norm() const;
        NODISCARD Real LInfinityNorm() const;

        NODISCARD VariableMatrix Inverse(bool* reportInvertibility = nullptr) const;
        NODISCARD Real Determinant() const;

        /// vector0^T * M * vector1
        /// ��numColumns(M) = size(vector1) ��
        /// numRows(M) = size(vector0) �Ǳ���ģ�
        NODISCARD Real QuadraticForm(const VariableLengthVector& vector0, const VariableLengthVector& vector1) const;

        // M^T
        NODISCARD VariableMatrix Transpose() const;

        NODISCARD Matrix3 GetMatrix3() const;

        /// �������

        /// ���������Ϊ0��
        void MakeZero();

        /// ���� (row,column) Ϊ1�������Ϊ�㡣
        void MakeUnit(int row, int column);

        /// �Խ�����Ŀ1��������Ŀ0����ʹ�Ƿ���������Ŀ��
        void MakeIdentity();

        NODISCARD static VariableMatrix Zero(int rowsNumber, int columnsNumber);
        NODISCARD static VariableMatrix Unit(int rowsNumber, int columnsNumber, int row, int column);
        NODISCARD static VariableMatrix Identity(int rowsNumber, int columnsNumber);

    private:
        /// �þ���洢�����������Զ�ά���顣
        /// �������������Ĺ�������ѡ��
        VectorContainerType container;
    };

    /// �Ƚ� (��ʹ����STL����)��
    /// �����������ͬ�Ĵ�С����ͬ������������
    /// ���������ͼ�������ıȽϡ�
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator==(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableMatrix<Real> operator*(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableMatrix<Real> Multiply(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    /// M * v (numColumns(matrix) = size(vector) �Ǳ����)
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableLengthVector<Real> operator*(const VariableMatrix<Real>& matrix, const VariableLengthVector<Real>& vector);

    /// v^T * M (numRows(matrix) = size(vector) �Ǳ����)
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableLengthVector<Real> operator*(const VariableLengthVector<Real>& vector, const VariableMatrix<Real>& matrix);

    /// M * mat^T (numColumns(lhs) = numColumns(rhs) �Ǳ����)
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableMatrix<Real> MultiplyTranspose(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    /// M^T * mat (numRows(lhs) = numRows(rhs) �Ǳ����)
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableMatrix<Real> TransposeMultiply(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    /// M^T * mat^T (numRows(lhs) = numColumns(rhs) �Ǳ����)
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableMatrix<Real> TransposeMultiplyTranspose(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    /// M*D��DΪ�����ζԽ��ߣ��洢Ϊʸ����
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableMatrix<Real> Multiply(const VariableMatrix<Real>& matrix, const VariableLengthVector<Real>& diagonal);

    /// D*M, DΪ�����ζԽ��ߣ��洢Ϊʸ����
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableMatrix<Real> Multiply(const VariableLengthVector<Real>& diagonal, const VariableMatrix<Real>& matrix);

    /// U*V^T��U��N��1��V��M��1�������N��M��
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableMatrix<Real> OuterProduct(const VariableLengthVector<Real>& u, const VariableLengthVector<Real>& v);

    /// �ԽǾ���ĳ�ʼ������Խ�����D�ķ�������ʹ�Ƿ�ƽ���ġ�
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableMatrix<Real> MakeDiagonal(int rowsNumber, int columnsNumber, const VariableLengthVector<Real>& diagonal);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool Approximate(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance());

    /// ���������
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    std::ostream& operator<<(std::ostream& stream, const VariableMatrix<Real>& matrix);

    using VariableMatrixF = VariableMatrix<float>;
    using VariableMatrixD = VariableMatrix<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_H
