///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/02 10:54)

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
