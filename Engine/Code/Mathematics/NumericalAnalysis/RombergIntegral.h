/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:43)

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

        // 最后一个参数是用户定义的数据。
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
