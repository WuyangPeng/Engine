///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 14:39)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_IMPL_H

#include "CoreTools/ObjectSystems/ConstObjectAssociated.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ObjectRegisterImpl final
    {
    public:
        using ClassType = ObjectRegisterImpl;

    public:
        ObjectRegisterImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD uint64_t GetUniqueID(const ConstObjectInterfaceSharedPtr& object) const;
        NODISCARD int GetOrderedSize() const;

        NODISCARD ConstRegisterContainerConstIter begin() const noexcept;
        NODISCARD ConstRegisterContainerConstIter end() const noexcept;

        NODISCARD uint64_t RegisterRoot(const ConstObjectInterfaceSharedPtr& object);

    private:
        // 存储objects，对顶层对象使用图的深度优先遍历。
        ConstRegisterContainer registered;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_IMPL_H
