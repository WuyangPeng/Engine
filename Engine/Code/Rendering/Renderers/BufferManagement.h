// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/26 15:28)

#ifndef RENDERING_RENDERERS_BUFFER_MANAGEMENT_H
#define RENDERING_RENDERERS_BUFFER_MANAGEMENT_H

#include "Rendering/RenderingDll.h"


#include <map>

namespace Rendering
{
	class Renderer;

    template <typename PlatformBufferType>
	class BufferManagement 
	{
	public:
		using ClassType = BufferManagement<PlatformBufferType>;
		using BufferType = typename PlatformBufferType::BufferType;
		using BufferConstPtr = std::shared_ptr<const BufferType>;
		using PlatformBufferTypeSharedPtr = std::shared_ptr<PlatformBufferType>;
	    using RendererPtr = std::shared_ptr<Renderer>;

	public:
		explicit BufferManagement(RendererPtr ptr);

		CLASS_INVARIANT_DECLARE;
	
       // ���㡢�����������������㡢��������������������Ѿ���Ӧ�ó��������䡣
       void Bind (BufferConstPtr buffer); 
       void Unbind (BufferConstPtr buffer);

       void EnableVertexBuffer (BufferConstPtr buffer,unsigned int streamIndex, unsigned int offset = 0);
       void DisableVertexBuffer (BufferConstPtr buffer,unsigned int streamIndex);
 
       void EnableIndexBuffer (BufferConstPtr buffer);
       void DisableIndexBuffer (BufferConstPtr buffer);

       void* Lock (BufferConstPtr buffer, BufferLocking mode);
       void Unlock (BufferConstPtr buffer);
       void Update (BufferConstPtr buffer);

       PlatformBufferTypeSharedPtr GetResource (BufferConstPtr buffer);

	private:
       using BufferMap = std::map<BufferConstPtr, PlatformBufferTypeSharedPtr>;

	private:
		std::weak_ptr<Renderer> m_Renderer;
	   BufferMap m_Buffers;	 
	};
}

#endif // RENDERING_RENDERERS_BUFFER_MANAGEMENT_H



	