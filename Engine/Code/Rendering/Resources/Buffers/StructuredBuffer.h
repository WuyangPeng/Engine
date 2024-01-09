/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 13:49)

#ifndef RENDERING_RESOURCES_STRUCTURED_BUFFER_H
#define RENDERING_RESOURCES_STRUCTURED_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE StructuredBuffer : public Buffer
    {
    public:
        using ClassType = StructuredBuffer;
        using ParentType = Buffer;

        using StructuredBufferSharedPtr = std::shared_ptr<StructuredBuffer>;

    public:
        StructuredBuffer(const std::string& name, int numElements, int elementSize, bool createStorage = true);
        StructuredBuffer(const std::string& name, int numElements, int elementSize, const StorageType& storage);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(StructuredBuffer);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        NODISCARD StructuredBufferSharedPtr Clone() const;

        NODISCARD CounterType GetCounterType() const noexcept;

        /// 在将缓冲区绑定到引擎之前，调用其中一个函数。
        /// 这将设置CounterType，并将用法设置为ShaderOutput。
        void MakeAppendConsume() noexcept;
        void MakeCounter() noexcept;

        /// 当缓冲区有计数器（AppendConsume或Counter）时，
        /// 让GPU知道是否更改其内部计数。
        /// “true”的输入意味着GPU将让计数器保持其当前值。
        /// 当缓冲区的计数器类型为None时，此函数将被忽略。
        void SetKeepInternalCount(bool aKeepInternalCount) noexcept;
        NODISCARD bool GetKeepInternalCount() const noexcept;

        // 供着色器类用于存储反射信息。
        NODISCARD static constexpr auto GetShaderDataLookup() noexcept
        {
            return 2;
        }

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    private:
        CounterType counterType;
        bool keepInternalCount;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(StructuredBuffer);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(StructuredBuffer);
}

#endif  // RENDERING_RESOURCES_STRUCTURED_BUFFER_H
