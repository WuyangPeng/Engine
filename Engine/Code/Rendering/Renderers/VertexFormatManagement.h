///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/22 14:51)

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

        // �����ʽ���������ʽ����������Ѿ����䣬
        // �������ԺͿ����Ӧ�ó������������á�
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
