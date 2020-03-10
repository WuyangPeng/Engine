// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 15:37)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_MANAGER_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_MANAGER_IMPL_H

#include "CoreTools/ObjectSystems/ObjectInterface.h"

#include <map>
#include <string>

namespace CoreTools
{
	class ObjectManagerImpl
	{
	public:
		using ClassType = ObjectManagerImpl;
		using FactoryFunction = ObjectInterface::FactoryFunction;

	public:
		ObjectManagerImpl();

		CLASS_INVARIANT_DECLARE;

	public:
		FactoryFunction Find(const std::string& name) const;
		void Insert(const std::string& name, FactoryFunction function);
		void Remove(const std::string& name);

		uint64_t NextUniqueID();

	private:
		using FactoryContainer = std::map<std::string, FactoryFunction>;

	private:
		FactoryContainer m_Factories;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_MANAGER_IMPL_H
