// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 11:21)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_DATA_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_DATA_H

#include "Rendering/RenderingDll.h"

#include "Flags/VertexFormatFlags.h"

namespace Rendering
{
	class VertexFormat;

	template <VertexFormatFlags::AttributeUsage usage>
	class VertexBufferAccessorData
	{
	public:
		using ClassType = VertexBufferAccessorData<usage>;
		using AttributeType = VertexFormatFlags::AttributeType;

	public:
		VertexBufferAccessorData();
		VertexBufferAccessorData(const ConstVertexFormatSmartPointer& vertexformat,const ConstVertexBufferSmartPointer& vertexbuffer);

		CLASS_INVARIANT_DECLARE;

		void Init(const ConstVertexFormatSmartPointer& vertexformat,const ConstVertexBufferSmartPointer& vertexbuffer,int number = 0);

		const char* GetData(int stride, int index) const;
		bool HasData() const;
		int GetDataChannels() const;
		const float* GetDataTuple(int stride, int index) const;

	private:
		const char* m_Data;
		int m_DataChannels;		 
	};
}

#endif // RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_DATA_H
