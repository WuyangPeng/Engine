///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/09 1:37)

#include "CoreTools/CoreToolsExport.h"

#include "CommonCopyFileTools.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CommonCopyFileTools::CommonCopyFileTools(const String& inFileName, const String& outFileName)
    : ParentType{}, inFile{ inFileName }, outFile{ outFileName }, buffer(inFile.GetFileByteSize())
{
    inFile.Read(buffer.size(), buffer.data());
    outFile.Write(buffer.size(), buffer.data());

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommonCopyFileTools)
