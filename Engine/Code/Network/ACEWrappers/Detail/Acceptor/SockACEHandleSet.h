// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 13:41)

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
		SockACEHandleSet(); 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		void SetBit(ACEHandle handle) override;
		int64_t GetMaxSet() const override;
		SockFdSet* GetFdSet() override;
		void Sync(ACEHandle maxHandle) override;
		bool IsSet(ACEHandle handle) const override;
		void ClearBit(ACEHandle handle) override;
		bool IsFdSetFull() const override;
		int IsFdSetCount() const override;

		ImplTypePtr Clone() const override;

		const ACEHandleSet& GetACEHandleSet() const noexcept override;

		bool Select(int width) override;

	private:
		ACEHandleSet m_ACEHandleSet;
	};
}

#endif // NETWORK_USE_ACE

#endif // NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_H
