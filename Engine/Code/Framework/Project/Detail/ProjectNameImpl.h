/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:51)

#ifndef FRAMEWORK_PROJECT_PROJECT_NAME_IMPL_H
#define FRAMEWORK_PROJECT_PROJECT_NAME_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"

#include <vector>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE ProjectNameImpl final
    {
    public:
        using ClassType = ProjectNameImpl;

        using String = System::String;

    public:
        ProjectNameImpl(const String& fileName, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetSelectDescribe() const;
        NODISCARD bool IsSelectValid(int select) const;
        NODISCARD String GetEngineeringName(int select) const;
        NODISCARD int GetContainerPrintWidth() const;

    private:
        using ProjectNameContainer = std::vector<String>;

    private:
        NODISCARD String GetSelectDescribe(const String& element, int index) const;

    private:
        ProjectNameContainer container;
    };
}

#endif  // FRAMEWORK_PROJECT_PROJECT_NAME_IMPL_H