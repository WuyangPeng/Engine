/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 00:05)

#include "CoreTools/CoreToolsExport.h"

#include "WindowsCopyFileTools.h"
#include "System/FileManager/File.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::WindowsCopyFileTools::WindowsCopyFileTools(const String& inFileName, const String& outFileName)
    : inFileName{ inFileName }, outFileName{ outFileName }
{
    if (!System::CopySystemFile(inFileName, outFileName))
    {
        THROW_WINDOWS_EXCEPTION
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, WindowsCopyFileTools)
