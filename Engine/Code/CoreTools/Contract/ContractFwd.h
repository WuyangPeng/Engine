///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/22 14:40)

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