// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 11:21)

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
		VertexBufferAccessorData() noexcept;
		VertexBufferAccessorData(const ConstVertexFormatSharedPtr& vertexformat,const ConstVertexBufferSharedPtr& vertexbuffer);

		CLASS_INVARIANT_DECLARE;

		void Init(const ConstVertexFormatSharedPtr& vertexformat,const ConstVertexBufferSharedPtr& vertexbuffer,int number = 0);

		const char* GetData(int stride, int index) const noexcept;
		bool HasData() const noexcept;
		int GetDataChannels() const noexcept;
		const float* GetDataTuple(int stride, int index) const noexcept;

	private:
		const char* m_Data;
		int m_DataChannels;		 
	};
}

#endif // RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_DATA_H
