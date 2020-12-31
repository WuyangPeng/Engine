//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/21 10:22)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_MANAGER_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_MANAGER_IMPL_H

#include "CoreTools/ObjectSystems/ObjectInterface.h"

#include <map>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ObjectManagerImpl final
    {
    public:
        using ClassType = ObjectManagerImpl;
        using FactoryFunction = ObjectInterface::FactoryFunction;

    public:
        ObjectManagerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

    public:
        [[nodiscard]] FactoryFunction Find(const std::string& name) const;
        void Insert(const std::string& name, FactoryFunction function);
        void Remove(const std::string& name);

    private:
        using FactoryContainer = std::map<std::string, FactoryFunction>;

    private:
        FactoryContainer m_Factories;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_MANAGER_IMPL_H
