// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 13:41)

#ifndef NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_ITERATOR_H
#define NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_ITERATOR_H

#include "Network/NetworkDll.h" 

#ifdef NETWORK_USE_ACE

#include "Network/Interface/Detail/HandleSetIteratorImpl.h" 

namespace Network
{
	class NETWORK_HIDDEN_DECLARE SockACEHandleSetIterator : public HandleSetIteratorImpl
	{
	public:
		using ClassType = SockACEHandleSetIterator;
		using ParentType = HandleSetIteratorImpl;

	public:
		explicit SockACEHandleSetIterator(const ACEHandleSet& handleSet);
		virtual ~SockACEHandleSetIterator();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual ACEHandle operator()() override;

	private:
		ACE_Handle_Set_Iterator m_ACEHandleSetIter;
	};
}

#endif // NETWORK_USE_ACE

#endif // NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_ITERATOR_H
