///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 15:02)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_H
#define MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "VariableLengthVector.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

// ��������Ӧ��Ϊ��ˡ�
// ���磬�����ľ���M������V�������ʸ��ΪM * V��
// Ҳ����˵��V������һ����������
// һЩͼ��APIʹ��V * M������V����Ϊ��������
// ����Щ�����У�����M����������M����ʾ��ת�á�
// ���Ƶأ�Ӧ��2����������M0��M1���Ը�˳��
// �����M1*M0��һ��������ת���ǣ�M1 * M0��* V = M1 *��M0* V����
// һЩͼ��APIʹ��M0 * M1����ͬ����Щ������ָ��������ʾ��ת�á�
// ��ˣ���һ��ҪС���������ͼ��API�ӿ���ת�����롣
//
// ���󱻴���Ϊ�����򱣴棬matrix[row][col].

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
        VariableMatrix() noexcept = default;
        VariableMatrix(int rowsNumber, int columnsNumber);
        VariableMatrix(int rowsNumber, int columnsNumber, const ContainerType& entry);
        explicit VariableMatrix(const VectorContainerType& matrix);
        explicit VariableMatrix(const Matrix2& rhs);
        explicit VariableMatrix(const Matrix3& rhs);

        CLASS_INVARIANT_DECLARE;

        // ��Ա����

        // ʹ��ResetSize����վ����ݡ�
        void ResetSize(int rowsNumber, int columnsNumber);
        NODISCARD int GetRowsNumber() const;
        NODISCARD int GetColumnsNumber() const;
        NODISCARD int GetElementsNumber() const;
        NODISCARD const VariableLengthVector& operator[](int row) const;
        NODISCARD VariableLengthVector& operator[](int row);
        NODISCARD const Real& operator()(int row, int column) const;
        NODISCARD Real& operator()(int row, int column);

        NODISCARD ContainerType GetContainer() const;
        void SetContainer(int rowsNumber, int columnsNumber, const ContainerType& entry);

        void SetIdentity();

        void SetRow(int row, const VariableLengthVector& vector);
        NODISCARD VariableLengthVector GetRow(int row) const;
        void SetColumn(int column, const VariableLengthVector& vector);
        NODISCARD VariableLengthVector GetColumn(int column) const;
        void ResetMatrix(const VectorContainerType& matrix);

        // ֧�ֽ����к��С�
        void SwapRows(int lhsRow, int rhsRow);
        void SwapColumns(int lhsColumns, int rhsColumns);

        // ���ھ���˷�����this�������е���Ŀ�������rhs�����е���Ŀ
        VariableMatrix& operator*=(const VariableMatrix& rhs);

        NODISCARD VariableMatrix operator-() const;

        // �����������ͬ�Ĵ�С����ͬ��������������
        // ���ھ���ļӷ��ͼ������㡣
        VariableMatrix& operator+=(const VariableMatrix& rhs);
        VariableMatrix& operator-=(const VariableMatrix& rhs);
        VariableMatrix& operator*=(Real scalar);
        VariableMatrix& operator/=(Real scalar);

        // firstVector^T * M * secondVector
        // ��numColumns(M) = size(secondVector) ��
        // numRows(M) = size(firstVector) �Ǳ���ģ�
        NODISCARD Real QuadraticForm(const VariableLengthVector& vector0, const VariableLengthVector& vector1) const;

        // M^T
        NODISCARD VariableMatrix Transpose() const;

        NODISCARD Matrix3 GetMatrix3() const;

    private:
        // �þ���洢�����������Զ�ά���顣
        VectorContainerType container;
    };

    // �Ƚ� (��ʹ����STL����)��
    // �����������ͬ�Ĵ�С����ͬ��������������
    template <typename Real>
    NODISCARD bool operator==(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    template <typename Real>
    NODISCARD bool operator<(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    template <typename Real>
    NODISCARD VariableMatrix<Real> operator*(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    // M * v (numColumns(matrix) = size(vector) �Ǳ����)
    template <typename Real>
    NODISCARD VariableLengthVector<Real> operator*(const VariableMatrix<Real>& matrix, const VariableLengthVector<Real>& vector);

    // v^T * M (numRows(matrix) = size(vector) �Ǳ����)
    template <typename Real>
    NODISCARD VariableLengthVector<Real> operator*(const VariableLengthVector<Real>& vector, const VariableMatrix<Real>& matrix);

    // M^T * mat (numRows(lhs) = numRows(rhs) �Ǳ����)
    template <typename Real>
    NODISCARD VariableMatrix<Real> TransposeTimes(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    // M * mat^T (numColumns(lhs) = numColumns(rhs) �Ǳ����)
    template <typename Real>
    NODISCARD VariableMatrix<Real> TimesTranspose(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    // M^T * mat^T (numRows(lhs) = numColumns(rhs) �Ǳ����)
    template <typename Real>
    NODISCARD VariableMatrix<Real> TransposeTimesTranspose(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    template <typename Real>
    NODISCARD bool Approximate(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs, const Real epsilon = Math<Real>::GetZeroTolerance());

    // ���������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const VariableMatrix<Real>& matrix);

    using VariableMatrixF = VariableMatrix<float>;
    using VariableMatrixD = VariableMatrix<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_H
