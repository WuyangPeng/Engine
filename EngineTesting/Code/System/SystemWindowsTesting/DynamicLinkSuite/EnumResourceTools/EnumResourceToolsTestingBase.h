///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:58)

/// 原始文件在SystemTesting下，SystemWindowsTesting下的为自动复制文件，请勿修改。
#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_ENUM_RESOURCE_TOOLS_TESTING_BASE_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_ENUM_RESOURCE_TOOLS_TESTING_BASE_H

#include "System/DynamicLink/Data/EnumResourceData.h"
#include "System/SystemTesting/DynamicLinkSuite/LoadResourceToolsTesting.h"

#include <vector>

namespace System
{
    class EnumResourceToolsTestingBase : public LoadResourceToolsTesting
    {
    public:
        using ClassType = EnumResourceToolsTestingBase;
        using ParentType = LoadResourceToolsTesting;

    public:
        explicit EnumResourceToolsTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void AddEnumResourceData(const DynamicLinkCharType* type, const DynamicLinkCharType* name, WindowsWord language);

    protected:
        using EnumResourceDataContainer = std::vector<EnumResourceData>;
        using EnumResourceDataContainerConstIter = EnumResourceDataContainer::const_iterator;

    protected:
        NODISCARD EnumResourceDataContainerConstIter begin() const noexcept;
        NODISCARD EnumResourceDataContainerConstIter end() const noexcept;
        NODISCARD size_t GetEnumResourceDataSize() const noexcept;
        NODISCARD static ClassType* GetBase(WindowsLongPtrSizeType lParam) noexcept;
        void ClearEnumResourceData() noexcept;

    private:
        EnumResourceDataContainer enumResourceDataContainer;
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_ENUM_RESOURCE_TOOLS_TESTING_BASE_H