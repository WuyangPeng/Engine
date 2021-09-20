//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/21 10:23)

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

        [[nodiscard]] bool IsTopLevel(const ConstObjectInterfaceSharedPtr& object) const;
        [[nodiscard]] int GetTopLevelSize() const;

        [[nodiscard]] ConstObjectContainerConstIter begin() const noexcept;
        [[nodiscard]] ConstObjectContainerConstIter end() const noexcept;

        // �Զ���Ķ�����б��档
        void Insert(const ObjectInterfaceSharedPtr& object);

    private:
        // ������������
        ConstObjectContainer m_TopLevel;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OUT_TOP_LEVEL_IMPL_H
