//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/14 14:18)

#include "CoreTools/CoreToolsExport.h"

#include "CopyFileTools.h"
#include "Detail/CopyFileToolsFactory.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CopyFileTools::CopyFileTools(const String& inFileName, const String& outFileName)
    : m_Impl{ CopyFileToolsFactory::Create(inFileName, outFileName) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, CopyFileTools)
