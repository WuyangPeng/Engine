///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 11:23)

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
        NODISCARD Real GetXRoot() const;
        NODISCARD Real GetYRoot() const;
        NODISCARD BisectRootType GetBisectRootType() const noexcept;

    private:
        Real xRoot;
        Real yRoot;
        BisectRootType bisectRootType;
    };

    using Bisect2RootF = Bisect2Root<float>;
    using Bisect2RootD = Bisect2Root<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_ROOT_H
