// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:04)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_IMPL_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_IMPL_H

#include "Network/NetworkDll.h" 

#include "Network/ACEWrappers/Using/ACEUsing.h"

#include <memory>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE HandleSetImpl
	{
	public:
		using ClassType = HandleSetImpl;
		using ImplTypePtr = std::shared_ptr<ClassType>;

	public:
		HandleSetImpl();
		virtual ~HandleSetImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual void SetBit(ACEHandle handle);
		virtual int64_t GetMaxSet() const;
		virtual SockFdSet* GetFdSet();
		virtual void Sync(ACEHandle maxHandle);
		virtual bool IsSet(ACEHandle handle) const;
		virtual void ClearBit(ACEHandle handle);

		virtual ImplTypePtr Clone() const;

		virtual const ACEHandleSet& GetACEHandleSet() const;

		virtual bool IsFdSetFull() const;
		virtual int IsFdSetCount() const;

		virtual bool Select(int width);

		bool IsFdSetCountIsOne() const;
	};
}

#endif // NETWORK_NETWORK_INTERFACE_HANDLE_SET_IMPL_H
