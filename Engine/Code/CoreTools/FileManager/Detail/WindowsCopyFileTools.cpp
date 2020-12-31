//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/14 13:52)

#include "CoreTools/CoreToolsExport.h"

#include "WindowsCopyFileTools.h"
#include "System/FileManager/File.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::WindowsCopyFileTools::WindowsCopyFileTools(const String& inFileName, const String& outFileName)
    : m_InFileName{ inFileName }, m_OutFileName{ outFileName }
{
    if (!System::CopySystemFile(m_InFileName.c_str(), m_OutFileName.c_str()))
    {
        THROW_WINDOWS_EXCEPTION;
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, WindowsCopyFileTools)
