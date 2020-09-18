// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 15:39)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_EXPORT_SHARED_PTR(ObjectLinkImpl);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE ObjectLink
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(ObjectLink);

	public:
		ObjectLink();

		CLASS_INVARIANT_DECLARE;

		ObjectInterfaceSharedPtr GetObjectPtr(uint64_t uniqueID);
		int GetOrderedSize() const;
		ObjectInterfaceSharedPtr& operator [](int index);

		void Insert(uint64_t uniqueID, const ObjectInterfaceSharedPtr& ptr);

		void Sort();

		template <typename T>
		void ResolveObjectLink(T*& object);
		template <typename T>
		void ResolveObjectLink(int elementsNumber, T** object);

		template <typename T>
		void ResolveLink(T*& object);
		template <typename T>
		void ResolveLink(int elementsNumber, T** object);

		template <typename T>
		void ResolveObjectSmartPointerLink(T& object);
		template <typename T>
		void ResolveObjectConstSmartPointerLink(T& object);
		template <typename T>
		void ResolveObjectSmartPointerLink(int elementsNumber, T* object);
		template <typename T>
		void ResolveObjectConstSmartPointerLink(int elementsNumber, T* object);

	private:
		IMPL_TYPE_DECLARE(ObjectLink);
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_LINK_H
