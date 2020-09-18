// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:33)

#include "Rendering/RenderingExport.h"

#include "VisualTechnique.h"
#include "Detail/VisualTechniqueImpl.h"
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
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, VisualTechnique);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VisualTechnique);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VisualTechnique);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, VisualTechnique);

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, VisualTechnique);

CORE_TOOLS_IMPL_OBJECT_PTR_DEFAULT_STREAM(Rendering, VisualTechnique);

Rendering::VisualTechnique
	::VisualTechnique()
	:ParentType("VisualTechnique"), m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VisualTechnique
	::~VisualTechnique()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, VisualTechnique)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualTechnique,InsertPass,VisualPassSmartPointer,void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualTechnique,GetNumPasses,int) 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique,GetPass,int,const Rendering::ConstVisualPassSmartPointer) 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique,GetVertexShader,int,const Rendering::ConstVertexShaderSmartPointer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique,GetPixelShader,int,const Rendering::ConstPixelShaderSmartPointer)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique,GetAlphaState,int,const Rendering::ConstAlphaStateSmartPointer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique,GetCullState,int,const Rendering::ConstCullStateSmartPointer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique,GetDepthState,int,const Rendering::ConstDepthStateSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique,GetOffsetState,int,const Rendering::ConstOffsetStateSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique,GetStencilState,int,const Rendering::ConstStencilStateSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique,GetWireState,int,const Rendering::ConstWireStateSmartPointer) 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique,SaveVisualPass, WriteFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualTechnique,LoadVisualPass, ReadFileManager&, void) 

CoreTools::ObjectInterfaceSharedPtr Rendering::VisualTechnique::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP