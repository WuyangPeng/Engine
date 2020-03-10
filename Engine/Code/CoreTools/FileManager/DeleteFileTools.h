// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 14:19)

#ifndef CORE_TOOLS_FILE_MANAGER_DELETE_FILE_TOOLS_H
#define CORE_TOOLS_FILE_MANAGER_DELETE_FILE_TOOLS_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(DeleteFileToolsImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE DeleteFileTools : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(DeleteFileTools);
		using String = System::String;

	public:
		explicit DeleteFileTools(const String& fileName);

		CLASS_INVARIANT_DECLARE;

	private:
		IMPL_TYPE_DECLARE(DeleteFileTools);
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_DELETE_FILE_TOOLS_H