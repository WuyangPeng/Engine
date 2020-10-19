//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/15 18:36)

#include "CoreTools/CoreToolsExport.h"

#include "LogFileNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::LogFileNameImpl::LogFileNameImpl(const String& fileName)
    : m_FileName{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogFileNameImpl)

System::String CoreTools::LogFileNameImpl::GetFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_FileName;
}
