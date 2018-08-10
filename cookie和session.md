```
说到HTTP，就不得不提Session和Cookie。
但严格来说，Session和Cookie并不是http协议的一部分。
由于HTTP协议设计原则是无状态的，但是近年来出现了种种需求，其中cookie的作用就是为了解决HTTP协议无状态的缺陷所作出的努力。

后来出现的session机制则是又一种在客户端与服务器之间保持状态的解决方案。

具体来说cookie机制采用的是在客户端保持状态的方案，而session机制采用的是在服务器端保持状态的方案。

同时我们也看到，由于采用服务器端保持状态的方案在客户端也需要保存一个标识，所以session机制可能需要借助于cookie机制来达到保存标识的目的，但实际上它还有其他选择。 

Session
Session是可以存储针对于某一个用户的浏览器以及通过其当前窗口打开的任何窗口具有针对性的用户信息存储机制。

通常大家认为，只要关闭浏览器，session就消失，其实这是错误的理解。对session来说也是一样的，除非程序通知服务器删除一个session，否则服务器会一直保留。由于关闭浏览器不会导致session被删除，迫使服务器为seesion设置了一个失效时间，当距离客户端上一次使用session的时间超过这个失效时间时，服务器就可以认为客户端已经停止了活动，才会把session删除以节省存储空间.

(1)第一次访问某个web站点资源时，客户端提交没有带SessionID的请求（请求报文头没有Cookie头域信息）。
  而web服务器会检查是否有SessionID过来，没有则创建SessionID，并根据web程序自身定义在请求哪个资源时添加属于当前会话的信息（也可为空），这个信息列表以SessionID作为标识。然后将SessionID返回给客户端（通过响应报文头的Set-Cookie头域）。
  
(2 )客户端再次访问同个web站点时，提交带有SessionID的请求（通过Cookie头域存储SessionID）。由服务端判断session是否失效，如果未失效，可查询属于当前会话的信息列表。如果失效，则创建新的session（产生新的SessionID），而原先的session（包含session带的信息列表）则丢失，无法访问。

Cookie

保存SessionID的方式可以采用Cookie，这样在交互过程中浏览器可以自动的按照规则把这个SessionID发回给服务器。Cookie的命名方式类似于SessionID。

有时Cookie被人为的禁止，所以出现了其他机制以便在Cookie被禁止时仍然能够把SessionID传递回服务器。这种技术叫做URL重写，就是把SessionID直接附加在URL路径的后面，附加方式也有两种，一种是作为URL路径的附加信息，表现形式为http://www.wantsoft.com/index.asp;jsessionid= ByOK3vjFD75aPnrF7C2HmdnV6QZcEbzWoWiBYEnLerjQ99zWpBng!-145788764 。

另一种是作为查询字符串附加在URL后面，表现形式为http://www.wantsoft.com/index?js ... 99zWpBng!-145788764 。
```
