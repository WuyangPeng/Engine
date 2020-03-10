// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 18:06)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_FILE_NAME_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_FILE_NAME_IMPL_H

#include "CoreTools/CoreToolsDll.h" 

#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE LogFileNameImpl
	{
	public:
		using ClassType = LogFileNameImpl;
		using String = System::String;

	public:
		explicit LogFileNameImpl(const String& fileName);

		CLASS_INVARIANT_DECLARE;

		String GetFileName() const;

	private:
		String m_FileName;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_LOG_FILE_NAME_IMPL_H
