/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/29 13:48)

#ifndef RENDERING_RESOURCES_INDIRECT_ARGUMENTS_BUFFER_H
#define RENDERING_RESOURCES_INDIRECT_ARGUMENTS_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE IndirectArgumentsBuffer : public Buffer
    {
    public:
        using ClassType = IndirectArgumentsBuffer;
        using ParentType = Buffer;

    public:
        IndirectArgumentsBuffer(const std::string& name, int numElements, bool createStorage = true);
        IndirectArgumentsBuffer(const std::string& name, int numElements, const StorageType& storage);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IndirectArgumentsBuffer);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;
    };
}

#endif  // RENDERING_RESOURCES_INDIRECT_ARGUMENTS_BUFFER_H
