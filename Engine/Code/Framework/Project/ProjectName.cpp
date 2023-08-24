///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/04 16:12)

#include "Framework/FrameworkExport.h"

#include "ProjectName.h"
#include "Detail/ProjectNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::ProjectName::ProjectName(const String& fileName, const EnvironmentDirectory& environmentDirectory)
    : impl{ fileName, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ProjectName)

System::String Framework::ProjectName::GetSelectDescribe() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetSelectDescribe();
}

bool Framework::ProjectName::IsSelectValid(int select) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->IsSelectValid(select);
}

System::String Framework::ProjectName::GetEngineeringName(int select) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetEngineeringName(select);
}

int Framework::ProjectName::GetContainerPrintWidth() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetContainerPrintWidth();
}
