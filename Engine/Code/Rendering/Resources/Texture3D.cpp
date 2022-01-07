// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 15:46)

#include "Rendering/RenderingExport.h"

#include "Texture3D.h"
#include "Detail/Texture3DImpl.h"
#include "Rendering/Renderers/RendererManager.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering,Texture3D);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,Texture3D);
CORE_TOOLS_FACTORY_DEFINE(Rendering,Texture3D); 

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
    COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, Texture3D);

using std::make_shared;

Rendering::Texture3D
    ::Texture3D(TextureFormat format, int dimension0,int dimension1,int dimension2,int numLevels,BufferUsage usage)
	:ParentType{}, impl{ make_shared<ImplType>(format,dimension0,dimension1,dimension2,numLevels,usage) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Texture3D ::~Texture3D()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
    EXCEPTION_TRY
    {
        RENDERER_MANAGE_SINGLETON.UnbindAll(this);
    }
    EXCEPTION_ALL_CATCH(Rendering)
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture3D)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture3D, GetFormat, Rendering::TextureFormat)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture3D, GetTextureType, Rendering::TextureFlags)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture3D, GetUsage, Rendering::BufferUsage)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture3D, GetNumLevels, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture3D, GetNumDimensions, int)


int Rendering::Texture3D
    ::GetDimension (int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return impl->GetDimension(index,level);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Texture3D,GetNumLevelBytes,int,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture3D, GetNumTotalBytes, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Texture3D,GetLevelOffset,int,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Texture3D,GetPixelSize,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Texture3D, IsCompressed, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Texture3D,IsMipmapable,bool)

void Rendering::Texture3D
    ::SetUserField (int index, int userField)
{
	;
    
    return impl->SetUserField(index,userField);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Texture3D,GetUserField,int,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Texture3D,GetWidth,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Texture3D,GetHeight,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Texture3D,GetThickness,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Texture3D,HasMipmaps,bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Texture3D,GetTextureData,int,char*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Texture3D,GetTextureData,int,const char*)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Texture3D,ReadFromFile,ReadFileManager&,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Texture3D,SaveToFile,WriteFileManager&,void)

void Rendering::Texture3D
    ::GenerateMipmaps ()
{
	;
  
    if(!impl->HasMipmaps())
    {
        RENDERER_MANAGE_SINGLETON.UnbindAll(this);
        
        impl->GenerateMipmaps();
        
      const  auto numLevels = impl->GetNumLevels();
        
        for (auto level = 0; level < numLevels; ++level)
        {
            RENDERER_MANAGE_SINGLETON.UpdateAll(this, level);
        }
    }
    else
    {
        impl->GenerateMipmaps();
    }
}

Rendering::Texture3D
   ::Texture3D (LoadConstructor value)
	:ParentType{ value }, impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Texture3D
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();
    
	size += impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::Texture3D
    ::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ParentType::Register(target);
}

void Rendering::Texture3D
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Texture3D
    ::Link (CoreTools::ObjectLink& source)
{
	;

	ParentType::Link(source);
}

void Rendering::Texture3D
    ::PostLink ()
{
	;
    
	ParentType::PostLink();
}

void Rendering::Texture3D
    ::Load (CoreTools::BufferSource& source)
{
	;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}


Rendering::TextureSharedPtr Rendering::Texture3D
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return TextureSharedPtr{ std::make_shared<ClassType>(*this) };
}

CoreTools::ObjectInterfaceSharedPtr Rendering::Texture3D::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP