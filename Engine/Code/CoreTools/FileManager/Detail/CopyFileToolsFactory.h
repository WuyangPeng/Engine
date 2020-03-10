// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 13:39)

#ifndef CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_FACTORY_H
#define CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <string>

namespace CoreTools
{
	class CopyFileToolsImpl;

	class CORE_TOOLS_HIDDEN_DECLARE CopyFileToolsFactory
	{
	public:
		using ClassType = CopyFileToolsFactory;
		using CopyFileToolsPtr = std::shared_ptr<CopyFileToolsImpl>;
		using String = System::String;

	public:
		static CopyFileToolsPtr Create(const String& inFileName, const String& outFileName);
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_FACTORY_H
