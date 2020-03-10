// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 14:21)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_FILE_HANDLE_H
#define CORE_TOOLS_FILE_MANAGER_READ_FILE_HANDLE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(ReadFileHandleImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE ReadFileHandle : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(ReadFileHandle);
		using String = System::String;

	public:
		explicit ReadFileHandle(const String& fileName);

		CLASS_INVARIANT_DECLARE;

		int GetFileByteSize() const;

		void Read(size_t itemSize, void* data);
		void Read(size_t itemSize, size_t itemsNumber, void* data);

	private:
		IMPL_TYPE_DECLARE(ReadFileHandle);
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_READ_FILE_HANDLE_H
