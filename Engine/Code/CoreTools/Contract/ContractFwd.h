//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/10 13:05)

#ifndef CORE_TOOLS_CONTRACT_FWD_H
#define CORE_TOOLS_CONTRACT_FWD_H

namespace CoreTools
{
    enum class TriggerAssertCheck;
    enum class CheckInvariantConditions;
    enum class DisableNotThrow;

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
}

#endif  // CORE_TOOLS_CONTRACT_FWD_H