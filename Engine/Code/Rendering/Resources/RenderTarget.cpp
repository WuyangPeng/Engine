// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 15:36)

#include "Rendering/RenderingExport.h"

#include "RenderTarget.h"
#include "Detail/RenderTargetImpl.h"
#include "Rendering/Renderers/RendererManager.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, RenderTarget);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, RenderTarget);
CORE_TOOLS_FACTORY_DEFINE(Rendering, RenderTarget);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, RenderTarget);

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, RenderTarget);

using std::string;
using std::vector;
using std::make_shared;

Rendering::RenderTarget
    ::RenderTarget(int numTargets, TextureFormat format,int width,int height, bool hasMipmaps,bool hasDepthStencil)
	:ParentType{ "RenderTarget" },m_Impl{ make_shared<ImplType>(numTargets,format,width,height,hasMipmaps,hasDepthStencil) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::RenderTarget
    ::~RenderTarget()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
    
    RENDERER_MANAGE_SINGLETON.UnbindAll(this);
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering,RenderTarget)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,RenderTarget,GetNumTargets,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,RenderTarget,GetFormat,Rendering::TextureFormat)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,RenderTarget,GetWidth,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,RenderTarget,GetHeight,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,RenderTarget,GetColorTexture,int,Rendering::RenderTarget::ConstTexture2DSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,RenderTarget,GetDepthStencilTexture,Rendering::RenderTarget::ConstTexture2DSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,RenderTarget,HasMipmaps,bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,RenderTarget,HasDepthStencil,bool)

Rendering::RenderTarget
   ::RenderTarget (LoadConstructor value)
	:ParentType{ value },m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::RenderTarget
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();
    
	size += m_Impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::RenderTarget
    ::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto uniqueID = ParentType::Register(target);
	if (uniqueID != 0)
	{
		m_Impl->Register(target);
	}    
    
    return uniqueID;
}

void Rendering::RenderTarget
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	m_Impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::RenderTarget
    ::Link (CoreTools::ObjectLink& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::Link(source);
    
    m_Impl->Link(source);
}

void Rendering::RenderTarget
    ::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::PostLink();
}

void Rendering::RenderTarget
    ::Load (CoreTools::BufferSource& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	m_Impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

