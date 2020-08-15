// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/29 11:11)

#ifndef RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_H
#define RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_H

#include "Rendering/RenderingDll.h"

#include "OpenGLVertexFormatData.h"
#include "OpenGLVertexFormatArrayData.h"
#include "Rendering/Renderers/Detail/PlatformVertexFormatImpl.h"

namespace Rendering
{
    class Renderer;
    class VertexFormat;

	class RENDERING_HIDDEN_DECLARE OpenGLVertexFormat : public PlatformVertexFormatImpl
    {
	public:
		using ClassType = OpenGLVertexFormat;
		using ParentType = PlatformVertexFormatImpl;
		using UInt = System::OpenGLUInt;
		using AttributeType = VertexFormatFlags::AttributeType;

	public:
	   OpenGLVertexFormat (Renderer* renderer, const VertexFormat* vertexFormat);
 

	   CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
	   
	   // 顶点格式操作。
	     void Enable (Renderer* renderer) noexcept override;
	     void Disable (Renderer* renderer) noexcept override;
	   
	private:
		void Init(const VertexFormat* vertexFormat);

	private:
		using OpenGLVertexFormatPosition = OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::Position>;
		using OpenGLVertexFormatNormal = OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::Normal>;
		using OpenGLVertexFormatTangent = OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::Tangent>;
		using OpenGLVertexFormatBinormal = OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::Binormal>;
		using OpenGLVertexFormatTexCoord = OpenGLVertexFormatArrayData<VertexFormatFlags::AttributeUsage::TextureCoord,VertexFormatFlags::MaximumNumber::TextureCoordinateUnits>;
		using OpenGLVertexFormatColor = OpenGLVertexFormatArrayData<VertexFormatFlags::AttributeUsage::Color,VertexFormatFlags::MaximumNumber::ColorUnits>;
		using OpenGLVertexFormatBlendIndices = OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::BlendIndices>;
		using OpenGLVertexFormatBlendWeight = OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::BlendWeight>;
		using OpenGLVertexFormatFogCoord = OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::FogCoord>;
		using OpenGLVertexFormatPsize = OpenGLVertexFormatData<VertexFormatFlags::AttributeUsage::Psize>;

	private:
		int m_Stride;

		OpenGLVertexFormatPosition m_Position;
		OpenGLVertexFormatNormal m_Normal;
		OpenGLVertexFormatTangent m_Tangent;
		OpenGLVertexFormatBinormal m_Binormal;
		OpenGLVertexFormatTexCoord m_TexCoord;
		OpenGLVertexFormatColor m_Color;
		OpenGLVertexFormatBlendIndices m_BlendIndices;
		OpenGLVertexFormatBlendWeight m_BlendWeight;
		OpenGLVertexFormatFogCoord m_FogCoord;
		OpenGLVertexFormatPsize m_PSize;
	};
}

#endif // RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_H
