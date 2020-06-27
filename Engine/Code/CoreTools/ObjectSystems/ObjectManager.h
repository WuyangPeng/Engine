// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 15:39)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_MANAGER_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Threading/ThreadingFwd.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(ObjectManagerImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE ObjectManager : public CoreTools::Singleton<ObjectManager>
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(ObjectManager); 
		SINGLETON_GET_PTR_DECLARE(ObjectManager); 
	public: 
		using ParentType = Singleton<ObjectManager>;  

	public:	
		static void Create();
		static void Destroy() noexcept;  

	private: 
		static void DoCreate(); 
		ObjectManager(); 
		~ObjectManager();

	public:
		using FactoryFunction = ObjectInterface::FactoryFunction;

		CLASS_INVARIANT_DECLARE;

	public:
		FactoryFunction Find(const std::string& name) const;
		void Insert(const std::string& name, FactoryFunction function);
		void Remove(const std::string& name);

		uint64_t NextUniqueID();

	private:
		SINGLETON_MEMBER_DECLARE(ObjectManager);
	};
}

#define OBJECT_MANAGER_SINGLETON CoreTools::ObjectManager::GetSingleton()

#endif // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_MANAGER_H
