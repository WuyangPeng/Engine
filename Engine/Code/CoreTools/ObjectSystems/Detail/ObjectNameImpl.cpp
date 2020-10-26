//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/22 14:57)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::ObjectNameImpl::ObjectNameImpl(const string& name)
    : m_Name{ name }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectNameImpl)

string CoreTools::ObjectNameImpl::GetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Name;
}

bool CoreTools::ObjectNameImpl::IsExactly(const ObjectNameImpl& name) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Name == name.m_Name;
}

void CoreTools::ObjectNameImpl::SetName(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Name = name;
}
