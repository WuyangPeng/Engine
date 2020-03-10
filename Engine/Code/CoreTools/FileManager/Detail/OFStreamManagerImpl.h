// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 13:41)

#ifndef CORE_TOOLS_FILE_MANAGER_OFSTREAM_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_OFSTREAM_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/FileManager/Using/CFileUsing.h"

#include <string>
#include <fstream>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE OFStreamManagerImpl
	{
	public:
		using ClassType = OFStreamManagerImpl;
		using String = System::String;
		using PosType = System::PosType;		
		using OFileStream = System::OFileStream;

	public:
		OFStreamManagerImpl(const String& fileName, bool addition);

		CLASS_INVARIANT_DECLARE;

		PosType GetOFStreamSize() const;

		OFStreamManagerImpl& operator << (const String& message);
		void SetSimplifiedChinese();

	private:
		void OpenFile(bool addition);
		void SeekEnd();

	private:
		OFileStream m_OStream;
		String m_FileName;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_OFSTREAM_MANAGER_IMPL_H
