///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/04 16:14)

#ifndef FRAMEWORK_PROJECT_GUI_PROJECT_MANAGER_H
#define FRAMEWORK_PROJECT_GUI_PROJECT_MANAGER_H

#include "Framework/FrameworkDll.h"

#include "ProjectFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "Framework/MiddleLayer/GUIManagerInterface.h"

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE GUIProjectManager : public GUIManagerInterface
    {
    public:
        using ClassType = GUIProjectManager;
        using ParentType = GUIManagerInterface;

        using String = System::String;

    public:
        GUIProjectManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        virtual void PrintSelect(const ProjectName& projectName) const;
        virtual void PrintEngineering(const String& engineeringName) const;
    };
}

#endif  // FRAMEWORK_PROJECT_GUI_PROJECT_MANAGER_H
