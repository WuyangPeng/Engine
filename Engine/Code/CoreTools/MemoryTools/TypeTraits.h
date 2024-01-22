/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 09:46)

#ifndef CORE_TOOLS_MEMORY_TOOLS_TYPE_TRAITS_H
#define CORE_TOOLS_MEMORY_TOOLS_TYPE_TRAITS_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    /// float, double��long double��IsArbitraryPrecision<T>::value��'false'��
    /// �����Զ������ͣ���Ҫ�ػ�Ϊ'true'��
    template <typename T>
    struct IsArbitraryPrecisionInternal : std::false_type
    {
    };

    template <typename T>
    struct IsArbitraryPrecision : IsArbitraryPrecisionInternal<T>::type
    {
    };

    /// float, double��long double��HasDivisionOperator<T>::value��'true'��
    template <typename T>
    struct HasDivisionOperatorInternal : std::false_type
    {
    };

    template <typename T>
    struct HasDivisionOperator : HasDivisionOperatorInternal<std::remove_cv_t<T>>::type
    {
    };

    template <>
    struct HasDivisionOperatorInternal<float> : std::true_type
    {
    };

    template <>
    struct HasDivisionOperatorInternal<double> : std::true_type
    {
    };

    template <>
    struct HasDivisionOperatorInternal<long double> : std::true_type
    {
    };

    /// ģ�����Ϊ��Parameters��bool Condition�������л���ģ�����������(SFINAE)��ģ�������
    /// ʾ���÷�Ϊ
    /// template <Parameters, bool Condition = DefaultCondition, TraitSelector<Condition> = 0>
    /// ReturnType MemberFunction(inputs)
    /// { implementation for Condition = true; }
    ///
    /// template <Parameters, bool Condition = DefaultCondition, TraitSelector<!Condition> = 0>
    /// ReturnType MemberFunction(inputs)
    /// { implementation for Condition = false; }
    template <bool Condition>
    using TraitSelector = std::enable_if_t<Condition, int>;

    /// ���ھ�������ģ����������л���ģ�����������(SFINAE)��ģ�������ѡ������������������Ǹ��㻹�����⾫�ȡ�
    /// ʾ���÷�Ϊ
    /// template <typename Numeric, IsNotArbitraryPrecisionType<Numeric> = 0>
    /// Numeric MemberFunction(Numeric inputs)
    /// { floating-point computations }
    ///
    /// template <typename Numeric, IsArbitraryPrecisionType<Numeric> = 0>
    /// Numeric MemberFunction(Numeric inputs)
    /// { arbitrary-precision computations }
    template <typename T>
    using IsNotArbitraryPrecisionType = std::enable_if_t<!IsArbitraryPrecision<T>::value, int>;

    template <typename T>
    using IsArbitraryPrecisionType = std::enable_if_t<IsArbitraryPrecision<T>::value, int>;

    /// ���ھ�������ģ����������л���ģ�����������(SFINAE)��ģ�������ѡ������������������Ƿ�֧�ֳ�����
    /// ʾ���÷�Ϊ
    /// template <typename Numeric, IsDivisionType<Numeric> = 0>
    /// Numeric MemberFunction(Numeric inputs)
    /// { Numeric computations that use divisions }
    ///
    /// template <typename Numeric, IsNotDivisionType<Numeric> = 0>
    /// Numeric MemberFunction(Numeric inputs)
    /// { Numeric computations without divisions }
    template <typename T>
    using IsDivisionType = std::enable_if_t<HasDivisionOperator<T>::value, int>;

    template <typename T>
    using IsNotDivisionType = std::enable_if_t<!HasDivisionOperator<T>::value, int>;
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_TYPE_TRAITS_H
