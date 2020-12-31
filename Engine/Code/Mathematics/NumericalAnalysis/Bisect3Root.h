///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/19 17:00)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/RootType.h"

#include <type_traits>

// ���ַ��ⷽ�̵ĸ�
namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Bisect3Root final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Bisect3Root<Real>;

    public:
        // �����޽�
        Bisect3Root() noexcept;
        // �����н�
        Bisect3Root(Real xRoot, Real yRoot, Real zRoot, BisectRootType type) noexcept;

        CLASS_INVARIANT_DECLARE;

        // ��m_BisectRootType == BisectRootType::HaveSolutionʱ��
        // m_XRoot��m_YRoot��m_ZRoot����Ч�ġ�
        // ��m_BisectRootType == BisectRootType::Unknownʱ��
        // m_XRoot��m_YRoot��m_ZRoot�ǽ���ֵ������֤�������ȷ�ġ�
        // ��m_BisectRootType == BisectRootType::NoSolutionʱ��
        // GetXRoot()��GetYRoot()��GetZRoot()�׳��쳣��
        [[nodiscard]] Real GetXRoot() const;
        [[nodiscard]] Real GetYRoot() const;
        [[nodiscard]] Real GetZRoot() const;
        [[nodiscard]] BisectRootType GetBisectRootType() const noexcept;

    private:
        Real m_XRoot;
        Real m_YRoot;
        Real m_ZRoot;
        BisectRootType m_BisectRootType;
    };

    using FloatBisect3Root = Bisect3Root<float>;
    using DoubleBisect3Root = Bisect3Root<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_H
