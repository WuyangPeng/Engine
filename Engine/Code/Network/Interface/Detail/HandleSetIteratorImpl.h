// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:04)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_IMPL_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_IMPL_H

#include "Network/NetworkDll.h" 

#include "Network/ACEWrappers/Using/ACEUsing.h"

namespace Network
{
	class NETWORK_HIDDEN_DECLARE HandleSetIteratorImpl
	{
	public:
		using ClassType = HandleSetIteratorImpl;

	public:
		HandleSetIteratorImpl();
		virtual ~HandleSetIteratorImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual ACEHandle operator()();
	};
}

#endif // NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_IMPL_H
