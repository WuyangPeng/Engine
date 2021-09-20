// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/17 09:25)

#ifndef MODEL_VIEW_CONTROLLER_TESTING_FRAME_VIEW_MIDDLE_LAYER_H
#define MODEL_VIEW_CONTROLLER_TESTING_FRAME_VIEW_MIDDLE_LAYER_H

#include "Framework/MiddleLayer/ViewMiddleLayer.h" 
#include "System/Time/Using/DeltaTimeUsing.h"

namespace ModelViewController
{  
	class FrameViewMiddleLayer : public Framework::ViewMiddleLayer
	{
	public:
		using ClassType = FrameViewMiddleLayer;
		using ParentType = ViewMiddleLayer;

	public:
		explicit FrameViewMiddleLayer(Framework:: MiddleLayerPlatform middleLayerPlatform);
		virtual ~FrameViewMiddleLayer();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool Idle(int64_t timeDelta) override;

	private:
		void PrintFrameRateMessage(int64_t timeDelta);

	private:
		static constexpr int sm_TimerInterval = System::g_Microseconds;

		int64_t m_TimeDelta;
	};
}

#endif // MODEL_VIEW_CONTROLLER_TESTING_FRAME_VIEW_MIDDLE_LAYER_H
