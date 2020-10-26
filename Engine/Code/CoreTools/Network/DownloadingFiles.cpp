//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 15:02)

#include "CoreTools/CoreToolsExport.h"

#include "DownloadingFiles.h"
#include "Detail/DownloadingFilesImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::DownloadingFiles::DownloadingFiles(const String& url, bool restart, const DownloadingFilesEventSharedPtr& downloadingFilesEvent)
    : m_Impl{ make_shared<ImplType>(url, restart, downloadingFilesEvent) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, DownloadingFiles)
