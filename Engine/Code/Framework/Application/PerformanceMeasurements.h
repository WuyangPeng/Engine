// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:10)

#ifndef FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_H
#define FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "System/Helper/UnicodeUsing.h"

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

		double GetFrameRate () const;

		void ResetTime ();
		void MeasureTime ();
		void UpdateFrameCount ();		
		
		std::string GetFrameRateMessage() const;

	private:
		IMPL_TYPE_DECLARE(PerformanceMeasurements);
	};
}

#endif // FRAMEWORK_APPLICATION_PERFORMANCE_MEASUREMENTS_H
