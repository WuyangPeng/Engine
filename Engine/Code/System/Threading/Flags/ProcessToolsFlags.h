///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/21 0:00)

#ifndef SYSTEM_THREADING_PROCESS_TOOLS_FLAGS_H
#define SYSTEM_THREADING_PROCESS_TOOLS_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class ProcessAffinity
    {
        Disables = 0x00000000UL,
        Enable = PROCESS_AFFINITY_ENABLE_AUTO_UPDATE,
    };

    enum class ProcessorFeature
    {
        FloatingPointPrecisionErrata = PF_FLOATING_POINT_PRECISION_ERRATA,
        FloatingPointEmulated = PF_FLOATING_POINT_EMULATED,
        CompareExchangeDouble = PF_COMPARE_EXCHANGE_DOUBLE,
        MmxInstructionsAvailable = PF_MMX_INSTRUCTIONS_AVAILABLE,
        PpcMovemem64BitOk = PF_PPC_MOVEMEM_64BIT_OK,
        AlphaByteInstructions = PF_ALPHA_BYTE_INSTRUCTIONS,
        XmmiInstructionsAvailable = PF_XMMI_INSTRUCTIONS_AVAILABLE,
        Now3DInstructionsAvailable = PF_3DNOW_INSTRUCTIONS_AVAILABLE,
        RdtscInstructionsAvailable = PF_RDTSC_INSTRUCTION_AVAILABLE,
        PaeEnabled = PF_PAE_ENABLED,
        Xmmi64InstructionsAvailable = PF_XMMI64_INSTRUCTIONS_AVAILABLE,
        SseDazModeAvailable = PF_SSE_DAZ_MODE_AVAILABLE,
        NxEnabled = PF_NX_ENABLED,
        Sse3InstructionsAvailable = PF_SSE3_INSTRUCTIONS_AVAILABLE,
        CompareExchange128 = PF_COMPARE_EXCHANGE128,
        Compare64Exchange128 = PF_COMPARE64_EXCHANGE128,
        ChannelsEnabled = PF_CHANNELS_ENABLED,
        XSaveEnabled = PF_XSAVE_ENABLED,
    };

    enum class ProcessShutdownParameters
    {
        Default = 0x00000001,
        ShutdownNoretry = SHUTDOWN_NORETRY,
    };

    enum class ProcessThreadAttribute
    {
        ParentProcess = PROC_THREAD_ATTRIBUTE_PARENT_PROCESS,
        HandleList = PROC_THREAD_ATTRIBUTE_HANDLE_LIST,
        GroupAffinity = PROC_THREAD_ATTRIBUTE_GROUP_AFFINITY,
        PreferredNode = PROC_THREAD_ATTRIBUTE_PREFERRED_NODE,
        IdealProcessor = PROC_THREAD_ATTRIBUTE_IDEAL_PROCESSOR,
        UmsThread = PROC_THREAD_ATTRIBUTE_UMS_THREAD,
        MitigationPolicy = PROC_THREAD_ATTRIBUTE_MITIGATION_POLICY,
    };

    enum class CtrlEvent
    {
        CEvent = CTRL_C_EVENT,
        BreakEvent = CTRL_BREAK_EVENT,
        Close = CTRL_CLOSE_EVENT,
        Logoff = CTRL_LOGOFF_EVENT,
        Shutdown = CTRL_SHUTDOWN_EVENT,
    };

    enum class ProcessAttachConsole : uint32_t
    {
        AttachParentProcess = ATTACH_PARENT_PROCESS,
    };

    enum class ProcessExitCode
    {
        StillActive = STILL_ACTIVE,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class ProcessAffinity
    {
        Disables = 0x00000000UL,
        Enable = 0x00000001UL,
    };

    enum class ProcessorFeature
    {
        FloatingPointPrecisionErrata = 0,
        FloatingPointEmulated = 1,
        CompareExchangeDouble = 2,
        MmxInstructionsAvailable = 3,
        PpcMovemem64BitOk = 4,
        AlphaByteInstructions = 5,
        XmmiInstructionsAvailable = 6,
        Now3DInstructionsAvailable = 7,
        RdtscInstructionsAvailable = 8,
        PaeEnabled = 9,
        Xmmi64InstructionsAvailable = 10,
        SseDazModeAvailable = 11,
        NxEnabled = 12,
        Sse3InstructionsAvailable = 13,
        CompareExchange128 = 14,
        Compare64Exchange128 = 15,
        ChannelsEnabled = 16,
        XSaveEnabled = 17,
    };

    enum class ProcessShutdownParameters
    {
        Default = 0x00000001,
        ShutdownNoretry = 0x00000002,
    };

    enum class ProcessThreadAttribute
    {
        ParentProcess = (0x00020000),
        HandleList = (2 | 0x00020000),
        GroupAffinity = (3 | 0x00010000 | 0x00020000),
        PreferredNode = (4 | 0x00020000),
        IdealProcessor = (5 | 0x00010000 | 0x00020000),
        UmsThread = (6 | 0x00010000 | 0x00020000),
        MitigationPolicy = (7 | 0x00020000),
    };

    enum class CtrlEvent
    {
        CEvent = 0,
        BreakEvent = 1,
        Close = 2,
        Logoff = 5,
        Shutdown = 6,
    };

    enum class ProcessAttachConsole : uint32_t
    {
        AttachParentProcess = (static_cast<uint32_t>(-1)),
    };

    enum class ProcessExitCode
    {
        StillActive = 0x00000103L,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_PROCESS_TOOLS_FLAGS_H