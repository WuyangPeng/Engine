/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:09)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_IN_TOP_LEVEL_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_IN_TOP_LEVEL_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "CoreTools/ObjectSystems/ObjectType.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE InTopLevelImpl final
    {
    public:
        using ClassType = InTopLevelImpl;

    public:
        InTopLevelImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsTopLevel(const ObjectInterfaceSharedPtr& object) const;
        NODISCARD int GetTopLevelSize() const;

        NODISCARD ObjectContainerConstIter begin() const noexcept;
        NODISCARD ObjectContainerConstIter end() const noexcept;

        NODISCARD ObjectContainerIter begin() noexcept;
        NODISCARD ObjectContainerIter end() noexcept;

        /// 对顶层的对象进行保存。
        void Insert(const ObjectInterfaceSharedPtr& object);

    private:
        /// 顶层对象的流。
        ObjectContainer topLevel;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_IN_TOP_LEVEL_IMPL_H
