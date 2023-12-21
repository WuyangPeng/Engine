@ingroup group_Engine_Documentation

----------------------------
框架设计

游戏系统管理器分为输入管理器、网络管理器、对象逻辑、物理模拟、消息管理器、事件管理器、系统管理器、资源管理器、音频管理器、相机系统、渲染管理器、GUI管理器构成。
1.  输入管理器与网络管理器、对象逻辑、系统管理器相互通信，并将指令发送给相机系统。
2.  网络管理器与输入管理器、对象逻辑相互通信，使用多个线程进行管理。
3.  对象逻辑与网络管理器、输入管理器、物理模拟、系统管理器、消息管理器相互通信。
4.  物理模拟与对象逻辑相互通信。
5.  消息管理器与系统管理器、对象逻辑相互通信，并接收事件管理器的指令。
6.  事件管理器与系统管理器相互通信，并将指令发送给消息管理器。
7.  系统管理器与输入管理器、对象逻辑、消息管理器、事件管理器、相机系统、渲染管理器、资源管理器、音频管理器相互通信。
8.  资源管理器与系统管理器、音频管理器、GUI管理器相互通信，并将指令发送给渲染管理器。
9.  音频管理器与系统管理器、资源管理器相互通信。
10. 相机系统与系统管理器相互通信，并将指令发送给渲染管理器、GUI管理器，并接收输入管理器的指令。
11. 渲染管理器与系统管理器相互通信，并接收资源管理器、GUI管理器、相机系统的指令。
12. GUI管理器与资源管理器相互通信，并接收相机系统的指令，并将指令发送给渲染管理器。

----------------------------
客户端设计

1. GameClient（游戏客户端），与GatewayServer（网关服务器）、UpdateServer（更新服务器）相连。
2. RobotClient（机器人客户端），与GatewayServer（网关服务器）相连。
3. MessageClient（消息客户端），与GatewayServer（网关服务器）相连。
4. BackgroundClient（后台客户端），与BackgroundServer（后台服务器）相连。

----------------------------
服务器设计

中心服务器：服务器不属于某个特定的区服。数量为每个游戏根据需要开启的该服务器数量。
区服服务器：服务器属于某个或某几个特定的区服。数量为某个或某几个特定的区服根据需要开启的该服务器数量。

1.  GatewayServer（网关服务器）：
    监听客户端：GameClient（游戏客户端）、
				RobotClient（机器人客户端）、
				MessageClient（消息客户端）。
	主动连接服务器：LoginServer（登陆服务器）、
					PlayerServer（玩家服务器）、
					GameServer（游戏服务器）、
					FightingServer（战斗服务器）、
					WorldServer（世界服务器）、
					CrossServer（跨服服务器）、
					OfflineServer（离线服务器）、
					LeaderBoardServer（排行榜服务器）、
					MailServer（邮件服务器）、
					ServerManager（服务器管理者）。
    服务器类型：可配置成中心服务器。数量：1-N。
				也可以配置成区服服务器。数量：1-N。
2.  LoginServer（登陆服务器）：
    监听客户端（http获取服务器列表）：GameClient（游戏客户端）、
									  RobotClient（机器人客户端）、
									  MessageClient（消息客户端）。
    主动连接服务器：ServerManager（服务器管理者）、
					BackgroundServer（后台服务器）、
					DatabaseServer（数据库服务器）。
    监听服务器：GatewayServer（网关服务器）。
    服务器类型：中心服务器。数量：1-N。
3.  PlayerServer（玩家服务器）：
    主动连接服务器：ServerManager（服务器管理者）、
					GameServer（游戏服务器）、
					WorldServer（世界服务器）、
					OfflineServer（离线服务器）、
					LeaderBoardServer（排行榜服务器）、
					FightingServer（战斗服务器）、
					RechargeServer（充值服务器）、
					LogServer（日志服务器）、
					GameMasterServer（游戏管理员服务器）、
					DatabaseServer（数据库服务器）。	
    监听服务器：GatewayServer（网关服务器）。
    服务器类型：可配置成中心服务器。数量：1-N。
				也可以配置成区服服务器。数量：1-N。
4.  GameServer（游戏服务器）：
    主动连接服务器：ServerManager（服务器管理者）、
					WorldServer（世界服务器）、
					OfflineServer（离线服务器）、
					LeaderBoardServer（排行榜服务器）、
					FightingServer（战斗服务器）、
					RechargeServer（充值服务器）、
					LogServer（日志服务器）、
					GameMasterServer（游戏管理员服务器）、
					DatabaseServer（数据库服务器）。	
    监听服务器：GatewayServer（网关服务器）、
				PlayerServer（玩家服务器）。
    服务器类型：区服服务器。数量：1。
5.  FightingServer（战斗服务器）：
    主动连接服务器：ServerManager（服务器管理者）、
					WorldServer（世界服务器）、
					DatabaseServer（数据库服务器）。
    监听服务器：GatewayServer（网关服务器）、
				PlayerServer（玩家服务器）、
				GameServer（游戏服务器）。
    服务器类型：可配置成中心服务器。数量：1-N。
				也可以配置成区服服务器。数量：1-N。
