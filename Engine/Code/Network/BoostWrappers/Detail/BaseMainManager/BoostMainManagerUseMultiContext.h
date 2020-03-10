// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/10/21 13:09)


#ifndef NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_USE_MULTI_CONTEX_H
#define NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_USE_MULTI_CONTEX_H

#include "Network/NetworkDll.h"

#include "ExecutorWorkGuardContextThread.h"
#include "Network/Interface/Detail/BaseMainManagerImpl.h"

#include <boost/ptr_container/ptr_vector.hpp>

namespace Network
{
	class ConfigurationSubStrategy;

	class NETWORK_HIDDEN_DECLARE BoostMainManagerUseMultiContext : public BaseMainManagerImpl
	{
	public:
		using ClassType = BoostMainManagerUseMultiContext;
		using ParentType = BaseMainManagerImpl;

	public:
		explicit BoostMainManagerUseMultiContext(const ConfigurationSubStrategy& subStrategy);
		virtual ~BoostMainManagerUseMultiContext();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

	public:
		virtual void Run() override;

		virtual IOContextType& GetIOContext() override;
		virtual void StopContext() override;
		virtual bool IsContextStop() const override;
		virtual void RestartContext() override;

	private:
		using Container = boost::ptr_vector<ExecutorWorkGuardContextThread>;

	private:
		void InitContainer(int containerNumber);

	private:
		Container m_Container;
		int m_CurrentIndex;
	};
}

#endif // NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_USE_MULTI_CONTEX_H
