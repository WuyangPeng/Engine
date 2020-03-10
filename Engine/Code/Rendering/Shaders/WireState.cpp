// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:36)

#include "Rendering/RenderingExport.h"

#include "WireState.h"
#include "Detail/WireStateImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

CORE_TOOLS_RTTI_DEFINE(Rendering, WireState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, WireState);
CORE_TOOLS_FACTORY_DEFINE(Rendering, WireState); 

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, WireState);

CORE_TOOLS_IMPL_NON_OBJECT_PTR_DEFAULT_STREAM(Rendering, WireState);

Rendering::WireState
	::WireState()
	:ParentType{ "WireState" }, m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::WireState
	::~WireState()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, WireState)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, WireState,IsEnabled,bool)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, WireState, SetEnabled, bool, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, WireState,SaveState, WriteFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, WireState,LoadState, ReadFileManager&, void)