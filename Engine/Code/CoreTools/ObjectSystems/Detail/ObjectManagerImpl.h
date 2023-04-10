///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/29 16:25) 

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
