///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 15:23)

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
        // �洢objects���Զ������ʹ��ͼ��������ȱ�����
        ConstRegisterContainer registered;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_IMPL_H
