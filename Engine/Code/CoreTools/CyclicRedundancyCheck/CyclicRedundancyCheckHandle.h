// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:49)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

CORE_TOOLS_EXPORT_UNIQUE_PTR(CyclicRedundancyCheckHandle);
CORE_TOOLS_EXPORT_SHARED_PTR(CyclicRedundancyCheckHandleImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	 
	class CORE_TOOLS_DEFAULT_DECLARE CyclicRedundancyCheckHandle : public Singleton<CyclicRedundancyCheckHandle>
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(CyclicRedundancyCheckHandle);
		using ParentType = Singleton<CyclicRedundancyCheckHandle>;

	private:
		enum class CyclicRedundancyCheckHandleCreate
		{
			Init,
		};

	public:
		explicit CyclicRedundancyCheckHandle(CyclicRedundancyCheckHandleCreate cyclicRedundancyCheckHandleCreate);

		static void Create();
		static void Destroy() noexcept;

		SINGLETON_GET_PTR_DECLARE(CyclicRedundancyCheckHandle);

		CLASS_INVARIANT_DECLARE;

		uint16_t GetCCITT(int index) const;
		uint16_t Get16Table(int index) const;
		uint32_t Get32Table(int index) const;

	private:
		using CyclicRedundancyCheckHandleUniquePtr = std::unique_ptr<CyclicRedundancyCheckHandle>;

	private:
		static CyclicRedundancyCheckHandleUniquePtr sm_CyclicRedundancyCheckHandle;
		IMPL_TYPE_DECLARE(CyclicRedundancyCheckHandle);
	};
}

#define CYCLIC_REDUNDANCY_CHECK_HANDLE_SINGLETON CoreTools::CyclicRedundancyCheckHandle::GetSingleton()

#endif // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_CYCLIC_REDUNDANCY_CHECK_H
