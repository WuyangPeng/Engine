// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ²âÊÔ°æ±¾£º0.3.0.1 (2020/05/27 0:08)

#include "HelperManagerInterface.h"
#include "HelperMiddleLayerFlags.h"
#include "HelperManagerInterfaceImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

using std::make_shared;

Framework::HelperManagerInterface
	::HelperManagerInterface(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }, m_Impl{ make_shared<ImplType>(System::EnumCastUnderlying(HelperMiddleLayer::Count)) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, HelperManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Helper, Input)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Helper, ObjectLogic)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Helper, Message)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Helper, Event)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Helper, Resource)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Helper, Audio)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Helper, CameraSystems)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Helper, Rendering)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Helper, Engine)

const Framework::ConstMiddleLayerInterfaceSharedPtr Framework::HelperManagerInterface
	::GetManager(HelperMiddleLayer helperMiddleLayer) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetMiddleLayerInterface(System::EnumCastUnderlying(helperMiddleLayer));
}
