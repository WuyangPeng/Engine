// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:27)


#include "Rendering/RenderingExport.h"

#include "VisualEffect.h"
#include "Detail/VisualEffectImpl.h"
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
CORE_TOOLS_RTTI_DEFINE(Rendering, VisualEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VisualEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VisualEffect);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, VisualEffect);

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, VisualEffect);

CORE_TOOLS_IMPL_OBJECT_PTR_DEFAULT_STREAM(Rendering, VisualEffect);

Rendering::VisualEffect
	::VisualEffect()
	:ParentType{ "VisualEffect" }, m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VisualEffect
	::~VisualEffect()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, VisualEffect)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualEffect,InsertTechnique,VisualTechniqueSmartPointer,void)  
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualEffect,GetNumTechniques,int)  
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffect,GetTechnique,int,const Rendering::ConstVisualTechniqueSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffect,GetNumPasses,int,int)
 
const Rendering::ConstVertexShaderSmartPointer Rendering::VisualEffect
	::GetVertexShader(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetVertexShader(techniqueIndex, passIndex);
}

const Rendering::ConstPixelShaderSmartPointer Rendering::VisualEffect
	::GetPixelShader(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetPixelShader(techniqueIndex, passIndex);
}

const Rendering::ConstAlphaStateSmartPointer Rendering::VisualEffect
	::GetAlphaState(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetAlphaState(techniqueIndex, passIndex);
}

const Rendering::ConstCullStateSmartPointer Rendering::VisualEffect
	::GetCullState(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetCullState(techniqueIndex, passIndex);
}

const Rendering::ConstDepthStateSmartPointer Rendering::VisualEffect
	::GetDepthState(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetDepthState(techniqueIndex, passIndex);
}

const Rendering::ConstOffsetStateSmartPointer Rendering::VisualEffect
	::GetOffsetState(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetOffsetState(techniqueIndex, passIndex);
}

const Rendering::ConstStencilStateSmartPointer Rendering::VisualEffect
	::GetStencilState(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetStencilState(techniqueIndex, passIndex);
}

const Rendering::ConstWireStateSmartPointer Rendering::VisualEffect
	::GetWireState(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetWireState(techniqueIndex, passIndex);
}

const Rendering::ConstVisualPassSmartPointer Rendering::VisualEffect
	::GetPass(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetPass(techniqueIndex, passIndex);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffect,SaveVisualTechnique, WriteFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffect,LoadVisualTechnique, ReadFileManager&, void)
			#include STSTEM_WARNING_POP						