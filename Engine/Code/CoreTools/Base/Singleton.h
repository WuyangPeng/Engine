// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 09:55)

// 自动Singleton基类的声明，这个基类需要手动控制创建和销毁。
// 如果实例化顺序并不重要，可以通过将派生类设为全局或局部静态。
// 也可以通过在派生类中使用new和delete来自己做。
// 静态库和动态库混用时会导致不同dll和exe使用不同的单例，需要特殊处理。
#ifndef CORE_TOOLS_BASE_SINGLETON_H
#define CORE_TOOLS_BASE_SINGLETON_H

#include <boost/noncopyable.hpp>

namespace CoreTools
{
	template <typename T>
	class Singleton : private boost::noncopyable
	{
	public:
		using ClassType = Singleton<T>;
		using ValueType = T;
		using PointType = ValueType*;
		using ReferenceType = ValueType&;

	public:
		static ReferenceType GetSingleton() noexcept;
		static PointType GetSingletonPtr() noexcept;

	protected:
		Singleton() noexcept;
		virtual ~Singleton() noexcept;

	private:
		static PointType sm_Singleton;
	};
}

#endif // CORE_TOOLS_BASE_SINGLETON_H

