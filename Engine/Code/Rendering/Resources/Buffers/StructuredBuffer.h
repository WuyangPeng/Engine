///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/29 16:45)

#ifndef RENDERING_RESOURCES_STRUCTURED_BUFFER_H
#define RENDERING_RESOURCES_STRUCTURED_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE StructuredBuffer : public Buffer
    {
    public:
        using ClassType = StructuredBuffer;
        using ParentType = Buffer;

    public:
        StructuredBuffer(int numElements, int elementSize);
        StructuredBuffer(int numElements, int elementSize, const StorageType& storage);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(StructuredBuffer);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD CounterType GetCounterType() const noexcept;

        void MakeAppendConsume() noexcept;
        void MakeCounter() noexcept;
        void SetKeepInternalCount(bool aKeepInternalCount) noexcept;
        NODISCARD bool GetKeepInternalCount() const noexcept;

        NODISCARD static constexpr auto GetShaderDataLookup() noexcept
        {
            return 2;
        }

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    private:
        CounterType counterType;
        bool keepInternalCount;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(StructuredBuffer);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(StructuredBuffer);
}

#endif  // RENDERING_RESOURCES_STRUCTURED_BUFFER_H
