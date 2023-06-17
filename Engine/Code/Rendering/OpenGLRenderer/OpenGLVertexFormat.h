///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:17)

#ifndef RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_H
#define RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_H

#include "Rendering/RenderingDll.h"

#include "OpenGLVertexFormatArrayData.h"
#include "OpenGLVertexFormatData.h"
#include "Rendering/Renderers/Detail/PlatformVertexFormatImpl.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLVertexFormat : public PlatformVertexFormatImpl
    {
    public:
        using ClassType = OpenGLVertexFormat;
        using ParentType = PlatformVertexFormatImpl;
        using UInt = System::OpenGLUInt;
        using AttributeType = VertexFormatFlags::AttributeType;

    public:
        OpenGLVertexFormat(Renderer* renderer, const VertexFormat* vertexFormat);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // �����ʽ������
        void Enable(Renderer* renderer) noexcept override;
        void Disable(Renderer* renderer) noexcept override;

    private:
        void Init(const VertexFormat* vertexFormat);

    private:
        using OpenGLVertexFormatPosition = OpenGLVertexFormatData<VertexFormatFlags::Semantic::Position>;
        using OpenGLVertexFormatNormal = OpenGLVertexFormatData<VertexFormatFlags::Semantic::Normal>;
        using OpenGLVertexFormatTangent = OpenGLVertexFormatData<VertexFormatFlags::Semantic::Tangent>;
        using OpenGLVertexFormatBinormal = OpenGLVertexFormatData<VertexFormatFlags::Semantic::Binormal>;
        using OpenGLVertexFormatTexCoord = OpenGLVertexFormatArrayData<VertexFormatFlags::Semantic::TextureCoord, VertexFormatFlags::MaximumNumber::TextureCoordinateUnits>;
        using OpenGLVertexFormatColor = OpenGLVertexFormatArrayData<VertexFormatFlags::Semantic::Color, VertexFormatFlags::MaximumNumber::ColorUnits>;
        using OpenGLVertexFormatBlendIndices = OpenGLVertexFormatData<VertexFormatFlags::Semantic::BlendIndices>;
        using OpenGLVertexFormatBlendWeight = OpenGLVertexFormatData<VertexFormatFlags::Semantic::BlendWeight>;
        using OpenGLVertexFormatFogCoord = OpenGLVertexFormatData<VertexFormatFlags::Semantic::FogCoord>;
        using OpenGLVertexFormatPsize = OpenGLVertexFormatData<VertexFormatFlags::Semantic::Psize>;

    private:
        int stride;

        OpenGLVertexFormatPosition position;
        OpenGLVertexFormatNormal normal;
        OpenGLVertexFormatTangent tangent;
        OpenGLVertexFormatBinormal binormal;
        OpenGLVertexFormatTexCoord texCoord;
        OpenGLVertexFormatColor color;
        OpenGLVertexFormatBlendIndices blendIndices;
        OpenGLVertexFormatBlendWeight blendWeight;
        OpenGLVertexFormatFogCoord fogCoord;
        OpenGLVertexFormatPsize pSize;
    };
}

#endif  // RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_H
