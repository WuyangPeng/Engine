///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/29 17:05)

#ifndef RENDERING_RESOURCES_RAW_BUFFER_H
#define RENDERING_RESOURCES_RAW_BUFFER_H

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

        NODISCARD static constexpr auto GetShaderDataLookup() noexcept
        {
            return 3;
        }
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(RawBuffer);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(RawBuffer);
}

#endif  // RENDERING_RESOURCES_RAW_BUFFER_H
