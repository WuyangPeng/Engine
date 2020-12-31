//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/21 10:20)

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

        [[nodiscard]] bool IsTopLevel(const ObjectInterfaceSharedPtr& object) const;
        [[nodiscard]] int GetTopLevelSize() const;

        [[nodiscard]] ObjectContainerConstIter begin() const noexcept;
        [[nodiscard]] ObjectContainerConstIter end() const noexcept;

        [[nodiscard]] ObjectContainerIter begin() noexcept;
        [[nodiscard]] ObjectContainerIter end() noexcept;

        // 对顶层的对象进行保存。
        void Insert(const ObjectInterfaceSharedPtr& object);

    private:
        // 顶层对象的流。
        ObjectContainer m_TopLevel;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_IN_TOP_LEVEL_IMPL_H
