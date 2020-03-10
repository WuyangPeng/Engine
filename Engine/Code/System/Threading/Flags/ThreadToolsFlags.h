// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:08)

#ifndef SYSTEM_THREADING_THREAD_TOOLS_FLAGS_H
#define SYSTEM_THREADING_THREAD_TOOLS_FLAGS_H  

#include "System/Helper/Platform.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	enum class ThreadStandardAccess
	{
		Default = (0x00000000L),
		Delete = DELETE,
		ReadControl = READ_CONTROL,
		WriteDac = WRITE_DAC,
		WriteOwner = WRITE_OWNER,
		Synchronize = SYNCHRONIZE,
	};

	enum class ThreadSpecificAccess
	{
		Synchronize = SYNCHRONIZE,
		Terminate = THREAD_TERMINATE,
		SuspendResume = THREAD_SUSPEND_RESUME,
		GetContext = THREAD_GET_CONTEXT,
		SetContext = THREAD_SET_CONTEXT,
		QueryInformation = THREAD_QUERY_INFORMATION,
		SetInformation = THREAD_SET_INFORMATION,
		SetThreadToken = THREAD_SET_THREAD_TOKEN,
		Impersonate = THREAD_IMPERSONATE,
		DirectImpersonation = THREAD_DIRECT_IMPERSONATION,
		SetLimitedInformation = THREAD_SET_LIMITED_INFORMATION,
		QueryLimitedInformation = THREAD_QUERY_LIMITED_INFORMATION,
		AllAccess = THREAD_ALL_ACCESS,
	};

	enum class TokenStandardAccess
	{
		Default = 0x00000000L,
		Delete = DELETE,
		ReadControl = READ_CONTROL,
		WriteDac = WRITE_DAC,
		WriteOwner = WRITE_OWNER,
		AccessSystemSecurity = ACCESS_SYSTEM_SECURITY,
	};

	enum class TokenSpecificAccess
	{
		Default = 0x0000,
		AssignPrimary = TOKEN_ASSIGN_PRIMARY,
		Duplicate = TOKEN_DUPLICATE,
		Impersonate = TOKEN_IMPERSONATE,
		Query = TOKEN_QUERY,
		QuerySource = TOKEN_QUERY_SOURCE,
		AdjustPrivileges = TOKEN_ADJUST_PRIVILEGES,
		AdjustGroups = TOKEN_ADJUST_GROUPS,
		AdjustDefault = TOKEN_ADJUST_DEFAULT,
		AdjustSessionID = TOKEN_ADJUST_SESSIONID,

		AllAccessP = TOKEN_ALL_ACCESS_P,
		AllAccess = TOKEN_ALL_ACCESS,

		Read = TOKEN_READ,
		Write = TOKEN_WRITE,
		Execute = TOKEN_EXECUTE,
	};

	enum class ThreadContextState
	{
		Control = CONTEXT_CONTROL,
		Integer = CONTEXT_INTEGER,
		Segments = CONTEXT_SEGMENTS,
		FloatingPoint = CONTEXT_FLOATING_POINT,
		DebugRegisters = CONTEXT_DEBUG_REGISTERS,

		Full = CONTEXT_FULL,
		All = CONTEXT_ALL,
		XState = CONTEXT_XSTATE,
	};

#else // !SYSTEM_PLATFORM_WIN32

	enum class ThreadStandardAccess
	{
		Default = (0x00000000L),
		Delete = (0x00010000L),
		ReadControl = (0x00020000L),
		WriteDac = (0x00040000L),
		WriteOwner = (0x00080000L),
		Synchronize = (0x00100000L),
	};

	enum class ThreadSpecificAccess
	{
		Synchronize = (0x00100000L),
		Terminate = (0x0001),
		SuspendResume = (0x0002),
		GetContext = (0x0008),
		SetContext = (0x0010),
		QueryInformation = (0x0040),
		SetInformation = (0x0020),
		SetThreadToken = (0x0080),
		Impersonate = (0x0100),
		DirectImpersonation = (0x0200),
		SetLimitedInformation = (0x0400),
		QueryLimitedInformation = (0x0800),
		Resume = (0x1000),
		AllAccess = (0x000F0000L | Synchronize | 0xFFFF),
	};

	enum class TokenStandardAccess
	{
		Default = (0x00000000L),
		Delete = (0x00010000L),
		ReadControl = (0x00020000L),
		WriteDac = (0x00040000L),
		WriteOwner = (0x00080000L),
		AccessSystemSecurity = (0x01000000L),
	};

	enum class TokenSpecificAccess
	{
		Default = 0x0000,
		AssignPrimary = (0x0001),
		Duplicate = (0x0002),
		Impersonate = (0x0004),
		Query = (0x0008),
		QuerySource = (0x0010),
		AdjustPrivileges = (0x0020),
		AdjustGroups = (0x0040),
		AdjustDefault = (0x0080),
		AdjustSessionID = (0x0100),

		AllAccessP = (0x000F0000L | AssignPrimary | Duplicate | Impersonate | Query | QuerySource | AdjustPrivileges | AdjustGroups | AdjustDefault),

		AllAccess = (AllAccessP | AdjustSessionID),

		Read = (0x00020000L | Query),
		Write = (0x00020000L | AdjustPrivileges | AdjustGroups | AdjustSessionID),
		Execute = 0x00020000L,
	};

	enum class ThreadContextState
	{
		I386 = 0x00010000L,
		I486 = 0x00010000L,

		Control = (I386 | 0x00000001L),
		Integer = (I386 | 0x00000002L),
		Segments = (I386 | 0x00000004L),
		FloatingPoint = (I386 | 0x00000008L),
		DebugRegisters = (I386 | 0x00000010L),
		ExtendedRegisters = (I386 | 0x00000020L),

		Full = (Control | Integer | Segments),

		All = (Control | Integer | Segments | FloatingPoint | DebugRegisters | ExtendedRegisters),

		XState = (I386 | 0x00000040L),
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_THREADING_THREAD_TOOLS_FLAGS_H