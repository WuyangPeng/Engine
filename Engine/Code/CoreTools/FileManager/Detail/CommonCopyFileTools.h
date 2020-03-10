// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 13:39)

#ifndef CORE_TOOLS_FILE_MANAGER_COMMON_COPY_FILE_TOOLS_H
#define CORE_TOOLS_FILE_MANAGER_COMMON_COPY_FILE_TOOLS_H

#include "CoreTools/CoreToolsDll.h"

#include "CopyFileToolsImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"

#include <string>
#include <vector>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE CommonCopyFileTools : public CopyFileToolsImpl
	{
	public:
		using ClassType = CommonCopyFileTools;
		using ParentType = CopyFileToolsImpl;

	public:
		CommonCopyFileTools(const String& inFileName, const String& outFileName);
		virtual ~CommonCopyFileTools();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

	private:
		using BufferType = std::vector<char>;

	private:
		ReadFileManager m_InFile;
		WriteFileManager m_OutFile;
		BufferType m_Buffer;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_COMMON_COPY_FILE_TOOLS_H
