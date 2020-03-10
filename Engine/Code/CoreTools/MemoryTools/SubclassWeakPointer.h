// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 16:43)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SUBCLASS_WEAK_POINTER_H
#define CORE_TOOLS_MEMORY_TOOLS_SUBCLASS_WEAK_POINTER_H

#include "CoreTools/CoreToolsDll.h"

#include <boost/operators.hpp>
#include <iosfwd>

namespace CoreTools
{
	template <typename SubclassSmartPointer>
	class SubclassWeakPointer : private boost::equality_comparable<SubclassWeakPointer<SubclassSmartPointer>,
										boost::equality_comparable<SubclassWeakPointer<SubclassSmartPointer>, typename SubclassSmartPointer::BaseClassType*>>
	{
	public:
		using SubclassSmartPointerType = SubclassSmartPointer;
		using ClassType = SubclassWeakPointer<SubclassSmartPointerType>;
		using SmartPointerOriginalType = typename SubclassSmartPointerType::SubclassType;
		using SubclassSmartPointerConstType = typename SubclassSmartPointer::ConstType;

	public:
		explicit SubclassWeakPointer(SubclassSmartPointer data = SubclassSmartPointer());

		CLASS_INVARIANT_DECLARE;

		const SubclassSmartPointerConstType GetConstSmartPointer() const;
		const SubclassSmartPointer GetSmartPointer() const;

		void Reset(SubclassSmartPointer data = SubclassSmartPointer());

		bool IsNullPtr() const noexcept;
		bool IsValidPtr() const noexcept;

	private:
		SmartPointerOriginalType* m_Data;
	};

	template <typename SubclassSmartPointer>
	bool operator== (const SubclassWeakPointer<SubclassSmartPointer>& lhs, typename SubclassSmartPointer::BaseClassType* data);

	template <typename SubclassSmartPointer>
	bool operator== (const SubclassWeakPointer<SubclassSmartPointer>& lhs, const SubclassWeakPointer<SubclassSmartPointer>& rhs);

	template <typename SubclassSmartPointer>
	bool operator< (const SubclassWeakPointer<SubclassSmartPointer>& lhs, const SubclassWeakPointer<SubclassSmartPointer>& rhs);

	template <typename SubclassSmartPointer>
	std::ostream& operator<<(std::ostream& os, const SubclassWeakPointer<SubclassSmartPointer>& rhs);
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SUBCLASS_WEAK_POINTER_H
