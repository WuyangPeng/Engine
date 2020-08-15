// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:12)

#ifndef CORE_TOOLS_THREADING_SEMAPHORE_IMPL_H
#define CORE_TOOLS_THREADING_SEMAPHORE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Window/Using/WindowUsing.h"

#include <atomic>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE SemaphoreImpl
	{
	public:
		using ClassType = SemaphoreImpl;
		using SemaphoreHandle = System::WindowHandle;

	public:
		SemaphoreImpl(int initialCount, int maximumCount);
		~SemaphoreImpl();
		SemaphoreImpl(const SemaphoreImpl&) = delete;
		SemaphoreImpl& operator=(const SemaphoreImpl&) = delete;
		SemaphoreImpl(SemaphoreImpl&&) noexcept = delete;
		SemaphoreImpl& operator=(SemaphoreImpl&&) noexcept = delete;

		CLASS_INVARIANT_DECLARE;

		void Release(int releaseCount);
		void Wait();

		int GetCurrentCount() const noexcept;
		int GetMaximumCount() const noexcept;

	private:
		using IntAtomic = std::atomic<int>;

	private:
		SemaphoreHandle m_Handle;
		IntAtomic m_CurrentCount;
		int m_MaximumCount;
	};
}

#endif // CORE_TOOLS_THREADING_SEMAPHORE_IMPL_H
