// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 13:42)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_BUFFERIO_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_READ_BUFFERIO_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "BufferIOImpl.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE ReadBufferIOImpl : public BufferIOImpl
	{
	public:
		using ClassType = ReadBufferIOImpl;
		using ParentType = BufferIOImpl;

	public:
		ReadBufferIOImpl(int bytesTotal, const char* buffer) noexcept;
 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		const char* GetBuffer() const noexcept override;

		void Read(size_t itemSize, void* data);
		void Read(size_t itemSize, size_t itemsNumber, void* data);

	private:
		// ���ҽ����������ֽ�������data�Ĵ�С�������ǳɹ��ġ������׳�Error�쳣��
		int ReadFromBuffer(size_t itemSize, size_t itemsNumber, void* data);

	private:
		const char* m_Buffer;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_READ_BUFFERIO_IMPL_H