// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:15)

#ifndef CORE_TOOLS_ENGINE_CONFIGURATION_STRING_REPLACING_H
#define CORE_TOOLS_ENGINE_CONFIGURATION_STRING_REPLACING_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>  

CORE_TOOLS_EXPORT_SHARED_PTR(StringReplacingImpl);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE StringReplacing
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(StringReplacing);

	public:
		explicit StringReplacing(const std::string& configurationFileName);

		CLASS_INVARIANT_DECLARE;

		const System::String GetReplacing(const System::String& original) const;

	private:
		IMPL_TYPE_DECLARE(StringReplacing);
	};
}

#endif // CORE_TOOLS_ENGINE_CONFIGURATION_STRING_REPLACING_H
