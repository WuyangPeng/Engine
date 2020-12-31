//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 14:45)

#ifndef CORE_TOOLS_DOWNLOADING_FILES_IMPL_H
#define CORE_TOOLS_DOWNLOADING_FILES_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Network/DownloadingFilesEvent.h"

namespace CoreTools
{
    // 用于从Internet下载文件的类。
    class CORE_TOOLS_HIDDEN_DECLARE DownloadingFilesImpl final
    {
    public:
        using ClassType = DownloadingFilesImpl;
        using String = System::String;

    public:
        DownloadingFilesImpl(const String& url, bool restart, const DownloadingFilesEventSharedPtr& downloadingFilesEvent);

        CLASS_INVARIANT_DECLARE;

    private:
        void Download();
        void CheckUrl();
        void CheckInternetAttemptConnect();
        [[nodiscard]] String GetFileName() const;

    public:
        String m_Url;
        bool m_Restart;
        std::weak_ptr<DownloadingFilesEvent> m_DownloadingFilesEvent;
    };
}

#endif  // CORE_TOOLS_DOWNLOADING_FILES_IMPL_H
