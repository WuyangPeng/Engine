///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/30 18:04)

#include "Rendering/RenderingExport.h"

#include "Texture.h"
#include "Detail/TextureImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, Texture);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Texture);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, Texture);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, Texture);

Rendering::Texture::Texture(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ "Texture" }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture)

// static
int Rendering::Texture::GetPixelSize(TextureFormat format)
{
    return TextureImpl::GetPixelSize(format);
}
