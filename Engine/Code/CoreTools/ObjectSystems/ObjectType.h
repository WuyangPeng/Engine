/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:56)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_TYPE_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_TYPE_H

#include "ConstObjectAssociated.h"
#include "ConstWeakObjectAssociated.h"
#include "ObjectAssociated.h"
#include "ObjectInterface.h"
#include "WeakObjectAssociated.h"
#include "System/Helper/PragmaWarning/MultiIndex.h"

#include <string>

namespace CoreTools
{
    struct UniqueObject
    {
    };

    using ConstObjectOrderedUnique = boost::multi_index::ordered_unique<boost::multi_index::tag<UniqueObject>, boost::multi_index::identity<ConstObjectInterfaceSharedPtr>>;
    using ConstObjectContainer = boost::multi_index_container<ConstObjectInterfaceSharedPtr, boost::multi_index::indexed_by<boost::multi_index::random_access<>, ConstObjectOrderedUnique>>;
    using ConstObjectContainerConstIter = ConstObjectContainer::const_iterator;

    using ObjectOrderedUnique = boost::multi_index::ordered_unique<boost::multi_index::tag<UniqueObject>, boost::multi_index::identity<ObjectInterfaceSharedPtr>>;
    using ObjectContainer = boost::multi_index_container<ObjectInterfaceSharedPtr, boost::multi_index::indexed_by<boost::multi_index::random_access<>, ObjectOrderedUnique>>;
    using ObjectContainerConstIter = ObjectContainer::const_iterator;
    using ObjectContainerIter = ObjectContainer::iterator;

    template <typename T>
    struct IsObjectAssociated
    {
        static constexpr auto result = false;
    };

    template <typename T>
    struct IsObjectAssociated<ConstObjectAssociated<T>>
    {
        static constexpr auto result = true;
    };

    template <typename T>
    struct IsObjectAssociated<ConstWeakObjectAssociated<T>>
    {
        static constexpr auto result = true;
    };

    template <typename T>
    struct IsObjectAssociated<ObjectAssociated<T>>
    {
        static constexpr auto result = true;
    };

    template <typename T>
    struct IsObjectAssociated<WeakObjectAssociated<T>>
    {
        static constexpr auto result = true;
    };

    template <typename T>
    struct IsString
    {
        static constexpr auto result = false;
    };

    template <>
    struct IsString<const char*>
    {
        static constexpr auto result = true;
    };

    template <>
    struct IsString<std::string>
    {
        static constexpr auto result = true;
    };

    template <>
    struct IsString<std::string_view>
    {
        static constexpr auto result = true;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_TYPE_H
