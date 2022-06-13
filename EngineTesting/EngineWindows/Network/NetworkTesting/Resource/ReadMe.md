@ingroup group_NetworkTesting_Documentation

----------------------------
网络库单元测试

----------------------------
1.   HelperSuite  

对帮助模块的单元测试，包括： 
（1）输入输出流宏：StreamMacroTesting。
（2）用户宏：UserMacroTesting。

----------------------------
2.	ConfigurationSuite  

对网络库配置模块的单元测试，包括：
（1）配置策略：ConfigurationStrategyTesting。
（2）配置子策略：ConfigurationSubStrategyTesting。
（3）配置参数：ConfigurationParameterTesting。
（4）配置解析：AnalysisNetworkConfigurationTesting。

----------------------------
3.	NetworkMessageSuite  

对网络消息模块的单元测试，包括：
（1）消息接口：MessageContainerGroupTesting、
			   MessageContainerTesting、
			   MessageInterfaceSharedPtrLessTesting、
			   MessageInterfaceTesting、
			   MessageManagerTesting、
			   DoubleMessageTesting、
			   IntegerDoubleMessageTesting、
			   IntegerMessageTesting、
			   MultipleDoubleMessageTesting、
			   MultipleMessageCastTesting、
			   MultipleMessageContainerGroupTesting、
			   MultipleMessageContainerTesting、
			   MultipleMessageElementTesting、
			   MultipleMessageInitValueTesting、
			   MultipleMessageSizeTesting、
			   MultipleMessageStreamingLoadTesting、
			   MultipleMessageStreamingSaveTesting、
			   MultipleMessageStreamingSizeTesting、
			   MultipleMessageTesting、
			   NullDoubleMessageTesting、
			   NullMessageTesting、
			   StringDoubleMessageTesting、
			   StringMessageTesting。
（2）消息事件：MessageEventContainerTesting、MessageEventManagerTesting、NetworkMessageEventTesting。
（3）消息类型：MessageTypeConditionOperatingTesting、MessageTypeConditionTesting。
（4）消息流：BufferReceiveStreamTesting、
			 BufferSendStreamTesting、
			 MessageBufferTesting、
			 MessageSourceTesting、
			 MessageTargetTesting、
			 ReceiveMessageLevelTesting、
			 SendMessageLevelTesting。
（5）套接字管理：SocketManagerTesting。 

----------------------------
4.	InterfaceSuite 

对网络库接口模块的单元测试，包括：
（1）基础主管理：BaseMainManagerTesting、NetworkUniqueIDManagerTesting、SingletonTesting。
（2）网络地址：SockAddressTesting。
（3）接受器：SockAcceptorTesting。
（4）连接器：SockConnectorTesting。
（5）流：SockStreamTesting。
（6）句柄集：HandleSetIteratorTesting、HandleSetTesting。
（7）发送套接字。
（8）客户端：CacheClientTesting、ClientTesting、OnlySendingClientTesting。
（9）服务器：IterativeServerTesting、ReactiveServerTesting、ServerTesting。

----------------------------
5.	ACEWrappersSuite

对ACE包装器模块的单元测试，包括：
（1）基础主管理：ACEMainManagerTesting。
（2）网络地址：ACESockInetAddressTesting。
（3）接受器：ACESockAcceptorTesting。
（4）连接器：ACESockConnectorTesting。
（5）流：ACEIovecSockStreamTesting、ACESockStreamTesting。
（6）句柄集：SockACEHandleSetIteratorTesting、SockACEHandleSetTesting。

----------------------------
6.	BoostWrappersSuite 

对boost包装器模块的单元测试，包括：
（1）基础主管理：BoostMainManagerTesting、BoostMainManagerUseMultiContextTesting、BoostMainManagerUseThreadsTesting。
（2）网络地址：BoostSockInetAddressTesting。
（3）接受器：BoostSockAcceptorAsynchronousTesting、
			 BoostSockAcceptorHandleTesting、
			 BoostSockAcceptorNonBlockingTesting、
			 BoostSockAcceptorSynchronizeTesting、
			 BoostSockAcceptorTesting。
（4）连接器：BoostSockConnectorAsynchronousTesting、BoostSockConnectorHandleTesting、BoostSockConnectorSynchronizeTesting、BoostSockConnectorTesting。
（5）流：BoostFixedSockStreamAsynchronousTesting、
		 BoostFixedSockStreamNonBlockingTesting、
		 BoostFixedSockStreamSynchronizeTesting、
		 BoostSegmentationSockStreamAsynchronousTesting、
		 BoostSegmentationSockStreamNonBlockingTesting、
		 BoostSegmentationSockStreamSynchronizeTesting、
		 BoostSockStreamHandleTesting、
		 BoostSockStreamTesting。

----------------------------
7.	NetworkWrappersSuite 

对Network包装器模块的单元测试，包括：
（1）基础主管理：NetworkMainManagerTesting。
（2）网络地址：NetworkSockInetAddressTesting。
（3）接受器：NetworkSockAcceptorTesting。
（4）连接器：NetworkSockConnectorTesting。
（5）流：NetworkSockStreamTesting。

----------------------------
8.	SocketWrappersSuite 

对socket包装器模块的单元测试，包括：
（1）socket。

----------------------------
9.	OpensslSuite（Openssl）

对openssl模块的单元测试，包括：
（1）openssl。

----------------------------