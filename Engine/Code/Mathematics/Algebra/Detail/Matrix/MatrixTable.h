/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/01/30 20:01)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_TABLE_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_TABLE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"

#include <array>

namespace Mathematics::Algebra
{
    template <int NumRows, int NumColumns, typename Real>
    requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
    class MatrixTable
    {
    public:
        using ClassType = MatrixTable<NumRows, NumColumns, Real>;

    public:
        MatrixTable() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// �洢˳�������Ԫ�ط���Ϊ2D���С�
        NODISCARD const Real& operator()(int row, int column) const;
        NODISCARD Real& operator()(int row, int column);

        /// Ԫ�ط���Ϊ1D���顣
        /// ������ά�洢˳�����ʱ�������ڲ�ʹ�ô�ѡ�
        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);

        NODISCARD bool operator==(const MatrixTable& rhs) const;
        NODISCARD bool operator<(const MatrixTable& rhs) const;

    private:
#if defined(MATHEMATICS_USE_ROW_MAJOR)

        using StorageType = std::array<std::array<Real, NumColumns>, NumRows>;

#else  // !MATHEMATICS_USE_ROW_MAJOR

        using StorageType = std::array<std::array<Real, NumRows>, NumColumns>;

#endif  // MATHEMATICS_USE_ROW_MAJOR

    private:
        StorageType storage;
    };
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_TABLE_H
