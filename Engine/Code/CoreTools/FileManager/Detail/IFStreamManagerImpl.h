// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 13:41)

#ifndef CORE_TOOLS_FILE_MANAGER_IFSTREAM_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_IFSTREAM_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>
#include <fstream>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE IFStreamManagerImpl
	{
	public:
		using ClassType = IFStreamManagerImpl;
		using String = System::String;
		using OStream = System::OStream;
		using IFileStream = System::IFileStream;

	public:
		explicit IFStreamManagerImpl(const String& fileName);

		CLASS_INVARIANT_DECLARE;

		String GetFileContent() const;
		String BackupFile() const;

		void SetSimplifiedChinese();

	private:
		String GetBackupName() const;
		void CopyContentToStream(OStream* osPtr) const;

	private:
		IFileStream m_IStream;
		String m_FileName;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_IFSTREAM_MANAGER_IMPL_H
