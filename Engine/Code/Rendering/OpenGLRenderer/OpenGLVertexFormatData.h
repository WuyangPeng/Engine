// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:14)

#ifndef RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_DATA_H
#define RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_DATA_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "Rendering/Resources/Flags/VertexFormatFlags.h"

namespace Rendering
{
	class VertexFormat;

	template <VertexFormatFlags::AttributeUsage usage>
	class OpenGLVertexFormatData
	{
	public:
		using ClassType = OpenGLVertexFormatData<usage>;
		using UInt = System::OpenGLUInt;
		using DataType = System::OpenGLData;

	public:
		OpenGLVertexFormatData ();

		CLASS_INVARIANT_DECLARE;

		void Init(const VertexFormat* vertexFormat);

		void Set(UInt has,UInt channels,DataType type,UInt offset);

		bool IsHas() const;
		UInt GetChannels() const;
		DataType GetType() const;
		UInt GetOffset() const;

		void Enable(int stride);
		void Disable();

	private:
		UInt m_Has;
		UInt m_Channels;
		DataType m_Type;
		UInt m_Offset;
	};
}

#endif // RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_DATA_H
