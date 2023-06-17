///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:24)

#ifndef RENDERING_RESOURCES_TEXTURE_ARRAY_H
#define RENDERING_RESOURCES_TEXTURE_ARRAY_H

#include "Rendering/RenderingDll.h"

#include "Texture.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TextureArray : public Texture
    {
    public:
        using ClassType = TextureArray;
        using ParentType = Texture;

    public:
        TextureArray(int numElements, int elementSize, GraphicsObjectType type);
        TextureArray(int numElements, int elementSize, const StorageType& storage, GraphicsObjectType type);

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(TextureArray);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

    public:
        NODISCARD int GetOffsetFor(int item, int level) const;

        NODISCARD ConstSpanIterator GetDataForArray(int item, int level) const;
        NODISCARD SpanIterator GetDataForArray(int item, int level);

    public:
        NODISCARD static constexpr int GetShaderDataLookup() noexcept
        {
            return 5;
        }
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(TextureArray);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TextureArray);
}

#endif  // RENDERING_RESOURCES_TEXTURE_ARRAY_H