///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 16:41)

#ifndef RENDERING_RESOURCES_INDIRECT_ARGUMENTS_BUFFER_H
#define RENDERING_RESOURCES_INDIRECT_ARGUMENTS_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"
#include "CoreTools/Helper/ExportMacro.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE IndirectArgumentsBuffer : public Buffer
    {
    public:
        using ClassType = IndirectArgumentsBuffer;
        using ParentType = Buffer;

    public:
        explicit IndirectArgumentsBuffer(int numElements);
        IndirectArgumentsBuffer(int numElements, const StorageType& storage);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IndirectArgumentsBuffer);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;
    };
}

#endif  // RENDERING_RESOURCES_INDIRECT_ARGUMENTS_BUFFER_H
