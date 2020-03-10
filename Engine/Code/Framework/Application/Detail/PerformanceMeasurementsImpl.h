// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:03)

#ifndef FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_IMPL_H
#define FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_IMPL_H

#include "CoreTools/Time/CustomTime.h"

#include <string>

namespace Framework
{
	class PerformanceMeasurementsImpl
	{
	public:
		using ClassType = PerformanceMeasurementsImpl;
		using CustomTime = CoreTools::CustomTime;

	public:	
		explicit PerformanceMeasurementsImpl(int maxTimer);
		
		CLASS_INVARIANT_DECLARE;

		double GetFrameRate () const;

		void ResetTime ();
		void MeasureTime ();
		void UpdateFrameCount ();	

		std::string GetFrameRateMessage() const;

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
