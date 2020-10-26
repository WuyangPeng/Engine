//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 14:51)

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
    class CORE_TOOLS_DEFAULT_DECLARE DownloadingFiles final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(DownloadingFiles);
         using String = System::String;

    public:
        DownloadingFiles(const String& url, bool restart, const DownloadingFilesEventSharedPtr& downloadingFilesEvent);

        CLASS_INVARIANT_DECLARE;

    private:
        IMPL_TYPE_DECLARE(DownloadingFiles);
    };
}

#endif  // CORE_TOOLS_DOWNLOADING_FILES_H
