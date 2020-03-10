// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.1.3 (2019/12/25 13:15)
// ��ʼ�汾��0.0.1.3

#ifndef CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(ReadFileManagerInterface);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE ReadFileManager : private boost::noncopyable
	{
	public:
		using ReadFileManagerImpl = ReadFileManagerInterface;
		NON_COPY_CLASSES_TYPE_DECLARE(ReadFileManager);
		using String = System::String;

	public:
		explicit ReadFileManager(const String& fileName);

		CLASS_INVARIANT_DECLARE;

		int GetFileByteSize() const;

		// ���ҽ����������ֽ�������data�Ĵ�С�������ǳɹ��ġ������׳�Error�쳣��
		void Read(size_t itemSize, void* data);
		void Read(size_t itemSize, size_t itemsNumber, void* data);

		const std::string LoadStdString();

	private:
		IMPL_TYPE_DECLARE(ReadFileManager);
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_H
