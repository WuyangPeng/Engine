///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/29 16:27)

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

        ConstObjectAssociated(const ConstObjectSharedPtr& object, int64_t associated) noexcept
            : object{ object }, associated{ associated }
        {
        }

        explicit ConstObjectAssociated(const ConstObjectSharedPtr& object) noexcept
            : object{ object }, associated{ 0 }
        {
        }

        ConstObjectSharedPtr object;
        int64_t associated;
    };

    using ConstObjectInterfaceAssociated = ConstObjectAssociated<ObjectInterface>;

    using ConstRegisterOrderedUnique = boost::multi_index::ordered_unique<boost::multi_index::tag<UniqueObject>, BOOST_MULTI_INDEX_MEMBER(ConstObjectInterfaceAssociated, ConstObjectInterfaceSharedPtr, object)>;
    using ConstRegisterContainer = boost::multi_index_container<ConstObjectInterfaceAssociated, boost::multi_index::indexed_by<boost::multi_index::random_access<>, ConstRegisterOrderedUnique>>;
    using ConstRegisterContainerConstIter = ConstRegisterContainer::const_iterator;
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_CONST_OBJECT_ASSOCIATED_H
