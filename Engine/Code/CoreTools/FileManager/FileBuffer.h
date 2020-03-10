// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 14:20)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_H
#define CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_EXPORT_SHARED_PTR(FileBufferImpl);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE FileBuffer
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(FileBuffer);

	public:
		explicit FileBuffer(size_t count);

		CLASS_INVARIANT_DECLARE;

		const char* GetBufferBegin() const noexcept;
		size_t GetSize() const noexcept;

		char* GetBufferBegin();

	private:
		IMPL_TYPE_DECLARE(FileBuffer);
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_FILE_BUFFER_H
