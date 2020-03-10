// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 20:13)

#ifndef NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_H
#define NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_H

#include "Network/NetworkDll.h" 

#ifdef NETWORK_USE_ACE

#include "Network/Interface/Detail/HandleSetImpl.h"  

namespace Network
{	
	class NETWORK_HIDDEN_DECLARE SockACEHandleSet : public HandleSetImpl
	{
	public:
		using ClassType = SockACEHandleSet;
		using ParentType = HandleSetImpl;

	public:
		SockACEHandleSet ();	
		virtual ~SockACEHandleSet();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual void SetBit(ACEHandle handle) override;
		virtual int64_t GetMaxSet() const override;
		virtual SockFdSet* GetFdSet() override;
		virtual void Sync(ACEHandle maxHandle) override;
		virtual bool isSet(ACEHandle handle) const override;
		virtual void ClearBit(ACEHandle handle) override;
		virtual bool IsFdSetFull() const override;
		virtual int IsFdSetCount() const override;

		virtual ImplTypePtr Clone() const override;

		virtual const ACEHandleSet& GetACEHandleSet() const override;

		virtual bool Select(int width) override;
		 	 
	private:
		ACEHandleSet m_ACEHandleSet;
	};	
} 

#endif // NETWORK_USE_ACE

#endif // NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_H
