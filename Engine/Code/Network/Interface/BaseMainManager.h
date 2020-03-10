// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.1.0 (2019/10/21 09:56)


#ifndef NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_H
#define NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_H

#include "Network/NetworkDll.h"

#include "NetworkInternalFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

NETWORK_EXPORT_SHARED_PTR(BaseMainManagerImpl);
EXPORT_NONCOPYABLE_CLASS(NETWORK);

namespace CoreTools
{
	class Mutex;
}

namespace Network
{
	class ConfigurationStrategy;

	class NETWORK_DEFAULT_DECLARE BaseMainManager : public CoreTools::Singleton<BaseMainManager>
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(BaseMainManager);
		SINGLETON_GET_PTR_DECLARE(BaseMainManager);
		
	public: 
		using ParentType = Singleton<BaseMainManager>;

	public:	
		static void Create(const ConfigurationStrategy& configurationStrategy);
		static void Destroy(); 

	private: 
		static void DoCreate(const ConfigurationStrategy& configurationStrategy);

		explicit BaseMainManager(const ConfigurationStrategy& configurationStrategy);
		~BaseMainManager();

	public:
		CLASS_INVARIANT_DECLARE;
		
	public:	
		// BoostMainManager调用Run会阻塞线程。
		void Run();

		IOContextType& GetIOContext();
		void StopContext();
		bool IsContextStop() const;
		void RestartContext();

	private:
		SINGLETON_MEMBER_DECLARE(BaseMainManager);
	};	
}

#define BASE_MAIN_MANAGER_SINGLETON Network::BaseMainManager::GetSingleton()

#endif // NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_H
