// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 13:42)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_INTERFACE_H
#define CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_INTERFACE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE ReadFileManagerInterface
	{
	public:
		using ClassType = ReadFileManagerInterface;

	public:
		virtual ~ReadFileManagerInterface();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual int GetFileByteSize() const = 0;

		virtual void Read(size_t itemSize, void* data) = 0;
		virtual void Read(size_t itemSize, size_t itemsNumber, void* data) = 0;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_INTERFACE_H