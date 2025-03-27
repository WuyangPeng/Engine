/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 10:00)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_ELIMINATION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_ELIMINATION_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/MemoryTools/LexicoArray2.h"
#include "Mathematics/Base/BaseFwd.h"

#include <vector>

namespace Mathematics
{
    /// �������matrix������NxN��
    /// Ԫ�ز��ҵĴ洢Լ����MATHEMATICS_USE_ROW_MAJOR������
    /// �������Ҫmatrix���棬����һ��wantInverseΪtrue��
    /// ���ص�inverseҲ������NxN����ʹ����M��ͬ�Ĵ洢Լ����
    /// �������Ҫmatrix���棬��ΪwantInverse����false��
    /// ���Ҫ���matrix * x = b �� x������x��b��Nx1���򴫵�b��
    /// ���ҪΪ���matrix * y = c�� y������y��c��NxK���򴫵�c������K���ݸ�numColumns��
    /// ����������£���N���ݸ�numRows��
    template <typename Real>
    class GaussianElimination final
    {
    public:
        using ClassType = GaussianElimination<Real>;

        using Container = std::vector<Real>;
        using MathType = Math<Real>;

    public:
        GaussianElimination(int numRows, const Container& matrix, bool wantInverse, const Container& b, int numColumns, const Container& c, Real epsilon = MathType::GetZeroTolerance());
        GaussianElimination(int numRows, const Container& matrix, bool wantInverse, Real epsilon = MathType::GetZeroTolerance());
        GaussianElimination(int numRows, const Container& matrix, bool wantInverse, const Container& b, Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsInverse() const noexcept;
        NODISCARD Container GetInverse() const;
        NODISCARD Container GetX() const;
        NODISCARD Container GetY() const;
        NODISCARD Real GetDeterminant() const noexcept;

    private:
        using IndexContainer = std::vector<int>;

#ifdef MATHEMATICS_USE_ROW_MAJOR

        using LexicoArray2 = CoreTools::LexicoArray2<true, typename Container::iterator>;

#else  // !MATHEMATICS_USE_ROW_MAJOR

        using LexicoArray2 = CoreTools::LexicoArray2<false, typename Container::iterator>;

#endif  // MATHEMATICS_USE_ROW_MAJOR

    private:
        void Init();

    private:
        int numRows;
        Container matrix;
        bool wantInverse;
        Container b;
        int numColumns;
        Container c;
        Real epsilon;

        bool isInverse;
        LexicoArray2 inverseMatrix;
        Real determinant;
        Container x;
        LexicoArray2 y;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_ELIMINATION_H