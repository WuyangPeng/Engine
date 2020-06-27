// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:45)

#ifndef FRAMEWORK_MIDDLE_LAYER_MODEL_MIDDLE_LAYER_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_MODEL_MIDDLE_LAYER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Framework/Application/PerformanceMeasurements.h" 

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE ModelMiddleLayerImpl
	{
	public:
		using ClassType = ModelMiddleLayerImpl;

	public:
		explicit ModelMiddleLayerImpl(int maxTimer);

		CLASS_INVARIANT_DECLARE;

		double GetFrameRate() const;
		std::string GetFrameRateMessage() const;

		void ResetTime();
		void MeasureTime();
		void UpdateFrameCount();

	private:
		PerformanceMeasurements m_PerformanceMeasurements;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_MODEL_MIDDLE_LAYER_IMPL_H

