// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 13:39)

#ifndef CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CFileManagerImpl.h"
#include "ReadFileManagerInterface.h"

// һ����ʾ���ݸ�_tfopen_s��ʾ�Ӵ���˳���ȡ�����Ż����档
// ���ó�Ա����WriteToFile��PutCharacter��PutString����������

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE CReadFileManagerImpl : public CFileManagerImpl, public ReadFileManagerInterface
	{
	public:
		using ClassType = CReadFileManagerImpl;
		using ParentType = CFileManagerImpl;
		using InterfaceType = ReadFileManagerInterface;

	public:
		explicit CReadFileManagerImpl(const String& fileName);
		~CReadFileManagerImpl();

		CReadFileManagerImpl(const CReadFileManagerImpl&) = delete;
		CReadFileManagerImpl& operator=(const CReadFileManagerImpl&) = delete;
		CReadFileManagerImpl(CReadFileManagerImpl&&) noexcept = delete;
		CReadFileManagerImpl& operator=(CReadFileManagerImpl&&) noexcept = delete;

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		int GetFileByteSize() const override;

		// ���ҽ����������ֽ�������data�Ĵ�С�������ǳɹ��ġ������׳�Error�쳣��
		void Read(size_t itemSize, void* data) override;
		void Read(size_t itemSize, size_t itemsNumber, void* data) override;

	private:
		// ��ֹ�������³�Ա����
		size_t WriteToFile(size_t itemSize, size_t itemsNumber, const void* data) override;
		bool PutCharacter(int character) override;
		bool PutString(const std::string& str) override;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_IMPL_H