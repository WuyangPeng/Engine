///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 14:38)

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
        NODISCARD FactoryFunction Find(const std::string& name) const;
        void Insert(const std::string& name, FactoryFunction function);
        void Remove(const std::string& name);

    private:
        using FactoryContainer = std::map<std::string, FactoryFunction>;

    private:
        FactoryContainer factories;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_MANAGER_IMPL_H
