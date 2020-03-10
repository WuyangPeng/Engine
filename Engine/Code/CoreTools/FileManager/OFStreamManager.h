// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 14:21)

#ifndef CORE_TOOLS_FILE_MANAGER_OFSTREAM_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_OFSTREAM_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/FileManager/Using/CFileUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(OFStreamManagerImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE OFStreamManager : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(OFStreamManager);
		using String = System::String;
		using PosType = System::PosType;		

	public:
		OFStreamManager(const String& fileName, bool addition);

		CLASS_INVARIANT_DECLARE;

		PosType GetOFStreamSize() const;

		OFStreamManager& operator << (const String& message);
		void SetSimplifiedChinese();

	private:
		IMPL_TYPE_DECLARE(OFStreamManager);
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_OFSTREAM_MANAGER_H
