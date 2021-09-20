//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/22 10:15)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "CoreTools/Helper/ExportMacro.h"

 
EXPORT_SHARED_PTR(CoreTools, ObjectLinkImpl, CORE_TOOLS_DEFAULT_DECLARE);
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ObjectLink final
    {
    public:
    public:
        void Swap(ObjectLink& rhs) noexcept;

    public:
        TYPE_DECLARE(ObjectLink);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~ObjectLink() noexcept = default;
        ObjectLink(const ObjectLink& rhs);
        ObjectLink& operator=(const ObjectLink& rhs);
        ObjectLink(ObjectLink&& rhs) noexcept;
        ObjectLink& operator=(ObjectLink&& rhs) noexcept;
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
        using ObjectLinkImplPtr = std::shared_ptr<ImplType>;

    private:
        ObjectLinkImplPtr impl;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(ObjectLink);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_H
