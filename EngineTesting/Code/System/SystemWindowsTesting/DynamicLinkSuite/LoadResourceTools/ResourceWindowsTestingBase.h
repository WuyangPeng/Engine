///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:38)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_RESOURCE_WINDOWS_TESTING_BASE_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_RESOURCE_WINDOWS_TESTING_BASE_H

#include "System/SystemWindowsTesting/DynamicLinkSuite/LoadResourceToolsTesting.h"
#include "System/Windows/Using/WindowsUsing.h"

#include <map>

namespace System
{
    class ResourceWindowsTestingBase : public LoadResourceToolsTesting
    {
    public:
        using ClassType = ResourceWindowsTestingBase;
        using ParentType = LoadResourceToolsTesting;

    public:
        ResourceWindowsTestingBase(const OStreamShared& stream, WindowsHInstance instance);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using TypeNameContainer = std::map<WindowsWord, const DynamicLinkCharType*>;
        using TypeNameContainerConstIter = TypeNameContainer::const_iterator;

    protected:
        NODISCARD TypeNameContainerConstIter begin() const noexcept;
        NODISCARD TypeNameContainerConstIter end() const noexcept;
        NODISCARD WindowsHInstance GetInstance() const noexcept;

    private:
        WindowsHInstance instance;
        TypeNameContainer container;
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_RESOURCE_WINDOWS_TESTING_BASE_H