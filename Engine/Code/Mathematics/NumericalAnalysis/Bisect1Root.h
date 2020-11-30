///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/19 14:40)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_ROOT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_ROOT_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/RootType.h"

#include <type_traits>

// ���ַ��ⷽ�̵ĸ�
namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Bisect1Root final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Bisect1Root<Real>;

    public:
        // �����޽�
        Bisect1Root() noexcept;
        // �����н�
        Bisect1Root(Real root, BisectRootType type) noexcept;

        CLASS_INVARIANT_DECLARE;

        // ��m_Bisect1RootType == Bisect1RootTypeHaveSolutionʱ��
        // m_Root����Ч�ġ�
        // ��m_Bisect1RootType == Bisect1RootTypeUnknownʱ��
        // m_Root�ǽ���ֵ������֤�������ȷ�ġ�
        // ��m_Bisect1RootType == Bisect1RootTypeNoSolutionʱ��
        // GetRoot()�׳��쳣��
        [[nodiscard]] Real GetRoot() const;
        [[nodiscard]] BisectRootType GetBisect1RootType() const noexcept;

    private:
        Real m_Root;
        BisectRootType m_Bisect1RootType;
    };

    using FloatBisect1Root = Bisect1Root<float>;
    using DoubleBisect1Root = Bisect1Root<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_ROOT_H
