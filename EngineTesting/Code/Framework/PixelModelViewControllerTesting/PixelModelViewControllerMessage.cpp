// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/17 10:10)

#include "Testing.h"
#include "PixelModelViewControllerMessage.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 
#include "Framework/WindowProcess/WindowMessageDetail.h"
#include "Framework/MiddleLayer/ControllerMiddleLayerDetail.h"
#include "Framework/MiddleLayer/ModelViewControllerMiddleLayerContainerDetail.h"

#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"

PixelModelViewController::PixelModelViewControllerMessage
	::PixelModelViewControllerMessage(int64_t delta)
    : ParentType(delta), m_Alloc(CoreTools::DisableNotThrow::Disable)
{  
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}
 
PixelModelViewController::PixelModelViewControllerMessage
	::~PixelModelViewControllerMessage()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(PixelModelViewController, PixelModelViewControllerMessage)
 
 