// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/11/29 10:25)


#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Network/ACEWrappers/Using/ACEUsing.h"

NETWORK_EXPORT_SHARED_PTR(HandleSetImpl);

namespace Network
{
	class ConfigurationStrategy;

	class NETWORK_DEFAULT_DECLARE HandleSet
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(HandleSet);

	public:
		explicit HandleSet(const ConfigurationStrategy& configurationStrategy);

		IMPL_MOVE_AND_COPY_OPERATOR_COMPLETE_DECLARE(HandleSet);

		void SetBit(ACEHandle handle);
		int64_t GetMaxSet() const;
		SockFdSet* GetFdSet();
		void Sync(ACEHandle maxHandle);
		bool isSet(ACEHandle handle) const;
		void ClearBit(ACEHandle handle);

		const ACEHandleSet& GetACEHandleSet() const;

		bool IsFdSetFull() const;
		int IsFdSetCount() const;

		bool IsFdSetCountIsOne() const;

		bool Select(int width);

	private:
		IMPL_TYPE_DECLARE(HandleSet);
	};
}

#endif // NETWORK_NETWORK_INTERFACE_HANDLE_SET_H
