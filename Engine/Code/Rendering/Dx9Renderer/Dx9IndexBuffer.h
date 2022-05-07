///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/23 17:16)

#ifndef RENDERING_RENDERERS_DX9_INDEX_BUFFER_H
#define RENDERING_RENDERERS_DX9_INDEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "System/Windows/Flags/WindowsFlags.h"
#include "Rendering/Renderers/Detail/PlatformIndexBufferImpl.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE Dx9IndexBuffer : public PlatformIndexBufferImpl
    {
    public:
        using ClassType = Dx9IndexBuffer;
        using ParentType = PlatformIndexBufferImpl;

    public:
        Dx9IndexBuffer(Renderer* renderer, const IndexBuffer* indexBuffer) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ����������
        void Enable(Renderer* renderer) noexcept override;
        void Disable(Renderer* renderer) noexcept override;
        NODISCARD void* Lock(BufferLocking mode) noexcept override;
        void Unlock() noexcept override;
    };
}

#endif  // RENDERING_RENDERERS_DX9_INDEX_BUFFER_H
