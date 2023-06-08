///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 16:41)

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
        NODISCARD Real GetXRoot() const;
        NODISCARD Real GetYRoot() const;
        NODISCARD Real GetZRoot() const;
        NODISCARD BisectRootType GetBisectRootType() const noexcept;

    private:
        Real xRoot;
        Real yRoot;
        Real zRoot;
        BisectRootType bisectRootType;
    };

    using Bisect3RootF = Bisect3Root<float>;
    using Bisect3RootD = Bisect3Root<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_H
