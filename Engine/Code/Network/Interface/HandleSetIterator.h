// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.1.0 (2019/11/29 10:27)


#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Network/ACEWrappers/Using/ACEUsing.h"

#include <boost/noncopyable.hpp> 

NETWORK_EXPORT_SHARED_PTR(HandleSetIteratorImpl);
EXPORT_NONCOPYABLE_CLASS(NETWORK);

namespace Network
{
	class ConfigurationStrategy;
	class HandleSet;

	class NETWORK_DEFAULT_DECLARE HandleSetIterator : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(HandleSetIterator);

	public:
		explicit HandleSetIterator(const ConfigurationStrategy& configurationStrategy, const HandleSet& handleSet);

		IMPL_MOVE_OPERATOR_COMPLETE_DECLARE(HandleSetIterator);

		ACEHandle operator()();

	private:
		IMPL_TYPE_DECLARE(HandleSetIterator);
	};
}

#endif // NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_H
