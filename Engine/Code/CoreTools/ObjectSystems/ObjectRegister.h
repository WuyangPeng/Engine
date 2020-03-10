// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 15:39)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

CORE_TOOLS_EXPORT_SHARED_PTR(ObjectRegisterImpl);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE ObjectRegister
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(ObjectRegister);

	public:
		ObjectRegister();

		CLASS_INVARIANT_DECLARE;

		uint64_t GetUniqueID(const ConstObjectInterfaceSmartPointer& smartPointer) const;
		int GetOrderedSize() const;
		const ConstObjectInterfaceSmartPointer& operator [](int index) const;

		uint64_t RegisterRoot(const ConstObjectInterfaceSmartPointer& smartPointer);

		template <typename T>
		void Register(const T* object);
		template <typename T>
		void Register(int elementsNumber, T* const* objects);

		template <typename T>
		void RegisterSmartPointer(const T& object);
		template <typename T>
		void RegisterSmartPointer(int elementsNumber, const T* objects);

	private:
		IMPL_TYPE_DECLARE(ObjectRegister);
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_REGISTER_H
