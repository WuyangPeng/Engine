//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 14:45)

#ifndef CORE_TOOLS_DOWNLOADING_FILES_IMPL_H
#define CORE_TOOLS_DOWNLOADING_FILES_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Network/DownloadingFilesEvent.h"

namespace CoreTools
{
    // ���ڴ�Internet�����ļ����ࡣ
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
