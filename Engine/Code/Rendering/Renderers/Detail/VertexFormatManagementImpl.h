///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/21 14:57)

#ifndef RENDERING_RENDERERS_VERTEX_FORMAT_MANAGEMENT_IMPL_H
#define RENDERING_RENDERERS_VERTEX_FORMAT_MANAGEMENT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/VertexFormat.h"

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

        // �����ʽ���������ʽ����������Ѿ����䣬
        // �������ԺͿ����Ӧ�ó������������á�
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
