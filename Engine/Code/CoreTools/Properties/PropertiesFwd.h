// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 16:19)

#ifndef CORE_TOOLS_PROPERTIES_FWD_H
#define CORE_TOOLS_PROPERTIES_FWD_H

namespace CoreTools
{
	template<typename Value, typename ConstReference>
	class SimplePropertyGetExternal;

	template<typename Value, typename Reference>
	class SimplePropertySetExternal;

	template<typename T, typename ConstReference, ConstReference(T::*PF)() const>
	class PropertyGetExternal;

	template<typename T, typename Reference, void (T::*PF)(Reference)>
	class PropertySetExternal;

	template<typename T, typename GetReference, GetReference(T::*FG)(void) const,
			 typename SetReference, void (T::*FS)(SetReference)	>
	class PropertyGetSetExternal;

	template<typename ConstReference, ConstReference(*PF)()>
	class StaticPropertyGetExternal;

	template<typename Reference, void(*PF)(Reference)>
	class StaticPropertySetExternal;

	template<typename GetReference, typename SetReference, GetReference(*FG)(void), void(*FS)(SetReference)>
	class StaticPropertyGetSetExternal;

	template<typename Value, typename Reference, typename Container>
	class DirectPropertyGetInternal;

	template<typename Value, typename Reference, typename Container>
	class DirectPropertySetInternal;

	template<typename T, typename ConstReference, ConstReference(T::*PF)() const, ptrdiff_t(*FO)()>
	class PropertyGetExternalOffset;

	template<typename T, typename V, typename Reference, Reference(T::*PF)() const, ptrdiff_t(*FO)()>
	class PropertyGetInternalOffset;

	template<typename Value, typename ConstReference, typename Container, ptrdiff_t(*FO)(), ConstReference(Container::*FG)() const>
	class MethodPropertyGet;

	template<typename Value, typename Reference, typename Container, ptrdiff_t(*FO)(), void (Container::*FS)(Reference)>
	class MethodPropertySet;

	template<typename Value, typename GetReference, typename SetReference, typename Container,
			 ptrdiff_t(*FO)(), GetReference(Container::*FG)() const, void (Container::*FS)(SetReference)>
	class MethodPropertyGetSet;

	template<typename ConstReference, typename Container, ptrdiff_t(*FO)(), ConstReference(Container::*FG)() const>
	class MethodPropertyGetExternal;

	template<typename Reference, typename Container, ptrdiff_t(*FO)(), void(Container::*FS)(Reference)>
	class MethodPropertySetExternal;

	template<typename GetReference, typename SetReference, typename Container,
			 ptrdiff_t(*FO)(), GetReference(Container::*FG)() const, void (Container::*FS)(SetReference)>
	class MethodPropertyGetSetExternal;

	template<typename V, typename GetReference, typename SetReference, typename Container,
			 GetReference(*FG)(void), void(*FS)(SetReference)>
	class StaticPropertyGetSet;

	template<typename ID, typename T>
	class PropertyBase;

	template<typename ID, typename T, typename V, typename R, void (T::*FS)(R), R(T::*FG)() const>
	class Property;
}

#endif // CORE_TOOLS_PROPERTIES_FWD_H