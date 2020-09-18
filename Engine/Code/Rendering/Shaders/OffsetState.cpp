// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 16:56)

#include "Rendering/RenderingExport.h"

#include "OffsetState.h"
#include "Detail/OffsetStateImpl.h"
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
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, OffsetState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, OffsetState);
CORE_TOOLS_FACTORY_DEFINE(Rendering, OffsetState); 

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, OffsetState);

CORE_TOOLS_IMPL_NON_OBJECT_PTR_DEFAULT_STREAM(Rendering, OffsetState);

Rendering::OffsetState
	::OffsetState()
	:ParentType{ "OffsetState" }, m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::OffsetState
	::~OffsetState()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, OffsetState)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, OffsetState,IsFillEnabled,bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, OffsetState,IsLineEnabled,bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, OffsetState,IsPointEnabled, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, OffsetState,GetScale, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, OffsetState,GetBias, float)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, OffsetState,SetFillEnabled, bool, void)
										  
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, OffsetState,SetLineEnabled, bool, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, OffsetState,SetPointEnabled, bool, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, OffsetState,SetScale, float, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, OffsetState,SetBias, float, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, OffsetState,SaveState, WriteFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, OffsetState,LoadState, ReadFileManager&, void)

CoreTools::ObjectInterfaceSharedPtr Rendering::OffsetState::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP