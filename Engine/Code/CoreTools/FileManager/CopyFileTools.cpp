///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/09 1:45)

#include "CoreTools/CoreToolsExport.h"

#include "CopyFileTools.h"
#include "Detail/CopyFileToolsFactory.h"
#include "Detail/CopyFileToolsImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CopyFileTools::CopyFileTools(const String& inFileName, const String& outFileName)
    : impl{ ImplCreateUseFactory::Default, inFileName, outFileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CopyFileTools)
