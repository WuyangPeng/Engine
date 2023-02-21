///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/10 10:27)

#ifndef RENDERING_RENDERERS_RAW_BUFFER_H
#define RENDERING_RENDERERS_RAW_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"
#include "CoreTools/Helper/ExportMacro.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RawBuffer : public Buffer
    {
    public:
        using ClassType = RawBuffer;
        using ParentType = Buffer;
        using MemberLayoutContainer = std::vector<MemberLayout>;

    public:
        explicit RawBuffer(int numElements);
        RawBuffer(int numElements, const StorageType& storage);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(RawBuffer);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(RawBuffer);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(RawBuffer);
}

#endif  // RENDERING_RENDERERS_RAW_BUFFER_H
