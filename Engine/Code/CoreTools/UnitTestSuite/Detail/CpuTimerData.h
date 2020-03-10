// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:12)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_CPU_TIMER_DATA_H
#define CORE_TOOLS_UNIT_TEST_SUITE_CPU_TIMER_DATA_H

#include "CoreTools/CoreToolsDll.h"

#include <boost/noncopyable.hpp>
#include <memory>

namespace boost
{
	namespace timer
	{
		class cpu_timer;
	}
}

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE CpuTimerData : private boost::noncopyable
	{
	public:
		using ClassType = CpuTimerData;
		using CpuTimer = boost::timer::cpu_timer;
		using CpuTimerPtr = std::shared_ptr<CpuTimer>;

	public:
		CpuTimerData();

		CLASS_INVARIANT_DECLARE;

		const CpuTimerPtr GetCpuTimerPtr() const noexcept;

		void Start() noexcept;
		void Resume() noexcept;
		void Stop() noexcept;

	private:
		CpuTimerPtr m_CpuTimerPtr;
	};
}

#endif // CORE_TOOLS_UNIT_TEST_SUITE_CPU_TIMER_DATA_H
