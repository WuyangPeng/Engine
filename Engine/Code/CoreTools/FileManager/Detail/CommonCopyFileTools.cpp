/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 23:32)

#include "CoreTools/CoreToolsExport.h"

#include "CommonCopyFileTools.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CommonCopyFileTools::CommonCopyFileTools(const String& inFileName, const String& outFileName)
    : ParentType{},
      inFile{ inFileName },
      outFile{ outFileName },
      buffer(inFile.GetFileByteSize())
{
    Copy();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::CommonCopyFileTools::Copy()
{
    inFile.Read(buffer.size(), buffer.data());
    outFile.Write(buffer.size(), buffer.data());
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CommonCopyFileTools)
