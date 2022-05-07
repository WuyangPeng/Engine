///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 14:51)

#ifndef RENDERING_RENDERERS_VERTEX_FORMAT_MANAGEMENT_H
#define RENDERING_RENDERERS_VERTEX_FORMAT_MANAGEMENT_H

#include "Rendering/RenderingDll.h"

#include "RenderersFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Resources/VertexFormat.h"

RENDERING_NON_COPY_EXPORT_IMPL(VertexFormatManagementImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VertexFormatManagement
    {
    public:
        NON_COPY_TYPE_DECLARE(VertexFormatManagement);
        using PlatformVertexFormatSharedPtr = std::shared_ptr<PlatformVertexFormat>;
        using RendererSharedPtr = std::shared_ptr<Renderer>;

    public:
        explicit VertexFormatManagement(const RendererSharedPtr& renderer);

        CLASS_INVARIANT_DECLARE;

        // 顶点格式管理。顶点格式对象必须是已经分配，
        // 它的属性和跨距由应用程序代码进行设置。
        void Bind(const ConstVertexFormatSharedPtr& vertexFormat);
        void Unbind(const ConstVertexFormatSharedPtr& vertexFormat);

        void Enable(const ConstVertexFormatSharedPtr& vertexFormat);
        void Disable(const ConstVertexFormatSharedPtr& vertexFormat);

        NODISCARD PlatformVertexFormatSharedPtr GetResource(const ConstVertexFormatSharedPtr& vertexFormat);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_VERTEX_FORMAT_MANAGEMENT_H
