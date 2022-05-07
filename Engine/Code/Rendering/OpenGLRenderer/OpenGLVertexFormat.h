///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/23 14:45)

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
        using OpenGLVertexFormatPosition = OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::Position>;
        using OpenGLVertexFormatNormal = OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::Normal>;
        using OpenGLVertexFormatTangent = OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::Tangent>;
        using OpenGLVertexFormatBinormal = OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::Binormal>;
        using OpenGLVertexFormatTexCoord = OpenGLVertexFormatArrayData<VertexFormatFlags::AttributeUsage::TextureCoord, VertexFormatFlags::MaximumNumber::TextureCoordinateUnits>;
        using OpenGLVertexFormatColor = OpenGLVertexFormatArrayData<VertexFormatFlags::AttributeUsage::Color, VertexFormatFlags::MaximumNumber::ColorUnits>;
        using OpenGLVertexFormatBlendIndices = OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::BlendIndices>;
        using OpenGLVertexFormatBlendWeight = OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::BlendWeight>;
        using OpenGLVertexFormatFogCoord = OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::FogCoord>;
        using OpenGLVertexFormatPsize = OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::Psize>;

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
