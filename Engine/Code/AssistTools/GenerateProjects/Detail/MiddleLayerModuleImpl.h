///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/21 10:08)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_MIDDLE_LAYER_MODULE_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_MIDDLE_LAYER_MODULE_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE MiddleLayerModuleImpl
    {
    public:
        using ClassType = MiddleLayerModuleImpl;

        using String = System::String;

    public:
        MiddleLayerModuleImpl(String middleLayerName, String uppercaseName, bool isManager) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetMiddleLayerName() const;
        NODISCARD String GetUppercaseName() const;
        NODISCARD bool IsManager() const noexcept;

    private:
        String middleLayerName;
        String uppercaseName;
        bool isManager;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_MIDDLE_LAYER_MODULE_IMPL_H
