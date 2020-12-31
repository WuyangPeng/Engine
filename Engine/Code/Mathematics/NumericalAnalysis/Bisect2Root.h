///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/19 15:32)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_ROOT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_ROOT_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/RootType.h"

#include <type_traits>

// ���ַ��ⷽ�̵ĸ�
namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Bisect2Root final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Bisect2Root<Real>;

    public:
        // �����޽�
        Bisect2Root() noexcept;
        // �����н�
        Bisect2Root(Real xRoot, Real yRoot, BisectRootType type) noexcept;

        CLASS_INVARIANT_DECLARE;

        // ��m_BisectRootType == BisectRootType::HaveSolutionʱ��
        // m_XRoot��m_YRoot����Ч�ġ�
        // ��m_BisectRootType == BisectRootType::Unknownʱ��
        // m_XRoot��m_YRoot�ǽ���ֵ������֤�������ȷ�ġ�
        // ��m_BisectRootType == BisectRootType::NoSolutionʱ��
        // GetXRoot()��GetYRoot()�׳��쳣��
        [[nodiscard]] Real GetXRoot() const;
        [[nodiscard]] Real GetYRoot() const;
        [[nodiscard]] BisectRootType GetBisectRootType() const noexcept;

    private:
        Real m_XRoot;
        Real m_YRoot;
        BisectRootType m_BisectRootType;
    };

    using FloatBisect2Root = Bisect2Root<float>;
    using DoubleBisect2Root = Bisect2Root<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_ROOT_H
