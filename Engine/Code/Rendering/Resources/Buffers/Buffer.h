///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:22)

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
        Buffer(int numElements, int elementSize, GraphicsObjectType type = GraphicsObjectType::Buffer);
        Buffer(int numElements, int elementSize, const StorageType& storage, GraphicsObjectType type = GraphicsObjectType::Buffer);
        explicit Buffer(GraphicsObjectType type);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Buffer);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Buffer);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Buffer);
}

#endif  // RENDERING_RESOURCES_BUFFER_H
