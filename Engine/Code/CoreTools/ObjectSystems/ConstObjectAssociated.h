//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/21 20:12)

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

        ConstObjectAssociated(const ConstObjectSharedPtr& object, uint64_t associated) noexcept
            : m_Object{ object }, m_Associated{ associated }
        {
        }

        ConstObjectSharedPtr m_Object;
        uint64_t m_Associated;
    };

    using ConstObjectInterfaceAssociated = ConstObjectAssociated<ObjectInterface>;

    using ConstRegisterOrderedUnique = boost::multi_index::ordered_unique<boost::multi_index::tag<UniqueObject>, BOOST_MULTI_INDEX_MEMBER(ConstObjectInterfaceAssociated, ConstObjectInterfaceSharedPtr, m_Object)>;
    using ConstRegisterContainer = boost::multi_index_container<ConstObjectInterfaceAssociated, boost::multi_index::indexed_by<boost::multi_index::random_access<>, ConstRegisterOrderedUnique>>;
    using ConstRegisterContainerConstIter = ConstRegisterContainer::const_iterator;
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_CONST_OBJECT_ASSOCIATED_H
