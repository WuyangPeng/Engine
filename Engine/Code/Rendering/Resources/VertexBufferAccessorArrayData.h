// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 11:21)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_ARRAY_DATA_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_ARRAY_DATA_H

#include "Rendering/RenderingDll.h"

#include "VertexBufferAccessorData.h"

namespace Rendering
{
	class VertexFormat;

	template <VertexFormatFlags::AttributeUsage usage, VertexFormatFlags::MaximumNumber number>
	class VertexBufferAccessorArrayData
	{
	public:
		using ClassType = VertexBufferAccessorArrayData<usage, number>;

	public:
		VertexBufferAccessorArrayData();
		VertexBufferAccessorArrayData(const ConstVertexFormatSharedPtr& vertexformat,const ConstVertexBufferSharedPtr& vertexbuffer);

		CLASS_INVARIANT_DECLARE;

		void Init(const ConstVertexFormatSharedPtr& vertexformat,const ConstVertexBufferSharedPtr& vertexbuffer);

		const char* GetData(int stride, int unit, int index) const;
		bool HasData(int unit) const;
		int GetDataChannels(int unit) const;
		const float* GetDataTuple(int stride, int unit, int index) const;

	private:
		VertexBufferAccessorData<usage> m_Data[System::EnumCastUnderlying(number)];
	};
}

#endif // RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_ARRAY_DATA_H



