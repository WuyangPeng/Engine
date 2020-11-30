///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/23 16:48)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_ROOT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_ROOT_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/RootType.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE BrentsMethodRoot final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BrentsMethodRoot<Real>;

    public:
        // �����޽�
        BrentsMethodRoot() noexcept;
        // �����н�
        BrentsMethodRoot(Real root, Real function, BrentsMethodRootType type) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetRoot() const;
        [[nodiscard]] Real GetFunction() const;
        [[nodiscard]] BrentsMethodRootType GetBrentsMethodRootType() const noexcept;

    private:
        Real m_Root;
        Real m_Function;
        BrentsMethodRootType m_BrentsMethodRootType;
    };

    using FloatBrentsMethodRoot = BrentsMethodRoot<float>;
    using DoubleBrentsMethodRoot = BrentsMethodRoot<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_ROOT_H
