// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:14)

#ifndef CORE_TOOLS_THREADING_MUTEX_H
#define CORE_TOOLS_THREADING_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "DllMutex.h"

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE Mutex : public DllMutex
	{
	public:
		using ClassType = Mutex;
		using ParentType = DllMutex;

	public:
		explicit Mutex(MutexCreate mutexCreate = MutexCreate::UseCriticalSection);
		~Mutex();
		Mutex(const Mutex&) = delete;
		Mutex& operator=(const Mutex&) = delete;
		Mutex(Mutex&&) noexcept = delete;
		Mutex& operator=(Mutex&&) noexcept = delete;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		void Initialize() override;
		void Delete() override;
	};
}

#endif // CORE_TOOLS_THREADING_MUTEX_H
