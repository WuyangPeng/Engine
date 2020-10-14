//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/14 10:11)

#include "CoreTools/CoreToolsExport.h"

#include "CommonCopyFileTools.h"
#include "CopyFileToolsFactory.h"
#include "WindowsCopyFileTools.h"

using std::make_shared;

// static
CoreTools::CopyFileToolsFactory::CopyFileToolsPtr CoreTools::CopyFileToolsFactory::Create(const String& inFileName, const String& outFileName)
{
#ifdef SYSTEM_PLATFORM_WIN32
    return make_shared<WindowsCopyFileTools>(inFileName, outFileName);
#else  // !SYSTEM_PLATFORM_WIN32
    return make_shared<CommonCopyFileTools>(inFileName, outFileName);
#endif  // SYSTEM_PLATFORM_WIN32
}
