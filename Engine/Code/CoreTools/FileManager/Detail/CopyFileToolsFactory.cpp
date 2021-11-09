///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/03 13:34)

#include "CoreTools/CoreToolsExport.h"

#include "CommonCopyFileTools.h"
#include "CopyFileToolsFactory.h"
#include "WindowsCopyFileTools.h"

using std::make_shared;

// static
CoreTools::CopyFileToolsFactory::CopyFileToolsSharedPtr CoreTools::CopyFileToolsFactory::Create(const String& inFileName, const String& outFileName)
{
#ifdef SYSTEM_PLATFORM_WIN32
    return make_shared<WindowsCopyFileTools>(inFileName, outFileName);
#else  // !SYSTEM_PLATFORM_WIN32
    return make_shared<CommonCopyFileTools>(inFileName, outFileName);
#endif  // SYSTEM_PLATFORM_WIN32
}
