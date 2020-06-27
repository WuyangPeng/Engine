// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 11:02)

#ifndef SYSTEM_THREADING_THREADING_FLAGS_FWD_H
#define SYSTEM_THREADING_THREADING_FLAGS_FWD_H 

#include "System/Helper/ConfigMacro.h"

namespace System
{
	// ConditionVariable
	enum class ConditionVariableLockMode;

	// CriticalSection
	enum class CriticalSectionInfo;

	// Event
	enum class EventSpecificAccess;
	enum class CreateEventType;

	// HandleTools
	enum class HandleInformation;
	enum class DuplicateOptions;

	// InitOnce
	enum class InitOnceBeginInitialize;

	// Mutex
	enum class MutexCreate;
	enum class MutexSpecificAccess;
	enum class PthreadResult : uint32_t;
	enum class PthreadMutexCompatibility;

	// Proces
	enum class ProcessCreation : uint32_t;
	enum class ProcessStandardAccess;
	enum class ProcessSpecificAccess;

	// ProcessTools
	enum class ProcessAffinity;
	enum class ProcessorFeature;
	enum class ProcessShutdownParameters;
	enum class ProcessThreadAttribute;
	enum class CtrlEvent;
	enum class ProcessAttachConsole : uint32_t;
	enum class ProcessExitCode;

	// Semaphore
	enum class MutexWait : uint32_t;
	enum class MutexWaitReturn : uint32_t;
	enum class MutexStandardAccess;
	enum class SemaphoreSpecificAccess;

	// SyncTools
	enum class SleepReturn;

	// Thread
	enum class ThreadCreation;
	enum class ThreadPriority;

	// ThreadLocalStorage
	enum class ThreadLocalStorageIndexes : uint32_t;

	// ThreadTools
	enum class ThreadStandardAccess;
	enum class ThreadSpecificAccess;
	enum class TokenStandardAccess;
	enum class TokenSpecificAccess;
	enum class ThreadContextState;

	// WaitableTimer
	enum class CreateWaitableTimerReset;
	enum class WaitableTimerSpecificAccess;
}

#endif // SYSTEM_THREADING_THREADING_FLAGS_FWD_H