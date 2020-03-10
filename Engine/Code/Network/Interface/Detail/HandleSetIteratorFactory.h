// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 16:54)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/ACEWrappers/Using/ACEUsing.h"

#include <memory>

namespace Network
{	
	class HandleSetIteratorImpl;
	class ConfigurationStrategy;
	class HandleSet;

	class NETWORK_HIDDEN_DECLARE HandleSetIteratorFactory
	{
	public:
		using ClassType = HandleSetIteratorFactory;
		using ImplType = HandleSetIteratorImpl;
		using ImplTypePtr = std::shared_ptr<ImplType>;

	public:
		HandleSetIteratorFactory();

		CLASS_INVARIANT_DECLARE;
		 	 
		static const ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy, const HandleSet& handleSet);
	};	
} 

#endif // NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_FACTORY_H
