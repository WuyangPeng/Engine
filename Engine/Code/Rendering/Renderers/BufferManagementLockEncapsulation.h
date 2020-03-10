// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:29)

#ifndef RENDERING_RENDERERS_BUFFER_MANAGEMENT_LOCK_ENCAPSULATION_H
#define RENDERING_RENDERERS_BUFFER_MANAGEMENT_LOCK_ENCAPSULATION_H

#include "Rendering/RenderingDll.h"

#include <boost/noncopyable.hpp>

namespace Rendering
{
	template <typename BufferManagementType>
	class BufferManagementLockEncapsulation : boost::noncopyable
	{
	public:
		using ClassType = BufferManagementLockEncapsulation<BufferManagementType>;
		using BufferConstPtr = typename BufferManagementType::BufferConstPtr;

	public:
		explicit BufferManagementLockEncapsulation(BufferManagementType& manager);
		~BufferManagementLockEncapsulation();

		CLASS_INVARIANT_DECLARE;

		void* Lock(BufferConstPtr buffer,BufferLocking mode);
	
	private:
		BufferManagementType& m_Manager;
		BufferConstPtr m_Buffer;		
	};
}

#endif // RENDERING_RENDERERS_BUFFER_MANAGEMENT_LOCK_ENCAPSULATION_H



	