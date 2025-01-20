# HttpServer 设计

```Mermaid
classDiagram
    %% Base HTTP Server
    class IServer {
        <<interface>>
        +start()
        +stop()
        +configure()
    }
    
    %% Request/Response
    class HttpRequest {
        +headers: Map
        +method: string
        +url: string
        +body: string
        +getParameter()
        +getHeader()
    }
    
    class HttpResponse {
        +status: int
        +headers: Map
        +body: string
        +setStatus()
        +setHeader()
        +setBody()
    }
    
    %% Router
    class Router {
        +routes: Map
        +addRoute()
        +removeRoute()
        +dispatch()
    }
    
    %% Handler
    class RequestHandler {
        <<interface>>
        +handle(request: HttpRequest)
    }
    
    %% Connection
    class Connection {
        +socket: Socket
        +read()
        +write()
        +close()
    }
    
    %% Connection Pool
    class ConnectionPool {
        +connections: List
        +acquire()
        +release()
        +manage()
    }
    
    %% Middleware
    class Middleware {
        <<interface>>
        +process(request, response)
        +next()
    }

    %% Relationships
    IServer *-- Router
    IServer *-- ConnectionPool
    ConnectionPool *-- Connection
    Router o-- RequestHandler
    RequestHandler ..> HttpRequest
    RequestHandler ..> HttpResponse
    Connection ..> HttpRequest
    Connection ..> HttpResponse
    IServer o-- Middleware
```