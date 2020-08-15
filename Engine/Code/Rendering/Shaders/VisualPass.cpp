// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 17:31)

#include "Rendering/RenderingExport.h"

#include "VisualPass.h"
#include "Detail/VisualPassImpl.h"
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
CORE_TOOLS_RTTI_DEFINE(Rendering, VisualPass);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VisualPass);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VisualPass);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, VisualPass);

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, VisualPass);

CORE_TOOLS_IMPL_OBJECT_PTR_DEFAULT_STREAM(Rendering, VisualPass); 

Rendering::VisualPass
	::VisualPass()
	:ParentType{ "VisualPass" }, m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VisualPass
	::~VisualPass()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, VisualPass)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualPass,SetVertexShader, VertexShaderSmartPointer, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualPass,SetPixelShader, PixelShaderSmartPointer, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualPass,SetAlphaState, AlphaStateSmartPointer, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualPass,SetCullState, CullStateSmartPointer, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualPass,SetDepthState, DepthStateSmartPointer, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualPass,SetOffsetState, OffsetStateSmartPointer, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualPass,SetStencilState, StencilStateSmartPointer, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualPass,SetWireState, WireStateSmartPointer, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualPass,GetVertexShader, const Rendering::ConstVertexShaderSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualPass,GetPixelShader,const Rendering::ConstPixelShaderSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualPass,GetAlphaState,const Rendering::ConstAlphaStateSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualPass,GetCullState,const Rendering::ConstCullStateSmartPointer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualPass,GetDepthState,const Rendering::ConstDepthStateSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualPass,GetOffsetState,const Rendering::ConstOffsetStateSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualPass,GetStencilState,const Rendering::ConstStencilStateSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualPass,GetWireState,const Rendering::ConstWireStateSmartPointer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualPass,SaveShader, WriteFileManager&, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualPass,SaveState, WriteFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualPass,LoadShader, ReadFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualPass,LoadState, ReadFileManager&, void)

#include STSTEM_WARNING_POP