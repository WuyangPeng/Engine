/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:09)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_FWD_H
#define CORE_TOOLS_TEMPLATE_TOOLS_FWD_H

namespace CoreTools
{
    template <typename T>
    struct MustBePod;

    template <typename T>
    struct MustBePodOrVoid;

    template <typename T1, typename T2>
    struct MustBeSameSize;

    template <typename T>
    struct MustBeSubscriptable;

    template <typename T>
    struct MustBeSubscriptableAsDecayablePointer;

    template <typename Derive, typename Base>
    struct MustHaveBase;

    template <unsigned N>
    struct Factorial;

    NODISCARD uint32_t RecursiveFactorial(uint32_t integer) noexcept;

    template <unsigned N>
    struct Fibonacci;

    NODISCARD uint32_t RecursiveFibonacci(uint32_t integer) noexcept;

    template <class T>
    struct ParamType;

    template <double& Radian, int MaxTerms>
    struct RecursiveSine;

    template <double& Radian>
    struct NonRecursiveSine;

    template <double& Radian>
    struct NonRecursiveCosine;

    template <double& Radian>
    struct NonRecursiveTangent;

    template <class T>
    class PtrLess;

    template <class T>
    class PtrGreater;

    template <bool Constant, typename Lhs, typename Rhs>
    class IfThenElse;

    template <int N, int Low, int High>
    class SqrtAlgorithm0;

    template <int N, int Low, int High>
    class SqrtAlgorithm1;

    template <int N, int I>
    class SqrtAlgorithm2;

    template <int N, int I>
    class SqrtAlgorithm3;

    template <int N>
    class Pow3;

    template <typename T>
    class ExplicitCast;

    template <typename T>
    class SimpleIncrementer;

    template <typename T>
    class SimpleDecrementer;

    template <typename T, typename Acquire, typename Release>
    class IncrementScope;

    template <typename T>
    NODISCARD T* GetAddress(T& t) noexcept;

    template <typename T, int64_t V>
    class LiteralCast;

    template <typename T>
    class ReferenceCast;

    template <typename T>
    class ValueScope;

    template <typename T0, typename T1, typename T2>
    struct Tiny;

    struct TinyNone;
    struct TinyTag;

    template <typename Tiny, typename Pos>
    struct TinyIterator;

    template <typename T, int N>
    struct TinyAt;

    template <typename T0, typename T1, typename T2>
    struct TinySize;

    template <typename TinyType, typename T, int N>
    struct TinyPushBack;

    template <typename T>
    struct CheckNotFull;

    template <typename T>
    struct CheckNotEmpty;

    template <typename TinyType, typename T, int N>
    struct TinyInsert;

    template <typename T0, typename T1, typename T2>
    struct TinyPopFront;

    template <typename T0, typename T1, typename T2>
    struct TinyPopBack;

    template <typename TinyType, int N>
    struct TinyErase;

    template <typename Tiny, typename Pos>
    struct TinyHasItem;

    template <typename Tiny, int F, int L>
    struct TinyEraseRange;

    template <typename Iterator>
    class ReversalObject;
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_FWD_H