// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 18:07)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_FILE_NAME_H
#define CORE_TOOLS_LOG_MANAGER_LOG_FILE_NAME_H

#include "CoreTools/CoreToolsDll.h" 

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(LogFileNameImpl);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE LogFileName
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(LogFileName);
		using String = System::String;

	public:
		explicit LogFileName(const String& fileName);

		CLASS_INVARIANT_DECLARE;

		String GetFileName() const;

	private:
		IMPL_TYPE_DECLARE(LogFileName);
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_LOG_FILE_NAME_H
