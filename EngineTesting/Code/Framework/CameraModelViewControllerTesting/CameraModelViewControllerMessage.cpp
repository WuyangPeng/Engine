// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.4 (2019/09/10 17:36)

#include "Testing.h"
#include "CameraModelViewControllerMessage.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 
#include "Framework/WindowProcess/WindowMessageDetail.h"
#include "Framework/MiddleLayer/CameraControllerMiddleLayerDetail.h"
#include "Framework/MiddleLayer/ModelViewControllerMiddleLayerContainerDetail.h"

#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"

CameraModelViewController::CameraModelViewControllerMessage
	::CameraModelViewControllerMessage(int64_t delta)
    : ParentType{ delta }, m_Alloc{ CoreTools::DisableNotThrow::Disable }
{ 
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CameraModelViewController::CameraModelViewControllerMessage
	::~CameraModelViewControllerMessage()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CameraModelViewController, CameraModelViewControllerMessage)
 
 