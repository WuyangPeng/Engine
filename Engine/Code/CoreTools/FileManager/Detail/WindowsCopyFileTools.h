// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 13:43)

#ifndef CORE_TOOLS_FILE_MANAGER_WINDOWS_COPY_FILE_TOOLS_H
#define CORE_TOOLS_FILE_MANAGER_WINDOWS_COPY_FILE_TOOLS_H

#include "CoreTools/CoreToolsDll.h"

#include "CopyFileToolsImpl.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE WindowsCopyFileTools : public CopyFileToolsImpl
	{
	public:
		using ClassType = WindowsCopyFileTools;
		using ParentType = CopyFileToolsImpl;

	public:
		WindowsCopyFileTools(const String& inFileName, const String& outFileName);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		String m_InFileName;
		String m_OutFileName;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_WINDOWS_COPY_FILE_TOOLS_H


