//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 14:51)

#ifndef CORE_TOOLS_DOWNLOADING_FILES_EVENT_H
#define CORE_TOOLS_DOWNLOADING_FILES_EVENT_H

#include "CoreTools/CoreToolsDll.h"

#include "NetworkFwd.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/SharedPtrMacro.h"

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
        using String = System::String;

    public:
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)

        DownloadingFilesEvent() noexcept = default;
        virtual ~DownloadingFilesEvent() noexcept = default;
        DownloadingFilesEvent(const DownloadingFilesEvent& rhs) noexcept = default;
        DownloadingFilesEvent& operator=(const DownloadingFilesEvent& rhs) noexcept = default;
        DownloadingFilesEvent(DownloadingFilesEvent&& rhs) noexcept = default;
        DownloadingFilesEvent& operator=(DownloadingFilesEvent&& rhs) noexcept = default;

#include STSTEM_WARNING_POP

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    public:
        virtual void Update(const String& fileName, int contentLength, int totalLength) = 0;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(DownloadingFilesEvent);
}

#endif  // CORE_TOOLS_DOWNLOADING_FILES_EVENT_H
