///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 14:24)

#ifndef RENDERING_RESOURCES_BUFFER_H
#define RENDERING_RESOURCES_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Resource.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Buffer : public Resource
    {
    public:
        using ClassType = Buffer;
        using ParentType = Resource;

    public:
        explicit Buffer(GraphicsObjectType type);
        Buffer(int numElements, int elementSize, GraphicsObjectType type = GraphicsObjectType::Buffer);
        Buffer(int numElements, int elementSize, const StorageType& storage, GraphicsObjectType type = GraphicsObjectType::Buffer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Buffer);

    protected:
        template <typename T>
        void CheckMember(const T& layout) const;

        template <typename T>
        void CheckMember(int index, const T& layout) const;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Buffer);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Buffer);
}

#endif  // RENDERING_RESOURCES_BUFFER_H
