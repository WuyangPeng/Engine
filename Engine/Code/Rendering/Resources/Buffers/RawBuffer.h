/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/29 13:49)

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
        RawBuffer(const std::string& name, int numElements, bool createStorage = true);
        RawBuffer(const std::string& name, int numElements, const StorageType& storage);

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
