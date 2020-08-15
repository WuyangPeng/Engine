// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 15:43)

#include "Rendering/RenderingExport.h"

#include "Texture2D.h"
#include "Detail/Texture2DImpl.h"
#include "Rendering/Renderers/RendererManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
CORE_TOOLS_RTTI_DEFINE(Rendering,Texture2D);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,Texture2D);
CORE_TOOLS_FACTORY_DEFINE(Rendering,Texture2D); 

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, Texture2D);

using std::make_shared;

Rendering::Texture2D
    ::Texture2D(TextureFormat format, int dimension0,int dimension1,int numLevels,BufferUsage usage)
    :ParentType{},m_Impl{ make_shared<ImplType>(format,dimension0,dimension1,numLevels,usage) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Texture2D
    ::~Texture2D()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
    
    EXCEPTION_TRY
    {
        RENDERER_MANAGE_SINGLETON.UnbindAll(this);
    }
    EXCEPTION_ALL_CATCH(Rendering)
    
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, Texture2D) 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering,Texture2D,GetFormat,Rendering::TextureFormat)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, GetTextureType, Rendering::TextureFlags)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, GetUsage, Rendering::BufferUsage)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, GetNumLevels, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, GetNumDimensions, int)


int Rendering::Texture2D
    ::GetDimension (int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Impl->GetDimension(index,level);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Texture2D,GetNumLevelBytes,int,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, GetNumTotalBytes, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Texture2D,GetLevelOffset,int,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Texture2D,GetPixelSize,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture2D, IsCompressed, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Texture2D,IsMipmapable,bool)

void Rendering::Texture2D
    ::SetUserField (int index, int userField)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
  
    return m_Impl->SetUserField(index,userField);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Texture2D,GetUserField,int,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Texture2D,GetWidth,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Texture2D,GetHeight,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Texture2D,HasMipmaps,bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Texture2D,GetTextureData,int,char*)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Texture2D,GetTextureData,int,const char*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Texture2D,SaveToFile,WriteFileManager&,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Texture2D,ReadFromFile,ReadFileManager&,void)

void Rendering::Texture2D
    ::GenerateMipmaps ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
   
    if(!m_Impl->HasMipmaps())
    {
        RENDERER_MANAGE_SINGLETON.UnbindAll(this);
        
        m_Impl->GenerateMipmaps();
        
       const auto numLevels = m_Impl->GetNumLevels();
        
        for (auto level = 0; level < numLevels; ++level)
        {
           RENDERER_MANAGE_SINGLETON.UpdateAll(this, level);
        }
    }
    else
    {
        m_Impl->GenerateMipmaps();
    }
}

Rendering::Texture2D
   ::Texture2D (LoadConstructor value)
	:ParentType{ value }, m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Texture2D
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();
    
	size += m_Impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::Texture2D
    ::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ParentType::Register(target);
}

void Rendering::Texture2D
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	m_Impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Texture2D
    ::Link (CoreTools::ObjectLink& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	    
	ParentType::Link(source);
}

void Rendering::Texture2D
    ::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	  
	ParentType::PostLink();
}

void Rendering::Texture2D
    ::Load (CoreTools::BufferSource& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	m_Impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}


Rendering::TextureSmartPointer Rendering::Texture2D
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return TextureSmartPointer{ std::make_shared<ClassType>(*this) };
}



#include STSTEM_WARNING_POP