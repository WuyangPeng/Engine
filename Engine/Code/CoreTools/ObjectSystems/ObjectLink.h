//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 10:15)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_EXPORT_SHARED_PTR(ObjectLinkImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ObjectLink final
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(ObjectLink, DESTRUCTOR_DEFAULT);
        using LinkSequentialContainer = std::vector<ObjectInterfaceSharedPtr>;
        using LinkSequentialContainerIter = LinkSequentialContainer::iterator;
        using LinkSequentialContainerConstIter = LinkSequentialContainer::const_iterator;

    public:
        explicit ObjectLink(DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] ObjectInterfaceSharedPtr GetObjectInterface(uint64_t uniqueID);
        [[nodiscard]] int GetOrderedSize() const;

        void Insert(uint64_t uniqueID, const ObjectInterfaceSharedPtr& object);

        void Sort();

        [[nodiscard]] LinkSequentialContainerConstIter begin() const noexcept;
        [[nodiscard]] LinkSequentialContainerConstIter end() const noexcept;
        [[nodiscard]] LinkSequentialContainerIter begin() noexcept;
        [[nodiscard]] LinkSequentialContainerIter end() noexcept;

        template <typename T>
        void ResolveLink(T& object);
        template <typename T>
        void ResolveLinkContainer(T& object);

    private:
        IMPL_TYPE_DECLARE(ObjectLink);
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(ObjectLink);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_H
