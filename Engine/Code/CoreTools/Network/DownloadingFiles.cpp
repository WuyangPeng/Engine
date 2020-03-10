// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:49)

#include "CoreTools/CoreToolsExport.h"

#include "DownloadingFiles.h"
#include "Detail/DownloadingFilesImpl.h"  
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"  

using std::make_shared;

CoreTools::DownloadingFiles
	::DownloadingFiles(const System::String& url, bool restart, const DownloadingFilesEventSharedPointer& downloadingFilesEvent)
	:m_Impl{ make_shared<ImplType>(url,restart,downloadingFilesEvent) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, DownloadingFiles)
