// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:40)

#ifndef FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_IMPL_H
#define FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Time/CustomTime.h"

#include <string>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE PerformanceMeasurementsImpl
	{
	public:
		using ClassType = PerformanceMeasurementsImpl;
		using CustomTime = CoreTools::CustomTime;

	public:
		explicit PerformanceMeasurementsImpl(int maxTimer) noexcept;

		CLASS_INVARIANT_DECLARE;

		double GetFrameRate() const;
		std::string GetFrameRateMessage() const;

		void ResetTime() noexcept;
		void MeasureTime() noexcept;
		void UpdateFrameCount() noexcept;

	private:
		CustomTime m_CustomTime;
		int64_t m_AccumulatedTime;
		int m_FrameCount;
		int m_AccumulatedFrameCount;
		int m_Timer;
		int m_MaxTimer;
	};
}

#endif // FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_IMPL_H
