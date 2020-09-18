// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 13:43)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_BUFFERIO_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_BUFFERIO_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "BufferIOImpl.h"

#include <vector>
#include "../FileBuffer.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE WriteBufferIOImpl : public BufferIOImpl
	{
	public:
		using ClassType = WriteBufferIOImpl;
		using ParentType = BufferIOImpl;

	public:
		explicit WriteBufferIOImpl(int bufferSize)  ;
 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		const char* GetBuffer() const noexcept override;

		void Write(size_t itemSize, const void* data);
		void Write(size_t itemSize, size_t itemsNumber, const void* data);

	private:
		// 当且仅当写入的字节数等于data的大小，操作是成功的。否则抛出Error异常。	 
		uint32_t WriteToBuffer(size_t itemSize, size_t itemsNumber, const void* data);

	private:
                FileBuffer m_Buffer;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_WRITE_BUFFERIO_IMPL_H