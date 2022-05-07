///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 15:33)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_CONST_OBJECT_ASSOCIATED_H
#define CORE_TOOLS_OBJECT_SYSTEMS_CONST_OBJECT_ASSOCIATED_H

#include "ObjectInterface.h"
#include "ObjectType.h"
#include "System/Helper/PragmaWarning/MultiIndex.h"

namespace CoreTools
{
    template <typename T>
    struct ConstObjectAssociated final
    {
        static_assert(std::is_base_of_v<ObjectInterface, T>, "T is not base of ObjectInterface");

        using ClassType = ConstObjectAssociated<T>;
        using ObjectType = T;
        using ConstObjectSharedPtr = std::shared_ptr<const T>;

        ConstObjectAssociated() noexcept
            : object{ nullptr }, associated{ 0 }
        {
        }

        ConstObjectAssociated(const ConstObjectSharedPtr& object, uint64_t associated) noexcept
            : object{ object }, associated{ associated }
        {
        }

        explicit ConstObjectAssociated(const ConstObjectSharedPtr& object) noexcept
            : object{ object }, associated{ 0 }
        {
        }

        ConstObjectSharedPtr object;
        uint64_t associated;
    };

    using ConstObjectInterfaceAssociated = ConstObjectAssociated<ObjectInterface>;

    using ConstRegisterOrderedUnique = boost::multi_index::ordered_unique<boost::multi_index::tag<UniqueObject>, BOOST_MULTI_INDEX_MEMBER(ConstObjectInterfaceAssociated, ConstObjectInterfaceSharedPtr, object)>;
    using ConstRegisterContainer = boost::multi_index_container<ConstObjectInterfaceAssociated, boost::multi_index::indexed_by<boost::multi_index::random_access<>, ConstRegisterOrderedUnique>>;
    using ConstRegisterContainerConstIter = ConstRegisterContainer::const_iterator;
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_CONST_OBJECT_ASSOCIATED_H
