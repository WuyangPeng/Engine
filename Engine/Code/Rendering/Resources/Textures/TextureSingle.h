///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 20:18)

#ifndef RENDERING_RESOURCES_TEXTURE_SINGLE_H
#define RENDERING_RESOURCES_TEXTURE_SINGLE_H

#include "Rendering/RenderingDll.h"

#include "Texture.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TextureSingle : public Texture
    {
    public:
        using ClassType = TextureSingle;
        using ParentType = Texture;

    public:
        TextureSingle(int numElements, int elementSize, GraphicsObjectType type);
        TextureSingle(int numElements, int elementSize, const StorageType& storage, GraphicsObjectType type);

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(TextureSingle);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD int GetOffsetFor(int level) const;

        NODISCARD ConstSpanIterator GetDataForSingle(int level) const;
        NODISCARD SpanIterator GetDataForSingle(int level);

    public:
        NODISCARD static constexpr int GetShaderDataLookup()
        {
            return 4;
        }
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(TextureSingle);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TextureSingle);
}

#endif  // RENDERING_RESOURCES_TEXTURE_SINGLE_H