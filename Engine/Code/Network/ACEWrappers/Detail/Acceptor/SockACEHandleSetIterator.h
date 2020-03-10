// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/01 20:14)

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
