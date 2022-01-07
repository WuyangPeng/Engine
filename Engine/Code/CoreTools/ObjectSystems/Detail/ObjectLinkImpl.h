///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 14:35)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ObjectSystems/ObjectInterface.h"

#include <map>
#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ObjectLinkImpl final
    {
    public:
        using ClassType = ObjectLinkImpl;
        using LinkSequentialContainer = std::vector<ObjectInterfaceSharedPtr>;
        using LinkSequentialContainerIter = LinkSequentialContainer::iterator;
        using LinkSequentialContainerConstIter = LinkSequentialContainer::const_iterator;

    public:
        ObjectLinkImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr GetObjectInterface(uint64_t uniqueID);
        NODISCARD int GetOrderedSize() const;

        void Insert(uint64_t uniqueID, const ObjectInterfaceSharedPtr& object);

        void Sort();

        NODISCARD LinkSequentialContainerConstIter begin() const noexcept;
        NODISCARD LinkSequentialContainerConstIter end() const noexcept;
        NODISCARD LinkSequentialContainerIter begin() noexcept;
        NODISCARD LinkSequentialContainerIter end() noexcept;

    private:
        using LinkAssociatedContainer = std::map<uint64_t, ObjectInterfaceSharedPtr>;

    private:
        // 存储图形加载过程中的顶层对象。
        LinkAssociatedContainer linked;
        LinkSequentialContainer ordered;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_IMPL_H
