from keys_listener import main
import web_config
import threading
from bottle import run

# start code here -> runs the keys listener and the web config page

if __name__ == "__main__":
    threading.Thread(target=run, kwargs=dict(
        host='localhost', port=8080)).start()
    y = threading.Thread(target=main()).start()
