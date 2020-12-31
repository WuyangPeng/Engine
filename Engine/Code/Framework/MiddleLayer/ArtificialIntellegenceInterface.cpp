// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:53)

#include "Framework/FrameworkExport.h"

#include "ArtificialIntellegenceInterface.h"
#include "Flags/ObjectLogicManagerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h" 
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

using std::make_shared;

Framework::ArtificialIntellegenceInterface
	::ArtificialIntellegenceInterface(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }, m_Impl{ make_shared<ImplType>(System::EnumCastUnderlying(ObjectLogicMiddleLayer::Count)) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Framework, ArtificialIntellegenceInterface)

ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ArtificialIntellegence, ObjectLogic, Input)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ArtificialIntellegence, ObjectLogic, Network)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ArtificialIntellegence, ObjectLogic, PhysicalModelling)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ArtificialIntellegence, ObjectLogic, Message)
ENGINE_MIDDLE_LAYER_CHILD_COMPONENTS_DEFINE(Framework, ArtificialIntellegence, ObjectLogic, System)