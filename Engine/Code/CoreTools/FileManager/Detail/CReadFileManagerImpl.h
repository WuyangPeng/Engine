// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 13:39)

#ifndef CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CFileManagerImpl.h"
#include "ReadFileManagerInterface.h"

// 一个提示传递给_tfopen_s表示从磁盘顺序存取，以优化缓存。
// 调用成员函数WriteToFile、PutCharacter和PutString将产生错误。

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

		// 当且仅当读出的字节数等于data的大小，操作是成功的。否则抛出Error异常。
		void Read(size_t itemSize, void* data) override;
		void Read(size_t itemSize, size_t itemsNumber, void* data) override;

	private:
		// 禁止调用以下成员函数
		size_t WriteToFile(size_t itemSize, size_t itemsNumber, const void* data) override;
		bool PutCharacter(int character) override;
		bool PutString(const std::string& str) override;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_IMPL_H