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
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering,TextureCube);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,TextureCube);
CORE_TOOLS_FACTORY_DEFINE(Rendering,TextureCube); 

#define COPY_CONSTRUCTION_DEFINE_WITH_PARENT(namespaceName, className)                      \
    namespaceName::className::className(const className& rhs)                               \
        : ParentType{ rhs }, impl{ std::make_shared<ImplType>(*rhs.impl) }                  \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        SELF_CLASS_IS_VALID_0;                                                              \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(const className& rhs)     \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        className temp{ rhs };                                                              \
        Swap(temp);                                                                         \
        return *this;                                                                       \
    }                                                                                       \
    void namespaceName::className::Swap(className& rhs) noexcept                            \
    {                                                                                       \
        ;                                       \
        std::swap(impl, rhs.impl);                                                          \
    }                                                                                       \
    namespaceName::className::className(className&& rhs) noexcept                           \
        : ParentType{ std::move(rhs) }, impl{ std::move(rhs.impl) }                         \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(className&& rhs) noexcept \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        ParentType::operator=(std::move(rhs));                                              \
        impl = std::move(rhs.impl);                                                         \
        return *this;                                                                       \
    }                                                                                        
    COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, TextureCube);

using std::make_shared;

Rendering::TextureCube
    ::TextureCube(TextureFormat format, int dimension,int numLevels,BufferUsage usage)
    :ParentType{},impl{ make_shared<ImplType>(format,dimension,numLevels,usage) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::TextureCube
    ::~TextureCube()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
    EXCEPTION_TRY
    {
        RENDERER_MANAGE_SINGLETON.UnbindAll(this);
    }
    EXCEPTION_ALL_CATCH(Rendering)
	
    
    
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TextureCube)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, GetFormat, Rendering::TextureFormat)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, GetTextureType, Rendering::TextureFlags)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, GetUsage, Rendering::BufferUsage)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, GetNumLevels, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, GetNumDimensions, int)


int Rendering::TextureCube
    ::GetDimension (int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return impl->GetDimension(index,level);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,TextureCube,GetNumLevelBytes,int,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, GetNumTotalBytes, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,TextureCube,GetLevelOffset,int,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,TextureCube,GetPixelSize,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TextureCube, IsCompressed, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,TextureCube,IsMipmapable,bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,TextureCube,SaveToFile,WriteFileManager&,void)

void Rendering::TextureCube
    ::SetUserField (int index, int userField)
{
	;
   
    return impl->SetUserField(index,userField);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,TextureCube,GetUserField,int,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,TextureCube,GetWidth,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,TextureCube,GetHeight,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,TextureCube,HasMipmaps,bool)

char* Rendering::TextureCube
    ::GetTextureData (int face,int level)
{
	;
    
    return impl->GetTextureData(face,level);
}

const char* Rendering::TextureCube
    ::GetTextureData (int face,int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return impl->GetTextureData(face,level);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,TextureCube,ReadFromFile,ReadFileManager&,void)

void Rendering::TextureCube
    ::GenerateMipmaps ()
{
	;
   
    if(!impl->HasMipmaps())
    {
        RENDERER_MANAGE_SINGLETON.UnbindAll(this);
        
        impl->GenerateMipmaps();
        
     const   auto numLevels = impl->GetNumLevels();
        
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
        impl->GenerateMipmaps();
    }
}

Rendering::TextureCube
   ::TextureCube (LoadConstructor value)
	:ParentType{ value }, impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::TextureCube
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();
    
	size += impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::TextureCube
    ::Register( const CoreTools::ObjectRegisterSharedPtr& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ParentType::Register(target);
}

void Rendering::TextureCube
    ::Save (const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::TextureCube
    ::Link (const CoreTools::ObjectLinkSharedPtr& source)
{
	;

	ParentType::Link(source);
}

void Rendering::TextureCube
    ::PostLink ()
{
	;
    
	ParentType::PostLink();
}

void Rendering::TextureCube
    ::Load (const CoreTools::BufferSourceSharedPtr& source)
{
	;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::TextureSharedPtr Rendering::TextureCube
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return TextureSharedPtr{ std::make_shared<ClassType>(*this) };
}

CoreTools::ObjectInterfaceSharedPtr Rendering::TextureCube::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP