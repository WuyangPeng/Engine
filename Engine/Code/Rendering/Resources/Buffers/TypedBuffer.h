///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/29 17:05)

#ifndef RENDERING_RESOURCES_TYPED_BUFFER_H
#define RENDERING_RESOURCES_TYPED_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"
#include "CoreTools/Helper/ExportMacro.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TypedBuffer : public Buffer
    {
    public:
        using ClassType = TypedBuffer;
        using ParentType = Buffer;

    public:
        TypedBuffer(int numElements, int elementSize);
        TypedBuffer(int numElements, int elementSize, const StorageType& storage);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TypedBuffer);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;
    };
}

#endif  // RENDERING_RESOURCES_TYPED_BUFFER_H
