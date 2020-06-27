// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:46)

#ifndef FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_H
#define FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 

#include <string>

FRAMEWORK_EXPORT_SHARED_PTR(PerformanceMeasurementsImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE PerformanceMeasurements
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(PerformanceMeasurements);

	public:
		explicit PerformanceMeasurements(int maxTimer);

		CLASS_INVARIANT_DECLARE;

		double GetFrameRate() const;
		std::string GetFrameRateMessage() const;

		void ResetTime();
		void MeasureTime();
		void UpdateFrameCount();

	private:
		IMPL_TYPE_DECLARE(PerformanceMeasurements);
	};
}

#endif // FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_H
