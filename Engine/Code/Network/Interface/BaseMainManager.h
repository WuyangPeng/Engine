// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/11 09:56)

#ifndef NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_H
#define NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_H

#include "Network/NetworkDll.h"

#include "NetworkInternalFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Threading/ThreadingFwd.h"

NETWORK_EXPORT_UNIQUE_PTR(BaseMainManager);
NETWORK_EXPORT_SHARED_PTR(BaseMainManagerImpl);
EXPORT_NONCOPYABLE_CLASS(NETWORK);

namespace Network
{
	class NETWORK_DEFAULT_DECLARE BaseMainManager : public CoreTools::Singleton<BaseMainManager>
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(BaseMainManager);
		using ParentType = Singleton<BaseMainManager>; 

	private:
		enum class BaseMainManagerCreate
		{
			Init,
		};

	public:
		explicit BaseMainManager(const ConfigurationStrategy& configurationStrategy, BaseMainManagerCreate baseMainManagerCreate);

		static void Create(const ConfigurationStrategy& configurationStrategy);
		static void Destroy() noexcept;

		SINGLETON_GET_PTR_DECLARE(BaseMainManager);

		CLASS_INVARIANT_DECLARE;

	public:
		// BoostMainManager调用Run会阻塞线程。
		void Run();

		IOContextType& GetIOContext();
		void StopContext();
		bool IsContextStop() const;
		void RestartContext();

	private:
		using BaseMainManagerUniquePtr = std::unique_ptr<BaseMainManager>;

	private:
		static BaseMainManagerUniquePtr sm_BaseMainManager;
		IMPL_TYPE_DECLARE(BaseMainManager);
	};
}

#define BASE_MAIN_MANAGER_SINGLETON Network::BaseMainManager::GetSingleton()

#endif // NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_H
