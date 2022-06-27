///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/21 18:14)

#ifndef RENDERING_RENDERERS_BUFFER_MANAGEMENT_H
#define RENDERING_RENDERERS_BUFFER_MANAGEMENT_H

#include "Rendering/RenderingDll.h"

#include "RenderersFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <map>

namespace Rendering
{
    template <typename PlatformBufferType>
    class BufferManagement
    {
    public:
        using ClassType = BufferManagement<PlatformBufferType>;
        using BufferType = typename PlatformBufferType::BufferType;
        using ConstBufferSharedPtr = std::shared_ptr<const BufferType>;
        using PlatformBufferTypeSharedPtr = std::shared_ptr<PlatformBufferType>;
        using RendererSharedPtr = std::shared_ptr<Renderer>;

    public:
        explicit BufferManagement(const RendererSharedPtr& renderer);

        CLASS_INVARIANT_DECLARE;

        // ���㡢�����������������㡢��������������������Ѿ���Ӧ�ó��������䡣
        void Bind(const ConstBufferSharedPtr& buffer);
        void Unbind(const ConstBufferSharedPtr& buffer);

        void EnableVertexBuffer(const ConstBufferSharedPtr& buffer, int streamIndex, int offset = 0);
        void DisableVertexBuffer(const ConstBufferSharedPtr& buffer, int streamIndex);

        void EnableIndexBuffer(const ConstBufferSharedPtr& buffer);
        void DisableIndexBuffer(const ConstBufferSharedPtr& buffer);

        NODISCARD void* Lock(const ConstBufferSharedPtr& buffer, BufferLocking mode);
        void Unlock(const ConstBufferSharedPtr& buffer);
        void Update(const ConstBufferSharedPtr& buffer);

        NODISCARD PlatformBufferTypeSharedPtr GetResource(ConstBufferSharedPtr buffer);

    private:
        using BufferMap = std::map<ConstBufferSharedPtr, PlatformBufferTypeSharedPtr>;

    private:
        std::weak_ptr<Renderer> renderer;
        BufferMap buffers;
    };
}

#endif  // RENDERING_RENDERERS_BUFFER_MANAGEMENT_H
