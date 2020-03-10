// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 13:38)

#ifndef CORE_TOOLS_FILE_MANAGER_BUFFERIO_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_BUFFERIO_IMPL_H

#include "CoreTools/CoreToolsDll.h"

// ֧�ֶ�ȡ��д������ƻ�����������಻֧�ֶ�д���ʡ�
// ����BufferIOһ����������;��ʹ��FileHandleHelp::LoadFromFile��ȡ�����ļ���Ȼ��ʹ��BufferIO��ȡ�ֶΡ�
// ͬ����BufferIO�����ڽ��ֶ�д��һ����������Ȼ��ʹ��FileHandleHelper::SaveIntoFile���������ļ���

// ���е������ļ����洢Ϊlittle endian��ʽ����Ϊ�����ƽ̨����little endian��

// BufferIO�౻���Ϊ�������ļ����ص���������Ȼ�������������

#include "CoreTools/FileManager/Flags/BufferIOFlags.h"

#include <boost/noncopyable.hpp> 

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE BufferIOImpl : private boost::noncopyable
	{
	public:
		using ClassType = BufferIOImpl;

	public:
		// �������ṩ���������ڴ棬�Լ��Ƿ��ȡ��д�룬����������ڴ档���������ؽ��ж�̬���䡣
		BufferIOImpl(int bytesTotal, BufferIO type);
		virtual ~BufferIOImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual const char* GetBuffer() const = 0;

		int GetBytesTotal() const noexcept;
		int GetBytesProcessed() const noexcept;

		void IncrementBytesProcessed(int bytesNumber) noexcept;

	protected:
		BufferIO GetBufferIOType() const noexcept;
		void SetBytesProcessed(int bytesProcessed) noexcept;

	private:
		int m_BytesTotal;
		int m_BytesProcessed;
		BufferIO m_BufferIOType;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_BUFFERIO_IMPL_H
