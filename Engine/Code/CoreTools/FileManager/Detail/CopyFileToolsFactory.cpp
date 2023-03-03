///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/02 10:30)

#include "CoreTools/CoreToolsExport.h"

#include "CommonCopyFileTools.h"
#include "CopyFileToolsFactory.h"
#include "WindowsCopyFileTools.h"

// static
CoreTools::CopyFileToolsFactory::CopyFileToolsSharedPtr CoreTools::CopyFileToolsFactory::Create(const String& inFileName, const String& outFileName)
{
#ifdef SYSTEM_PLATFORM_WIN32

    return std::make_shared<WindowsCopyFileTools>(inFileName, outFileName);

#else  // !SYSTEM_PLATFORM_WIN32

    return std::make_shared<CommonCopyFileTools>(inFileName, outFileName);

#endif  // SYSTEM_PLATFORM_WIN32
}
