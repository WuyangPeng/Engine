///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/21 9:50)

#ifndef CORE_TOOLS_CONTRACT_FWD_H
#define CORE_TOOLS_CONTRACT_FWD_H

namespace CoreTools
{
    enum class TriggerAssertCheck;
    enum class CheckInvariantConditions;
    enum class DisableNotThrow;
    enum class ImplCreateUseFactory;
    enum class ImplCreateUseDefaultConstruction;

    class FunctionDescribed;

    template <typename T>
    class ScopeExit;

    class TriggerAssert;

    template <typename T>
    class CheckInvariant;

    class Assertion;

    struct TrueType;
    struct FalseType;

    struct ShareClasses;
    struct PerformanceUnsharedClasses;
    struct CopyUnsharedClasses;
    struct DelayCopyUnsharedClasses;
    struct NonCopyClasses;

    template <typename Original, typename Package>
    class CopyUnsharedImpl;

    template <typename Original, typename Package>
    class DelayCopyUnsharedImpl;

    template <typename T>
    class NonCopyImpl;

    template <typename T>
    class PerformanceUnsharedImpl;

    template <typename T>
    class SharedImpl;
}

#endif  // CORE_TOOLS_CONTRACT_FWD_H