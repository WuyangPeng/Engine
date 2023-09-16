@ingroup group_NetworkTesting_Documentation

----------------------------
网络库单元测试

----------------------------
1.   HelperSuite  

对帮助模块的单元测试： 
（1）输入输出流宏：StreamMacroTesting。
（2）用户宏：UserMacroTesting。

----------------------------
2.	ConfigurationSuite  

对网络库配置模块的单元测试：
（1）配置策略：ConfigurationStrategyTesting。
（2）配置子策略：ConfigurationSubStrategyTesting。
（3）配置参数：ConfigurationParameterTesting。
（4）配置解析：AnalysisNetworkConfigurationTesting。

----------------------------
3.	NetworkMessageSuite  

对网络消息模块的单元测试：
（1）消息接口：MessageInterfaceTesting、
			   NullMessageTesting、
			   NullDoubleMessageTesting、 
			   MessageContainerTesting、
			   IntegerMessageTesting、
			   StringMessageTesting、
			   MultipleMessageCastTesting、
			   MultipleMessageElementTesting、
			   MultipleMessageSizeTesting、
			   MultipleMessageInitValueTesting、			   
			   MultipleMessageStreamingLoadTesting、
			   MultipleMessageStreamingSaveTesting、
			   MultipleMessageStreamingSizeTesting、
			   MultipleMessageContainerTesting、			  
			   MultipleMessageTesting、	
			   MessageContainerGroupTesting、			   
			   MessageInterfaceSharedPtrLessTesting、
			   MessageManagerTesting、		   
			   MultipleMessageContainerGroupTesting。			   
（2）消息事件：NetworkMessageEventTesting、
			   MessageEventContainerTesting、
			   MessageEventManagerTesting。
（3）消息类型：MessageTypeConditionTesting、
			   MessageTypeConditionOperatingTesting。
（4）消息流：BufferReceiveStreamTesting、
			 BufferSendStreamTesting、
			 MessageBufferTesting、
			 MessageSourceTesting、
			 MessageTargetTesting、
			 ReceiveMessageLevelTesting、
			 SendMessageLevelTesting。 
（5）protobuf： ProtoBufMessageTesting。
（6）json： JsonMessageTesting。
----------------------------
4.	ServiceWrappersSuite 

对服务包装器接口模块的单元测试：
（1）服务包装器。

----------------------------
5.	InterfaceSuite 

对网络库接口模块的单元测试：
（1）基础主管理：BaseMainManagerTesting、
				 SingletonTesting。
（2）网络地址：SockAddressTesting。
（3）接受器：SockAcceptorTesting。
（4）连接器：SockConnectorTesting。
（5）流：SockStreamTesting。
（6）句柄集：HandleSetIteratorTesting、
		     HandleSetTesting。

----------------------------
6.	ACEWrappersSuite

对ACE包装器模块的单元测试：
（1）基础主管理：ACEMainManagerTesting。
（2）网络地址：ACESockInetAddressTesting。
（3）接受器：ACESockAcceptorTesting。
（4）连接器：ACESockConnectorTesting。
（5）流：ACEIovecSockStreamTesting、
		 ACESockStreamTesting。
（6）句柄集：SockACEHandleSetIteratorTesting、
		     SockACEHandleSetTesting。

----------------------------
7.	BoostWrappersSuite 

对boost包装器模块的单元测试：
（1）基础主管理：BoostMainManagerTesting、
				 BoostMainManagerUseMultiContextTesting、
				 BoostMainManagerUseThreadsTesting。
（2）网络地址：BoostSockInetAddressTesting。
（3）接受器：BoostSockAcceptorAsynchronousTesting、
			 BoostSockAcceptorHandleTesting、
			 BoostSockAcceptorNonBlockingTesting、
			 BoostSockAcceptorSynchronizeTesting、
			 BoostSockAcceptorTesting。
（4）连接器：BoostSockConnectorAsynchronousTesting、
			 BoostSockConnectorHandleTesting、
			 BoostSockConnectorSynchronizeTesting、
			 BoostSockConnectorTesting。
（5）流：BoostFixedSockStreamAsynchronousTesting、
		 BoostFixedSockStreamNonBlockingTesting、
		 BoostFixedSockStreamSynchronizeTesting、
		 BoostSegmentationSockStreamAsynchronousTesting、
		 BoostSegmentationSockStreamNonBlockingTesting、
		 BoostSegmentationSockStreamSynchronizeTesting、
		 BoostSockStreamHandleTesting、
		 BoostSockStreamTesting。

----------------------------
8.	NetworkWrappersSuite 

对Network包装器模块的单元测试：
（1）基础主管理：NetworkMainManagerTesting。
（2）网络地址：NetworkSockInetAddressTesting。
（3）接受器：NetworkSockAcceptorTesting。
（4）连接器：NetworkSockConnectorTesting。
（5）流：NetworkSockStreamTesting。

----------------------------
9.	OpensslSuite

对openssl模块的单元测试：
（1）openssl。

----------------------------
10.	MessageOrientedMiddlewareSuite

对消息中间件模块的单元测试：
（1）消息中间件：ConsumerTesting、
				 ProducerTesting、
				 RouteServiceManagerTesting、
				 RouteServiceTesting。

----------------------------
11.	ActiveMQSuite

对ActiveMQ模块的单元测试：
（1）ActiveMQ：ActiveMQConsumerTesting、
			   ActiveMQProducerTesting、
			   ActiveMQRouteServiceManagerTesting、
			   ActiveMQRouteServiceTesting。

----------------------------
12.	NatsSuite

对Nats模块的单元测试：
（1）Nats。

----------------------------
13.	KafkaSuite

对Kafka模块的单元测试：
（1）Kafka。

----------------------------