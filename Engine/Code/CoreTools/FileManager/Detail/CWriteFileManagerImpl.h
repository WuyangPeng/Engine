// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 13:39)

#ifndef CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CFileManagerImpl.h"
#include "WriteFileManagerInterface.h"

// һ����ʾ���ݸ�_tfopen_s��ʾ�Ӵ���˳���ȡ�����Ż����档�����ӳ���ReadFromFile����������

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE CWriteFileManagerImpl : public CFileManagerImpl, public WriteFileManagerInterface
	{
	public:
		using ClassType = CWriteFileManagerImpl;
		using ParentType = CFileManagerImpl;
		using InterfaceType = WriteFileManagerInterface;

	public:
		explicit CWriteFileManagerImpl(const String& fileName);
		 
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		int GetFileByteSize() const override;

		// ���ҽ���д����ֽ�������data�Ĵ�С�������ǳɹ��ġ������׳�Error�쳣��
		void Write(size_t itemSize, const void* data) override;
		void Write(size_t itemSize, size_t itemsNumber, const void* data) override;

#ifdef SYSTEM_BIG_ENDIAN
	private:
		size_t WriteToFileWithBigEndian(size_t itemSize, size_t itemsNumber, const void* data) noexcept;
		size_t WriteToFileSwap2ByteOrder(size_t itemsNumber, const void* data) noexcept;
		size_t WriteToFileSwap4ByteOrder(size_t itemsNumber, const void* data) noexcept;
		size_t WriteToFileSwap8ByteOrder(size_t itemsNumber, const void* data) noexcept;
#endif // SYSTEM_BIG_ENDIAN

	private:
		// ��ֹ�������³�Ա����
		size_t ReadFromFile(size_t itemSize, size_t itemsNumber, void* data)   override;
		int GetCharacter()    override;
		bool UnGetCharacter(int character)   override;
		std::string GetString(int count) override;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_IMPL_H