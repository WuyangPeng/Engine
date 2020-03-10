// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 14:21)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_AND_WRITE_FILE_HANDLE_H
#define CORE_TOOLS_FILE_MANAGER_READ_AND_WRITE_FILE_HANDLE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(ReadAndWriteFileHandleImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE ReadAndWriteFileHandle : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(ReadAndWriteFileHandle);
		using String = System::String;

	public:
		explicit ReadAndWriteFileHandle(const String& fileName);

		CLASS_INVARIANT_DECLARE;

		uint64_t GetFileLength() const;

		void Read(size_t itemSize, void* data);
		void Read(size_t itemSize, size_t itemsNumber, void* data);
		void Write(size_t itemSize, const void* data);
		void Write(size_t itemSize, size_t itemsNumber, const void* data);

	private:
		IMPL_TYPE_DECLARE(ReadAndWriteFileHandle);
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_READ_AND_WRITE_FILE_HANDLE_H