// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 13:43)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_FILE_MANAGER_INTERFACE_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_FILE_MANAGER_INTERFACE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE WriteFileManagerInterface
	{
	public:
		using ClassType = WriteFileManagerInterface;

	public:
		virtual ~WriteFileManagerInterface();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual int GetFileByteSize() const = 0;

		virtual void Write(size_t itemSize, const void* data) = 0;
		virtual void Write(size_t itemSize, size_t itemsNumber, const void* data) = 0;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_INTERFACE_H