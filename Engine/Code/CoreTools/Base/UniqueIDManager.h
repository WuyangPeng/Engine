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

CORE_TOOLS_EXPORT_UNIQUE_PTR(UniqueIDManager);
CORE_TOOLS_EXPORT_SHARED_PTR(UniqueIDManagerImpl); 

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE UniqueIDManager : public CoreTools::Singleton<UniqueIDManager>
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(UniqueIDManager);  
		using ParentType = Singleton<UniqueIDManager>;

	private:
		enum class UniqueIDManagerCreate
		{
			Init,
		};

	public: 
		explicit UniqueIDManager(int count,UniqueIDManagerCreate uniqueIDManagerCreate);

		static void Create(int count);
		static void Destroy() noexcept;

		SINGLETON_GET_PTR_DECLARE(WindowProcessManager);

		CLASS_INVARIANT_DECLARE; 

	public:
		uint64_t NextUniqueID(int index);
		uint64_t NextDefaultUniqueID();

		template<typename E>
		static void Create(E count);

		template<typename E>
		uint64_t NextUniqueID(E index);

	private:
		using UniqueIDManagerUniquePtr = std::unique_ptr<UniqueIDManager>;

	private:
		static UniqueIDManagerUniquePtr sm_UniqueIDManager;
		IMPL_TYPE_DECLARE(UniqueIDManager);
	};
}

#define UNIQUE_ID_MANAGER_SINGLETON CoreTools::UniqueIDManager::GetSingleton()

#endif // CORE_TOOLS_BASE_UNIQUE_ID_MANAGER_H
