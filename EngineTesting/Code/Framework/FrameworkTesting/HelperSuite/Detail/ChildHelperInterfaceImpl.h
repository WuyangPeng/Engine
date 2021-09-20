// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.3.0.1 (2020/05/27 14:13)

#ifndef FRAMEWORK_HELPER_SUITE_CHILD_HELPER_INTERFACE_IMPL_H
#define FRAMEWORK_HELPER_SUITE_CHILD_HELPER_INTERFACE_IMPL_H 

#include "Framework/MiddleLayer/MiddleLayerInterface.h" 

#include <vector>

namespace Framework
{
	class ChildHelperInterfaceImpl
	{
	public:
		using ClassType = ChildHelperInterfaceImpl;

	public:
		explicit ChildHelperInterfaceImpl(int containerSize);

		CLASS_INVARIANT_DECLARE;

		MiddleLayerInterfaceSharedPtr GetMiddleLayerInterface(int index);
		ConstMiddleLayerInterfaceSharedPtr GetMiddleLayerInterface(int index) const;

		void SetMiddleLayerInterface(int index, const MiddleLayerInterfaceSharedPtr& middleLayer);
		int GetSize() const;

	private:
		using WeakPointer = std::weak_ptr<MiddleLayerInterface>;
		using Container = std::vector<WeakPointer>;

	private:
		Container m_Container;
	};

}

#endif // FRAMEWORK_HELPER_SUITE_CHILD_HELPER_INTERFACE_IMPL_H

