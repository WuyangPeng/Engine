// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 13:43)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_IMPL_H

#include "FileHandleImpl.h"
#include "WriteFileManagerInterface.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE WriteFileHandleImpl : public FileHandleImpl, public WriteFileManagerInterface
	{
	public:
		using ClassType = WriteFileHandleImpl;
		using ParentType = FileHandleImpl;
		using InterfaceType = WriteFileManagerInterface;

	public:
		explicit WriteFileHandleImpl(const String& fileName, FileHandleCreationDisposition creation = FileHandleCreationDisposition::CreateAlways);
		virtual ~WriteFileHandleImpl();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual int GetFileByteSize() const override;

		virtual void Write(size_t itemSize, const void* data) override;
		virtual void Write(size_t itemSize, size_t itemsNumber, const void* data) override;

		virtual void ReadFromFile(size_t itemSize, size_t itemsNumber, void* data) override;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_IMPL_H