// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:36)

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
		ModelMiddleLayerImpl(); 
	
		CLASS_INVARIANT_DECLARE;

		void ResetTime();
		std::string GetFrameRateMessage() const;
		void MeasureTime ();
		void UpdateFrameCount ();
		double GetFrameRate() const;
		
	private:
		PerformanceMeasurements m_PerformanceMeasurements;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_MODEL_MIDDLE_LAYER_IMPL_H

