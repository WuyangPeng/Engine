// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 15:39)

#include "Rendering/RenderingExport.h"

#include "Detail/TextureImpl.h"
#include "Texture.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"

CORE_TOOLS_RTTI_DEFINE(Rendering,Texture);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,Texture);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering,Texture); 
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, Texture);

Rendering::Texture
    ::Texture()
	:ParentType{ "Texture" }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Texture
    ::~Texture()
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,Texture)

// static
int Rendering::Texture
    ::GetPixelSize (TextureFormat format)
{
    return ImplType::GetPixelSize(format);
}



