// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:19)

#include "Rendering/RenderingExport.h"

#include "StencilState.h"
#include "Detail/StencilStateImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26426)
CORE_TOOLS_RTTI_DEFINE(Rendering, StencilState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, StencilState);
CORE_TOOLS_FACTORY_DEFINE(Rendering, StencilState); 

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, StencilState);

CORE_TOOLS_IMPL_NON_OBJECT_PTR_DEFAULT_STREAM(Rendering, StencilState);

Rendering::StencilState
	::StencilState()
	:ParentType{ "StencilState" }, m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::StencilState
	::~StencilState()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, StencilState)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StencilState,IsEnabled,bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StencilState,GetCompare,Rendering::StencilState::CompareMode)
								 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StencilState,GetReference,unsigned int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StencilState,GetMask,unsigned int)									
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StencilState, GetWriteMask,unsigned int)									
									 								 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StencilState,GetOnFail,Rendering::StencilState::OperationType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StencilState,GetOnZFail,Rendering::StencilState::OperationType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StencilState,GetOnZPass,Rendering::StencilState::OperationType)
		
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState,SetEnabled, bool, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState,SetCompare, CompareMode, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState,SetReference, unsigned int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState,SetMask, unsigned int, void)								  
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState,SetWriteMask, unsigned int, void)								  
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState,SetOnFail, OperationType, void)								  
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState,SetOnZFail, OperationType, void)								  
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState,SetOnZPass, OperationType, void)								  
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState,SaveState, WriteFileManager&, void)

									  
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState,LoadState, ReadFileManager&, void)
#include STSTEM_WARNING_POP