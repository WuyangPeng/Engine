///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:23)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OUT_TOP_LEVEL_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OUT_TOP_LEVEL_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "CoreTools/ObjectSystems/ObjectType.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE OutTopLevelImpl final
    {
    public:
        using ClassType = OutTopLevelImpl;

    public:
        OutTopLevelImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsTopLevel(const ConstObjectInterfaceSharedPtr& object) const;
        NODISCARD int GetTopLevelSize() const;

        NODISCARD ConstObjectContainerConstIter begin() const noexcept;
        NODISCARD ConstObjectContainerConstIter end() const noexcept;

        // 对顶层的对象进行保存。
        void Insert(const ObjectInterfaceSharedPtr& object);

    private:
        // 顶层对象的流。
        ConstObjectContainer topLevel;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OUT_TOP_LEVEL_IMPL_H
