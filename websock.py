#coding:utf-8

import tornado.httpserver
import tornado.ioloop
import tornado.web
import tornado.websocket
from tornado.options import define
import socket

hos = "127.0.0.1"
#por -> ソケット通信用のポート
#openFrameworksとの通信で使用する
por = 11999
#PORT -> Webソケット通信用のポート番号
PORT = 8000
#socket通信用のオブジェクト
ser = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

#イニシャライズ
define("port", default=PORT, help="run on the given port", type=int)

class ControlMouseWebSocket(tornado.websocket.WebSocketHandler):

    def open(self):
        print "open websocket"

    def on_message(self, message):
        mes = message.split(',')
        print "x-> ", mes[0],
        print "y-> ", mes[1],
        print "z-> ", mes[2]
        send_data = str(mes[0])+":"+str(mes[1])+":"+str(mes[2])
        ser.sendto(send_data, (hos,por))


    def on_close(self):
        print "close websocket"


class Application(tornado.web.Application):
    def __init__(self):
        handlers = [(r"/move", ControlMouseWebSocket)]
        settings = dict(debug=True)
        tornado.web.Application.__init__(self, handlers, **settings)

def main():
    tornado.options.parse_command_line()
    http_server = tornado.httpserver.HTTPServer(Application())
    http_server.listen(PORT)
    tornado.ioloop.IOLoop.instance().start()

if __name__ == "__main__":
    main()
    