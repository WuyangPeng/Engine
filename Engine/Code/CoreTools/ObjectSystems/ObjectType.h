//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.2 (2020/09/12 22:53)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_TYPE_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_TYPE_H

#include "ObjectInterface.h"
#include "System/Helper/PragmaWarning/MultiIndex.h"

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
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_TYPE_H
