// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 16:54)

#include "Rendering/RenderingExport.h"

#include "DepthState.h"
#include "Detail/DepthStateImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26456)
using std::make_shared;

CORE_TOOLS_RTTI_DEFINE(Rendering, DepthState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, DepthState);
CORE_TOOLS_FACTORY_DEFINE(Rendering, DepthState); 

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, DepthState);

CORE_TOOLS_IMPL_NON_OBJECT_PTR_DEFAULT_STREAM(Rendering, DepthState);

Rendering::DepthState
	::DepthState()
	:ParentType{ "DepthState" }, m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::DepthState
	::~DepthState()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, DepthState)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, DepthState,IsEnabled,bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, DepthState,IsWritable,bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, DepthState,GetCompare,Rendering::DepthState::CompareMode)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DepthState,SetEnabled, bool,void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DepthState,SetWritable, bool, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DepthState,SetCompare, CompareMode,void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DepthState,SaveState, WriteFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DepthState,LoadState, ReadFileManager&, void)

CoreTools::ObjectInterfaceSharedPtr Rendering::DepthState::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP