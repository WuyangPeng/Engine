// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 09:56)

#ifndef CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_H
#define CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Base/SingletonDetail.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(UniqueIDManagerImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class Mutex;

	class CORE_TOOLS_DEFAULT_DECLARE UniqueIDManager : public CoreTools::Singleton<UniqueIDManager>
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(UniqueIDManager); 
		SINGLETON_GET_PTR_DECLARE(UniqueIDManager);  

	public: 
		using ParentType = Singleton<UniqueIDManager>;

	public:	
		static void Create(int count);
		static void Destroy(); 

	private: 
		static void DoCreate(int count);
		explicit UniqueIDManager(int count);
		~UniqueIDManager();
		
	public:	 
		CLASS_INVARIANT_DECLARE;

	public:
		uint64_t NextUniqueID(int index);
		uint64_t NextDefaultUniqueID();

		template<typename E>
		static void Create(E count);

		template<typename E>
		uint64_t NextUniqueID(E index);

	private:
		SINGLETON_MEMBER_DECLARE(UniqueIDManager);
	};
}

#define UNIQUE_ID_MANAGER_SINGLETON CoreTools::UniqueIDManager::GetSingleton()

#endif // CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_H
