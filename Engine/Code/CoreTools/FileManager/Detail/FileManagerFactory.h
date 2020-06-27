// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 13:40)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_MANAGER_FACTORY_H
#define CORE_TOOLS_FILE_MANAGER_FILE_MANAGER_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h" 

#include <string>
#include <memory>

namespace CoreTools
{
	class ReadFileManagerInterface;
	class WriteFileManagerInterface;

	class CORE_TOOLS_HIDDEN_DECLARE FileManagerFactory
	{
	public:
		using ClassType = FileManagerFactory;
		using String = System::String;
		using ReadFileManageInterfacePtr = std::shared_ptr<ReadFileManagerInterface>;
		using WriteFileManageInterfacePtr = std::shared_ptr<WriteFileManagerInterface>;

	public:
		static ReadFileManageInterfacePtr CreateReadFileManage(const String& fileName);
		static WriteFileManageInterfacePtr CreateWriteFileManage(const String& fileName);
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_FILE_MANAGER_FACTORY_H
