///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/30 10:10)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROMBERG_INTEGRAL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROMBERG_INTEGRAL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real, typename UserDataType>
    class RombergIntegral final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = RombergIntegral<Real, UserDataType>;

        // ���һ���������û���������ݡ�
        using Function = Real (*)(Real, const UserDataType*);
        using Math = Math<Real>;

    public:
        RombergIntegral(int order, Real begin, Real end, Function function, const UserDataType* userData);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetValue() const noexcept;

    private:
        using Container = std::vector<Real>;
        using RomType = std::array<Container, 2>;

    private:
        void Calculate() noexcept;

    private:
        int m_Order;
        Real m_Begin;
        Real m_End;
        Function m_Function;
        const UserDataType* m_UserData;
        Real m_Value;
        RomType m_Rom;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROMBERG_INTEGRAL_H
