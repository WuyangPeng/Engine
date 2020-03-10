// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 17:40)

#ifndef CORE_TOOLS_DOWNLOADING_FILES_IMPL_H
#define CORE_TOOLS_DOWNLOADING_FILES_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include "CoreTools/Network/DownloadingFilesEvent.h"

namespace CoreTools
{
	// 用于从Internet下载文件的类。
	class CORE_TOOLS_HIDDEN_DECLARE DownloadingFilesImpl
	{
	public:
		using ClassType = DownloadingFilesImpl;

	public:
		DownloadingFilesImpl(const System::String& url, bool restart, const DownloadingFilesEventSharedPointer& downloadingFilesEvent);

		CLASS_INVARIANT_DECLARE;

	private:
		void Download();
		void CheckUrl();
		void CheckInternetAttemptConnect();
		System::String GetFileName() const;

	public:
		System::String m_Url;
		bool m_Restart;
		std::weak_ptr<DownloadingFilesEvent> m_DownloadingFilesEvent;
	};
}

#endif // CORE_TOOLS_DOWNLOADING_FILES_IMPL_H
