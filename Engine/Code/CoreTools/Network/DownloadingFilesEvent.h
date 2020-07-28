// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:46)

#ifndef CORE_TOOLS_DOWNLOADING_FILES_EVENT_H
#define CORE_TOOLS_DOWNLOADING_FILES_EVENT_H

#include "CoreTools/CoreToolsDll.h"

#include "NetworkFwd.h"
#include "System/Helper/UnicodeUsing.h" 

#include <memory>
#include <string> 

template class CORE_TOOLS_DEFAULT_DECLARE std::weak_ptr<CoreTools::DownloadingFilesEvent>;
template class CORE_TOOLS_DEFAULT_DECLARE std::enable_shared_from_this<CoreTools::DownloadingFilesEvent>;

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE DownloadingFilesEvent : public std::enable_shared_from_this<DownloadingFilesEvent>
	{
	public:
		using ClassType = DownloadingFilesEvent;

	public:
		DownloadingFilesEvent() noexcept = default;
		virtual ~DownloadingFilesEvent() noexcept = default;
		DownloadingFilesEvent(const DownloadingFilesEvent&) noexcept = default;
		DownloadingFilesEvent& operator=(const DownloadingFilesEvent&) noexcept = default;
		DownloadingFilesEvent(DownloadingFilesEvent&&) noexcept = default;
		DownloadingFilesEvent& operator=(DownloadingFilesEvent&&) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

	public:
		virtual void Update(const System::String& fileName, int contentLength, int totalLength) = 0;
	};

	using ConstDownloadingFilesEventSharedPointer = std::shared_ptr<const DownloadingFilesEvent>;
	using DownloadingFilesEventSharedPointer = std::shared_ptr<DownloadingFilesEvent>;
}

#endif // CORE_TOOLS_DOWNLOADING_FILES_EVENT_H
