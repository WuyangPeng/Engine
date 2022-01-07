///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 14:39)

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

        // �Զ���Ķ�����б��档
        void Insert(const ObjectInterfaceSharedPtr& object);

    private:
        // ������������
        ConstObjectContainer topLevel;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OUT_TOP_LEVEL_IMPL_H
