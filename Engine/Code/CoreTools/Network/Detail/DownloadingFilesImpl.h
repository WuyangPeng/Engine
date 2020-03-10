// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 17:40)

#ifndef CORE_TOOLS_DOWNLOADING_FILES_IMPL_H
#define CORE_TOOLS_DOWNLOADING_FILES_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include "CoreTools/Network/DownloadingFilesEvent.h"

namespace CoreTools
{
	// ���ڴ�Internet�����ļ����ࡣ
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
