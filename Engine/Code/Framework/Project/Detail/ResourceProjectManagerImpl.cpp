///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 16:12)

#include "Framework/FrameworkExport.h"

#include "ResourceProjectManagerImpl.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Framework/Project/GUIProjectManager.h"
#include "Framework/Project/ProjectName.h"

Framework::ResourceProjectManagerImpl::ResourceProjectManagerImpl(const EnvironmentDirectory& environmentDirectory)
    : environmentDirectory{ environmentDirectory }, directory{ System::GetEngineeringDirectory() }, projectName{}
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ResourceProjectManagerImpl)

bool Framework::ResourceProjectManagerImpl::Create()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    projectName = std::make_unique<ProjectName>(SYSTEM_TEXT("Project.json"), environmentDirectory);

    return true;
}

bool Framework::ResourceProjectManagerImpl::Initialize(const GUIProjectManager& gui) const
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (projectName != nullptr)
    {
        gui.PrintSelect(*projectName);

        return true;
    }
    else
    {
        return false;
    }
}

bool Framework::ResourceProjectManagerImpl::IsSelectValid(int select) const
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CheckProjectName();

    return projectName->IsSelectValid(select);
}

System::String Framework::ResourceProjectManagerImpl::GetEngineeringName(int select) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    CheckProjectName();

    return projectName->GetEngineeringName(select);
}

void Framework::ResourceProjectManagerImpl::PrintEngineering(const String& engineeringName, const GUIProjectManager& gui) const
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CheckProjectName();

    gui.PrintEngineering(engineeringName);
    gui.PrintSelect(*projectName);
}

int Framework::ResourceProjectManagerImpl::GetContainerPrintWidth() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    CheckProjectName();

    return projectName->GetContainerPrintWidth();
}

void Framework::ResourceProjectManagerImpl::CheckProjectName() const
{
    if (projectName == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未正确调用Create初始化工程名。"s))
    }
}
