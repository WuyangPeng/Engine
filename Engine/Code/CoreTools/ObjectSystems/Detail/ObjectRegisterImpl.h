//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.2 (2020/09/15 12:55)

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
        // �洢objects���Զ������ʹ��ͼ��������ȱ�����
        ConstRegisterContainer m_Registered;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_IMPL_H
