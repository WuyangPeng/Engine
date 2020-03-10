// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 14:19)

#ifndef CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_H
#define CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(CopyFileToolsImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE CopyFileTools : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(CopyFileTools);
		using String = System::String;

	public:
		CopyFileTools(const String& inFileName, const String& outFileName);

		CLASS_INVARIANT_DECLARE;

	private:
		IMPL_TYPE_DECLARE(CopyFileTools);
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_H
