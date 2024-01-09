/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 14:08)

#include "Rendering/RenderingExport.h"

#include "Texture.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Resources/Detail/Textures/TextureImpl.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, Texture);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Texture);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, Texture);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, Texture);

Rendering::Texture::Texture(const std::string& name, int numElements, int elementSize, GraphicsObjectType type, bool createStorage)
    : ParentType{ name, numElements, elementSize, type, createStorage }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Texture::Texture(const std::string& name, int numElements, int elementSize, const StorageType& storage, GraphicsObjectType type)
    : ParentType{ name, numElements, elementSize, storage, type }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture)

Rendering::Texture::ConstSpanIterator Rendering::Texture::GetDataFor(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto offset = GetLevelOffset(item, level);

    return GetStorage(offset);
}

Rendering::SubResource Rendering::Texture::GetSubResource(int index)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto numLevels = GetNumLevels();
    const auto item = index / numLevels;
    const auto level = index % numLevels;
    const auto rowPitch = GetDimension(level, 0) * GetElementSize();

    SubResource subResource{ item, level, GetDataFor(item, level), rowPitch, GetDimension(level, 1) * rowPitch };

    return subResource;
}

Rendering::Texture::SpanIterator Rendering::Texture::GetDataFor(int item, int level)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto offset = GetLevelOffset(item, level);

    return GetStorage(offset);
}
