///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/11 15:38)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_H
#define MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Flags/MatrixFlags.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
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
    class VariableMatrixImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<VariableMatrixImpl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<VariableMatrixImpl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<VariableMatrixImpl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE VariableMatrix final : private boost::additive<VariableMatrix<Real>, boost::multiplicative<VariableMatrix<Real>, Real, boost::totally_ordered<VariableMatrix<Real>>>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using VariableMatrixImpl = VariableMatrixImpl<Real>;

    public:
        void Swap(VariableMatrix& rhs) noexcept;

    public:
        TYPE_DECLARE(VariableMatrix);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~VariableMatrix() noexcept = default;
        VariableMatrix(const VariableMatrix& rhs);
        VariableMatrix& operator=(const VariableMatrix& rhs);
        VariableMatrix(VariableMatrix&& rhs) noexcept;
        VariableMatrix& operator=(VariableMatrix&& rhs) noexcept;

        using Math = Math<Real>;
        using Matrix2 = Matrix2<Real>;
        using Matrix3 = Matrix3<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;
        using ContainerType = std::vector<Real>;
        using VectorContainerType = std::vector<VariableLengthVector>;

    public:
        explicit VariableMatrix(int rowsNumber = 0, int columnsNumber = 0);
        VariableMatrix(int rowsNumber, int columnsNumber, const ContainerType& entry);
        explicit VariableMatrix(const VectorContainerType& matrix);
        explicit VariableMatrix(const Matrix2& rhs);
        explicit VariableMatrix(const Matrix3& rhs);

        CLASS_INVARIANT_DECLARE;

        // ��Ա����

        // ʹ��ResetSize����վ����ݡ�
        void ResetSize(int rowsNumber, int columnsNumber);
        [[nodiscard]] int GetRowsNumber() const;
        [[nodiscard]] int GetColumnsNumber() const;
        [[nodiscard]] int GetElementsNumber() const;
        [[nodiscard]] const VariableLengthVector& operator[](int row) const;
        [[nodiscard]] VariableLengthVector& operator[](int row);
        [[nodiscard]] const Real& operator()(int row, int column) const;
        [[nodiscard]] Real& operator()(int row, int column);

        [[nodiscard]] ContainerType GetContainer() const;
        void SetContainer(int rowsNumber, int columnsNumber, const ContainerType& entry);

        void SetIdentity();

        void SetRow(int row, const VariableLengthVector& vector);
        [[nodiscard]] const VariableLengthVector GetRow(int row) const;
        void SetColumn(int column, const VariableLengthVector& vector);
        [[nodiscard]] const VariableLengthVector GetColumn(int column) const;
        void ResetMatrix(const VectorContainerType& matrix);

        // ֧�ֽ����к��С�
        void SwapRows(int lhsRow, int rhsRow);
        void SwapColumns(int lhsColumns, int rhsColumns);

        // ���ھ���˷�����this�������е���Ŀ�������rhs�����е���Ŀ
        VariableMatrix& operator*=(const VariableMatrix& rhs);

        [[nodiscard]] const VariableMatrix operator-() const;

        // �����������ͬ�Ĵ�С����ͬ��������������
        // ���ھ���ļӷ��ͼ������㡣
        VariableMatrix& operator+=(const VariableMatrix& rhs);
        VariableMatrix& operator-=(const VariableMatrix& rhs);
        VariableMatrix& operator*=(Real scalar);
        VariableMatrix& operator/=(Real scalar);

        // firstVector^T * M * secondVector
        // ��numColumns(M) = size(secondVector) ��
        // numRows(M) = size(firstVector) �Ǳ���ģ�
        [[nodiscard]] Real QuadraticForm(const VariableLengthVector& vector0, const VariableLengthVector& vector1) const;

        // M^T
        [[nodiscard]] const VariableMatrix Transpose() const;

        [[nodiscard]] const Matrix3 GetMatrix3() const;

    private:
        // �þ���洢�����������Զ�ά���顣
        using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
    };

    // �Ƚ� (��ʹ����STL����)��
    // �����������ͬ�Ĵ�С����ͬ��������������
    template <typename Real>
    [[nodiscard]] bool operator==(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool operator<(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    template <typename Real>
    [[nodiscard]] const VariableMatrix<Real> operator*(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    // M * v (numColumns(matrix) = size(vector) �Ǳ����)
    template <typename Real>
    [[nodiscard]] const VariableLengthVector<Real> operator*(const VariableMatrix<Real>& matrix, const VariableLengthVector<Real>& vector);

    // v^T * M (numRows(matrix) = size(vector) �Ǳ����)
    template <typename Real>
    [[nodiscard]] const VariableLengthVector<Real> operator*(const VariableLengthVector<Real>& vector, const VariableMatrix<Real>& matrix);

    // M^T * mat (numRows(lhs) = numRows(rhs) �Ǳ����)
    template <typename Real>
    [[nodiscard]] const VariableMatrix<Real> TransposeTimes(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    // M * mat^T (numColumns(lhs) = numColumns(rhs) �Ǳ����)
    template <typename Real>
    [[nodiscard]] const VariableMatrix<Real> TimesTranspose(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    // M^T * mat^T (numRows(lhs) = numColumns(rhs) �Ǳ����)
    template <typename Real>
    [[nodiscard]] const VariableMatrix<Real> TransposeTimesTranspose(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool Approximate(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs, const Real epsilon = Math<Real>::GetZeroTolerance());

    // ���������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const VariableMatrix<Real>& matrix);

    using FloatVariableMatrix = VariableMatrix<float>;
    using DoubleVariableMatrix = VariableMatrix<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_H
