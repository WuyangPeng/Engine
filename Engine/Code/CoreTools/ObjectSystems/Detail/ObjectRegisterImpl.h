//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.2 (2020/09/15 12:55)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_IMPL_H

#include "CoreTools/ObjectSystems/ConstObjectAssociated.h" 

namespace CoreTools
{
    class ObjectRegisterImpl
    {
    public:
        using ClassType = ObjectRegisterImpl;

    public:
        ObjectRegisterImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] uint64_t GetUniqueID(const ConstObjectInterfaceSharedPtr& object) const;
        [[nodiscard]] int GetOrderedSize() const;

        [[nodiscard]] ConstRegisterContainerConstIter begin() const noexcept;
        [[nodiscard]] ConstRegisterContainerConstIter end() const noexcept;

        [[nodiscard]] uint64_t RegisterRoot(const ConstObjectInterfaceSharedPtr& object);

    private:
        // 存储objects，对顶层对象使用图的深度优先遍历。
        ConstRegisterContainer m_Registered;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_IMPL_H
