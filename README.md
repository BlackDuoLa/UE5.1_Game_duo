# Game_Duo

**本文档存入一些GAS中遇到的函数方便浏览总结**

##### AbilitySystemCompinent:

1. **TryActivateAbility**：这是一个客户端函数，用于尝试激活一个能力。它生成一个新的预测键（PredictionKey），并调用服务器函数ServerTryActivateAbility进行验证。
2. **ServerTryActivateAbility**：这是一个服务器函数，用于验证客户端的请求是否真的应该激活某个能力。根据验证结果，服务器会调用ClientActivateAbility(Failed/Succeed)来通知客户端结果。
3. **ClientActivateAbility(Failed/Succeed)**：这是客户端接收到的回调函数，用于处理能力激活成功或失败的结果。如果激活失败，客户端需要回滚相关的副作用；如果成功，则等待属性复制赶上。
4. **GetGameplayAttributeValueChangeDelegate**：这个函数用于获取属性值变化的委托，以便在属性值变化时执行特定的操作，如更新UI等。
5. **FActiveGameplayEffectsContainer**：这是ASC内部使用的一个容器，用于保存当前活跃的游戏效果。ASC提供了一系列的方法来操作这个容器，如添加、移除和查询游戏效果。
6. **GameplayEffect**：这是GAS中用于表示游戏效果的类。ASC负责将GameplayEffect应用于目标或自身，并管理其生命周期。
7. **GameplayAttribute**：这是GAS中用于表示属性的类。ASC提供了分配、初始化和获取属性的方法。