6.  WorldServer（世界服务器）：
    主动连接服务器：ServerManager（服务器管理者）、
					DatabaseServer（数据库服务器）。
    监听服务器：GatewayServer（网关服务器）、
				PlayerServer（玩家服务器）、
				GameServer（游戏服务器）、
				FightingServer（战斗服务器）。
    服务器类型：中心服务器。数量：1。
7.  CrossServer（跨服服务器）：
    主动连接服务器：ServerManager（服务器管理者）、
					DatabaseServer（数据库服务器）。
    监听服务器：GatewayServer（网关服务器）、
				PlayerServer（玩家服务器）、
				GameServer（游戏服务器）、
				FightingServer（战斗服务器）。
    服务器类型：中心服务器。数量：1-N。
8.  OfflineServer（离线服务器）：
    主动连接服务器：ServerManager（服务器管理者）。
    监听服务器：GatewayServer（网关服务器）、
				PlayerServer（玩家服务器）、
				GameServer（游戏服务器）、
				DatabaseServer（数据库服务器）。
    服务器类型：中心服务器。数量：1-N。
9.  LeaderBoardServer（排行榜服务器）：
    主动连接服务器：ServerManager（服务器管理者）。
    监听服务器：GatewayServer（网关服务器）、
				PlayerServer（玩家服务器）、
				GameServer（游戏服务器）、
				DatabaseServer（数据库服务器）。
    服务器类型：中心服务器。数量：1-N。
10. MailServer（邮件服务器）：
    主动连接服务器：ServerManager（服务器管理者）。
    监听服务器：GatewayServer（网关服务器）、
				PlayerServer（玩家服务器）、
				GameServer（游戏服务器）。
    服务器类型：中心服务器。数量：1-N。
11. ChatServer（聊天服务器）：
    主动连接服务器：ServerManager（服务器管理者）。
    监听服务器：GatewayServer（网关服务器）、
				PlayerServer（玩家服务器）、
				GameServer（游戏服务器）。
    服务器类型：中心服务器。数量：1-N。
12. RechargeServer（充值服务器）：
    主动连接服务器：ServerManager（服务器管理者）、
					BackgroundServer（后台服务器）、
					DatabaseServer（数据库服务器）。
    监听服务器：PlayerServer（玩家服务器）、
				GameServer（游戏服务器）。
    服务器类型：中心服务器。数量：1-N。
13. LogServer（日志服务器）：
    主动连接服务器：ServerManager（服务器管理者）、
					DatabaseServer（数据库服务器）。
    监听服务器：PlayerServer（玩家服务器）、
				GameServer（游戏服务器）。 
    服务器类型：可配置成中心服务器。数量：1-N。
				也可以配置成区服服务器。数量：1-N。
14. GameMasterServer（游戏管理员服务器）：
    主动连接服务器：ServerManager（服务器管理者）、
					BackgroundServer（后台服务器）。
    监听服务器：PlayerServer（玩家服务器）、
				GameServer（游戏服务器）。
    服务器类型：中心服务器。数量：1-N。
15. UpdateServer（更新服务器）：
    监听客户端：GameClient（游戏客户端）。
    主动连接服务器：ServerManager（服务器管理者）。
    服务器类型：中心服务器。数量：1-N。
16. BackgroundServer（后台服务器）：
    监听客户端：BackgroundClient（后台客户端）。
    监听服务器：LoginServer（登陆服务器）、
				RechargeServer（充值服务器）、
				PlayerServer（玩家服务器）、
				GameMasterServer（游戏管理员服务器）、
				DatabaseServer（数据库服务器）。
    主动连接服务器：ServerManager（服务器管理者）。
    服务器类型：中心服务器。数量：1。
17. DatabaseServer（数据库服务器）：
	监听服务器：LoginServer（登陆服务器）、
				PlayerServer（玩家服务器）、
				GameServer（游戏服务器）、
				FightingServer（战斗服务器）、
				WorldServer（世界服务器）、
				CrossServer（跨服服务器）、
				LeaderBoardServer（排行榜服务器）、
				MailServer（邮件服务器）、
				RechargeServer（充值服务器）、
				LogServer（日志服务器）、
				BackgroundServer（后台服务器）。	
	主动连接服务器：ServerManager（服务器管理者）。
    服务器类型：中心服务器。数量：1-N。
18. ServerManager（服务器管理者）：
    监听服务器：GatewayServer（网关服务器），
				LoginServer（登陆服务器）、
				PlayerServer（玩家服务器）、
				GameServer（游戏服务器）、
				FightingServer（战斗服务器）、
				WorldServer（世界服务器）、
				CrossServer（跨服服务器）、
				OfflineServer（离线服务器）、
				LeaderBoardServer（排行榜服务器）、
				MailServer（邮件服务器）、
				RechargeServer（充值服务器）、
				LogServer（日志服务器）、
				UpdateServer（更新服务器）、
				BackgroundServer（后台服务器）、
				DatabaseServer（数据库服务器）。
    服务器类型：中心服务器。数量：1。
19. 其他业务服务器：
    主动连接服务器：ServerManager（服务器管理者）。
    可能需要监听服务器：GatewayServer（网关服务器）、
						PlayerServer（玩家服务器）、
						GameServer（游戏服务器）。
    服务器类型：可配置成中心服务器。数量：1-N。
				也可以配置成区服服务器。数量：1-N。

----------------------------