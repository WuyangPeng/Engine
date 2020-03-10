// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 13:42)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_AND_WRITE_FILE_HANDLE_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_READ_AND_WRITE_FILE_HANDLE_IMPL_H

#include "FileHandleImpl.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE ReadAndWriteFileHandleImpl : public FileHandleImpl
	{
	public:
		using ClassType = ReadAndWriteFileHandleImpl;
		using ParentType = FileHandleImpl;

	public:
		explicit ReadAndWriteFileHandleImpl(const String& fileName);
		virtual ~ReadAndWriteFileHandleImpl();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		void Read(size_t itemSize, void* data);
		void Read(size_t itemSize, size_t itemsNumber, void* data);
		void Write(size_t itemSize, const void* data);
		void Write(size_t itemSize, size_t itemsNumber, const void* data);
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_READ_AND_WRITE_FILE_HANDLE_IMPL_H