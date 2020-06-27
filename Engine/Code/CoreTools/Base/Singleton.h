// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 09:55)

// 自动Singleton基类的声明，这个基类需要手动控制创建和销毁。
// 如果实例化顺序并不重要，可以通过将派生类设为全局或局部静态。
// 也可以通过在派生类中使用new和delete来自己做。
// 静态库和动态库混用时会导致不同dll和exe使用不同的单例，需要特殊处理。
// 单例在创建和销毁时没有加锁，必须保证单线程处理。
#ifndef CORE_TOOLS_BASE_SINGLETON_H
#define CORE_TOOLS_BASE_SINGLETON_H

#include "CoreTools/Threading/Mutex.h"

namespace CoreTools
{
	template <typename T>
	class Singleton 
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
		~Singleton() noexcept;
		static Mutex& GetMutex() noexcept;

	public:
		Singleton(const Singleton&) noexcept = delete;
		Singleton& operator=(const Singleton&)  noexcept  = delete;
		Singleton(Singleton&& rhs) noexcept = delete;
		Singleton& operator=(Singleton&& rhs) noexcept = delete; 

	private:
		static PointType sm_Singleton;
		static Mutex* sm_Mutex;
	};
}

#endif // CORE_TOOLS_BASE_SINGLETON_H

