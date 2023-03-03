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
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CommonCopyFileTools::CommonCopyFileTools(const String& inFileName, const String& outFileName)
    : ParentType{}, inFile{ inFileName }, outFile{ outFileName }, buffer(inFile.GetFileByteSize())
{
    inFile.Read(buffer.size(), buffer.data());
    outFile.Write(buffer.size(), buffer.data());

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommonCopyFileTools)
