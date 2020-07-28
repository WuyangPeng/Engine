// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 13:42)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_FILE_HANDLE_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_READ_FILE_HANDLE_IMPL_H

#include "FileHandleImpl.h"
#include "ReadFileManagerInterface.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE ReadFileHandleImpl : public FileHandleImpl, public ReadFileManagerInterface
	{
	public:
		using ClassType = ReadFileHandleImpl;
		using ParentType = FileHandleImpl;
		using InterfaceType = ReadFileManagerInterface;

	public:
		explicit ReadFileHandleImpl(const String& fileName);
		 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		  int GetFileByteSize() const override;

		  void Read(size_t itemSize, void* data) override;
		  void Read(size_t itemSize, size_t itemsNumber, void* data) override;

		  void WriteToFile(size_t itemSize, size_t itemsNumber, const void* data) override;
		  void AppendToFile(size_t itemSize, size_t itemsNumber, const void* data) override;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_READ_FILE_HANDLE_IMPL_H