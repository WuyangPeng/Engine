///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:36)

#ifndef RENDERING_RENDERERS_VERTEX_FORMAT_MANAGEMENT_IMPL_H
#define RENDERING_RENDERERS_VERTEX_FORMAT_MANAGEMENT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"

#include <map>
#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE VertexFormatManagementImpl
    {
    public:
        using ClassType = VertexFormatManagementImpl;
        using FactoryType = ClassType;
        using PlatformVertexFormatSharedPtr = std::shared_ptr<PlatformVertexFormat>;
        using RendererSharedPtr = std::shared_ptr<Renderer>;

    public:
        explicit VertexFormatManagementImpl(const RendererSharedPtr& renderer);

        CLASS_INVARIANT_DECLARE;

        // 顶点格式管理。顶点格式对象必须是已经分配，
        // 它的属性和跨距由应用程序代码进行设置。
        void Bind(const ConstVertexFormatSharedPtr& vertexFormat);
        void Unbind(const ConstVertexFormatSharedPtr& vertexFormat);

        void Enable(const ConstVertexFormatSharedPtr& vertexFormat);
        void Disable(const ConstVertexFormatSharedPtr& vertexFormat);

        NODISCARD PlatformVertexFormatSharedPtr GetResource(const ConstVertexFormatSharedPtr& vertexFormat);

    private:
        using VertexFormatMap = std::map<ConstVertexFormatSharedPtr, PlatformVertexFormatSharedPtr>;

    private:
        std::weak_ptr<Renderer> renderer;
        VertexFormatMap vertexFormats;
    };
}

#endif  // RENDERING_RENDERERS_VERTEX_FORMAT_MANAGEMENT_IMPL_H
