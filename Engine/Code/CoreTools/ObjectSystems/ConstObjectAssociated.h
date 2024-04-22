/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 17:05)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_CONST_OBJECT_ASSOCIATED_H
#define CORE_TOOLS_OBJECT_SYSTEMS_CONST_OBJECT_ASSOCIATED_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "ObjectType.h"
#include "System/Helper/PragmaWarning/MultiIndex.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"

namespace CoreTools
{
    template <typename T>
    requires(std::is_base_of_v<ObjectInterface, T>)
    struct ConstObjectAssociated final
    {
        using ClassType = ConstObjectAssociated<T>;
        using ObjectType = T;
        using ConstObjectSharedPtr = std::shared_ptr<const T>;

        ConstObjectAssociated() noexcept
            : object{ nullptr }, associated{ 0 }
        {
        }

        ConstObjectAssociated(ConstObjectSharedPtr object, int64_t associated) noexcept
            : object{ std::move(object) }, associated{ associated }
        {
        }

        explicit ConstObjectAssociated(ConstObjectSharedPtr object) noexcept
            : object{ std::move(object) }, associated{ 0 }
        {
        }

        NODISCARD ConstObjectSharedPtr Clone() const
        {
            if (object != nullptr)
                return boost::polymorphic_pointer_cast<const T>(object->CloneObject());
            else
                return object;
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
