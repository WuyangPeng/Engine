// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 14:22)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_BUFFERIO_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_BUFFERIO_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(WriteBufferIOImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE WriteBufferIO : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(WriteBufferIO);

	public:
		WriteBufferIO(int bytesTotal, char* buffer);

		CLASS_INVARIANT_DECLARE;

		const char* GetBuffer() const;
		int GetBytesTotal() const noexcept;
		int GetBytesProcessed() const noexcept;

		void IncrementBytesProcessed(int bytesNumber) noexcept;
		void Write(size_t itemSize, const void* data);
		void Write(size_t itemSize, size_t itemsNumber, const void* data);

	private:
		IMPL_TYPE_DECLARE(WriteBufferIO);
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_WRITE_BUFFERIO_H
