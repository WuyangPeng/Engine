// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:42)

#ifndef CORE_TOOLS_DOWNLOADING_FILES_H
#define CORE_TOOLS_DOWNLOADING_FILES_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Network/DownloadingFilesEvent.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(DownloadingFilesImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE DownloadingFiles : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(DownloadingFiles);

	public:
		DownloadingFiles(const System::String& url, bool restart, const DownloadingFilesEventSharedPointer& downloadingFilesEvent);

		CLASS_INVARIANT_DECLARE;

	private:
		IMPL_TYPE_DECLARE(DownloadingFiles);
	};
}

#endif // CORE_TOOLS_DOWNLOADING_FILES_H
