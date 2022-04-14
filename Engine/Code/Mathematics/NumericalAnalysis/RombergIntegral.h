///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/17 11:02)

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

        NODISCARD Real GetValue() const noexcept;

    private:
        using Container = std::vector<Real>;
        using RomType = std::array<Container, 2>;

    private:
        void Calculate();

    private:
        int order;
        Real begin;
        Real end;
        Function function;
        const UserDataType* userData;
        Real value;
        RomType rom;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROMBERG_INTEGRAL_H
