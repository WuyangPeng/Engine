// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 16:56)

#ifndef CORE_TOOLS_TIME_SECOND_TIMER_H 
#define CORE_TOOLS_TIME_SECOND_TIMER_H

#include "CoreTools/CoreToolsDll.h"
#include "CoreTools/Helper/ExportMacro.h" 

CORE_TOOLS_EXPORT_SHARED_PTR(DeltaTimeManagerImpl);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE SecondTimer
	{
	public:
		using SecondTimerImpl = DeltaTimeManagerImpl;
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(SecondTimer);

	public:
		explicit SecondTimer(uint64_t second);

		CLASS_INVARIANT_DECLARE;

		uint64_t GetRemain() const noexcept;
		uint64_t GetElapsedTime() const noexcept;
		bool IsElapsed() const noexcept;
		uint64_t GetNowTime() const noexcept;

		void ReTiming(uint64_t second);

	private:
		IMPL_TYPE_DECLARE(SecondTimer);
		uint64_t m_Second;
	};
}

#endif // CORE_TOOLS_TIME_SECOND_TIMER_H
