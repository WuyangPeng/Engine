/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:54)

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

        NODISCARD int64_t GetUniqueId(const ConstObjectInterfaceSharedPtr& object) const;
        NODISCARD int GetOrderedSize() const;

        NODISCARD ConstRegisterContainerConstIter begin() const noexcept;
        NODISCARD ConstRegisterContainerConstIter end() const noexcept;

        NODISCARD int64_t RegisterRoot(const ConstObjectInterfaceSharedPtr& object);

    private:
        // 存储objects，对顶层对象使用图的深度优先遍历。
        ConstRegisterContainer registered;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_IMPL_H
