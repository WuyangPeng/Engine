///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:27)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_COPY_UNSHARED_EXPORT_IMPL(ObjectLink, ObjectLinkImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ObjectLink final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ObjectLink);

        using LinkSequentialContainer = std::vector<ObjectInterfaceSharedPtr>;
        using LinkSequentialContainerIter = LinkSequentialContainer::iterator;
        using LinkSequentialContainerConstIter = LinkSequentialContainer::const_iterator;
        using ObjectLinkSharedPtr = std::shared_ptr<ObjectLink>;

    public:
        NODISCARD static ObjectLinkSharedPtr Create();

    private:
        enum class ObjectLinkInit
        {
            Default,
        };

    public:
        explicit ObjectLink(ObjectLinkInit objectLinkInit);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr GetObjectInterface(int64_t uniqueId);
        NODISCARD int GetOrderedSize() const;

        void Insert(int64_t uniqueId, const ObjectInterfaceSharedPtr& object);

        void Sort();

        NODISCARD LinkSequentialContainerConstIter begin() const noexcept;
        NODISCARD LinkSequentialContainerConstIter end() const noexcept;
        NODISCARD LinkSequentialContainerIter begin() noexcept;
        NODISCARD LinkSequentialContainerIter end() noexcept;

        template <typename T>
        void ResolveLink(T& object);
        template <typename T>
        void ResolveLinkContainer(T& object);

    private:
        PackageType impl;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(ObjectLink);
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_H
