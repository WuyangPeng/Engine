// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.4 (2019/09/17 10:10)

#include "FrameViewMiddleLayer.h" 
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 
#include "Framework/MiddleLayer/ModelMiddleLayer.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"

#include <iostream>

using std::cout;

PixelModelViewController::FrameViewMiddleLayer
	::FrameViewMiddleLayer(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }, m_TimeDelta{ sm_TimerInterval }
{ 
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

PixelModelViewController::FrameViewMiddleLayer
	::~FrameViewMiddleLayer()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(PixelModelViewController, FrameViewMiddleLayer)

bool PixelModelViewController::FrameViewMiddleLayer
	::Idle(int64_t timeDelta)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (ParentType::Idle(timeDelta))
	{
		PrintFrameRateMessage(timeDelta);

		return true;
	}
	else
	{
		return false;
	}
}

// private
void PixelModelViewController::FrameViewMiddleLayer
	::PrintFrameRateMessage(int64_t timeDelta)
{
	m_TimeDelta -= timeDelta;
	if (m_TimeDelta <= 0)
	{
		auto modelMiddleLayer = boost::polymorphic_pointer_downcast<Framework::ModelMiddleLayer>(this->GetModelMiddleLayer()); 

		if (modelMiddleLayer)
		{
			cout << modelMiddleLayer->GetFrameRateMessage() << '\n';
		}

		m_TimeDelta = sm_TimerInterval;
	}
}

 