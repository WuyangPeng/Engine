// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/11 09:56)

#ifndef NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_H
#define NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_H

#include "Network/NetworkDll.h"

#include "NetworkInternalFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Threading/ThreadingFwd.h"

NETWORK_EXPORT_SHARED_PTR(BaseMainManagerImpl);
EXPORT_NONCOPYABLE_CLASS(NETWORK);

namespace Network
{
	class NETWORK_DEFAULT_DECLARE BaseMainManager : public CoreTools::Singleton<BaseMainManager>
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(BaseMainManager);
		SINGLETON_GET_PTR_DECLARE(BaseMainManager);

	public:
		using ParentType = Singleton<BaseMainManager>;

	public:
		static void Create();
		static void Create(const ConfigurationStrategy& configurationStrategy);
		static void Destroy();

	private:
		static void DoCreate(const ConfigurationStrategy& configurationStrategy);

		explicit BaseMainManager(const ConfigurationStrategy& configurationStrategy);
		~BaseMainManager();

	public:
		CLASS_INVARIANT_DECLARE;

	public:
		// BoostMainManager����Run�������̡߳�
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
