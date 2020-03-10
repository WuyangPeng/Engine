// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 15:50)

#include "Rendering/RenderingExport.h"

#include "TextureCube.h"
#include "Detail/TextureCubeImpl.h"
#include "Rendering/Renderers/RendererManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

CORE_TOOLS_RTTI_DEFINE(Rendering,TextureCube);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,TextureCube);
CORE_TOOLS_FACTORY_DEFINE(Rendering,TextureCube); 

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, TextureCube);

using std::make_shared;

Rendering::TextureCube
    ::TextureCube(TextureFormat format, int dimension,int numLevels,BufferUsage usage)
    :ParentType{},m_Impl{ make_shared<ImplType>(format,dimension,numLevels,usage) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::TextureCube
    ::~TextureCube()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
    
    RENDERER_MANAGE_SINGLETON.UnbindAll(this);
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, TextureCube)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,TextureCube,GetFormat,Rendering::TextureFormat)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,TextureCube,GetTextureType,Rendering::TextureFlags)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,TextureCube,GetUsage,Rendering::BufferUsage)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,TextureCube,GetNumLevels,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,TextureCube,GetNumDimensions,int)


int Rendering::TextureCube
    ::GetDimension (int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Impl->GetDimension(index,level);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,TextureCube,GetNumLevelBytes,int,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,TextureCube,GetNumTotalBytes,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,TextureCube,GetLevelOffset,int,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,TextureCube,GetPixelSize,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,TextureCube,IsCompressed,bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,TextureCube,IsMipmapable,bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,TextureCube,SaveToFile,WriteFileManager&,void)

void Rendering::TextureCube
    ::SetUserField (int index, int userField)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
   
    return m_Impl->SetUserField(index,userField);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,TextureCube,GetUserField,int,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,TextureCube,GetWidth,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,TextureCube,GetHeight,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,TextureCube,HasMipmaps,bool)

char* Rendering::TextureCube
    ::GetTextureData (int face,int level)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    return m_Impl->GetTextureData(face,level);
}

const char* Rendering::TextureCube
    ::GetTextureData (int face,int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Impl->GetTextureData(face,level);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,TextureCube,ReadFromFile,ReadFileManager&,void)

void Rendering::TextureCube
    ::GenerateMipmaps ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
   
    if(!m_Impl->HasMipmaps())
    {
        RENDERER_MANAGE_SINGLETON.UnbindAll(this);
        
        m_Impl->GenerateMipmaps();
        
        auto numLevels = m_Impl->GetNumLevels();
        
		for (auto face = 0; face < 6; ++face)
		{
			for (auto level = 0; level < numLevels; ++level)
			{
				RENDERER_MANAGE_SINGLETON.UpdateAll(this,face, level);
			}
		}
    }
    else
    {
        m_Impl->GenerateMipmaps();
    }
}

Rendering::TextureCube
   ::TextureCube (LoadConstructor value)
	:ParentType{ value }, m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::TextureCube
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();
    
	size += m_Impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::TextureCube
    ::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ParentType::Register(target);
}

void Rendering::TextureCube
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	m_Impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::TextureCube
    ::Link (CoreTools::ObjectLink& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Link(source);
}

void Rendering::TextureCube
    ::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::PostLink();
}

void Rendering::TextureCube
    ::Load (CoreTools::BufferSource& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	m_Impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::TextureSmartPointer Rendering::TextureCube
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return TextureSmartPointer{ NEW0 ClassType(*this) };
}


