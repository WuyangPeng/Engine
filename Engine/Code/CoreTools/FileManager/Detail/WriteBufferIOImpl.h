// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 13:43)

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
		// ���ҽ���д����ֽ�������data�Ĵ�С�������ǳɹ��ġ������׳�Error�쳣��	 
		uint32_t WriteToBuffer(size_t itemSize, size_t itemsNumber, const void* data);

	private:
                FileBuffer m_Buffer;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_WRITE_BUFFERIO_IMPL_H