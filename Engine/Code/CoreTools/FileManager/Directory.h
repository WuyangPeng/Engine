// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 14:20)

#ifndef CORE_TOOLS_FILE_MANAGER_DIRECTORY_H
#define CORE_TOOLS_FILE_MANAGER_DIRECTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "System/Helper/UnicodeUsing.h"

CORE_TOOLS_EXPORT_SHARED_PTR(DirectoryImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE Directory : private boost::noncopyable 
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(Directory);

	public:
		explicit Directory(const System::String& directoryName);

		CLASS_INVARIANT_DECLARE;		 

	private:
		IMPL_TYPE_DECLARE(FileBuffer);
	};
}

 

#endif // CORE_TOOLS_FILE_MANAGER_DIRECTORY_H
